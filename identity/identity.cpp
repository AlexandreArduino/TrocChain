#include "identity.h"

namespace IdentityCreation {
    struct IdentityObject create_new_identity(const char *password) {
        
        // The username is the hash of the current timestamp
        
        logger.infoln("Creating new identity object...");

        struct IdentityObject new_identity;

        std::time_t timestamp = std::time(NULL);

        std::string str_id = sha256(std::to_string(timestamp));
        const char *cc_id = str_id.c_str();

        memcpy((void*)&new_identity.id[0], (void*)cc_id, LEN_SHA256);

        std::string str_password_hash = sha256(std::string(password));
        const char *cc_password_hash = str_password_hash.c_str();

        memcpy((void*)&new_identity.password_hash[0], (void*)cc_password_hash, LEN_SHA256);

        return new_identity;

    }

    bool save_identity_to_file(struct IdentityObject to_save) {
        logger.infoln(std::string("Saving user ") + std::string(to_save.id) + std::string(" to file..."));
        return true;
    }
}