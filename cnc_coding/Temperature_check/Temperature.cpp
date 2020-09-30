
#include "../Parameter/Parameter.hpp"
#include "../Temperature_check/Temperature.hpp"
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
	    

ExceedThresholdHeatObserver::ExceedThresholdHeatObserver(ExceedThresholdHeatObserverHeatObserver& detector) : observed_overheat_detector_(detector), exceed_heat_count_(0) {}

void ExceedThresholdHeatObserver::handleStateChange(const IObservable& read_detector) 

{
  if (&observed_overheat_detector_ == &read_detector) {
    exceed_heat_event_count_++;
  }
}

unsigned int ExceedThresholdHeatObserver::getOverHeatEventCount() {
  return exceed_heat_event_count_;
}


ExceedThresholdHeatHandler::ExceedThresholdHeatHandler(OverHeatDetector& to_be_observed_detector)
    : observed_overheat_detector_(to_be_observed_detector),
      over_heat_event_count_(0) {}

void ExceedThresholdHeatHandler::handleStateChange(const IObservable& observed_detector) {
  if (&observed_overheat_detector_ == &observed_detector) {
    over_heat_event_count_++;
  }
}

unsigned int ExceedThresholdHeatHandler::getOverHeatEventCount() {
  return over_heat_event_count_;
}