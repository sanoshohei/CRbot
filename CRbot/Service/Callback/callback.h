#ifndef CRBOT_SERVICE_CALLBACK_CALLBACK_H_
#define CRBOT_SERVICE_CALLBACK_CALLBACK_H_

namespace CRbot{
    namespace Service{
        namespace Callback{

            template<typename R, typename ...Args>
            class callbackMethod{
                R (*method)(Args...);

            public:
                callbackMethod(){
                    method = nullptr;
                }

                callbackMethod(R (*method)(Args...)){
                    this->method = method;
                }

                virtual ~callbackMethod(){
                }

            	virtual R call(Args ...args){
            	    return (*method)(args...);
            	}
            };

            template<typename T, typename R, typename ...Args>
            class callbackMethodContext: public callbackMethod<R, Args...>{
            	T *obj;
            	R (T::*method)(Args...);

            public:
            	callbackMethodContext(T *obj, R (T::*method)(Args...)){
            		this->obj = obj;
            		this->method = method;
            	}

            	virtual ~callbackMethodContext(){
            	}

            	virtual R call(Args ...args){
            		return (obj->*method)(args...);
            	}
            };

            template<typename F>
            class callback;

            template<typename R, typename ...Args>
            class callback<R(Args...)>{
            	callbackMethod<R, Args...> *callback_method;

            public:
            	callback(){
            	    callback_method = nullptr;
            	}

            	callback(R (*method)(Args...)){
            	    callback_method = nullptr;
            	    setFunction(method);
            	}

            	template<typename T>
            	callback(T *obj, R (T::*method)(Args...)){
            	    callback_method = nullptr;
            	    setFunction(obj, method);
            	}

                ~callback(){
                    delete callback_method;
                }

                void setFunction(R (*method)(Args...)){
                    delete callback_method;
            		callback_method = new callbackMethod<R, Args...>(method);
                }

                template<typename T>
                void setFunction(T *obj, R (T::*method)(Args...)){
                    delete callback_method;
            		callback_method = new callbackMethodContext<T, R, Args...>(obj, method);
            	}

            	bool isValid(){
            	    if (callback_method == nullptr)
            	        return false;

            	    return true;
            	}

            	R call(Args ...args){
            	    return callback_method->call(args...);
            	}
            };

        }
    }
}

#endif //CRBOT_SERVICE_CALLBACK_CALLBACK_H_
