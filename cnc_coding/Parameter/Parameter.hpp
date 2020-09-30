// Parameter.hpp

using namespace std;

class ParameterType
{
	float temperature,
	double cuttingtooldimension,
	double Operatingtime
};


class Parameter
{
    public:
    	static Parameter* Create(ParameterType type);
	      
};





























