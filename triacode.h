#ifndef TRIACODE_H_INCLUDED
#define TRIACODE_H_INCLUDED

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "triacodeconfig.h"

#define UNIT8  unsigned char

#define TRIA_CODE_BIT_0            0b0
#define TRIA_CODE_BIT_1            0b1

#define BT  TRIA_CODE_BIT_1
#define BF  TRIA_CODE_BIT_0

#define TRIA_CODE_QUBIT_O          0b00  //b00
#define TRIA_CODE_QUBIT_I          0b01  //b01
#define TRIA_CODE_QUBIT_T          0b10  //b10
#define TRIA_CODE_QUBIT_R          0b11  //b11

#define O   TRIA_CODE_QUBIT_O
#define I   TRIA_CODE_QUBIT_I
#define T   TRIA_CODE_QUBIT_T
#define R   TRIA_CODE_QUBIT_R

#define QO           'O'
#define QI           'I'
#define QT           'T'
#define QR           'R'

#define TRIA_BIT_SIZE           I
#define TRIA_TRIT_SIZE          T
//#define TRIA_TRIT_SIZE2   4


#define TRIA_CODE_MODE_BALANCE1     O
#define TRIA_CODE_MODE_POSITIVE     I
#define TRIA_CODE_MODE_NAGATIVE     T     //default mode
#define TRIA_CODE_MODE_BALANCE2     R

#define TRIA_CODE_LOGIC_NO          O
#define TRIA_CODE_LOGIC_YES         I
#define TRIA_CODE_LOGIC_NONE        T

#define TRIA_CODE_NAGATIVE_0        O       // 0 = b[00] = t[0]
#define TRIA_CODE_NAGATIVE_1        I       // 0 = b[01] = t[1]
#define TRIA_CODE_NAGATIVE_T        T       // 0 = b[10] = t[T]
#define TRIA_CODE_NAGATIVE_R        R       // 0 = b[11] = t[R]

#define TRIA_CODE_POSITIVE_0        O       // 0 = b[00] = t[0]
#define TRIA_CODE_POSITIVE_1        T       // 0 = b[10] = t[1]
#define TRIA_CODE_POSITIVE_T        I       // 0 = b[01] = t[T]
#define TRIA_CODE_POSITIVE_R        R       // 0 = b[11] = t[R]

#define TRIA_CODE_BALANCE1_0        O         // 0 = b[00] = t[0]
#define TRIA_CODE_BALANCE1_1        I        // 0 = b[01] = t[1]
#define TRIA_CODE_BALANCE1_I        T        // 0 = b[10] = t[1]
#define TRIA_CODE_BALANCE1_T        R        // 0 = b[11] = t[T]

#define TRIA_CODE_BALANCE2_0        O         // 0 = b[00] = t[0]
#define TRIA_CODE_BALANCE2_T        I        // 0 = b[01] = t[T]
#define TRIA_CODE_BALANCE2_U        T        // 0 = b[10] = t[T]
#define TRIA_CODE_BALANCE2_1        R        // 0 = b[11] = t[1]

#define TRIA_CODE_SHOW_ENABLE       TRIA_CODE_LOGIC_YES
#define TRIA_CODE_SHOW_DISABLE      TRIA_CODE_LOGIC_NO

#define TRIA_CODE_COMBINE_MODE_IS   TRIA_CODE_MODE_NAGATIVE
//#define TRIA_CODE_COMBINE_MODE_IS TRIA_CODE_MODE_POSITIVE

//#define TRIA_CODE_SHOW_MSG  TRIA_CODE_SHOW_ENABLE
#define TRIA_CODE_SHOW_MSG          TRIA_CODE_SHOW_DISABLE

#define AX       (a.u.x)
#define AY       (a.u.y)
#define BX       (b.u.x)
#define BY       (b.u.y)
#define CX       (c.u.x)
#define CY       (c.u.y)
#define DX       (d.u.x)
#define DY       (d.u.y)
#define OX       (one.u.x)
#define OY       (one.u.y)
#define TX       (two.u.x)
#define TY       (two.u.y)
#define RX       ((AX & AY) | (BX & BY))
#define RY       ((AX | AY) & (BX | BY))
#define QX       (AX & AY & BX & BY)
#define QY       (AX | AY | BX | BY)
#define AND      &
#define OR       |
#define XOR      ^
#define OXXX      (AX | BX | CX)
#define OYYY      (AY | BY | CY)
#define AXXX      (AX & BX & CX)
#define AYYY      (AY & BY & CY)
#define XXXX      (AX ^ BX ^ CX)
#define XYYY      (AY ^ BY ^ CY)

typedef enum triacode_mode
{
  balance1 = TRIA_CODE_MODE_BALANCE1,
  positive = TRIA_CODE_MODE_POSITIVE,
  nagative = TRIA_CODE_MODE_NAGATIVE,
  balance2 = TRIA_CODE_MODE_BALANCE2
} mode;

/*
qubit
b = 0 
b = 1 
*/
typedef struct tria_code_bit 
{
  unsigned char u : TRIA_BIT_SIZE;
} triacodebit;


/*
qubit 
z = 0 : x = 0 : y = 0
z = 1 : x = 1 : y = 0
z = 2 : x = 0 : y = 1
z = 3 : x = 1 : y = 1
*/
typedef struct tria_code_qubit 
{
  unsigned char x : TRIA_BIT_SIZE;
  unsigned char y : TRIA_BIT_SIZE;
} triacodequbit;

typedef union tria_code_one 
{
  unsigned char  z : TRIA_TRIT_SIZE;
  triacodequbit  u;
} triacode;

typedef struct tria_code_qubits 
{
  unsigned char sx : TRIA_BIT_SIZE;
  unsigned char sy : TRIA_BIT_SIZE;
  unsigned char cx : TRIA_BIT_SIZE;
  unsigned char cy : TRIA_BIT_SIZE;

} triacodequbits;

typedef struct tria_code_8bits
{
  unsigned char x1 : TRIA_BIT_SIZE;
  unsigned char y1 : TRIA_BIT_SIZE;
  unsigned char x2 : TRIA_BIT_SIZE;
  unsigned char y2 : TRIA_BIT_SIZE;
  unsigned char x3 : TRIA_BIT_SIZE;
  unsigned char y3 : TRIA_BIT_SIZE;
  unsigned char x4 : TRIA_BIT_SIZE;
  unsigned char y4 : TRIA_BIT_SIZE;
}triacode8bits;


typedef union tria_codes{
  unsigned char   z;
  triacodequbits  u;
} triacodes;

typedef union tria_codes_8bits {
  unsigned char   z;
  triacode8bits   u;
} triacode8s;

typedef union tria_codes_16bits {
  unsigned short   z;
  triacode8bits    u;
} triacode16s;


void tria_code_combine_mode();

triacode triacode_balance1(triacode); 
triacode triacode_balance2(triacode);
triacode triacode_positive(triacode);

triacode triacode_change_mode(mode, triacode);

triacode triacode_combin(triacodebit, triacodebit);
triacode triacode_combine(triacode);
triacode triacode_not(triacode);

triacode triacode_and(triacode, triacode);
triacode triacode_or(triacode, triacode);
triacode triacode_xand(triacode, triacode);
triacode triacode_xor(triacode, triacode);
triacode triacode_mand(triacode, triacode);
triacode triacode_mor(triacode, triacode);
triacode triacode_sum(triacode, triacode);
triacode triacode_sub(triacode, triacode);
triacode triacode_sums(triacode, triacode, triacode);
triacode triacode_cary(triacode, triacode, triacode);

triacodes triacode_adder(triacode, triacode);
triacodes triacode_adders(triacode, triacode, triacode);

#endif // TRIACODE_H_INCLUDED

