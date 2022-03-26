#include "debug/log.h"
#include "object/object.h"
#include "library/pictures/resize.h"
#include "identity/identity.h"
#include "tests/test.h"
#include <unistd.h>

int main() {
    logger.enable();
    // struct Object tux = ObjectCreation::create("assets/examples/linux.jpeg", {"Tux", "Logo", "Linux"});
    // ObjectCreation::get_exif_descriptors_from_image(std::string(tux.signature));
    // struct IdentityObject user = IdentityCreation::create_new_identity("admin"); 
    // IdentityCreation::save_identity_to_file(user);
    if(!IdentityCreation::is_genesis_here()) IdentityCreation::save_genesis_identity();
    // IdentityFileOperations::read_block(&genesis_user.id[0]);
    // struct IdentityObject user = IdentityCreation::create_new_identity("admin");
    // IdentityFileOperations::write_new_block_and_update_previous(user);

    // The tests functions
    #if TEST == ENABLE
        logger.infoln("Running tests functions...");
        Tests::create_hundred_new_identity();
    #endif

    return 0;
}
