#include "fileop.h"

namespace IdentityFileOperations {
    bool write_new_block(struct IdentityObject block) {
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
}