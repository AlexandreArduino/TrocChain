#include "identity.h"

struct IdentityObject genesis_user = {"genesis", "no_password", "NULL"};

namespace IdentityCreation {
    struct IdentityObject create_new_identity(const char *password) {
        
        // The username is the hash of the current timestamp
        
        logger.infoln("Creating new identity object...");

        if(std::string(password).length() < MINIMUM_PASSWORD_SIZE) {
            logger.errorln("The password must have a length of 12!");
            return null_user;
        }

        struct IdentityObject new_identity;

        std::time_t timestamp = std::time(NULL);

        std::string str_id = sha256(std::to_string(timestamp));
        const char *cc_id = str_id.c_str();

        memcpy((void*)&new_identity.id[0], (void*)cc_id, LEN_SHA256);

        std::string str_password_hash = sha256(std::string(password));
        const char *cc_password_hash = str_password_hash.c_str();

        memcpy((void*)&new_identity.password_hash[0], (void*)cc_password_hash, LEN_SHA256);

        std::string str_next_hash("NULL");
        const char *cc_next_hash = str_next_hash.c_str();

        memcpy((void*)&new_identity.next_id[0], (void*)cc_next_hash, 5);

        return new_identity;

    }

    bool save_identity_to_file(struct IdentityObject to_save) {
        return IdentityFileOperations::write_new_block_independantly(to_save);
    }

    bool save_genesis_identity() {

        return IdentityFileOperations::write_new_block_independantly(genesis_user);
    }

    bool is_genesis_here() {
        logger.infoln("Checking if genesis user is present...");

        std::string filename("blockchain/identity/");
        filename += std::string(genesis_user.id);

        std::ifstream file;
        file.open(filename);

        if(!file.is_open()) return false; else {
            file.close();
            return true;
        }
    }
}