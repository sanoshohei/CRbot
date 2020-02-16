#ifndef CRBOT_SERVICE_COMMUNICATION_SUBPUB_PUBLISHER_H_
#define CRBOT_SERVICE_COMMUNICATION_SUBPUB_PUBLISHER_H_

#include "../../Callback/callback.h"
#include "../../Timestamp/timestamp.h"

namespace CRbot{
    namespace Service{
        namespace Communication{
            namespace SubPub{

                template<typename MsgT>
                class publisher{
                    topic<MsgT> *myTopic;

                public:
                    publisher(){
                        myTopic = nullptr;
                    }

                    void publish(MsgT msg){
                        if (myTopic != nullptr)
                            myTopic->writeMsg(msg);
                    }

                    template<typename MsgU>
                    friend void operator>>(publisher<MsgU>&, topic<MsgU>&);
                };

            }
        }
    }
}

#endif //CRBOT_SERVICE_COMMUNICATION_SUBPUB_PUBLISHER_H_
