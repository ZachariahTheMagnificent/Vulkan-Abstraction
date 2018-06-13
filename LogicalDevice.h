/*!
 *
 */

#ifndef COMPUTE_LOGICALDEVICE_H
#define COMPUTE_LOGICALDEVICE_H

#include <vulkan/vulkan.h>

#include "PhysicalDevice.h"

namespace Vk
{
    class LogicalDevice
    {
    public:
        LogicalDevice( ) = default;
        LogicalDevice( PhysicalDevice& physical_device,
                                const std::vector<const char*>& validation_layers,
                                const std::vector<const char*>& device_extensions );
        LogicalDevice( const LogicalDevice& logical_device ) = delete;
        LogicalDevice( LogicalDevice&& logical_device ) noexcept;
        ~LogicalDevice( );

        LogicalDevice& operator=( const LogicalDevice& logical_device ) = delete;
        LogicalDevice& operator=( LogicalDevice&& logical_device ) noexcept;

    private:
        VkDevice device_handle_ = VK_NULL_HANDLE;
    };
}

#endif //COMPUTE_LOGICALDEVICE_H
