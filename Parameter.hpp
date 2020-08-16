// Parameter.hpp

using namespace std;


enum ParameterType
{
	Temperature,
	OperatingTime,
	CuttingToolDimension
};


class Parameter
{
    public:
    	static Parameter* Create(ParameterType type);
	      
};





























