cmake_minimum_required(VERSION 3.14)
project(NeuralTest)

set(CMAKE_CXX_STANDARD 14)

find_package (PkgConfig REQUIRED)
find_package (OpenGL REQUIRED)
find_package (glfw3 REQUIRED)

include_directories(include)

include_directories(GLAD/include)

set(SOURCE_FILES
        main.cpp
        NeuronGrid.cpp NeuronGrid.h
        Neuron.cpp Neuron.h
        Connector.cpp Connector.h
        Utilities.cpp Utilities.h
        Array.cpp Array.h
        Display.cpp Display.h
        GLAD/src/glad.c Rectangle.cpp Rectangle.h)


add_executable(NeuralTest ${SOURCE_FILES})

target_link_libraries(NeuralTest glfw)
