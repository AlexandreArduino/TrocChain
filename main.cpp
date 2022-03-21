#include "debug/log.h"
#include "object/object.h"
#include "library/pictures/resize.h"

int main() {
    logger.enable();
    ObjectCreation::generate_object_template("assets/examples/linux.jpeg");
    return 0;
}
