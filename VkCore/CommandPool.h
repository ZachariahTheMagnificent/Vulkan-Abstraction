/*!
 *
 */

#ifndef COMPUTE_COMMANDPOOL_H
#define COMPUTE_COMMANDPOOL_H

#include <vulkan/vulkan.h>

#include "LogicalDevice.h"

namespace Vk
{
    class CommandPool
    {
    public:
        CommandPool( ) = default;
        CommandPool( const PhysicalDevice& physical_device,
                     const LogicalDevice* p_logical_device,
                     const PhysicalDevice::QueueFamilyType& type );
        CommandPool( const CommandPool& command_pool ) = delete;
        CommandPool( CommandPool&& command_pool ) noexcept;
        ~CommandPool( );

        CommandPool& operator=( const CommandPool& command_pool ) = delete;
        CommandPool& operator=( CommandPool&& command_pool ) noexcept;

    private:
        const LogicalDevice* p_logical_device_;

        VkCommandPool command_pool_handle_ = VK_NULL_HANDLE;
    };
}

#endif //COMPUTE_COMMANDPOOL_H
