
#include "Parameter.hpp"
#include "OperatingTimer.hpp"

using namespace std;

OperatingTimer::OperatingTimer(float setDefaultTimerValue)
{
    this.setDefaultTimerValue = setDefaultTimerValue;
}

float OperatingTimer::getOperatingTime()
{
    return operatingTime;
}

void OperatingTimer::SetElapsedMachineOperationTime(float operatingTime)
{
	this.operatingTime = operatingTime;
}



void OperatingTime::updateOperatingTime(float time_elapsed) 
{

  operating_time_ = operating_time_ + (time_elapsed / 60.0f);
  notify();
}

