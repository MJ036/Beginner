#include "hw4.hh"
#include <iostream>
#include "log4cpp/OstreamAppender.hh"
#include  "log4cpp/FileAppender.hh"
#include "log4cpp/RollingFileAppender.hh"
#include "log4cpp/Priority.hh"
#include "log4cpp/PatternLayout.hh"


using std::cout;
using std::endl;
using namespace log4cpp;

Mylogger * Mylogger::_pInstance = nullptr;
Mylogger::Mylogger():_mycat(Category::getInstance("mycat"))
{
    auto ptn1 = new PatternLayout();
    ptn1->setConversionPattern("%d %c [%p] %m%n");

    auto ptn2 = new PatternLayout();
    ptn2->setConversionPattern("%d %c [%p] %m%n");

    auto ptn3 = new PatternLayout();
    ptn3->setConversionPattern("%d %c [%p] %m%n");

    auto pos = new OstreamAppender("console",&cout);
    pos->setLayout(ptn1);
    
    

    auto rollingfile = new RollingFileAppender("rollingfile","rollingfile.log",5 * 1024,9);
    rollingfile->setLayout(ptn2);

    auto pfile = new FileAppender("pfile","my.log");
    pfile->setLayout(ptn3);

    _mycat.setPriority(Priority::DEBUG);
    _mycat.addAppender(pos);
    _mycat.addAppender(pfile);
    _mycat.addAppender(rollingfile);

    cout << "Mylogger()" << endl;
}

Mylogger::~Mylogger(){
    Category::shutdown();
    cout << "~Mylogger()" << endl;
}

Mylogger* Mylogger::getInstance(){
    if(_pInstance == nullptr){
        _pInstance = new Mylogger();
    }
    return _pInstance;
}

void Mylogger::destroy(){
    if(_pInstance){
        delete _pInstance;
        _pInstance = nullptr;
    }
}

void Mylogger::warn(const char * msg)
{
    _mycat.warn(msg);
}

void Mylogger::error(const char *msg)
{
    _mycat.error(msg);
}

void Mylogger::debug(const char *msg)
{
    _mycat.debug(msg);
}

void Mylogger::info(const char *msg)
{
    _mycat.info(msg);
}





