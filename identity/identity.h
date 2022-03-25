#pragma once

#include "../object/object.h"
#include "../debug/log.h"
#include "../crypto/sha256.h"
#include <ctime>
#include <fstream>
#include "object.h"
#include "fileop.h"

extern struct IdentityObject genesis_user;

#define MINIMUM_PASSWORD_SIZE 12

namespace IdentityCreation {
    struct IdentityObject create_new_identity(const char *password);
    bool save_identity_to_file(struct IdentityObject to_save);
    bool save_genesis_identity();
    bool is_genesis_here();
}