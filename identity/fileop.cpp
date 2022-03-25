#include "fileop.h"

namespace IdentityFileOperations {
    bool write_new_block_independantly(struct IdentityObject block) {
        logger.infoln(std::string("Writing new block with id : ") + std::string(block.id) + std::string(" ..."));

        std::string filename("blockchain/identity/");
        filename += std::string(block.id);

        std::ofstream file;
        file.open(filename);

        if(!file.is_open()) {
            logger.errorln(std::string("Unable to open ") + std::string(filename) + std::string(" !"));
            return false;
        } else {
            file << "PASSWORD_HASH=" << block.password_hash << std::endl;
            file << "NEXT_HASH=" << block.next_id << std::endl;
            file.close();
        }
        
        return true;
    }

    bool write_new_block_and_update_previous(struct IdentityObject block) {

        if(!IdentityBlockOperations::compare(block, null_user)) {
            logger.errorln("Cannot write null user block!");
            return false;
        }

        // First, write the new block independantly
        write_new_block_independantly(block);

        // Find the last block written which is linked to the others
        struct IdentityObject last_block_written_and_linked = find_last_block_written();

        // Modify the next hash of the block by the id of the new block
        memcpy((void*)&last_block_written_and_linked.next_id[0], (void*)&block.id[0], LEN_SHA256);

        // Rewrite the new block
        write_new_block_independantly(last_block_written_and_linked);

        return true;
    }

    struct IdentityObject find_last_block_written() {
        struct IdentityObject last_block;

        // Start by the genesis block
        last_block = read_block("genesis");
        while(!IdentityBlockOperations::is_next_id_null(last_block)) {
            last_block = read_block((char*)&last_block.next_id[0]);
        }
        return last_block;
    }

    struct IdentityObject read_block(char *block_id) {
        logger.infoln(std::string("Reading ") + std::string(block_id) + std::string(" block..."));
        
        std::string filename("blockchain/identity/");
        filename += std::string(block_id);

        std::ifstream file;
        file.open(filename);

        if(!file.is_open()) {
            logger.errorln(std::string("Unable to open ") + filename + std::string(" !"));
            return null_user;
        } else {
            std::string text;
            std::string line;
            while(std::getline(file, line)) {
                text += line + std::string("\n");
            }
            file.close();

            // Now parse the string content

            std::string password_field_content = IdentityBlockOperations::read_field(std::string("PASSWORD_HASH="), text);
            std::string next_hash_field_content = IdentityBlockOperations::read_field(std::string("NEXT_HASH="), text);

            struct IdentityObject block_read;

            const char *cc_password_field = password_field_content.c_str();
            memcpy((void*)&block_read.password_hash[0], (void*)cc_password_field, LEN_SHA256);
            
            const char *cc_next_hash_field = next_hash_field_content.c_str();
            memcpy((void*)&block_read.next_id[0], (void*)cc_next_hash_field, LEN_SHA256);

            memcpy((void*)&block_read.id[0], (void*)block_id, LEN_SHA256);

            return block_read;
        }
    }
}