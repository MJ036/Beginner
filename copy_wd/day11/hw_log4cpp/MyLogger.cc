#include "MyLogger.h"
#include <iostream>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>

using namespace std;

MyLogger *MyLogger::_pInstance = nullptr;

MyLogger *MyLogger::getInstance()
{
    if(_pInstance == nullptr)
    {
        _pInstance = new MyLogger();
    }
    return _pInstance;
}

void MyLogger::destroy()
{
    if(_pInstance)
    {
        delete _pInstance;
        _pInstance = nullptr;
    }
}

void MyLogger::warn(const char *msg)
{
    _mycat.warn(msg);
}

void MyLogger::error(const char *msg)
{
    _mycat.error(msg);
}
void MyLogger::debug(const char *msg)
{
    _mycat.debug(msg);
}
void MyLogger::info(const char *msg)
{
    _mycat.info(msg);
}

MyLogger::MyLogger()
    :_mycat(Category::getRoot().getInstance("Mycat"))
{
    cout << "Mylogger()" << endl;
    
    PatternLayout *pp11 = new PatternLayout();
    pp11->setConversionPattern("%d %c [%p] %m%n");

    PatternLayout *pp12 = new PatternLayout();
    pp12->setConversionPattern("%d %c [%p] %m%n");

    OstreamAppender *pos = new OstreamAppender("OstringAppend122",&cout);
    pos->setLayout(pp11);

    FileAppender *pfa = new FileAppender("FileAppender12","wd.log");
    pfa->setLayout(pp12);

    _mycat.addAppender(pos);
    _mycat.addAppender(pfa);

    _mycat.setPriority(Priority::DEBUG);


}

MyLogger::~MyLogger()
{
    cout << "~MyLogger()" << endl;
    Category::shutdown();
}

