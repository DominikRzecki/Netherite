#include <iostream>
#include "modules/core/Core.h"
#include <thread>
#include <chrono>

int main() {
    Netherite::Core core;
    core.Init();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    return EXIT_SUCCESS;
}
