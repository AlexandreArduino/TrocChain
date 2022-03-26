#include "object.h"

using std::experimental::filesystem::directory_iterator;

namespace ObjectCreation {
    bool add_object_to_user_file(struct Object object, std::string user_signature) {
        logger.infoln("Updating user file...");

        // Check if the object signature is not already used
        for (const auto & file : directory_iterator(std::string("blockchain/pictures/"))) {
            if(std::string(file.path()) == std::string("blockchain/pictures/") + std::string(object.signature) + std::string(".jpeg")) {
                logger.errorln("Picture image already used! Cannot use it for another user!");
                return false;
            }
        }

        std::string filename("blockchain/identity/");
        filename += user_signature;

        // Save the content file
        std::ifstream file;
        file.open(filename);
        std::string content_file;
        if(!file.is_open()) {
            logger.errorln(std::string("Unable to open ") + filename + std::string(" !"));
            return false;
        } else {
            std::string line;
            while(std::getline(file, line)) {
                content_file += line + std::string("\n");
            }
            file.close();
        }
        
        // Replace the data
        // std::size_t found = content_block_string.find(field);
        // if(found == std::string::npos)
        std::size_t found = content_file.find(")");
        if(found == std::string::npos) {
            logger.errorln("Unable to find OBJECTS=() in file content!");
            return false;
        } else {
            std::string output("");
            for(size_t i = 0; i < found; i++) output += content_file[i];
            output += std::string("/");
            output += std::string(object.signature);
            output += std::string(")");
            for(size_t i = found + 1; i < content_file.length(); i++) output += content_file[i];
            std::ofstream new_user_file;
            new_user_file.open(filename);
            if(!new_user_file.is_open()) {
                logger.errorln(std::string("Unable to open/write ") + filename + std::string(" !"));
                return false;
            } else {
                new_user_file << output;
                new_user_file.close();
                return true;
            }
        }
    }
}