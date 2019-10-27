#include <iostream>
#include <algorithm>
#include "canvas.h"
#include "canvasManager.h"
#include <memory>

void one_iter(void* arg) {
  // process input
  // render to screen
};

void RenderLoopCallback()
{
    static std::array<float,4> color = {1.0f,0.0f,0.0f,0.0f};
    static float ii = 0;
    ii = ii + 0.01f;
    int j = (int)ii;
    std::rotate(color.begin(), color.begin()+(j%3), color.end()); 
    
    auto canvasManager = WebCoder::CanvasManager();
    std::shared_ptr<WebCoder::Canvas> canvasPtr = canvasManager.getCanvasPtr("canvas");
    
    canvasPtr->setColor(color);
    canvasPtr->render();
};



int main()
{
    auto canvasManager = WebCoder::CanvasManager();
    auto canvasPtr = canvasManager.getCanvasPtr("canvas");    //std::make_shared<WebCoder::Canvas>("canvas");
    // WebCoder::Canvas canvas1 = WebCoder::Canvas("canvas1");

    canvasPtr->setColor({0.0f,1.0f,1.0f});
    
    //canvas1.setColor({1.0f,0.0f,1.0f});


    // canvas1.render();
    canvasPtr->render();

    emscripten_set_main_loop(&RenderLoopCallback, 60, 1);

};
