import os

cmd = "git clone https://github.com/emscripten-core/emsdk.git"

returned_value = os.system(cmd)  # returns the exit code in unix
print('returned value:', returned_value)


cmd = ".\emsdk\emsdk.bat install latest"

returned_value = os.system(cmd)  # returns the exit code in unix
print('returned value:', returned_value)