#include "identity.h"

namespace Tests {
    void create_hundred_new_identity() {
        for(size_t i = 1; i < 100; i++) {
            struct IdentityObject user = IdentityCreation::create_new_identity(std::to_string(i).c_str());
            IdentityCreation::save_identity_to_file(user);
            sleep(1);
        }
    }
}