#define __init_c
#include "includeAll.h"
//=============================================================================
void SysInit() {
   F_clearWDT();  //启动后立即清除看门狗
  //时钟初始化
   CLKCON = 0x03; // Clock div 1  7.3728Mhz
  STPPCK = 0;
  STPFCK = 0;
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  SELFCK = 1;
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();

  // IO 模式初始化
  P1MODL = 0xaa;   //P10 初始化为输出
  // IO 状态初始化
  F_ledOff();
  //初始化 T2 定时器，设置为 1ms 中断一次；
  // T2 初始化  7.3728Mhz/2 = 3686400Hz
  //  3686400Hz/3686.4 = 1000Hz = 1ms timer2 interrupt
  TH2 = (65536 - 3686) / 256;
  RCP2H = TH2;
  TL2 = (65536 - 3686) % 256;
  RCP2L = TL2;
  TR2 = 1;
  ET2 = 1;
  EA = 1;
}
//=============================================================================
void VarsInit() {} 