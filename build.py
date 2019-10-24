import platform
import os


if platform.system() == 'Linux':
    cmd = ""
else:
    cmd = (".\emsdk\emsdk activate latest && " +
            ".\emsdk\emsdk_env.bat && " +
            "em++ .\src\main.cpp -s USE_WEBGL2=1 -std=c++14 -o .\\build\index.js -o .\\build\index.wasm")

returned_value = os.system(cmd)  # returns the exit code in unix
print('returned value:', returned_value)