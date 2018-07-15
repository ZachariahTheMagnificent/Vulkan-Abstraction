cmake_minimum_required(VERSION 3.11)
project(glm VERSION 1.0.0 DESCRIPTION "BouwnLaw's attempt at Vulkan" LANGUAGES CXX)

add_library(glm INTERFACE)
target_include_directories(glm INTERFACE include)
target_compile_features(compute PUBLIC cxx_std_17)
