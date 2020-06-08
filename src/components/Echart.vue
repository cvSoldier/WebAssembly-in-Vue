<template>
  <div class="chart-root"></div>
</template>

<script>
import echarts from 'echarts'

export default {
  name: 'Chart',
  methods: {
    drawChart(data) {
      var posList = [
        'left', 'right', 'top', 'bottom',
        'inside',
        'insideTop', 'insideLeft', 'insideRight', 'insideBottom',
        'insideTopLeft', 'insideTopRight', 'insideBottomLeft', 'insideBottomRight'
      ];

      app.configParameters = {
        rotate: {
          min: -90,
          max: 90
        },
        align: {
          options: {
            left: 'left',
            center: 'center',
            right: 'right'
          }
        },
        verticalAlign: {
          options: {
            top: 'top',
            middle: 'middle',
            bottom: 'bottom'
          }
        },
        position: {
          options: echarts.util.reduce(posList, function (map, pos) {
            map[pos] = pos;
            return map;
          }, {})
        },
        distance: {
          min: 0,
          max: 100
        }
      };

      app.config = {
        rotate: 90,
        align: 'left',
        verticalAlign: 'middle',
        position: 'insideBottom',
        distance: 15,
        onChange: function () {
          var labelOption = {
            normal: {
              rotate: app.config.rotate,
              align: app.config.align,
              verticalAlign: app.config.verticalAlign,
              position: app.config.position,
              distance: app.config.distance
            }
          };
          myChart.setOption({
            series: [{
              label: labelOption
            }, {
              label: labelOption
            }, {
              label: labelOption
            }, {
              label: labelOption
            }]
          });
        }
      };


      var labelOption = {
        normal: {
          show: true,
          position: app.config.position,
          distance: app.config.distance,
          align: app.config.align,
          verticalAlign: app.config.verticalAlign,
          rotate: app.config.rotate,
          formatter: '{c}  {name|{a}}',
          fontSize: 16,
          rich: {
            name: {
              textBorderColor: '#fff'
            }
          }
        }
      };

      const option = {
        color: ['#003366', '#006699'],
        tooltip: {
          trigger: 'axis',
          axisPointer: {
            type: 'shadow'
          }
        },
        toolbox: {
          show: true,
          orient: 'vertical',
          left: 'right',
          top: 'center',
          feature: {
            mark: {show: true},
            dataView: {show: true, readOnly: false},
            magicType: {show: true, type: ['line', 'bar', 'stack', 'tiled']},
            restore: {show: true},
            saveAsImage: {show: true}
          }
        },
        calculable: true,
        xAxis: [
          {
            type: 'category',
            axisTick: {show: false},
            // data: ['40', '43', '46', '49']
            data: data.xAxis
          }
        ],
        yAxis: [
          {
            type: 'value'
          }
        ],
        series: [
          {
            name: 'wasm',
            type: 'bar',
            barGap: 0,
            label: labelOption,
            // data: [797, 3694, 16210, 69830]
            data: data.series.c
          },
          {
            name: 'js',
            type: 'bar',
            label: labelOption,
            // data: [4061, 20296, 82032, 369963]
            data: data.series.js
          },
          {
            name: 'ts',
            type: 'bar',
            label: labelOption,
            // data: [4061, 20296, 82032, 369963]
            data: data.series.ts
          }
        ]
      };
      const chart = echarts.init(document.getElementsByClassName('chart-root')[0])
      chart.setOption(option)
    }
  }
}
</script>
<style scoped>
.chart-root {
  margin: 0 auto;
  width: 1000px;
  height: 500px;
}
</style>
