#include "Parameter.hpp"

using namespace std;

class OperatingTimer : public Parameter
{  
    private:

        float operatingTime;

    public:

    	OperatingTimer(float setDefaultTimerValue);
	    float getOperatingTime();
	    void SetElapsedMachineOperationTime(float operatingTime);
	   
};