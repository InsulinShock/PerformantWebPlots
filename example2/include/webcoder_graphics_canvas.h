#ifndef WEBCODER_GRAPHICS_CANVAS
#define WEBCODER_GRAPHICS_CANVAS

#include <iostream>
#include <emscripten.h>
#include <emscripten/html5.h>
#include <emscripten/val.h>
#include <GLES3/gl32.h>

#include <array>
#include <vector>
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
    const std::string cssID_;
    const emscripten::val canvas_;
public:
    Canvas(const std::string &id) : cssID_(id)
    {

    };

    auto getCssId() const -> std::string
    {
        return this->cssID_;
    };

    auto copyOffscreenCanvas() -> void 
    {

    };

    auto getDimensions() -> std::array<unsigned int,4>
    {
        const auto 
    };

};

} // namespace Graphics
} // namespace WebCoder

#endif