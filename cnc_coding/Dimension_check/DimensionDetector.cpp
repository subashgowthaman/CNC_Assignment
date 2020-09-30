
#include "Parameter.hpp"
#include "DimensionDetector.hpp"
using namespace std;

DimensionDetector::DimensionDetector(float DefaultCuttingToolDimension)
{
    this.DefaultCuttingToolDimension = DefaultCuttingToolDimension;
}

float DimensionDetector::getCuttingToolDimension()
{
    return cuttingToolDimension;
}

void DimensionDetector::SetCuttingToolVariationNow(float cuttingToolDimension)
{
	this.cuttingToolDimension = cuttingToolDimension;
}
