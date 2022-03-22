#include "object.h"

namespace ObjectCreation {
    struct Object generate_object_template(const char *src, struct KeywordsDescription descriptors) {
        // This function generates the object template of a picture to add it to the network later
        struct Object new_object;
        
        std::time_t timestamp = std::time(NULL); // The name of the file in .cache directory

        if(!Library::Image::resize(src, (std::string(".cache/") + std::to_string(timestamp) + std::string(".jpeg")).c_str())) {
            return NULL_OBJECT;
        }
        else {
            // Add the descriptors and the image path to the new object
            new_object.descriptors = descriptors;
            new_object.image_path = src;

            // Generate the signature of the picture

            // Read the content of the picture as a string
            std::string content_picture;
            std::string line;

            logger.infoln("Reading content picture as a string...");
            std::ifstream file;
            file.open(std::string(".cache/") + std::to_string(timestamp) + std::string(".jpeg"));
            if(!file.is_open()) {
                logger.errorln("Unable to open it!");
                return NULL_OBJECT;
            } else {
                while(std::getline(file, line)) {
                    content_picture += line + std::string("\n");
                }
                file.close();
            }

            logger.infoln("Generating the signature...");
            
            std::string picture_signature = sha256(content_picture);

            logger.successln(std::string("Signature : ") + picture_signature);

            new_object.signature = picture_signature.c_str();

            return new_object;
        }
    }
}