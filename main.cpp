#include "debug/log.h"
#include "object/object.h"
#include "library/pictures/resize.h"
#include "identity/identity.h"

int main() {
    logger.enable();
    // ObjectCreation::generate_object_template("assets/examples/linux.jpeg", {"Tux", "Logo", "Picture"});
    struct IdentityObject user = IdentityCreation::create_new_identity("admin"); 
    // IdentityCreation::save_identity_to_file(user);
    return 0;
}
