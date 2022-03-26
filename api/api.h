#pragma once

#include "../identity/identity.h"
#include "../object/object.h"

namespace API {
    struct IdentityObject add_user(const char *password);
    struct Object proclaim_object(const char *picture_path, struct KeywordsDescription descriptors, std::string user_signature);
}