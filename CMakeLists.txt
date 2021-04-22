cmake_minimum_required(VERSION 3.19)
project(Netherite)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall" )

add_executable(Netherite src/main.cpp src/modules/core/Core.cpp src/modules/core/Core.h src/modules/core/thread/Thread.h src/modules/core/module/Module.cpp src/modules/core/module/Module.h src/modules/core/control/Control.cpp src/modules/core/control/Control.h src/modules/core/netherite.h)
target_link_libraries(Netherite pthread)