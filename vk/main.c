#include <vulkan/vulkan.h>
#include <stdio.h>
#include <string.h>

VkInstance instance;

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

    VkResult result = vkCreateInstance(
        &info,
        NULL,
        &instance
    );

    printf("intsance created sucesifuly :%d",result == VK_SUCCESS);
}
