



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

TEST(OPERATING_TIME_TC01, detect_no_overtime) {
  OperatingTime system_operating_time;
  OverTimeDetector overtime_detector(system_operating_time, 6.0f);
  OverTimeHandler overtime_handler(overtime_detector);
  OperatingTimeInMinutes.SetElapsedMachineOperationTime(15.0f);
  OperatingTimeInMinutes.updateOperatingTime(15.0f);
  OperatingTimeInMinutes.SetElapsedMachineOperationTime(15.0f);
  OperatingTimeInMinutes.SetElapsedMachineOperationTime(15.0f);
}

TEST(OPERATING_TIME_TC02, detect_overtime) {
  OperatingTime system_operating_time;
  OverTimeDetector overtime_detector(system_operating_time, 0.75f);
  OverTimeHandler overtime_handler(overtime_detector);
  system_operating_time.SetElapsedMachineOperationTime(15.0f);
  system_operating_time.SetElapsedMachineOperationTime(15.0f);
  system_operating_time.SetElapsedMachineOperationTime(15.0f);
  system_operating_time.SetElapsedMachineOperationTime(15.0f);
  ASSERT_EQ(overtime_handler.getOverTimeEventsCount(), 2);
}

TEST(PART_DIMENSION_TC01, detect_no_deviation) {

  PartDimensionChecker part_a1_checker(part_a1, 0.05f);
  PartDimensionChecker part_a2_checker(part_a2, 0.05f);

  PartDimensionDeviationHandler part_a1_dev_handler(part_a1_checker);
  PartDimensionDeviationHandler part_a2_dev_handler(part_a2_checker);


  part_a1.SetCuttingToolVariationNow(12.01f);
  part_a1.SetCuttingToolVariationNow(12.03f);
  part_a2.SetCuttingToolVariationNow(4.001f);
  part_a2.SetCuttingToolVariationNow(4.003f);

  ASSERT_EQ(part_a1_dev_handler.getNumberOfDefectiveParts(), 0);
  ASSERT_EQ(part_a2_dev_handler.getNumberOfDefectiveParts(), 0);
}

TEST(PART_DIMENSION_TC02, detect_deviation) 
{


  PartDimensionChecker part_a1_checker(part_a1, 0.05f);
  PartDimensionChecker part_a2_checker(part_a2, 0.05f);

  PartDimensionDeviationHandler part_a1_dev_handler(part_a1_checker);
  PartDimensionDeviationHandler part_a2_dev_handler(part_a2_checker);

  part_a1.SetCuttingToolVariationNow(12.31f);
  part_a1.SetCuttingToolVariationNow(11.93f);
  part_a2.SetCuttingToolVariationNow(4.12f);
  part_a2.SetCuttingToolVariationNow(3.8f);

  ASSERT_EQ(part_a1_dev_handler.getNumberOfDefectiveParts(), 2);
  ASSERT_EQ(part_a2_dev_handler.getNumberOfDefectiveParts(), 2);
}

TEST(POWERONSELFTEST_TC01, detect_no_failure) {
  PowerOnSelfTest system_POST;
  SelfTestFailureDetector POST_checker(system_POST);
  SelfTestFailureHandler POST_failure_handler(POST_checker);

  system_POST.setSelfTestState(SelfTestState::ALL_OK);

  ASSERT_EQ(POST_failure_handler.isPOSTFailed(), false);
}

TEST(POWERONSELFTEST_TC02, detect_no_failure) {
  PowerOnSelfTest system_POST;
  SelfTestFailureDetector POST_checker(system_POST);
  SelfTestFailureHandler POST_failure_handler(POST_checker);

  system_POST.setSelfTestState(SelfTestState::CONFIGURATION_FAULT);

  ASSERT_EQ(POST_failure_handler.isPOSTFailed(), true);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}