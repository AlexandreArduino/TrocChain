#include "identity.h"

namespace IdentityCreation {
    struct IdentityObject create_new_identity(const char *password) {
        
        // The username is the hash of the current timestamp
        
        logger.infoln("Creating new identity object...");

        struct IdentityObject new_identity;

        std::time_t timestamp = std::time(NULL);

        std::string id = sha256(std::to_string(timestamp));
        std::string password_hash = sha256(std::string(password));

        new_identity.id = id.c_str();
        new_identity.password_hash = password_hash.c_str();

        logger.successln(std::string("User id : ") + std::string(new_identity.id));

        return new_identity;

    }
}