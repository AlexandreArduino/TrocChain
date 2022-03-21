#include "log.h"

Logger logger(true);

Logger::Logger(bool state) {
    this->state = state;
}

void Logger::disable() { this->state = false; }
void Logger::enable() { this->state = true; }
bool Logger::get_state() { return this->state; }

void Logger::info(const char *str) {
    if(this->state) std::cout << "[i] " << str;
}

void Logger::success(const char *str) {
    if(this->state) std::cout << "[+] " << str;
}

void Logger::error(const char *str) {
    if(this->state) std::cout << "[-] " << str;
}

void Logger::infoln(const char *str) {
    if(this->state) {
        this->info(str);
        std::cout << std::endl;
    }
}

void Logger::successln(const char *str) {
    if(this->state) {
        this->success(str);
        std::cout << std::endl;
    }
}

void Logger::errorln(const char *str) {
    if(this->state) {
        this->error(str);
        std::cout << std::endl;
    }
}

void Logger::info(std::string str) {
    if(this->state) std::cout << "[i] " << str;
}

void Logger::success(std::string str) {
    if(this->state) std::cout << "[+] " << str;
}

void Logger::error(std::string str) {
    if(this->state) std::cout << "[-] " << str;
}

void Logger::infoln(std::string str) {
    if(this->state) {
        this->info(str);
        std::cout << std::endl;
    }
}

void Logger::successln(std::string str) {
    if(this->state) {
        this->success(str);
        std::cout << std::endl;
    }
}

void Logger::errorln(std::string str) {
    if(this->state) {
        this->error(str);
        std::cout << std::endl;
    }
}