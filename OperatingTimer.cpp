
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
