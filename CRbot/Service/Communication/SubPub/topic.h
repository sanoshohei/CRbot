#ifndef CRBOT_SERVICE_COMMUNICATION_SUBPUB_TOPIC_H_
#define CRBOT_SERVICE_COMMUNICATION_SUBPUB_TOPIC_H_

#include <vector>
#include "../../Callback/callback.h"

namespace CRbot{
    namespace Service{
        namespace Communication{
            namespace SubPub{

                using CRbot::Service::Callback::callback;

                template<typename MsgT>
                class topic{
                	MsgT myMsg;
                	std::vector<subscriber<MsgT>*> subscribers;

            	public:
                	void writeMsg(MsgT msg){
                		myMsg = msg;
                		multicast();
                	}

                	MsgT readMsg(){
                		return myMsg;
                	}

                	template<typename MsgU>
                	friend void operator>>(publisher<MsgU>&, topic<MsgU>&);

                	template<typename MsgU>
                	friend void operator>>(topic<MsgU>&, subscriber<MsgU>&);

                private:
                	void multicast(){
                		for(subscriber<MsgT> *sub: subscribers){
            				sub->call(myMsg);
                		}
                	}
                };

            }
        }
    }
}

#endif //CRBOT_SERVICE_COMMUNICATION_SUBPUB_TOPIC_H_
