#pragma once

#include <string.h>
#include "../library/pictures/resize.h"
#include <ctime>
#include "../crypto/sha256.h"
#include <fstream>
#include <experimental/filesystem>
#include <vector>

#define TIMESTAMP_MAX_NAME 15

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
    char cache_name[TIMESTAMP_MAX_NAME];
    const char *image_path;
    struct KeywordsDescription descriptors;
}__attribute__((packed));

#define NULL_STRING "NULL"
#define NULL_OBJECT (struct Object){NULL_STRING, NULL_STRING, NULL_STRING, (struct KeywordsDescription){NULL_STRING, NULL_STRING, NULL_STRING}};

#define EXIF_RESULT_COMMAND_OFFSET "Description                     : "

namespace ObjectCreation {
    struct Object create(const char *src, struct KeywordsDescription descriptors, std::string user_signature);
    struct Object generate_object_template(const char *src, struct KeywordsDescription descriptors);
    bool save_object_to_file(struct Object object);
    bool update_exif_data_to_image_file(struct Object object);
    struct KeywordsDescription get_exif_descriptors_from_image(std::string signature);
    bool add_object_to_user_file(struct Object object, std::string user_signature);
}