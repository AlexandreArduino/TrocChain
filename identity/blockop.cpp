#include "blockop.h"

namespace IdentityBlockOperations {
    std::string read_field(std::string field, std::string content_block_string) {
        std::string field_content("");
        std::size_t found = content_block_string.find(field);
        if(found == std::string::npos) field_content = "NULL_REFERENCE";
        else {
            size_t pos = found + field.size();
            while(content_block_string[pos] != '\n') {
                field_content += content_block_string[pos];
                pos++;
            }
        }
        return field_content;
    }
    
    bool is_next_id_null(struct IdentityObject block) {
        char signature[4] = {'N', 'U', 'L', 'L'};
        for(size_t i = 0; i < 4; i++) {
            if(block.next_id[i] != signature[i]) return false;
        }
        return true;
    }

    bool compare(struct IdentityObject one, struct IdentityObject two) {
    for(size_t i = 0; i < LEN_SHA256; i++) {
        if(one.id[i] != two.id[i]) return false;
        if(one.password_hash[i] != two.password_hash[i]) return false;
        if(one.next_id[i] != two.next_id[i]) return false;
    }
    return true;
}
}