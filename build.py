import platform
import subprocess

cmd = []
print(platform.system())
if platform.system() == 'Linux':
    cmd = ("source emsdk/emsdk_env.sh") # +
            # "em++ ./src/main.cpp -s USE_WEBGL2=1 -std=c++14 -o ./build/index.js -o ./build/index.wasm")
else:
    cmd = (".\\emsdk\\emsdk activate latest && " +
            ".\\emsdk\\emsdk_env.bat && " +
            "em++ .\\src\\main.cpp -s USE_WEBGL2=1 -std=c++14 -o .\\build\\index.js -o .\\build\\index.wasm")

print(cmd)


process = subprocess.Popen(cmd.split(), stdout=subprocess.PIPE)
output, error = process.communicate()
print('returned value:', output)