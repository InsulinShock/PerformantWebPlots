#ifndef WEBCODER_GRAPHICS_CANVASMANAGER_H
#define WEBCODER_GRAPHICS_CANVASMANAGER_H

#include <iostream>
#include <emscripten.h>
#include <emscripten/html5.h>
#include <emscripten/val.h>
#include <GLES3/gl32.h>

#include <array>
#include <map>
#include <string>
#include <memory>

#include "webcoder_graphics_canvas.h"

namespace WebCoder
{
namespace Graphics
{
class CanvasManager
{
private:
    static EMSCRIPTEN_WEBGL_CONTEXT_HANDLE context_;
    static std::vector<std::shared_ptr<WebCoder::Graphics::Canvas>> canvases_;

public:
    CanvasManager(void){};

    static EMSCRIPTEN_WEBGL_CONTEXT_HANDLE createOpenGLContext(const std::string &cssId)
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

        // Add offscreen canvas creation here

        return emscripten_webgl_create_context(cssId.c_str(), &attr);
    };

    auto getCanvasPtr(const std::string &cssId) -> std::shared_ptr<WebCoder::Graphics::Canvas>
    {
        auto cssIdsMatch = [=](const std::shared_ptr<WebCoder::Graphics::Canvas> canvasPtr) {
            return canvasPtr->getCssId().compare(cssId);
        };
        auto canvasIter = std::find_if(canvases_.begin(), canvases_.end(), cssIdsMatch);

        if (canvasIter != canvases_.end())
            return *canvasIter;

        auto canvasPtr = std::make_shared<WebCoder::Graphics::Canvas>(cssId);

        canvases_.push_back(canvasPtr);

        return canvasPtr;
    };
};
} // namespace Graphics
} // namespace WebCoder

auto WebCoder::Graphics::CanvasManager::context_ = WebCoder::Graphics::CanvasManager::createOpenGLContext("#offScreenCanvas");
auto WebCoder::Graphics::CanvasManager::canvases_ = std::vector<std::shared_ptr<WebCoder::Graphics::Canvas>>();

#endif