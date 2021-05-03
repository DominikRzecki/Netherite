cmake_minimum_required(VERSION 3.19)
project(Netherite)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall" )

include_directories(src/include)

add_executable(Netherite src/main.cpp src/modules/core/Core.cpp src/modules/core/Core.h src/modules/thread/Thread.h src/modules/module/Module.cpp src/modules/module/Module.h src/modules/control/Control.cpp src/modules/control/Control.h src/Netherite.h src/include/Netherite/ParentChildHierarchy.h)
target_link_libraries(Netherite pthread)