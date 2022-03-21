#include "resize.h"

namespace Library {
    namespace Image {
        bool resize(const char *src, const char *dest) {
            sf::Image original; // This object is used just to check if the file is present
            logger.infoln(std::string("Loading ") + std::string(src) + std::string(" ..."));
            if(!original.loadFromFile(std::string(src))) {
                logger.errorln("Unable to load it!");
                return false;
            } else {
                logger.infoln("Resizing image...");
                system((std::string("convert ") + std::string(src) + std::string(" -resize ") + std::string(RESIZED_WIDTH_IMAGE_STRING) + std::string(" ") + std::string(dest)).c_str());
                return true;
            }
        }
    }
}