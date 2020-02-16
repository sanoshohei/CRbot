#ifndef CRBOT_MSG_BASE_H_
#define CRBOT_MSG_BASE_H_

#include "../Service/Timestamp/timestamp.h"

using CRbot::Service::Timestamp::timestamp;

namespace CRbot{
    namespace Msg{

        struct base{
        public:
            base(){
            }

            virtual ~base(){
            }

            virtual uint8_t getBinaryData(size_t index){
                return 0;
            }

            virtual size_t getBinarySize(){
                return 0;
            }
        };

        struct stamped_base: public base{
        protected:
            timestamp ts;

        public:
            stamped_base(){
                ts.stamp();
            }

            virtual ~stamped_base(){
            }

            timestamp getTimestamp(){
                return ts;
            }
        };

    }
}

#endif //CRBOT_MSG_BASE_H_
