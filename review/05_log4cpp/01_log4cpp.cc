#include "mai.h"
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Category.hh>
#include <log4cpp/Appender.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
using namespace std;
int main()
{
    using namespace log4cpp;

    PatternLayout *ptn1 = new PatternLayout();
    ptn1->setConversionPattern("%d %c [%p] %m%n");

    PatternLayout *ptn2 = new PatternLayout();
    ptn2->setConversionPattern("%d %c [%p] %m%n");

    PatternLayout *ptn3 = new PatternLayout();
    ptn3->setConversionPattern("%d %c [%p] %m%n");

    OstreamAppender *pos = new OstreamAppender("console",&cout);
    pos->setLayout(ptn1);

    FileAppender *filePos = new FileAppender("file","wd.log");
    filePos->setLayout(ptn2);

    RollingFileAppender *rfPos = new RollingFileAppender("rollingfile","rollingfile.log",5 * 1024,9);
    rfPos->setLayout(ptn3);
    
    Category& salesDepart = Category::getInstance("salesDepart");
    salesDepart.setPriority(Priority::ERROR);
    salesDepart.setAppender(pos);
    salesDepart.setAppender(filePos);
    salesDepart.setAppender(rfPos);

    int count = 100;
    while(count-- > 0){
        salesDepart.emerg("emerge msg");
        salesDepart.fatal("fatal msg");
        salesDepart.alert("alert msg");
        salesDepart.crit("crit msg");
        salesDepart.error("error msg");
        salesDepart.warn("warn msg");
        salesDepart.notice("notice msg");
        salesDepart.info("info msg");
    }
    
    Category::shutdown();


    return 0;
}


