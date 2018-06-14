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

        VkCommandPool create_command_pool( VkCommandPoolCreateInfo& create_info ) const;
        VkCommandPool destroy_command_pool( VkCommandPool& command_pool_handle ) const;

        VkSemaphore create_semaphore( VkSemaphoreCreateInfo& create_info ) const;
        VkSemaphore destroy_semaphore( VkSemaphore& semaphore_handle ) const;

        VkFence create_fence( VkFenceCreateInfo& create_info ) const;
        VkFence destroy_fence( VkFence& fence_handle ) const;

        void wait_for_fences( VkFence* p_fence_handle, uint32_t fence_count, VkBool32 wait_all, uint64_t timeout ) const;
        void reset_fences( VkFence* p_fence_handle, uint32_t fence_count ) const;

    private:
        VkDevice device_handle_ = VK_NULL_HANDLE;
    };
}

#endif //COMPUTE_LOGICALDEVICE_H
