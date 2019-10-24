#include <iostream>
#include <emscripten.h>
#include <emscripten/html5.h>
#include <GL/glfw.h>

class Plot
{
public:
EMSCRIPTEN_WEBGL_CONTEXT_HANDLE context;

Plot(const char* id) {
    EmscriptenWebGLContextAttributes attribs;
    emscripten_webgl_init_context_attributes(&attribs);
    attribs.alpha = false;
    attribs.enableExtensionsByDefault = false;
    context = emscripten_webgl_create_context(id, &attribs); 
}

auto render() -> void
{    
    emscripten_webgl_make_context_current(context);

    glfw


    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearStencil(0);
    glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

};


