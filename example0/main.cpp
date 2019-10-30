#include <iostream>
#include <emscripten.h>
#include <emscripten/html5.h>
#include <emscripten/val.h>

#include <array>
#include <map>
#include <string>
#include <memory>
#include <GLES3/gl32.h>

int main()
{
    EmscriptenWebGLContextAttributes attr;
    emscripten_webgl_init_context_attributes(&attr);
    attr.alpha = EM_FALSE;
    attr.depth = EM_FALSE;
    attr.stencil = EM_FALSE;
    attr.antialias = EM_FALSE;
    attr.preserveDrawingBuffer = EM_FALSE;
    attr.failIfMajorPerformanceCaveat = EM_FALSE;
    attr.preferLowPowerToHighPerformance = EM_TRUE;
    attr.enableExtensionsByDefault = EM_TRUE;
    attr.premultipliedAlpha = EM_FALSE;
    attr.majorVersion = 1;
    attr.minorVersion = 0;

    EMSCRIPTEN_WEBGL_CONTEXT_HANDLE context = emscripten_webgl_create_context("canvas", &attr);

    emscripten_webgl_make_context_current(context);
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClearStencil(0);
    glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
 
    return 0;
};