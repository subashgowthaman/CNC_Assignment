
#include "Parameter.hpp"
using namespace std;


class Temperature : public Parameter
{  
    private:

        float temperature;

    public:

	    Temperature(float DefaultTemperature);
	    float getOperatingTemperature();
	    void SetOperatingTemperature(float temperature);
	    
};


class TemperatureDetector
{
public:
    TemperatureDetector() { }

    virtual ~TemperatureDetector() { }

    virtual int Detector(const std::vector<DetectionParameters> &DetectionParameterArray, std::string &detection);
};