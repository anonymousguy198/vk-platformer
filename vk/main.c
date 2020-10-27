#include <vulkan/vulkan.h>
#include <stdio.h>
#include <string.h>

VkInstance instance;

typedef enum{
    false,true}bool;

void create_instance(){

    const char *instance_layers[] = { "VK_LAYER_LUNARG_standard_validation" };
    const char *instance_extensions[] = { "VK_EXT_debug_report" };

    //ceck layer support
    //comming soon

    VkApplicationInfo app_info;
    app_info.sType=VK_STRUCTURE_TYPE_APPLICATION_INFO;
    app_info.pApplicationName="platformer";
    app_info.applicationVersion=VK_MAKE_VERSION (1, 0, 0);
    app_info.pEngineName="Ykan";
    app_info.engineVersion=VK_MAKE_VERSION (1, 0, 0);
    app_info.apiVersion=VK_MAKE_VERSION (1, 0, 0);

    VkInstanceCreateInfo info;
    info.sType= VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    info.pApplicationInfo = &app_info;
    info.enabledExtensionCount = sizeof(instance_extensions);
    info.ppEnabledExtensionNames = instance_extensions;
    info.enabledLayerCount = sizeof(instance_layers);
    info.ppEnabledLayerNames = instance_layers;

    VkResult result = vkCreateInstance(&info,NULL,&instance);

    ////////////////////////////////////////
    ///// Finished setting up Instance /////
    ////////////////////////////////////////



    printf("intsance created sucesifuly :%d",result == VK_SUCCESS);
}

/*
                        #########################
                        # PHISICHAL DEVICES #####
                        #########################
*/

bool HasRequierdExts(const VkPhysicalDevice device, const char** required_extentions, const uint32_t required_extention_count){

    uint32_t ext_count;
    vkEnumerateDeviceExtensionProperties(device,NULL,&ext_count,NULL);

    VkExtensionProperties available_extensions[ext_count];
    vkEnumerateDeviceExtensionProperties(device,NULL,&ext_count,&available_extensions);

    for(int i=0;i<required_extention_count;i++){
        bool extFound = false;

        for(int j=0;j<ext_count;j++){
            if(strcmp(required_extentions[i],available_extensions[j].extensionName) == 0){
                extFound = true;
                break;
            }
            if(!extFound){return false;}
        }

    }
return true;
}

bool GetQueueFamily(const VkPhysicalDevice physical_device, VkQueueFlags required_queue_flags, uint32_t queue_family_index);{


    return true;
}

void select_device(){

    // List GPUs

    uint32_t device_count;
    vkEnumeratePhysicalDevices(instance,&device_count,NULL);
    VkPhysicalDevice GPUs[device_count];
    vkEnumeratePhysicalDevices(instance,&device_count,&GPUs);

    // Device extension
    uint32_t ext_count=1;
    const char *device_extensions[ext_count] = { VK_KHR_SWAPCHAIN_EXTENSION_NAME };

    //selected device
    VkPhysicalDevice chosen_physical_device = VK_NULL_HANDLE;
    uint32_t chosen_physical_devices_queue_family = 0;
    VkPhysicalDeviceProperties chosen_physical_device_properties;
    VkPhysicalDeviceFeatures chosen_physical_device_features;
    VkPhysicalDeviceMemoryProperties chosen_physical_device_mem_properties;

    ///// Choicing the device
    for (int i = 0 ; i < device_count; i++){
        //Cecking extensions
        if (HasRequierdExts(devices[i], device_extensions, extention_count)){

            //ceking the que families
            uint32_t queue_family;
            if (GetQueueFamily(devices[i], VkQueueFlagBits::VK_QUEUE_GRAPHICS_BIT, queue_family)){

                VkPhysicalDeviceProperties physical_device_properties;
                vkGetPhysicalDeviceProperties(GPUs[i],&physical_device_properties);

                VkPhysicalDeviceFeatures physical_device_features;
                vkGetPhysicalDeviceFeatures(GPUs[i],&physical_device_features);

                // Get all information about the devices memory
                VkPhysicalDeviceMemoryProperties physical_device_mem_properties;
                vkGetPhysicalDeviceMemoryProperties(GPUs[i],&physical_device_mem_properties);


                if (chosen_physical_device == VK_NULL_HANDLE || chosen_physical_device != VK_NULL_HANDLE && physical_device_properties.deviceType == VkPhysicalDeviceType.VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU){
                    chosen_physical_device = devices[i];
                    chosen_physical_devices_queue_family = queue_family;
                    chosen_physical_device_properties = physical_device_properties;
                    chosen_physical_device_features = physical_device_features;
                    chosen_physical_device_mem_properties = physical_device_mem_properties;
                    }
            }
        }
    }
}

    void vkClear(){

        /////////////////////////////////////////////
        ///// Destroy all things from vulkan ;) /////
        /////////////////////////////////////////////

        /// Destroy the instance
        vkDestroyInstance(instance,NULL);
        printf("Program exited!");
}
