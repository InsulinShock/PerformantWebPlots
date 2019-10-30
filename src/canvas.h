#ifndef WEBCODER_GRAPHICS_CANVAS_H
#define WEBCODER_GRAPHICS_CANVAS_H

#include <iostream>
#include <emscripten.h>
#include <emscripten/html5.h>
#include <emscripten/val.h>
#include <GLES2/gl2.h>
#include <array>
#include <map>
#include <string>
#include <memory>

namespace WebCoder
{
namespace Graphics
{

class Canvas
{
private:
    static std::vector<std::shared_ptr<emscripten::val>> canvasPtrs_;
    static EmscriptenWebGLContextAttributes attr_;
    static EMSCRIPTEN_WEBGL_CONTEXT_HANDLE context_;
    const std::shared_ptr<emscripten::val> canvasPtr_;

    static auto getContextAttribute() -> EmscriptenWebGLContextAttributes
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
        return attr;
    };

public:
    Canvas(const std::string id) : canvas_(emscripten::val::global("document").call<emscripten::val>("getElementById", id)),
                                   attr_(Canvas::getContextAttribute()),
                                   context_(emscripten_webgl_create_context(id.c_str(), &attr_))
                                       {};

    auto getId() -> std::string
    {
        return canvas_["id"].as<std::string>();
    };

    auto render() -> void
    {
        emscripten_webgl_make_context_current(context_);
        glClearColor(std::get<0>(this->color_), std::get<1>(this->color_), std::get<2>(this->color_), std::get<3>(this->color_));
        glClearStencil(0);
        glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    };

    auto setColor(const std::array<float, 4> color) -> void
    {
        this->color_ = color;
    };

    auto getColor(void) const -> std::array<float, 4>
    {
        return this->color_;
    };
};
} // namespace Graphics
} // namespace WebCoder
#endif