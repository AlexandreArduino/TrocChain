#include "debug/log.h"
#include "object/object.h"
#include "library/pictures/resize.h"
#include "identity/identity.h"

int main() {
    logger.enable();
    // ObjectCreation::generate_object_template("assets/examples/linux.jpeg", {"Tux", "Logo", "Picture"});
    // struct IdentityObject user = IdentityCreation::create_new_identity("admin"); 
    // IdentityCreation::save_identity_to_file(user);
    if(!IdentityCreation::is_genesis_here()) IdentityCreation::save_genesis_identity();
    // IdentityFileOperations::read_block(&genesis_user.id[0]);
    // struct IdentityObject user = IdentityCreation::create_new_identity("admin");
    // IdentityFileOperations::write_new_block_and_update_previous(user);
    return 0;
}
