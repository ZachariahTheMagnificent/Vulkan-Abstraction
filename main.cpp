#include <iostream>

#include "Instance.h"
#include "DebugReport.h"
#include "PhysicalDevice.h"
#include "LogicalDevice.h"

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

    return 0;
}