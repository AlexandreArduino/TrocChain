#include "object.h"

namespace ObjectCreation {
    bool save_object_to_file(struct Object object) {
        
        logger.infoln(std::string("Saving ") + std::string(object.signature) + std::string(" image to file..."));
        
        std::ofstream file;
        std::string filename("blockchain/pictures/");
        filename += std::string(object.signature);
        filename += std::string(".jpeg");

        file.open(filename);
        if(!file.is_open()) {
            logger.errorln("Unable to open/write it!");
            return false;
        } else {
            
        }
        
        return true;
    }
}