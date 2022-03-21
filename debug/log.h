#pragma once

#include <iostream>
#include <string>

class Logger {
public:
    Logger(bool state = true);
    void disable();
    void enable();
    bool get_state();
    void info(const char *str);
    void success(const char *str);
    void error(const char *str);
    void infoln(const char *str);
    void successln(const char *str);
    void errorln(const char *str);
    void info(std::string str);
    void success(std::string str);
    void error(std::string str);
    void infoln(std::string str);
    void successln(std::string str);
    void errorln(std::string str);
private:
private:
    bool state;
};

extern Logger logger;