#include <iostream>
#include <emscripten.h>
#include <emscripten/html5.h>
#include <emscripten/val.h>
#include <GLES2/gl2.h>
#include <array>
#include <map>
#include <string>
#include <memory>
#include "canvas.h"

namespace WebCoder
{
class CanvasManager
{
private:
    static std::vector<std::shared_ptr<WebCoder::Canvas>> canvasPtrs_;

public:
    CanvasManager(){};

    auto getCanvasPtr(const std::string id) const -> std::shared_ptr<WebCoder::Canvas>
    {

        // Check if client already exists in the list
        auto idMatch = [&id](std::shared_ptr<WebCoder::Canvas> canvasPtr) {
            std::cout << (*canvasPtr.get()).getId() << std::endl;
            return id.compare((*canvasPtr.get()).getId()) == 0;
        };

        auto it = std::find_if(canvasPtrs_.begin(), canvasPtrs_.end(), idMatch);

        if (it != this->canvasPtrs_.end())
        {
            std::cout << "Using existing canvas." << std::endl;
            return *it;
        }

        // Otherwise create a new client object
        auto canvasPtr = std::make_shared<WebCoder::Canvas>(id);
        this->canvasPtrs_.push_back(canvasPtr);
        std::cout << "Creating new websocket." << std::endl;
        return canvasPtr;
    };
};

std::vector<std::shared_ptr<WebCoder::Canvas>> CanvasManager::canvasPtrs_ = {};
} // namespace WebCoder