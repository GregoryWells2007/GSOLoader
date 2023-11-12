#pragma once

#include "gso_loader_version_1.h"

static int gso_version = 0.0;
static void gso_set_version (float version) {
    gso_version = version;
}

static gso_object gso_load(gso_object object) {
    if (gso_version == 1.0)
        object = gso_loader_1::gso_load_version_1_0(object);
    else {
        std::cout << "This loader does not support version " << gso_version << " gso files\n";
        std::cout << "The supported versions are\n";
        std::cout << "  Version 1 files\n";  
        std::cout << "      Version 1.0 - supported\n";
        std::cout << "      Version 1.1 - not supported\n";
        std::cout << "      Version 1.2 - not supported\n";    
        std::cout << "      Version 1.3 - not supported\n";
        std::cout << "      Version 1.4 - not supported\n";
        std::cout << "      Version 1.5 - not supported\n";            
        std::cout << "      Version 1.6 - not supported\n";
        std::cout << "      Version 1.7 - not supported\n";
        std::cout << "      Version 1.8 - not supported\n";  
        std::cout << "      Version 1.9 - not supported\n";    
        std::cout << "  Version 2 files\n";  
        std::cout << "      Version 2.0 - not supported\n";
        std::cout << "      Version 2.1 - not supported\n";
        std::cout << "      Version 2.2 - not supported\n";    
        std::cout << "      Version 2.3 - not supported\n";
        std::cout << "      Version 2.4 - not supported\n";
        std::cout << "      Version 2.5 - not supported\n";            
        std::cout << "      Version 2.6 - not supported\n";
        std::cout << "      Version 2.7 - not supported\n";
        std::cout << "      Version 2.8 - not supported\n";  
        std::cout << "      Version 2.9 - not supported\n";       
    }

    return object;
}