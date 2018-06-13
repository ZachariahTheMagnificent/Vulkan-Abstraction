/*!
 *
 */

#include <vector>
#include <set>
#include <iostream>

#include "PhysicalDevice.h"

namespace Vk
{
    PhysicalDevice::PhysicalDevice( Instance &instance )
    {
        auto devices = instance.enumerate_physical_devices();

        for( auto& device : devices )
        {
            if( is_device_suitable_for_compute( device ) )
            {
                physical_device_handle_ = device;
                break;
            }
        }

        std::cout << "Physical device found:" << std::endl;

        vkGetPhysicalDeviceProperties( physical_device_handle_, &physical_device_properties_ );

        std::cout << "\tName: " << physical_device_properties_.deviceName << "\n\tDriver: " << physical_device_properties_.driverVersion;
        std::cout << "\n\tVendor: " << physical_device_properties_.vendorID << std::endl;
    }
    PhysicalDevice::PhysicalDevice( Instance& instance, VkPhysicalDeviceFeatures& physical_Device_features )
        :
        PhysicalDevice( instance )
    {
        set_device_features( physical_Device_features );
    }
    PhysicalDevice::PhysicalDevice( PhysicalDevice &&physical_device ) noexcept
    {
        *this = std::move( physical_device );
    }

    void
    PhysicalDevice::set_device_features( VkPhysicalDeviceFeatures& physical_device_features ) noexcept
    {
        physical_device_features_ = physical_device_features;
    }

    std::set<int>
    PhysicalDevice::unique_queue_families( ) noexcept
    {
        std::set<int> unique_queue_family;

        if( queue_family_indices_.graphics_family >= 0 )
            unique_queue_family.emplace( queue_family_indices_.graphics_family );

        if( queue_family_indices_.present_family >= 0 )
            unique_queue_family.emplace( queue_family_indices_.present_family );

        if( queue_family_indices_.compute_family >= 0 )
            unique_queue_family.emplace( queue_family_indices_.compute_family );

        return unique_queue_family;
    }

    const VkPhysicalDeviceFeatures&
    PhysicalDevice::features( ) noexcept
    {
        return physical_device_features_;
    }

    PhysicalDevice&
    PhysicalDevice::operator=( PhysicalDevice &&physical_device ) noexcept
    {
        if( this != &physical_device );
        {
            physical_device_handle_ = physical_device.physical_device_handle_;
            physical_device.physical_device_handle_ = VK_NULL_HANDLE;
        }

        return *this;
    }

    VkDevice
    PhysicalDevice::create_device( VkDeviceCreateInfo &create_info )
    {
        VkDevice device_handle;

        if( vkCreateDevice( physical_device_handle_, &create_info, nullptr, &device_handle ) != VK_NULL_HANDLE )
            std::cerr << "Failed to create logical device" << std::endl;
        else
            std::cout << "Logical device created succesfully." << std::endl;

        return device_handle;
    }

    bool
    PhysicalDevice::is_device_suitable_for_compute( VkPhysicalDevice &physical_device_handle ) noexcept
    {
        find_compute_queue_family( physical_device_handle );

        return queue_family_indices_.is_compute_complete();
    }

    void
    PhysicalDevice::find_compute_queue_family( VkPhysicalDevice &physical_device_handle ) noexcept
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
