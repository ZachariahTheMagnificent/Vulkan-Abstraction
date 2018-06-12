#include <iostream>

#include "DebugReport.h"
#include "Instance.h"
#include "QueueFamilyIndices.h"
#include "PhysicalDevice.h"

int main( )
{
    std::vector<const char*> extensions;

    Vk::Instance instance( "Compute test", extensions );
    Vk::DebugReport debug_report( &instance );
    Vk::PhysicalDevice gpu( &instance );

    return 0;
}