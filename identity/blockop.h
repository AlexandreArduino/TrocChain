#pragma once

// The blocks operations to analyze and parse data

#include "../debug/log.h"
#include "identity.h"
#include <fstream>
#include <string>

namespace IdentityBlockOperations {
    std::string read_field(std::string field, std::string content_block_string);
    bool is_next_id_null(struct IdentityObject block);
}