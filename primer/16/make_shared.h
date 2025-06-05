#ifndef __make_shared_H__
#define __make_shared_H__

#include "mai.h"
#include <memory>
#include <utility>

template<typename T,typename...Args>
 auto make_shared(Args&&... args)->std::shared_ptr<T> {
    return std::shared_ptr<T>(new T(std::forward<Args>(args)...));
}

#endif


