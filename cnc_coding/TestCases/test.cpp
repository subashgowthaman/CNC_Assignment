



TEST(TEMPERATURE_TC01, detect_no_overheat) {

  TemperatureInCelcius.SetOperatingTemperature(30.4f);
  TemperatureInCelcius.SetOperatingTemperature(33.2f);
  ASSERT_EQ(over_heat_handler.getOverHeatEventCount(), 0);
}

TEST(TEMPERATURE_TC02, detect_overheat) {
  Temperature system_temperature(31.0f);
  TemperatureInCelcius.SetOperatingTemperature(30.4f);
  TemperatureInCelcius.SetOperatingTemperature(36.2f);
  ASSERT_EQ(over_heat_handler.getOverHeatEventCount(), 1);
}

TEST(OPERATING_TIME_TC01, detect_no_overtime) 
{
  OperatingTime system_operating_time;
  OverTimeDetector overtime_detector(system_operating_time, 6.0f);
  OverTimeHandler overtime_handler(overtime_detector);
  OperatingTimeInMinutes.SetElapsedMachineOperationTime(15.0f);
  OperatingTimeInMinutes.updateOperatingTime(15.0f);
  OperatingTimeInMinutes.SetElapsedMachineOperationTime(15.0f);
  OperatingTimeInMinutes.SetElapsedMachineOperationTime(15.0f);
}

TEST(OPERATING_TIME_TC02, detect_overtime) 
{
  OperatingTime system_operating_time;
  OverTimeDetector overtime_detector(system_operating_time, 0.75f);
  OverTimeHandler overtime_handler(overtime_detector);
  system_operating_time.SetElapsedMachineOperationTime(15.0f);
  system_operating_time.SetElapsedMachineOperationTime(15.0f);
  system_operating_time.SetElapsedMachineOperationTime(15.0f);
  system_operating_time.SetElapsedMachineOperationTime(15.0f);
  ASSERT_EQ(overtime_handler.getOverTimeEventsCount(), 2);
}




int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
