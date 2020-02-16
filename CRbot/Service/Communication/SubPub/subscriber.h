#ifndef CRBOT_SERVICE_COMMUNICATION_SUBPUB_SUBSCRIBER_H_
#define CRBOT_SERVICE_COMMUNICATION_SUBPUB_SUBSCRIBER_H_

#include "../../Callback/callback.h"

namespace CRbot{
    namespace Service{
        namespace Communication{
            namespace SubPub{

                using CRbot::Service::Callback::callback;

                template<typename MsgT>
                class subscriber{
                	topic<MsgT> *myTopic;
                	callback<void(MsgT)> myCallback;

                public:
                    subscriber(){
                        myTopic = nullptr;
                    }

                    subscriber(void (*method)(MsgT)){
                        setCallback(method);
                    }

                    template<typename T>
                    subscriber(T *obj, void (T::*method)(MsgT)){
                        setCallback(obj, method);
                	}

                	void setCallback(void (*method)(MsgT)){
                		myCallback.setFunction(method);
                	}

                	template<typename T>
                	void setCallback(T *obj, void (T::*method)(MsgT)){
                		myCallback.setFunction(obj, method);
                	}

                	MsgT subscribe(){
                		if (myTopic != nullptr){
                			return myTopic->readMsg();
                		}

                		MsgT msg;
                		return msg;
                	}

                	void call(MsgT msg){
                	    if (myCallback.isValid())
                    	    myCallback.call(msg);
                	}

                	template<typename MsgU>
                	friend void operator>>(topic<MsgU>&, subscriber<MsgU>&);
                };

            }
        }
    }
}

#endif //CRBOT_SERVICE_COMMUNICATION_SUBPUB_SUBSCRIBER_H_
