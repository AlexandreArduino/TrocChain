#pragma once

#include <string.h>
#include "../library/pictures/resize.h"
#include <ctime>
#include "../crypto/sha256.h"
#include <fstream>

// Main Object Structure

struct KeywordsDescription {
    const char *first;
    const char *second;
    const char *third;
}__attribute__((packed));

struct Object {
    const char *signature;
    const char *image_path;
    struct KeywordsDescription descriptors;
}__attribute__((packed));

#define NULL_STRING "NULL"
#define NULL_OBJECT (struct Object){NULL_STRING, NULL_STRING, (struct KeywordsDescription){NULL_STRING, NULL_STRING, NULL_STRING}};


namespace ObjectCreation {
    struct Object generate_object_template(const char *src, struct KeywordsDescription descriptors);
}