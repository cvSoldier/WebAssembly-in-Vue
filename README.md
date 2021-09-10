# WebAssembly-in-Vue
在vue中使用WebAssembly的样例工程

npm install安装依赖
npm run dev启动工程

工程会根据设置的值来计算使用wasm和js的fibnacci函数的消耗时间，然后使用echarts绘制图表
(index):1 Uncaught (in promise) RuntimeError: abort(undefined) at Error
    at jsStackTrace (eval at completeLoadEmscriptenModule (webpack://qt-webpack/./src/qtcompile/qtloader.js?), <anonymous>:1369:12)
    at stackTrace (eval at completeLoadEmscriptenModule (webpack://qt-webpack/./src/qtcompile/qtloader.js?), <anonymous>:1384:11)
    at abort (eval at completeLoadEmscriptenModule (webpack://qt-webpack/./src/qtcompile/qtloader.js?), <anonymous>:973:43)
    at _abort (eval at completeLoadEmscriptenModule (webpack://qt-webpack/./src/qtcompile/qtloader.js?), <anonymous>:7382:2)
    at wasm-function[15328]:1
    at wasm-function[30075]:68
    at wasm-function[25250]:386
    at wasm-function[25251]:76
    at wasm-function[19019]:357
    at wasm-function[18538]:85
    at abort (eval at completeLoadEmscriptenModule (webpack://qt-webpack/./src/qtcompile/qtloader.js?), <anonymous>:975:8)
    at _abort (eval at completeLoadEmscriptenModule (webpack://qt-webpack/./src/qtcompile/qtloader.js?), <anonymous>:7382:2)
    at wasm-function[15328]:1
    at wasm-function[30075]:68
    at wasm-function[25250]:386
    at wasm-function[25251]:76
    at wasm-function[19019]:357
    at wasm-function[18538]:85
    at wasm-function[18540]:86
    at wasm-function[18527]:426
