#include <iostream>

#include "plot.h"

int main()
{
    Plot plot = Plot("canvas1");
    plot.render();
    std::cout << "Hello Browser" << std::endl;
}


