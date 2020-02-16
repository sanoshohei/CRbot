#ifndef CRBOT_MSG_STD_ANYTYPE_H_
#define CRBOT_MSG_STD_ANYTYPE_H_

#include "base.h"

using CRbot::Msg::base;

namespace CRbot{
    namespace Msg{
        namespace Std{

            template<typename T>
            struct anytype: public stamped_base{
                T data;

            private:
                void *binary_ptr;
                size_t binary_size;

            public:
                anytype(){
                    binary_ptr = &data;
                    binary_size = sizeof(T);
                }

                virtual uint8_t getBinaryData(size_t index){
                    if (binary_ptr != nullptr && index < binary_size && index >= 0)
                        return *(static_cast<uint8_t*>(binary_ptr) + index);

                    return 0;
                }

                virtual size_t getBinarySize(){
                    return binary_size;
                }
            };

        }
    }
}

#endif //CRBOT_MSG_STD_ANYTYPE_H_
