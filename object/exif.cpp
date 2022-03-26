#include "object.h"

namespace ObjectCreation {
    bool update_exif_data_to_image_file(struct Object object) {
        // The data are the descriptors which need to be written
        std::string command("exiftool \"-description=");
        command += std::string(object.descriptors.first);
        command += std::string("/");
        command += std::string(object.descriptors.second);
        command += std::string("/");
        command += std::string(object.descriptors.third);
        command += std::string("\" ");
        command += std::string("\"blockchain/pictures/");
        command += std::string(object.signature);
        command += std::string(".jpeg\"");
        
        logger.infoln(std::string("Updating exif data to ") + std::string(object.signature) + std::string(" picture..."));
        Library::run(command);

        return true;
    }

    struct KeywordsDescription get_exif_descriptors_from_image(std::string signature) {
        
    }
}