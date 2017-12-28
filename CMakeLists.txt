cmake_minimum_required(VERSION 3.9)
project(armadillo_network)

set(CMAKE_CXX_STANDARD 11)

add_executable(armadillo_network
        main.cpp NetPoint.cpp NetPoint.hpp Util.cpp Util.hpp Layer.cpp Layer.hpp NeuralNet.cpp NeuralNet.hpp)
target_link_libraries(armadillo_network armadillo)