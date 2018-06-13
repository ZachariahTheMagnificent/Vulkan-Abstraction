/*!
 *
 */

#ifndef COMPUTE_FENCES_H
#define COMPUTE_FENCES_H

#include <array>

#include <vulkan/vulkan.h>

#include "LogicalDevice.h"

namespace Vk
{
    template<size_t size>
    class Fences
    {
    public:
        Fences( ) = default;
        explicit Fences( const LogicalDevice* p_logical_device )
            :
            p_logical_device_( p_logical_device )
        {
            VkFenceCreateInfo create_info = {};
            create_info.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
            create_info.flags = VK_FENCE_CREATE_SIGNALED_BIT;

            for( auto& fence : fence_handles_ )
            {
                fence = p_logical_device_->create_fence( create_info );
            }
        }
        Fences( const Fences& fences ) = delete;
        Fences( Fences&& fences ) noexcept
        {
            *this = std::move( fences );
        }
        ~Fences( )
        {
            for( auto& fence : fence_handles_ )
            {
                fence = p_logical_device_->destroy_fence( fence );
            }
        }

        Fences& operator=( const Fences& fences ) = delete;
        Fences& operator=( Fences&& fences ) noexcept
        {
            if( this != &fences )
            {
                for( auto i = 0; i < size; ++i )
                {
                    if( fence_handles_[i] != VK_NULL_HANDLE )
                        fence_handles_[i] = p_logical_device_->destroy_fence( fence_handles_[i] );

                    fence_handles_[i] = fences.fence_handles_[i];
                    fences.fence_handles_[i] = VK_NULL_HANDLE;

                    p_logical_device_ = fences.p_logical_device_;
                }
            }

            return *this;
        }

    private:
        const LogicalDevice* p_logical_device_ = nullptr;

        std::array<VkFence, size> fence_handles_ = {};
    };
}

#endif //COMPUTE_FENCES_H
