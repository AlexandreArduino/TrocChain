#include "object.h"

namespace ObjectCreation {
    struct Object generate_object_template(const char *src) {
        // This function generates the object template of a picture to add it to the network later
        struct Object new_object;
        
        std::time_t timestamp = std::time(NULL); // The name of the file in .cache directory

        if(!Library::Image::resize(src, (std::string(".cache/") + std::to_string(timestamp) + std::string(".jpeg")).c_str())) return NULL_OBJECT;

    }
}