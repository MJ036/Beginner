#include "mai.h"

using namespace std;
class Date{
private:
    unsigned int _y;
    unsigned int _m;
    unsigned int _d;

    unsigned int getMonth(const string monthStr){
        static const std::map<std::string, unsigned> monthMap = {
            {"January", 1}, {"February", 2}, {"March", 3}, {"April", 4},
            {"May", 5}, {"June", 6}, {"July", 7}, {"August", 8},
            {"September", 9}, {"October", 10}, {"November", 11}, {"December", 12},
            {"Jan", 1}, {"Feb", 2}, {"Mar", 3}, {"Apr", 4},
            {"May", 5}, {"Jun", 6}, {"Jul", 7}, {"Aug", 8},
            {"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12}

        };

        auto it = monthMap.find(monthStr);
        if (it != monthMap.end()) {
            return it->second;

        } else {
            throw std::invalid_argument("Invalid month: " + monthStr);

        }

    }

public:
    Date(const string &data){
        istringstream stm(data);
        if(data.find('/') != string::npos){
            unsigned int y,m,d;
            char slash1,slash2;
            stm >> m >> slash1 >> d >> slash2 >> y;
            if(slash1 == '/' && slash2 == '/'){
                _y = y;
                _m = m;
                _d = d;
                return;
            }else{
                throw std::invalid_argument("Invalid date format:" + data);
            }
        }
        string part;
        stm >> part;
        if(isalpha(part[0])){
            _m = getMonth(part);
            stm >> _d;
            if(data.find(',') != string::npos){
                char douhao;
                stm >> douhao;
                if(douhao != ','){
                    throw std::invalid_argument("Invalid date format:" + data);
                }
            }
            stm >> _y;
        }else{
            throw std::invalid_argument("Invalid date format:" + data);
        }
    }
    void print()const{
        cout << _y << " " << _m << " " << _d << endl;
    }
};

int main()
{try {
    Date date1("January 1, 1900");
    date1.print();

    Date date2("1/1/1990");
    date2.print();

    Date date3("Jan 1 1900");
    date3.print();

     } catch (const std::exception& e) {
         std::cerr << e.what() << std::endl;

     }

return 0;
}

