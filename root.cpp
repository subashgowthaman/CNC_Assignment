
using namespace std;


int main()
{
	ParameterFactory *parameterFactory = new ParameterFactory();

    Temperature TemperatureInCelcius;
    OperatingTimer OperatingTimeInMinutes;
    DimensionDetector CuttingToolDimensionInMm;

    
    TemperatureInCelcius.SetOperatingTemperature(28.0F);
    TemperatureInCelcius.SetOperatingTemperature(29.0F);

    TemperatureInCelcius.SetOperatingTemperature(34.0F);

    TemperatureInCelcius.SetOperatingTemperature(34.0F);
    TemperatureInCelcius.SetOperatingTemperature(35.0F);

    OperatingTimeInMinutes.SetElapsedMachineOperationTime(15.0f);
    OperatingTimeInMinutes.SetElapsedMachineOperationTime(25.0f);

    OperatingTimeInMinutes.SetElapsedMachineOperationTime(250.0f);
    OperatingTimeInMinutes.SetElapsedMachineOperationTime(350.0f);
	
    OperatingTimeInMinutes.SetElapsedMachineOperationTime(360.0f);
    OperatingTimeInMinutes.SetElapsedMachineOperationTime(365.0f);

    CuttingToolDimensionInMm.SetCuttingToolVariationNow(0.002f);

    CuttingToolDimensionInMm.SetCuttingToolVariationNow(0.035f);
    CuttingToolDimensionInMm.SetCuttingToolVariationNow(0.045f);
    CuttingToolDimensionInMm.SetCuttingToolVariationNow(0.05f);
    CuttingToolDimensionInMm.SetCuttingToolVariationNow(0.051f);

    return 0;

}
