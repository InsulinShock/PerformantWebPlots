#include <iostream>
#include <emscripten.h>
#include <emscripten/html5.h>
#include <emscripten/val.h>

#include <array>
#include <map>
#include <string>
#include <memory>
#include <GLES3/gl32.h>


EMSCRIPTEN_WEBGL_CONTEXT_HANDLE context;

void main_loop(void) 
{
    emscripten_webgl_make_context_current(context);   
    glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
    glClearStencil(0);
    glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    glFinish();


    emscripten::val onScreenCanvas = emscripten::val::global("document").call<emscripten::val>("querySelector",std::string("#canvas"));
    emscripten::val offScreenCanvas = emscripten::val::global("document").call<emscripten::val>("querySelector",std::string("#offscreen"));

    onScreenCanvas
        .call<emscripten::val>("getContext",std::string("2d"))
        .call<void>("drawImage",offScreenCanvas, emscripten::val(0), emscripten::val(0));

};




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
    attr.majorVersion = 3;
    attr.minorVersion = 2;

    context = emscripten_webgl_create_context("#offscreen", &attr);

    emscripten_webgl_make_context_current(context);   
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClearStencil(0);
    glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    glFinish();

    std::cout << glGetString(GL_VERSION) << std::endl;

    emscripten::val onScreenCanvas = emscripten::val::global("document").call<emscripten::val>("querySelector",std::string("#canvas"));
    emscripten::val offScreenCanvas = emscripten::val::global("document").call<emscripten::val>("querySelector",std::string("#offscreen"));



    onScreenCanvas
        .call<emscripten::val>("getContext",std::string("2d"))
        .call<void>("drawImage",offScreenCanvas, emscripten::val(0), emscripten::val(0));

    emscripten_set_main_loop(main_loop,0,1);

    return 0;
};