/*!
 *
 */

#include <vector>
#include <set>
#include <iostream>

#include "PhysicalDevice.h"

namespace Vk
{
    PhysicalDevice::PhysicalDevice( Instance *p_instance )
    {
        auto devices = p_instance->enumerate_physical_devices();

        for( auto& device : devices )
        {
            if( is_device_suitable_for_compute( device ) )
            {
                physical_device_handle_ = device;
                break;
            }
        }

        std::cout << "Physical device found:" << std::endl;

        vkGetPhysicalDeviceProperties( physical_device_handle_, &physical_device_properties );

        std::cout << "\tName: " << physical_device_properties.deviceName << "\n\tDriver: " << physical_device_properties.driverVersion;
        std::cout << "\n\tVendor: " << physical_device_properties.vendorID << std::endl;
    }
    PhysicalDevice::PhysicalDevice( PhysicalDevice &&physical_device ) noexcept
    {
        *this = std::move( physical_device );
    }

    PhysicalDevice &PhysicalDevice::operator=( PhysicalDevice &&physical_device ) noexcept
    {
        if( this != &physical_device );
        {
            physical_device_handle_ = physical_device.physical_device_handle_;
            physical_device.physical_device_handle_ = VK_NULL_HANDLE;
        }

        return *this;
    }

    bool PhysicalDevice::is_device_suitable_for_compute( VkPhysicalDevice &physical_device_handle )
    {
        find_compute_queue_family( physical_device_handle );

        return queue_family_indices_.is_compute_complete();
    }

    void PhysicalDevice::find_compute_queue_family( VkPhysicalDevice &physical_device_handle )
    {
        uint32_t queue_family_count = 0;
        vkGetPhysicalDeviceQueueFamilyProperties( physical_device_handle, &queue_family_count, nullptr );

        std::vector<VkQueueFamilyProperties> queue_family_properties( queue_family_count );
        vkGetPhysicalDeviceQueueFamilyProperties( physical_device_handle, &queue_family_count, queue_family_properties.data() );

        int i = 0;
        for( const auto& queue_family_property : queue_family_properties )
        {
            if( queue_family_property.queueCount > 0 && queue_family_property.queueFlags & VK_QUEUE_COMPUTE_BIT )
                queue_family_indices_.compute_family = i;

            if( queue_family_indices_.is_compute_complete() )
                break;

            ++i;
        }
    }
}
