#pragma once

#include <SFML/Graphics.hpp>
#include "../../debug/log.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "system/command.h"

#define RESIZED_WIDTH_IMAGE 100 // px
#define RESIZED_HEIGHT_IMAGE 100 // px

#define RESIZED_WIDTH_IMAGE_STRING "100x"
#define RESIZE_HEIGHT_IMAGE_STRING "100x"

namespace Library {
    namespace Image {
        bool resize(const char *src, const char *dest);
    }
}