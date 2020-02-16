#ifndef CRBOT_SERVICE_TIMESTAMP_TIMESTAMP_H_
#define CRBOT_SERVICE_TIMESTAMP_TIMESTAMP_H_

#include <cstdint>

namespace CRbot{
    namespace Service{
        namespace Timestamp{

            uint32_t (*timestampStampingFunction_)() = nullptr;
            float timestampCvtToSec_ = 1.0;

            class timestamp{
            	uint32_t time_stamp;

            public:
            	static void setStampingFunction(uint32_t (*tsGetFptr)(), const char auxiliaryUnit = ' '){
            		timestampStampingFunction_ = tsGetFptr;
            		setDefaultAuxiliaryUnit(auxiliaryUnit);
            	}

            	static void setDefaultAuxiliaryUnit(const char auxiliaryUnit){
            		switch(auxiliaryUnit){
        			case 'm':
        				timestampCvtToSec_ = 0.001;
        			case 'u':
        				timestampCvtToSec_ = 0.000001;
        			case 'n':
        				timestampCvtToSec_ = 0.000000001;
        			default:
        				timestampCvtToSec_ = 1.0;
            		}
            	}

            	void stamp(){
            	    if (timestampStampingFunction_ != nullptr)
                	    time_stamp = (*timestampStampingFunction_)();
            	}

            	float inSec(){
            		return (float)time_stamp * timestampCvtToSec_;
            	}

            	float inMiliSec(){
            		return (float)time_stamp * timestampCvtToSec_ * 1000;
            	}
            };

        }
    }
}

#endif //CRBOT_SERVICE_TIMESTAMP_TIMESTAMP_H_
