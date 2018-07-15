cmake_minimum_required(VERSION 3.11)
project(vulkan-abstraction VERSION 1.0.0 DESCRIPTION "BouwnLaw's attempt at Vulkan" LANGUAGES CXX)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")

add_subdirectory(glfw)
add_subdirectory(compute)
add_subdirectory(glm)
add_subdirectory(vulkan)
