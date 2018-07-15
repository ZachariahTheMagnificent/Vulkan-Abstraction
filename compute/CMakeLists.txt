cmake_minimum_required(VERSION 3.11)
project(compute VERSION 1.0.0 DESCRIPTION "BouwnLaw's attempt at Vulkan" LANGUAGES CXX)

add_executable(compute
        main.cpp
        VkCore/Instance.h
        VkCore/Instance.cpp
        VkCore/DebugReport.h
        VkCore/DebugReport.cpp
        VkCore/PhysicalDevice.h
        VkCore/PhysicalDevice.cpp
        VkHelpers/QueueFamilyIndices.h
        VkCore/LogicalDevice.h
        VkCore/LogicalDevice.cpp
        VkCore/CommandPool.h
        VkCore/CommandPool.cpp
        VkCore/Semaphores.h VkCore/Fences.h VkCore/Queue.h VkCore/Queue.cpp VkCore/CommandBuffers.h VkCore/ShaderModule.h VkCore/ShaderModule.cpp read.h)
		
target_include_directories(compute PUBLIC VkCore)
target_compile_features(compute PUBLIC cxx_std_17)
target_link_libraries(compute vulkan glfw glm)
