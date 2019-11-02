#include "webcoder_graphics_canvas.h"

WebCoder::Graphics::Canvas::Canvas(const std::string& id) : 
    canvas_(emscripten::val::global("document").call<emscripten::val>("querySelector", id))
{};

auto WebCoder::Graphics::Canvas::getCssId() const -> std::string
{
    return "#" + canvas_["id"].as<std::string>();
};


auto WebCoder::Graphics::Canvas::copyOffscreenCanvas(
    const emscripten::val offScreenCanvas,
    const std::tuple<unsigned int, unsigned int, unsigned int, unsigned int>& offScreenRect) -> void
{
    canvas_.call<emscripten::val>("getContext", emscripten::val("2d"))
        .call<void>("drawImage", offScreenCanvas,
                    emscripten::val(std::get<0>(offScreenRect)),
                    emscripten::val(std::get<1>(offScreenRect)),
                    emscripten::val(std::get<2>(offScreenRect)),
                    emscripten::val(std::get<3>(offScreenRect)),
                    emscripten::val(0),
                    emscripten::val(0),
                    canvas_["width"],
                    canvas_["height"]);
};


auto WebCoder::Graphics::Canvas::getDimensions() -> std::tuple<unsigned int, unsigned int>
{
    return {canvas_["width"].as<unsigned int>(), canvas_["height"].as<unsigned int>()};
};