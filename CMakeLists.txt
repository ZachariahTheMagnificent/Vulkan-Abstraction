cmake_minimum_required( VERSION 3.10 )
project( Compute )

include_directories( ${PROJECT_SOURCE_DIR}/dependencies/include )

link_directories( ${PROJECT_SOURCE_DIR}/dependencies/lib/vulkan )
link_directories( ${PROJECT_SOURCE_DIR}/dependencies/lib/glfw )

set( CMAKE_CXX_STANDARD 17 )

add_executable( Compute main.cpp VkCore/Instance.h VkCore/Instance.cpp VkCore/DebugReport.h VkCore/DebugReport.cpp VkCore/PhysicalDevice.h VkCore/PhysicalDevice.cpp VkCore/QueueFamilyIndices.h VkCore/LogicalDevice.h VkCore/LogicalDevice.cpp VkCore/CommandPool.h VkCore/CommandPool.cpp)

target_link_libraries( Compute libvulkan.so libglfw.so )