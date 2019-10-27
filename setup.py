import platform
import os



cmd = "git clone https://github.com/emscripten-core/emsdk.git"

returned_value = os.system(cmd)  # returns the exit code in unix
print('returned value:', returned_value)


if platform.system() == 'Linux':
    cmd = "./emsdk/emsdk install latest"
else:
    cmd = ".\\emsdk\\emsdk.bat install latest"

returned_value = os.system(cmd)  # returns the exit code in unix
print('returned value:', returned_value)