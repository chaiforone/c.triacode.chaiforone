#ifndef TRIA_CODE_C_INCLUDED
#define TRIACODECONFIG_C_INCLUDED

#include <stdio.h>
#include "triacode.h"
//int tria_code_show =1;

void tria_code_combine_mode(void)
{

  if(TRIA_CODE_SHOW_MSG)
  {
    switch(TRIA_CODE_COMBINE_MODE_IS)
    {
      case TRIA_CODE_MODE_BALANCE1:
        printf("%s", "TriaCode mode : Blance1\n");
      break;
      case TRIA_CODE_MODE_BALANCE2:
        printf("%s", "TriaCode mode : Blance2\n");
      break;
      case TRIA_CODE_MODE_NAGATIVE:
        printf("%s", "TriaCode mode : Nagative\n");
      break;
      case TRIA_CODE_MODE_POSITIVE:
        printf("%s", "TriaCode mode : Positive\n");
      break;
    }
  }
}


/*
 display triacode with char O,I,T,R
*/
char triacode_show(register triacode one)
{
  register unsigned char ones;
  switch(one.z)
  {
    case TRIA_CODE_QUBIT_O:
      ones = QO;
    break;
    case TRIA_CODE_QUBIT_I:
      ones = QI;
    break;
    case TRIA_CODE_QUBIT_T:
      ones = QT;
    break;
    case TRIA_CODE_QUBIT_R:
      ones = QR;
    break;
  }
  if(TRIA_CODE_SHOW_MSG)
  {
//		printf("%c", ones);
  }
  return ones;
}


/*
triacode ternary not operator
*/
triacode triacode_not(register triacode one)
{
  register triacode two;
  if (TRIA_CODE_SHOW_MSG)
  {
    printf("tria code not input:%d\n", one.z);
  }
  //#define TRIA_CODE_SHOW_MSG  TRIA_CODE_SHOW_DISABLE
  two = triacode_combine(one);
  //#define	TRIA_CODE_SHOW_MSG  TRIA_CODE_SHOW_ENABLE
  OX = TY;
  OY = TX;
  return one;

}

/*
combine QUBIT CODE to TRIA CODE
*/
triacode triacode_combin(register triacodebit x, register triacodebit y)
{
  //	if(NULL == one){return 1;}
  if (TRIA_CODE_SHOW_MSG)
  {
    //        printf("tria code combine input:%d\n", one.z );
  }
  //   triacode* two = malloc(sizeof(one));

  register triacode one;
  one.z = 0;
  OX = (x.u & y.u) ^ x.u;
  OY = (x.u & y.u) ^ y.u;
 
  if (TRIA_CODE_SHOW_MSG)
  {
    //    printf("triacode_combine output:%d\n", one.z );
  }
  //	free(two);
  return one;

}

/*
combine QUBIT CODE to TRIA CODE
*/
triacode triacode_combine(register triacode one)
{
  //	if(NULL == one){return 1;}
  if (TRIA_CODE_SHOW_MSG)
  {
    //        printf("tria code combine input:%d\n", one.z );
  }
  //   triacode* two = malloc(sizeof(one));

  register triacode two;
  TX = (OX & OY) ^ OX;
  TY = (OX & OY) ^ OY;
  OX = TX;
  OY = TY;

  if (TRIA_CODE_SHOW_MSG)
  {
    //    printf("triacode_combine output:%d\n", one.z );
  }
  //	free(two);
  return one;

}




/*
change triacode balance1 mode to nagative;
*/
triacode triacode_balance1(register triacode one)
{
  register triacode two;
  two.z = 0;
  printf("triacode_balance1 input= x/y=%d/%d, z=%c ,out=", OX, OY,triacode_show(one));
  TX = (~(OX & OY) & (OX & OY)) | ((OX & OY) & (OX));
  TY = (~(OX & OY) & (OX | OY)) | ((OX & OY) & (~OX));
  printf("x/y=%d/%d,z=%c \n", TX,TY,triacode_show(two));
  return two;
}

/*
change triacode balance2 mode to nagative;
*/
triacode triacode_balance2(register triacode one)
{
  register triacode two;
  two.z = 0;
  printf("triacode_balance2 input= x/y=%d/%d, z=%c ,out=", OX, OY, triacode_show(one));
  TX = (~(OX & OY) & (OX | OY)) | ((OX & OY) & (~OX));
  TY = (~(OX & OY) & (OX & OY)) | ((OX & OY) & (OX));
  printf("x/y=%d/%d,z=%c \n", TX, TY, triacode_show(two));
  return two;
}

/*
change triacode positive mode to nagative;
*/
triacode triacode_positive(register triacode one)
{
  register triacode two;
  two.z = 0;
  printf("triacode_positive input= x/y=%d/%d, z=%c ,out=", OX, OY, triacode_show(one));
  two = triacode_not(triacode_combine(one));
  printf("x/y=%d/%d,z=%c \n", TX, TY, triacode_show(two));
  return two;

}

/*
change triacode positive mode to nagative;
*/
triacode triacode_nagative(register triacode one)
{
  register triacode two;
  two.z = 0;
  printf("triacode_nagative input= x/y=%d/%d, z=%c ,out=", OX, OY, triacode_show(one));
  two = triacode_combine(one);
  printf("x/y=%d/%d,z=%c \n", TX, TY, triacode_show(two));
  return two;

}

/*
change triacode positive mode to nagative;
*/
triacode triacode_change_mode(mode triacodemode, register triacode one)
{
  register triacode two;
  two.z = 0;
  switch (triacodemode) 
  {
  case balance1:
    two = triacode_balance1(one);
    break;
  case positive:
    two = triacode_positive(one);
    break;
  case nagative:
    two = triacode_nagative(one);
    break;
  case balance2:
    two = triacode_balance2(one);
    break;
  }
  return two;
}


/*
  triacode ternary and operator
  and:
    T 0 1
  T T T T
  0 T 0 0
  1 T 0 I
*/
triacode triacode_and(register triacode a, register triacode b)
{
  register triacode one;
//  triacode two;
// RX = (AX & AY) | (BX & BY);
// TY = AX | AY | BX | BY;
// OX = (AX & BX);
// OY = (AY | BY);
  OX = (~RX) & (AX & BX) | (RX & QX);
  OY = (~RX) & (AY | BY) | (RX & AY & BY);

  if(TRIA_CODE_SHOW_MSG)
  {
    printf("tria code logic: tria and( a=%c, b=%c )", triacode_show(a), triacode_show(b) );
    printf(" =>  c=%c ", triacode_show(one));
    printf(" ( rx = %d ,qx=%d, qy=%d )\n", RX, QX, QY);
  }
  return one;
}

/*
  triacode ternary or operator
  or:
    T 0 1
  T T 0 1
  0 0 0 1
  1 1 1 1
*/
triacode triacode_or(register triacode a, register triacode b)
{
  register triacode one;
//  triacode two;
//  OX = (AX | BX);
//  OY = (AY & BY);
  OX = (~RX) & (AX | BX) | (RX & AX & BX);
  OY = (~RX) & (AY & BY) | (RX & QX) ;
  if(TRIA_CODE_SHOW_MSG)
  {
    printf("tria code logic: tria or( a=%c, b=%c )", triacode_show(a), triacode_show(b) );
    printf(" =>  c=%c ", triacode_show(one));
    printf(" ( rx = %d ,qx=%d, qy=%d )\n", RX, QX, QY);
  }
  return one;
}


/*
  triacode ternary xand operator
  xand:
    T 0 1
  T I 0 T
  0 0 0 0
  1 T 0 I
*/
triacode triacode_xand(register triacode a,register triacode b)
{
  register triacode one;
  OX = (~RX) & ((AX & BX) | (AY & BY));
  OY = (~RX) & ((AX & BY) | (AY & BX));
  if(TRIA_CODE_SHOW_MSG)
  {
    printf("tria code logic: tria xand( a=%c, b=%c )", triacode_show(a), triacode_show(b) );
    printf(" =>  c=%c ", triacode_show(one));
    printf(" ( rx = %d ,qx=%d, qy=%d )\n", RX, QX, QY);
  }
  return one;
}

/*
  triacode ternary xor operator
  xor:
    T 0 1
  T T 0 1
  0 0 0 0
  1 1 0 T
*/
triacode triacode_xor(register triacode a, register triacode b)
{
  register triacode one;
  OX = (~RX) & ((AX | BX) & (AY | BY));
  OY = (~RX) & ((AX | BY) & (AY | BX));
//  OY = (~RX) & ((AY | BY) & (AY | BX));
  if(TRIA_CODE_SHOW_MSG)
  {
    printf("tria code logic: tria xor( a=%c, b=%c )", triacode_show(a), triacode_show(b) );
    printf(" =>  c=%c ", triacode_show(one));
    printf(" ( rx = %d ,qx=%d, qy=%d )\n", RX, QX, QY);
  }
  return one;
}

/*
  triacode ternary mand operator
  mand:
    T 0 1
  T T 0 0
  0 0 0 0
  1 0 0 1
*/
triacode triacode_mand(register triacode a, register triacode b)
{
  register triacode one;
  OX = (~RX) & (AX & BX);
  OY = (~RX) & (AY & BY);
  if(TRIA_CODE_SHOW_MSG)
  {
    printf("tria code logic: tria mand( a=%c, b=%c )", triacode_show(a), triacode_show(b) );
    printf(" =>  c=%c ", triacode_show(one));
    printf(" ( rx=%d,ry=%d,qx=%d,qy=%d )\n", RX, RY, QX, QY);
  }

//  printf("tria code logic: tria mand( a=%c=%d, b=%c=%d )", triacode_show(a),a.z, triacode_show(b),b.z);
//  printf(" =>  c=%c  one.z=%d, one=%d", triacode_show(one), one.z,one);
//  printf(" ( rx=%d,ry=%d,qx=%d,qy=%d )\n", RX, RY, QX, QY);
  return one;
}

/*
  triacode ternary mor operator
  mor:
    T 0 1
  T T T 0
  0 T 0 1
  1 0 1 1
*/
triacode triacode_mor(register triacode a, register triacode b)
{
  register triacode one;
  OX = (~RX) & ((~RY) & (AX | BX) | (RY) & (AX & BX)) | (RX & (AX & BX));
  OY = (~RX) & ((~RY) & (AY | BY) | (RY) & (AY & BY)) | (RX & (AY & BY));
  if(TRIA_CODE_SHOW_MSG)
  {
    printf("tria code logic: tria mor( a=%c, b=%c )", triacode_show(a), triacode_show(b) );
    printf(" =>  c=%c ", triacode_show(one));
    printf(" ( rx=%d,ry=%d,qx=%d,qy=%d )\n", RX, RY, QX, QY);
  }
  return one;
}

/*
  triacode ternary sum operator
  sum:
    T 0 1
  T I T 0
  0 T 0 1
  1 0 I T
*/
triacode triacode_sum(register triacode a, register triacode b)
{
  register triacode one;
//#define RX    ((AX & AY) | (BX & BY))
//#define RY    ((AX | AY) & (BX | BY))
//#define QX    (AX & AY & BX & BY)
//#define QY    (AX | AY | BX | BY)
//  OX = ((AX & BX) | (AY & BY)) & (AY | BY) | ((~(AX & BX | AY & BY)) & (AX + BX));
//  OY = ((AX & BX) | (AY & BY)) & (AX | BX) | ((~(AX & BX | AY & BY)) & (AY | BY));
  //  c = (a*b+a'*b')*(a'+b')+(~(a*b+a'*b'))*(a+b)
//  c' = (a*b)+(a'*b')*(a+b)+(~(a*b+a'*b'))*(a' + b')
//  one = triacode_combine(one);
  OX = ((~RX) & ((RY) & (AY & BY) | (~RY) & (AX | BX))) | ((RX) & ((AX & AY) & (AY & BX) | (~(AX & AY) & (AX & BY))));
  OY = ((~RX) & ((RY) & (AX & BX) | (~RY) & (AY | BY))) | ((RX) & ((AX & AY) & (AX & BY) | (~(AX & AY) & (AY & BX))));
//  one.u.x = ((((AX & BX) | (AY & BY)) & (AY | BY)) \
//         |((~((AX & BX) | (AY) & BY))) & (AX | BX));
//  one.u.y = (((AX & BX) | (AY & BY) & (AX |BX)) \
//         |((~((AX & BX) | (AY & BY))) & (AY | BY)));
/*
if(TRIA_CODE_SHOW_MSG)
{
printf("tria code logic: tria sum( a=%c, b=%c )", triacode_show(a), triacode_show(b) );
printf(" =>  c=%c ", triacode_show(one));
printf(" ( rx=%d,ry=%d,qx=%d,qy=%d )\n", RX, RY, QX, QY);
}

*/
  return one;
}

/*
  triacode ternary sub operator

  sub:
    T 0 1
  T T I 0
  0 I 0 T
  1 0 T I
*/
triacode triacode_sub(register triacode a, register triacode b)
{

  //#define RX    ((AX & AY) | (BX & BY))
  //#define RY    ((AX | AY) & (BX | BY))
  //#define QX    (AX & AY & BX & BY)
  //#define QY    (AX | AY | BX | BY)
  register triacode one;
//  OX = ((~RX) & ((RY)& (AY & BY) | (~RY) & (AX | BX))) | ((RX)& ((AX & AY) & (AY & BX) | (~(AX & AY) & (AX & BY))));
//  OY = ((~RX) & ((RY)& (AX & BX) | (~RY) & (AY | BY))) | ((RX)& ((AX & AY) & (AX & BY) | (~(AX & AY) & (AY & BX))));
//  c = (~(a*b + a'*b')*(a'+b')) + (a*b + a'*b')*(a + b)
 //   c' = (~(a*b)+(a'*b')*(a+b))+(a*b+a'*b')*(a' + b')
//  OX = ((~RX) & ((RY)& (AX & BX) | (~RY) & (AY | BY))) | ((RX) & ((AX & AY) & (AY & BX) | (~(AX & AY) & (AX & BY))));
//  OY = ((~RX) & ((RY)& (AY & BY) | (~RY) & (AX | BX))) | ((RX) & ((AX & AY) & (AX & BY) | (~(AX & AY) & (AY & BX))));

  OX = ((~RX) & ((RY)& (AX & BX) | (~RY) & (AY | BY))) | ((RX)& ((AX & AY) & (AX & BY) | (~(AX & AY) & (AY & BX))));
  OY = ((~RX) & ((RY)& (AY & BY) | (~RY) & (AX | BX))) | ((RX)& ((AX & AY) & (AY & BX) | (~(AX & AY) & (AX & BY))));

//    one.u.x = (((((a.u.x) & (b.u.x)) | ((a.u.y) & (b.u.y))) & ((a.u.y) | (b.u.y))) \
//   |((~(((a.u.x) & (b.u.x)) | ((a.u.y) & (b.u.y)))) & ((a.u.x) | (b.u.x))));
//   one.u.y = ((((a.u.x) & (b.u.x)) | ((a.u.y) & (b.u.y)) & ((a.u.x) |( b.u.x))) \
//   |((~(((a.u.x) & (b.u.x)) | ((a.u.y) & (b.u.y)))) & ((a.u.y) | (b.u.y))));
  if(TRIA_CODE_SHOW_MSG)
  {
   printf("tria code logic: tria sub( a=%c, b=%c )", triacode_show(a), triacode_show(b) );
   printf(" =>  c=%c ", triacode_show(one));
   printf(" ( rx=%d,ry=%d,qx=%d,qy=%d )\n", RX, RY, QX, QY);
  }
  return one;
}

triacodes triacode_adder(register triacode a, register triacode b)
{
  register triacodes two;
  register triacode one1;
  register triacode one2;
  two.z = 0;
  one1 = triacode_mand(a, b);
  two.u.cx = one1.u.x;
  two.u.cy = one1.u.y;
  one2 = triacode_sum(a, b);
  two.u.sx = one2.u.x;
  two.u.sy = one2.u.y;
  printf("a=%d,b=%d,c=%d, %c + %c = %c%c \n", a.z, b.z, two.z, triacode_show(a), triacode_show(b), triacode_show(one1), triacode_show(one2));
  return  two;
}

/*
sums:
X T 0 1
T I T 0
0 T 0 1
1 0 I T
*/
triacode triacode_sums(register triacode a, register triacode b, register triacode c)
{
  register triacode one;
  one.z = 0;
  one = triacode_sum(triacode_sum(a, b), c);
  printf("a=%d,b=%d,c=%d, %c + %c + %c = %c \n", a.z, b.z, c.z, triacode_show(a), triacode_show(b), triacode_show(c), triacode_show(one));
  return one;
}

triacode triacode_cary(register triacode a, register triacode b, register triacode c)
{
  printf("%c + %c + %c  : ", triacode_show(a), triacode_show(b), triacode_show(c));
  a = triacode_combine(a);
  b = triacode_combine(b);
  c = triacode_combine(c);
  register triacode one;
  one.z = 0;
  one.u.x = (AXXX | AYYY) & (OXXX) | ((XXXX | XYYY) & AXXX) | (~(XXXX | XYYY) & OXXX);
  one.u.y = (AXXX | AYYY) & (OYYY) | ((XXXX | XYYY) & AYYY) | (~(XXXX | XYYY) & OYYY);
  printf("a=%d,b=%d,c=%d, %c + %c + %c = %c \n", a.z, b.z, c.z, triacode_show(a), triacode_show(b), triacode_show(c), triacode_show(one));
  return one;
}

triacodes triacode_adders(register triacode a, register triacode b, register triacode c)
{
  register triacodes two;
  register triacode one1;
  register triacode one2;
  two.z = 0;
  one1 = triacode_cary(a, b, c);
  two.u.cx = one1.u.x;
  two.u.cy = one1.u.y;
  one2 = triacode_sums(a, b, c);
  two.u.sx = one2.u.x;
  two.u.sy = one2.u.y;
  printf("adders: a=%d,b=%d,c=%d, %c + %c +%c= %c%c \n", a.z, b.z, c.z, triacode_show(a), triacode_show(b), triacode_show(c), triacode_show(one1), triacode_show(one2));
  return  two;
}

triacode8s triacode_adder8(register triacode a, register triacode b)
{
  register triacode8s two;
  register triacode one1;
  register triacode one2;
  two.z = 0;
  one1 = triacode_mand(a, b);
  two.u.x2 = one1.u.x;
  two.u.y2 = one1.u.y;
  one2 = triacode_sum(a, b);
  two.u.x1 = one2.u.x;
  two.u.y1 = one2.u.y;
  
  printf("a=%d,b=%d,c=%d, %c + %c = %c%c \n", a.z, b.z, two.z, triacode_show(a), triacode_show(b), triacode_show(one1), triacode_show(one2));
  return  two;
}

/*
triacodes2 triacode_adder(triacode a, triacode b)
{
  triacodes2 two;
  two.d.c = triacode_mand(a, b);
 printf(" tria add( two.d.c=%d \n", two.d.c.z);
  two.d.s = triacode_sum(a, b);
  printf(" tria add( two.d.s=%d \n", two.d.s.z);
  printf(" tria add( two.z=%d \n", two.z);
 // printf("tria code logic: tria add( a=%c, b=%c ) =", triacode_show(a), triacode_show(b));
 // printf("add=%d c=%c\,s=%c, to=%d\n" ,two, triacode_show(two.d.c), triacode_show(two.d.s),two.z);
  return two;
}

*/
#endif // TRIA_CODE_C_INCLUDED
