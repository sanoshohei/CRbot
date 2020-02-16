#ifndef CRBOT_DEVICE_STD_SUMMATION_H_
#define CRBOT_DEVICE_STD_SUMMATION_H_

#include "../Service/Communication/SubPub/subpub.h"
#include "../Msg/Std/anytype.h"

namespace CRbot{
    namespace Device{
        namespace User{

            using namespace CRbot::Service;
            using Callback::callback;
            using Communication::SubPub::subscriber;
            using Communication::SubPub::publisher;
            using Msg::Std::anytype;

            class summation{
                anytype<int> sum;

                void add(anytype<int> value){
                    sum.data += value.data;
                    pub.publish(sum);
                }

            public:
                subscriber<anytype<int>> sub;
                publisher<anytype<int>> pub;

                summation(){
                    sum.data = 0;
                    sub.setCallback(this, &summation::add);
                }
            };

        }
    }
}

#endif //CRBOT_DEVICE_STD_SUMMATION_H_
