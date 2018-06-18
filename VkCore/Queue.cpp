/*!
 *
 */

#include "Queue.h"

namespace Vk
{
    Queue::Queue( const LogicalDevice& logical_device,
                  const PhysicalDevice& physical_device,
                  const PhysicalDevice::QueueFamilyType type,
                  uint32_t queue_index)
    {
        queue_handle_ = logical_device.get_queue( physical_device.get_queue_family_index( type ), queue_index );
    }
    Queue::Queue( Queue&& queue ) noexcept
    {
        *this = std::move( queue );
    }

    void Queue::wait_idle( )
    {
        vkQueueWaitIdle( queue_handle_ );
    }

    Queue& Queue::operator=( Queue&& queue ) noexcept
    {
        if( this != &queue )
        {
            queue_handle_ = queue.queue_handle_;
            queue.queue_handle_ = VK_NULL_HANDLE;
        }

        return *this;
    }
}