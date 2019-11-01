#include <iostream>
#include <emscripten.h>
#include <emscripten/html5.h>
#include <emscripten/val.h>

#include <array>
#include <map>
#include <string>
#include <memory>
#include <GLES3/gl32.h>

#include "webcoder_graphics.h"


void main_loop(void) 
{
    std::cout << "Render loop" << std::endl;
    
    /*
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
    */
};


int main()
{
    auto cm = WebCoder::Graphics::CanvasManager();

    auto canvasPtr1 = cm.getCanvasPtr("#plot1");
    auto canvasPtr2 = cm.getCanvasPtr("#plot2");
    auto canvasPtr3 = cm.getCanvasPtr("#plot3");
/*
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
*/
    emscripten_set_main_loop(main_loop,0,1);

    return 0;
};