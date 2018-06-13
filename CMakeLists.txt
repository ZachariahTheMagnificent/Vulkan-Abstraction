cmake_minimum_required( VERSION 3.10 )
project( Compute )

include_directories( ${PROJECT_SOURCE_DIR}/dependencies/include )

link_directories( ${PROJECT_SOURCE_DIR}/dependencies/lib/vulkan )
link_directories( ${PROJECT_SOURCE_DIR}/dependencies/lib/glfw )

set( CMAKE_CXX_STANDARD 17 )

add_executable( Compute main.cpp Instance.h Instance.cpp DebugReport.h DebugReport.cpp PhysicalDevice.h PhysicalDevice.cpp QueueFamilyIndices.h LogicalDevice.h LogicalDevice.cpp)

target_link_libraries( Compute libvulkan.so libglfw.so )