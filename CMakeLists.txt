cmake_minimum_required(VERSION 3.11)
project(vulkan-abstraction VERSION 1.0.0 DESCRIPTION "BouwnLaw's attempt at Vulkan" LANGUAGES CXX)

set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Do not build documents")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Do not build tests")
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Do not build example programs")
set(GLFW_INSTALL OFF CACHE INTERNAL "Do not generate installation target")

add_subdirectory(glfw) # Build the GLFW project.
add_subdirectory(compute) # Build the Compute project.
add_subdirectory(glm) # Build the GLM project.
add_subdirectory(vulkan) # Build the Vulkan project.
