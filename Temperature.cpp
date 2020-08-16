
#include "Parameter.hpp"
#include "Temperature.hpp"
using namespace std;


Temperature::Temperature(float DefaultTemperature)
{
    this.DefaultTemperature = DefaultTemperature;
}

float Temperature::getOperatingTemperature()
{
    return temperature;
}

void Temperature::SetOperatingTemperature(float temperature)
{
	this.temperature = temperature;
}
	    
