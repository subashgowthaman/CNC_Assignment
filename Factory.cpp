#include "Parameter.hpp"
#include "Temperature.hpp"
#include "DimensionDetector.hpp"

using namespace std;

class Parameterfactory
{
	public:
		ParameterFactory()
		{
	        Parameter::Create(Temperature);
	        Parameter::Create(OperatingTime);
	        Parameter::Create(CuttingToolDimension);
		}

};


void Parameter::Create(ParameterType type)
{
	if(type == Temperature)
	{
    	new Temperature(26.0f);
	}

    else if(type == OperatingTime)
    {
    	new OperatingTime(1.0f);
    }

    else if(type = CuttingToolDimension)
    {
    	new DimensionDetector(0.0005f);
    }

}