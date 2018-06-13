/*!
 *
 */

#include "CommandPool.h"

namespace Vk
{

    CommandPool::CommandPool( const PhysicalDevice& physical_device,
                              const LogicalDevice* p_logical_device,
                              const PhysicalDevice::QueueFamilyType& type )
        :
        p_logical_device_( p_logical_device )
    {
        VkCommandPoolCreateInfo create_info = {};
        create_info.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
        create_info.queueFamilyIndex = static_cast<uint32_t>( physical_device.get_queue_family_index( type ) );

        command_pool_handle_ = p_logical_device_->create_command_pool( create_info );
    }
    CommandPool::CommandPool( CommandPool&& command_pool ) noexcept
    {
        *this = std::move( command_pool );
    }
    CommandPool::~CommandPool( )
    {
        if( command_pool_handle_ != VK_NULL_HANDLE )
            command_pool_handle_ = p_logical_device_->destroy_command_pool( command_pool_handle_ );
    }

    CommandPool& CommandPool::operator=( CommandPool&& command_pool ) noexcept
    {
        if( this != &command_pool )
        {
            if( command_pool_handle_ != VK_NULL_HANDLE )
                command_pool_handle_ = p_logical_device_->destroy_command_pool( command_pool_handle_ );

            command_pool_handle_ = command_pool.command_pool_handle_;
            command_pool.command_pool_handle_ = VK_NULL_HANDLE;

            p_logical_device_ = command_pool.p_logical_device_;
        }

        return *this;
    }
}
