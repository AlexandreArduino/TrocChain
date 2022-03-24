#pragma once

// The file operations functions needed to write identity blocks

#include "../debug/log.h"
#include "identity.h"
#include <fstream>
#include <string>

namespace IdentityFileOperations {
    bool write_new_block(struct IdentityObject block);
}