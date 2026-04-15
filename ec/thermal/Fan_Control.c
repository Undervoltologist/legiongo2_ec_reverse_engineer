
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Fan_Control(void)

{
  uint Current_RPM;
  
  if (EC_Status != '\x10') {
    FanPWM = 0;
    PWM_2 = 0;
    return;
  }
  GetFanRPM();
  if ((Thermal_Logic_Flag >> 2 & 1) != 0) {
    ThermalPolicyManager();
    Thermal_Logic_Flag = Thermal_Logic_Flag & 0xfb;
  }
  if ((Manual_Mode_Timer != '\0') && ((Thermal_Logic_Flag & 8) != 0)) {
    Manual_Mode_Timer = Manual_Mode_Timer + -1;
    Thermal_Logic_Flag = Thermal_Logic_Flag & 0xf7;
  }
  if ((EC_Status == '3') || ((Fan_Kill_Switch & 1) != 0)) {
    Fan_Kill_Switch = Fan_Kill_Switch | 4;
    FanPWM = 0;
    return;
  }
  Fan_Kill_Switch = Fan_Kill_Switch & 0xfb;
  if (Fan_PWM_Override != 0) {
    if (MaxPWM < Fan_PWM_Override) {
      FanPWM = MaxPWM;
      return;
    }
    FanPWM = Fan_PWM_Override;
    return;
  }
  Current_RPM = (uint)_EC_FanRPM;
  if ((Current_RPM == 0) && (_EC_TargetRPM != 0)) {
    Fan_Kickstart_14_PWM();
    return;
  }
  if (Current_RPM + 10 < (uint)_EC_TargetRPM) {
    if ((FanPWM < MaxPWM) && (FanRampUpFlag = FanRampUpFlag + 1, 1 < FanRampUpFlag)) {
      FanRampUpFlag = 0;
      FanPWM = FanPWM + 1;
      return;
    }
  }
  else if (((_EC_TargetRPM + 10 < Current_RPM) && (FanPWM != 0)) &&
          (FanRampDownFlag = FanRampDownFlag + 1, 1 < FanRampDownFlag)) {
    FanPWM = FanPWM - 1;
    FanRampDownFlag = 0;
  }
  return;
}

