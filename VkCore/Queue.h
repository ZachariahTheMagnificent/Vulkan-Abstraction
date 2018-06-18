/*!
 *
 */

#ifndef COMPUTE_QUEUE_H
#define COMPUTE_QUEUE_H

#include "LogicalDevice.h"

namespace Vk
{
    class Queue
    {
    public:
        Queue( ) = default;
        Queue( const LogicalDevice& logical_device,
               const PhysicalDevice& physical_device,
               const PhysicalDevice::QueueFamilyType type,
               uint32_t queue_index );
        Queue( const Queue& queue ) = delete;
        Queue( Queue&& queue ) noexcept;
        ~Queue( ) = default;

        void wait_idle();

        Queue& operator=( const Queue& queue ) = delete;
        Queue& operator=( Queue&& queue ) noexcept;

    private:
        VkQueue queue_handle_ = VK_NULL_HANDLE;
    };
}

#endif //COMPUTE_QUEUE_H
