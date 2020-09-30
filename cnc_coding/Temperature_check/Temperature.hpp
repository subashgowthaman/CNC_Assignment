
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

class ExceedThresholdHeatObserver : public IObservable, public IObserver 

{
 private:
  const Temperature& observed_temperature_;
  float upper_limit_;

 public:
  ExceedThresholdHeatObserver(const Temperature& to_be_observered_temperature, float upper_limit);
  void handleStateChange(const IObservable& observable) override;
  const Temperature& getTemperatureDetail() const;
};

class ExceedThresholdHeatHandler : public IObserver {
 private:
  const ExceedThresholdHeatDetector& observed_overheat_detector_;

  unsigned int over_heat_event_count_;

 public:
  explicit ExceedThresholdHeatHandler(ExceedThresholdHeatDetector& to_be_observed_detector);
  void handleStateChange(const IObservable& observable) override;
  unsigned int getOverHeatEventCount();
};

