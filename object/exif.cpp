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
        
        std::string command("exiftool -description \"blockchain/pictures/");
        command += signature;
        command += std::string(".jpeg\"");
        
        std::string output = Library::run(command);
        std::string exif = "";
        size_t i = std::string(EXIF_RESULT_COMMAND_OFFSET).length();
        while(output[i] != '\n') {
            exif += output[i];
            i++;
        }
        
        struct KeywordsDescription to_return;

        uint8_t found_count = 0;
        std::string first = "";
        std::string second = "";
        std::string third = "";

        for(size_t i = 0; i < exif.length(); i++) {
            if(exif[i] == '/') found_count++;
            switch(found_count) {
                case 0:
                    first += exif[i];
                    break;
                case 1:
                    second += exif[i];
                    break;
                case 2:
                    third += exif[i];
                    break;
                default: break;
            }
        }
        to_return.first = first.c_str();
        to_return.second = second.c_str();
        to_return.third = third.c_str();

        return to_return;
    }
}