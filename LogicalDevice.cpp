/*!
 *
 */

#include <vector>
#include <set>
#include <iostream>

#include "LogicalDevice.h"
#include "Instance.h"

namespace Vk
{
    LogicalDevice::LogicalDevice( PhysicalDevice& physical_device,
                                  const std::vector<const char*>& validation_layers,
                                  const std::vector<const char*>& device_extensions )
    {
        std::vector<VkDeviceQueueCreateInfo> queue_create_infos;
        auto unique_queue_families = physical_device.unique_queue_families();

        float queue_priority = 1.0f;
        for( const auto& queue_family : unique_queue_families )
        {
            VkDeviceQueueCreateInfo create_info = {};
            create_info.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
            create_info.queueFamilyIndex = queue_family;
            create_info.queueCount = 1;
            create_info.pQueuePriorities = &queue_priority;

            queue_create_infos.emplace_back( create_info );
        }

        auto physical_device_features = physical_device.features();

        VkDeviceCreateInfo create_info = {};
        create_info.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
        create_info.queueCreateInfoCount = unique_queue_families.size();
        create_info.pQueueCreateInfos = queue_create_infos.data();
        create_info.pEnabledFeatures = &physical_device_features;
        create_info.enabledExtensionCount = static_cast<uint32_t>( device_extensions.size() );
        create_info.ppEnabledExtensionNames = device_extensions.data();

        if( enable_validation_layers )
        {
            create_info.enabledLayerCount = static_cast<uint32_t>( validation_layers.size() );
            create_info.ppEnabledLayerNames = validation_layers.data();
        }
        else
        {
            create_info.enabledLayerCount = 0;
        }

        device_handle_ = physical_device.create_device( create_info );
    }

    LogicalDevice::~LogicalDevice( )
    {
        vkDestroyDevice( device_handle_, nullptr );

        std::cout << "Logical device destroyed." << std::endl;
    }

    LogicalDevice::LogicalDevice( LogicalDevice &&logical_device ) noexcept
    {
        *this = std::move( logical_device );
    }

    LogicalDevice&
    LogicalDevice::operator=( LogicalDevice &&logical_device ) noexcept
    {
        if( this != &logical_device )
        {
            device_handle_ = logical_device.device_handle_;
            logical_device.device_handle_ = VK_NULL_HANDLE;
        }

        return *this;
    }
}
