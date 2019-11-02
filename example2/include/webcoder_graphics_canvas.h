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
#include <tuple>

namespace WebCoder
{
namespace Graphics
{

class Canvas
{
private:
    // const std::string cssID_;
    const emscripten::val canvas_;
public:
    Canvas(const std::string &id);

    auto getCssId() const -> std::string;


    auto copyOffscreenCanvas(
        const emscripten::val offScreenCanvas, 
        const std::tuple<unsigned int, unsigned int, unsigned int, unsigned int>& offScreenRect) -> void;
        

    auto getDimensions() -> std::tuple<unsigned int, unsigned int>;
};

} // namespace Graphics
} // namespace WebCoder

#endif