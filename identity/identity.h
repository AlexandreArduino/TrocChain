#pragma once

#include "../object/object.h"
#include "../debug/log.h"
#include "../crypto/sha256.h"
#include <ctime>

struct IdentityObject {
    const char *id;
    const char *password_hash;

}__attribute__((packed));

namespace IdentityCreation {
    struct IdentityObject create_new_identity(const char *password);
}