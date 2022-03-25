#pragma once

// The file operations functions needed to write identity blocks

#include "../debug/log.h"
#include "identity.h"
#include <fstream>
#include <string>
#include "blockop.h"

namespace IdentityFileOperations {
    bool write_new_block_independantly(struct IdentityObject block);
    bool write_new_block_and_update_previous(struct IdentityObject block);
    struct IdentityObject find_last_block_written();
    struct IdentityObject read_block(char* block_id);
}