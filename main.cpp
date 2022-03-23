#include "debug/log.h"
#include "object/object.h"
#include "library/pictures/resize.h"
#include "identity/identity.h"

int main() {
    logger.enable();
    // ObjectCreation::generate_object_template("assets/examples/linux.jpeg", {"Tux", "Logo", "Picture"});
    IdentityCreation::create_new_identity("admin"); 
    return 0;
}
