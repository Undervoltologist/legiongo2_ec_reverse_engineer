
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ThermalPolicyManager(void)

{
  Fan_Table_Select();
  if ((RPM_Calc_Method >> 6 & 1) == 0) {
    Get_Temperature_Data();
  }
  else {
    Get_APU_Temps();
  }
  Calculate_TargetRPM();
  if ((Overheat_Check >> 1 & 1) != 0) {
    _EC_TargetRPM = 0x12c0;
  }
  if (Hard_Fan_Kill != '\0') {
    _EC_TargetRPM = 0;
  }
  if (_Manual_RPM_Override != 0) {
    if (_Manual_RPM_Override < 0x5dc) {
      _EC_TargetRPM = 0;
    }
    else {
      _EC_TargetRPM = _Manual_RPM_Override;
      if (10000 < _Manual_RPM_Override) {
        _EC_TargetRPM = 10000;
      }
    }
  }
  return;
}

