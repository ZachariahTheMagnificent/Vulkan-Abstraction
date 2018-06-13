#include <iostream>

#include "VkCore/Instance.h"
#include "VkCore/DebugReport.h"
#include "VkCore/PhysicalDevice.h"
#include "VkCore/LogicalDevice.h"
#include "VkCore/CommandPool.h"
#include "VkCore/Semaphores.h"

int main( )
{
    const std::vector<const char*> validation_layers =
    {
        "VK_LAYER_LUNARG_standard_validation"
    };
    const std::vector<const char*> device_extensions =
    {
        VK_KHR_SWAPCHAIN_EXTENSION_NAME
    };
    std::vector<const char*> extensions;

    Vk::Instance instance( "Compute test", validation_layers, extensions );
    if( enable_validation_layers )
        Vk::DebugReport debug_report( &instance );
    Vk::PhysicalDevice gpu( instance );
    Vk::LogicalDevice logical_device( gpu, validation_layers, device_extensions );
    Vk::CommandPool command_pool( gpu, &logical_device, Vk::PhysicalDevice::QueueFamilyType::eCOMPUTE );

    Vk::Semaphores<2> semaphores( &logical_device );

    return 0;
}