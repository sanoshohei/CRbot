#ifndef CRBOT_SERVICE_COMMUNICATION_SUBPUB_MODEL_H_
#define CRBOT_SERVICE_COMMUNICATION_SUBPUB_MODEL_H_

namespace CRbot{
    namespace Service{
        namespace Communication{
            namespace SubPub{

                template<typename MsgT>
                class subscriber;

                template<typename MsgT>
                class publisher;

                template<typename MsgT>
                class topic;

                template<typename MsgT>
                void operator>>(publisher<MsgT>&, topic<MsgT>&);

                template<typename MsgT>
                void operator>>(topic<MsgT>&, subscriber<MsgT>&);

            }
        }
    }
}

#endif //CRBOT_SERVICE_COMMUNICATION_SUBPUB_MODEL_H_
