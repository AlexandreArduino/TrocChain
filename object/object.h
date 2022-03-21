#pragma once

#include <string.h>
#include "../library/pictures/resize.h"
#include <ctime>

// Main Object Structure

struct Object {
    const char *signature;
    const char *image_path;
}__attribute__((packed));

#define NULL_OBJECT (struct Object){"NULL", "NULL"}

namespace ObjectCreation {
    struct Object generate_object_template(const char *src);
}