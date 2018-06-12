/*!
 *
 */

#ifndef COMPUTE_PHYSICALDEVICE_H
#define COMPUTE_PHYSICALDEVICE_H

#include <vulkan/vulkan.h>

#include "Instance.h"
#include "QueueFamilyIndices.h"

namespace Vk
{
    class PhysicalDevice
    {
    public:
        PhysicalDevice() = default;
        explicit PhysicalDevice( Instance* p_instance );
        PhysicalDevice( const PhysicalDevice& physical_device ) = delete;
        PhysicalDevice( PhysicalDevice&& physical_device ) noexcept;
        ~PhysicalDevice( ) = default;

        PhysicalDevice& operator=( const PhysicalDevice& physical_device ) = delete;
        PhysicalDevice& operator=( PhysicalDevice&& physical_device ) noexcept;

    private:
        bool is_device_suitable_for_compute( VkPhysicalDevice &physical_device_handle );
        void find_compute_queue_family( VkPhysicalDevice& physical_device_handle );


    private:
        VkPhysicalDevice physical_device_handle_ = VK_NULL_HANDLE;
        VkPhysicalDeviceProperties physical_device_properties;

        Helpers::QueueFamilyIndices queue_family_indices_;
    };
}

#endif //COMPUTE_PHYSICALDEVICE_H
