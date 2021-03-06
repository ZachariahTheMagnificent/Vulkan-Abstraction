#include <iostream>

#include "VkCore/Instance.h"
#include "VkCore/DebugReport.h"
#include "VkCore/PhysicalDevice.h"
#include "VkCore/LogicalDevice.h"
#include "VkCore/CommandPool.h"
#include "VkCore/Semaphores.h"
#include "VkCore/Fences.h"
#include "VkCore/Queue.h"
#include "VkCore/CommandBuffers.h"
#include "VkCore/ShaderModule.h"
#include "glm/vec2.hpp"

int main( )
{
	try {
		glm::vec2 vec;
		const std::vector<const char*> validation_layers =
		{
			"VK_LAYER_LUNARG_standard_validation"
		};
		const std::vector<const char*> device_extensions =
		{
			VK_KHR_SWAPCHAIN_EXTENSION_NAME
		};
		std::vector<const char*> extensions;

		Vk::Core::Instance instance("Compute test", validation_layers, extensions);
		Vk::Core::DebugReport debug_report;

		if(enable_validation_layers)
			debug_report = Vk::Core::DebugReport(&instance);

		Vk::Core::PhysicalDevice gpu(instance);
		Vk::Core::LogicalDevice logical_device(gpu, validation_layers, device_extensions);
		Vk::Core::CommandPool command_pool(gpu, &logical_device, Vk::Helpers::QueueFamilyType::eCOMPUTE);
		Vk::Core::Queue compute_queue(logical_device, gpu, Vk::Helpers::QueueFamilyType::eCOMPUTE, 0);

		Vk::Core::CommandBuffers<10> command_buffers(&command_pool);

		Vk::Core::Semaphores<2> semaphores(&logical_device);
		Vk::Core::Fences<2> fences(&logical_device);
	}
	catch(const std::exception&) {

	}

	std::system("pause");
    return 0;
}