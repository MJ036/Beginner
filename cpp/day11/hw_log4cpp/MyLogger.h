#ifndef __MYLOGGER_H__
#define __MyLOGGER_H__

#include <log4cpp/Category.hh>

using namespace log4cpp;

class MyLogger
{
public:
    static MyLogger *getInstance();
    static void destroy();

    void warn(const char *msg);
    void error(const char *msg);
    void debug(const char *msg);
    void info(const char *msg);

private:
    MyLogger();
   ~MyLogger();

    static MyLogger *_pInstance;
    Category &_mycat;
    

};

#define prefix(msg) string(__FILE__).append("  ").append(__FUNCTION__).\
    append(string("  ")).append(string(std::to_string(__LINE__))).append(":").\
    append(msg).c_str()

#define logError(msg) MyLogger::getInstance()->error(prefix(msg));
#define logWarn(msg) MyLogger::getInstance()->warn(prefix(msg));
#define logDebug(msg) Mylog::getInstance()->debug(prefix(msg));
#define logInfo(msg) MyLogger::getInstance()->info(prefix(msg));

#endif
