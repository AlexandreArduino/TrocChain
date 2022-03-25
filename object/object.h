#pragma once

#include <string.h>
#include "../library/pictures/resize.h"
#include <ctime>
#include "../crypto/sha256.h"
#include <fstream>
#include <filesystem>

// Main Object Structure

struct ObjectsList {
    struct Object *previous = NULL;
    struct Object *next;
}__attribute__((packed));

struct KeywordsDescription {
    const char *first;
    const char *second;
    const char *third;
}__attribute__((packed));

struct Object {
    char signature[LEN_SHA256];
    const char *image_path;
    struct KeywordsDescription descriptors;
}__attribute__((packed));

#define NULL_STRING "NULL"
#define NULL_OBJECT (struct Object){NULL_STRING, NULL_STRING, (struct KeywordsDescription){NULL_STRING, NULL_STRING, NULL_STRING}};


namespace ObjectCreation {
    struct Object generate_object_template(const char *src, struct KeywordsDescription descriptors);
    bool save_object_to_file(struct Object object);
}