#include "mai.h"
using namespace std;


namespace mathLib{
    namespace MatrixLib{
        class matrix{};
        matrix operator*(const matrix&,const matrix&){};
    }
}

mathLib::MatrixLib::matrix operator*(const mathLib::MatrixLib::matrix&,const mathLib::MatrixLib::matrix&){
}

