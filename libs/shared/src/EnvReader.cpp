#include "EnvReader.hpp"

#include <string>
#include <cstdlib>
#include <stdexcept>

namespace  waste_detection::lib {
    std::string getEnvRequired(const char* name) {
        const char* value = std::getenv(name);

        if (value == nullptr || std::string(value).empty()) {
            throw std::runtime_error(std::string("Missing env variable: ") + name);
        }

        return value;
    }

    int getEnvIntRequired(const char* name) {
        return std::stoi(getEnvRequired(name));
    }


}

