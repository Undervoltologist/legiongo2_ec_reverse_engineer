
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void GetFanRPM(void)

{
  uint uVar1;
  
  _EC_FanRPM = (ushort)FanRPM_LO;
  if (((FanRPM_HI != 0) || (FanRPM_LO != 0)) &&
     (uVar1 = 0x20e6da / (ushort)((ushort)FanRPM_LO + (ushort)FanRPM_HI * 0x100) & 0xffff,
     _EC_FanRPM = (ushort)uVar1, 10000 < uVar1)) {
    _EC_FanRPM = 10000;
  }
  return;
}

