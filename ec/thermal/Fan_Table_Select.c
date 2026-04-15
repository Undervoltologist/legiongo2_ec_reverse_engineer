
/* WARNING: Instruction at (ram,0x00009f74) overlaps instruction at (ram,0x00009f72)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00009f3e) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Fan_Table_Select(void)

{
  uint uVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  undefined *unaff_fp;
  int unaff_gp;
  
  if ((Fan_Mode & 1) == 0) {
    iVar3 = unaff_gp + 0x82a4;
LAB_00011f4a:
    *(int *)(&LAB_000085ac + unaff_gp) = iVar3;
    return;
  }
  *(int *)(&LAB_000085a8 + unaff_gp) = unaff_gp + 0x8514;
  if (3 < DAT_00100678 - 0xb0) {
    iVar3 = unaff_gp + 0x8340;
    goto LAB_00011f4a;
  }
  puVar2 = (undefined *)(uint)*(byte *)(DAT_00100678 + 0x9e80);
  iVar3 = 0x100000;
  switch(DAT_00100678) {
  case 0xb0:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  default:
    if (_DAT_001011a0 % 100 == 0x21) {
      _DAT_001011c0 = _DAT_001011c0 + 1;
    }
    if (_DAT_001011a0 % 100 == 0x42) {
      _DAT_001011c4 = _DAT_001011c4 + 1;
    }
    puVar2 = &DAT_00101000;
    if (_DAT_001011a0 % 500 != 0) goto LAB_00009f98;
    unaff_fp = &DAT_00101000;
    iVar3 = _DAT_001011c8;
switchD_00011f2e_caseD_b3:
    *(int *)(unaff_fp + 0x1c8) = iVar3 + 1;
LAB_00009f98:
    if (*(uint *)(puVar2 + 0x1a0) % 500 == 0xa0) {
      _DAT_001011cc = _DAT_001011cc + 1;
    }
    if (_DAT_001011a0 % 500 == 0x140) {
      _DAT_001011d0 = _DAT_001011d0 + 1;
    }
    if (_DAT_001011a0 % 1000 == 0) {
      _DAT_001011d4 = _DAT_001011d4 + 1;
    }
    if (_DAT_001011a0 % 1000 == 0x14a) {
      _DAT_001011d8 = _DAT_001011d8 + 1;
    }
    if (_DAT_001011a0 % 1000 == 0x294) {
      _DAT_001011dc = _DAT_001011dc + 1;
    }
    uVar4 = _DAT_001011a0 / 60000;
    uVar1 = _DAT_001011a0 % 60000;
    if (uVar1 == 0) {
      uVar4 = _DAT_001011a4 + 1;
      _DAT_001011a0 = uVar1;
      _DAT_001011a4 = uVar4;
    }
    FUN_0000a75a(uVar1,uVar4);
    return;
  case 0xb3:
    goto switchD_00011f2e_caseD_b3;
  }
}

