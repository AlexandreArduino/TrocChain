#include "api.h"

namespace API {
    struct IdentityObject add_user(const char *password) {
        struct IdentityObject user = IdentityCreation::create_new_identity(password);
        IdentityCreation::save_identity_to_file(user);
        return user;
    }

    struct Object proclaim_object(const char *picture_path, struct KeywordsDescription descriptors, std::string user_signature) {
        return ObjectCreation::create(picture_path, descriptors, user_signature);
    }
}