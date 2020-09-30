#include "../Parameter/Parameter.hpp"

using namespace std;

class OperatingTimer : public Parameter
{  
    private:

        float operatingTime;

    public:

    	OperatingTimer(float setDefaultTimerValue);
	    void SetElapsedMachineOperationTime(float operatingTime);

};



float OverTimeDetector::getOperatingTime() const 
{
  return observed_operating_time_.getOperatingTime();
}