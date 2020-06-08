<template>
  <div id="app">
    <Echart ref="chart"/>
  </div>
</template>

<script>
import Echart from './components/Echart'
import wasmC from './wasm/index.c'
import wasmTs from './ts-wasm/index.ts'

export default {
  name: 'App',
  data() {
    return {
      xAxis: [],
      cTimes: [],
      jsTimes: [],
      tsTimes: [],
    }
  },
  components: {
    Echart
  },
  mounted() {
    const p = Promise.all([wasmC({
      'global': {},
      'env': {
        'memoryBase': 0,
        'tableBase': 0,
        'memory': new WebAssembly.Memory({initial: 256}),
        'table': new WebAssembly.Table({initial: 0, element: 'anyfunc'})
      }
    }), wasmTs])
    p.then(_ => {
      debugger
      this.fibC = _[0].instance.exports.fibonacci;
      this.fibTs = _[1].fibonacci;
      let i = 40
      console.log(i);
      while(i < 42) {
        this.xAxis.push(i)
        this.cTimes.push(this.computeTime(this.fibC, i))
        // this.cTailTimes[i] = this.computeTime(this.fibTailC, i)
        this.tsTimes.push(this.computeTime(this.fibTs, i))
        // this.jsTailTimes[i] = this.computeTime(this.fibTailJS, i)
        i += 3
      }
      this.$refs.chart.drawChart({ xAxis: this.xAxis, series: { c: this.cTimes, ts: this.tsTimes }})
    }).catch(console.log)
    // wasmC({
    //   'global': {},
    //   'env': {
    //     'memoryBase': 0,
    //     'tableBase': 0,
    //     'memory': new WebAssembly.Memory({initial: 256}),
    //     'table': new WebAssembly.Table({initial: 0, element: 'anyfunc'})
    //   }
    // }).then(result => {
    //   const exports = result.instance.exports;
    //   const add = exports.add;
    //   this.fibC = exports.fibonacci;
    //   this.fibTailC = exports.fibonacciTail;

      // let i = 40
      // while(i < 45) {
      //   this.xAxis.push(i)
      //   this.cTimes.push(this.computeTime(this.fibC, i))
      //   // this.cTailTimes[i] = this.computeTime(this.fibTailC, i)
      //   this.jsTimes.push(this.computeTime(this.fibJS, i))
      //   // this.jsTailTimes[i] = this.computeTime(this.fibTailJS, i)
      //   i += 3
      // }
      // this.$refs.chart.drawChart({ xAxis: this.xAxis, series: { c: this.cTimes, js: this.jsTimes }})
    // });
    // wasmTs.then(result => {
    //   this.fibTs = result.fibonacci;

    //   let i = 40
    //   while(i < 47) {
    //     this.xAxis.push(i)
    //     this.cTimes.push(this.computeTime(this.fibTs, i))
    //     // this.cTailTimes[i] = this.computeTime(this.fibTailC, i)
    //     this.jsTimes.push(this.computeTime(this.fibJS, i))
    //     // this.jsTailTimes[i] = this.computeTime(this.fibTailJS, i)
    //     i += 3
    //   }
    //   this.$refs.chart.drawChart({ xAxis: this.xAxis, series: { c: this.cTimes, js: this.jsTimes }})
    // });
  },
  methods: {
    computeTime(func, times) {
      var now = Date.now()
      func(times)
      return Date.now() - now
    },
    fibJS (n) {
      if (n <= 1) {
        return n;
      } else {
        return this.fibJS(n - 1) + this.fibJS(n - 2);
      }
    },
    fibTailJS (n, a1 = 1, a2 = 1) {
      if (n <= 1) {
        return a2;
      } else {
        return this.fibTailJS(n - 1, a2, a1 + a2);
      }
    }
  }
}
</script>

<style>
#app {
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
}
</style>
