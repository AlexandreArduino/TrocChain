#include "object.h"

namespace ObjectCreation {
    bool save_object_to_file(struct Object object) {
        
        logger.infoln(std::string("Saving ") + std::string(object.signature) + std::string(" image to file..."));
        
        std::string src(".cache/");
        src += std::string(object.cache_name);
        src += std::string(".jpeg");
        
        std::string dest("blockchain/pictures/");
        dest += std::string(object.signature);
        dest += std::string(".jpeg");

        std::string content_src_file("");

        // Read the content file
        std::ifstream src_file;
        src_file.open(src);
        if(!src_file.is_open()) {
            logger.errorln(std::string("Unable to open/read ") + src + std::string(" !"));
            return false;
        } else {
            std::string line = "";
            while(std::getline(src_file, line)) {
                content_src_file += line + std::string("\n");
            }
            src_file.close();
            
            // Write it in the new file
            std::ofstream dest_file;
            dest_file.open(dest);
            if(!dest_file.is_open()) {
                logger.errorln(std::string("Unable to open/write ") + dest + std::string(" !"));
                return false;
            } else {
                dest_file << content_src_file;
                dest_file.close();
                return true;
            }
        }

        return true;
    }
}