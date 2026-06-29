#pragma once

#include <string>

namespace  waste_detection::lib {
    std::string getEnvRequired(const char* name);
    int getEnvIntRequired(const char* name);
}