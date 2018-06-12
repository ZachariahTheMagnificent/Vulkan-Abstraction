/*!
 *
 */

#ifndef COMPUTE_INSTANCE_H
#define COMPUTE_INSTANCE_H

#include <string>
#include <vector>

#include <vulkan/vulkan.h>

namespace Vk
{
    class Instance
    {
    public:
        Instance() = default;
        Instance( const std::string& name, std::vector<const char*>& extensions );
        Instance( const Instance& instance ) = delete;
        Instance( Instance&& instance ) noexcept;
        ~Instance( );

        Instance& operator=( const Instance& instance ) = delete;
        Instance& operator=( Instance&& instance ) noexcept;

        VkDebugReportCallbackEXT create_debug_report( const VkDebugReportCallbackCreateInfoEXT& create_info );
        VkDebugReportCallbackEXT destroy_debug_report( VkDebugReportCallbackEXT& debug_report_handle );

        std::vector<VkPhysicalDevice> enumerate_physical_devices( );

    private:
        bool check_validation_layer_support();

        VKAPI_ATTR VkResult VKAPI_CALL vk_create_debug_report_callback_EXT( VkInstance instance,
                                                                            const VkDebugReportCallbackCreateInfoEXT* pCreateInfo,
                                                                            const VkAllocationCallbacks* pAllocator,
                                                                            VkDebugReportCallbackEXT* pCallback );
        VKAPI_ATTR void VKAPI_CALL vk_destroy_debug_report_callback_EXT( VkInstance instance,
                                                                         VkDebugReportCallbackEXT callback,
                                                                         const VkAllocationCallbacks* pAllocator );

    private:
        VkInstance instance_handle_ = VK_NULL_HANDLE;

        const std::vector<const char *> validation_layers =
        {
            "VK_LAYER_LUNARG_standard_validation"
        };
    };
}

#endif //COMPUTE_INSTANCE_H
