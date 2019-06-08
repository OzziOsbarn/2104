/*******************************************************************************
*
* Copyright (C) 2019 TUSUR, FB, Osipov Daniil
*
* File              : main.cpp
* Compiler          : IAR EWB IDE 8.32
* Version           : 1.0
* Created File      : 07.06.2019
* Last modified     : 07.06.2019
*
* Support mail      : stalkerkop@mail.ru
* Target MCU        : MCU: Milandr 1986BE9x
*
* Description       : Work with stack
*
********************************************************************************/
#include <stdlib.h>
#include <stdio.h>

int recursion(void){
  return recursion();
}

int send_params1(int a, int b, int c, int d, int e, int f){
  return (a+b+c+d+e+f);    
}
int send_params2(int a[5])
{
  return (a[0]+a[1]+a[2]+a[3]+a[4]);
}

int main() {
  int sum=0;
  int input=6;
  switch( input )
  {
  case 0://add new data in stack
    __asm(
          "MOV R13, #9999"
            );
    break;
  case 1://push overflow
      while(1)
      {
        __asm(
              "PUSH {R1}" 
                );
      }
      break;
  case 2://change top of stack
    __asm(
          "MOV R1, #1024\n"
           "ADD R13, R1"
              );
    break;
  case 3://recursion overflow 
    recursion();
    break;
  case 4://Stack params type 1
    sum = send_params1(0x1,0x2,0x3,0x4,0x5,0x6);
    break;
  case 5://Stack params type 2
    int array[5] = {1,2,3,4,5};
    sum = send_params2(array);
    break;
  case 6://Two stack pointer
    __asm("MOV R0, #0x2 \n" "MSR CONTROL, R0");
    break;
  case 7://
    asm(
        "MOV R13, #9999 \n"
          "ADD R13, R1 \n"
            );
    
    break;
  }

  return 0;
}