#pragma once

#include <string.h>

// Main Object Structure

struct Object {
    const char *signature;
    const char *image_path;
}__attribute__((packed));

namespace ObjectCreation {
}