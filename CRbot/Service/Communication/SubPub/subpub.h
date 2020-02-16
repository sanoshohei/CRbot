#ifndef CRBOT_SERVICE_COMMUNICATION_SUBPUB_SUBPUB_H_
#define CRBOT_SERVICE_COMMUNICATION_SUBPUB_SUBPUB_H_

#include "model.h"
#include "subscriber.h"
#include "publisher.h"
#include "topic.h"

namespace CRbot{
    namespace Service{
        namespace Communication{
            namespace SubPub{

                template<typename MsgT>
                void operator>>(publisher<MsgT> &pub, topic<MsgT> &top){
                    pub.myTopic = &top;
                }

                template<typename MsgT>
                void operator>>(topic<MsgT> &top, subscriber<MsgT> &sub){
                    top.subscribers.push_back(&sub);
                    top.subscribers.shrink_to_fit();
                    sub.myTopic = &top;
                }

            }
        }
    }
}

#endif //CRBOT_SERVICE_COMMUNICATION_SUBPUB_SUBPUB_H_
