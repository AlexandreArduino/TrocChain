#pragma once

#include "../object/object.h"
#include "../debug/log.h"
#include "../crypto/sha256.h"
#include <ctime>

#define LEN_SHA256 64

struct IdentityObject {
    char id[LEN_SHA256];
    char password_hash[LEN_SHA256];

}__attribute__((packed));

namespace IdentityCreation {
    struct IdentityObject create_new_identity(const char *password);
    bool save_identity_to_file(struct IdentityObject to_save);
}