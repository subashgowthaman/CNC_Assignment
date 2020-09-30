
#include "Parameter.hpp"
using namespace std;


class DimensionDetector : public Parameter
{  
    private:

        float cuttingToolDimension;

    public:

    	DimensionDetector(float DefaultCuttingToolDimension);
	    float getCuttingToolDimension();
	    void SetCuttingToolVariationNow(float cuttingToolDimension);
};
