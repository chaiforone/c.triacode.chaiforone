#include <stdio.h>
#include <stdlib.h>
#include "triacode.h"
#include "main.h"



//void tria_code_combine_mode1();
int main()
{
 //   printf("%d, %d, %d, %d\n",O,I,T,R);
 //   printf("%d, %d, %d, %d\n",TRIA_CODE_MODE_BALANCE1,TRIA_CODE_MODE_BALANCE2,TRIA_CODE_MODE_NAGATIVE,TRIA_CODE_MODE_POSITIVE);
    triacode a,b,c,d;
    a.z = 1;
    b.z = 0;
    c.z = 2;
    d.z = 3;
   // c->z = 1;
    //c->z=0;
tria_code_combine_mode();

printf("triacode size %d\n", sizeof(triacode));
printf("triacodes size %d\n", sizeof(triacodes));

triacodes test;
triacode p1,p2;

test.z = 0;
p1.z = 1;
printf("z=%d,x=%d,y=%d \n", p1.z, p1.u.x, p1.u.y);
p2.z = 2;
printf("z=%d,x=%d,y=%d \n", p2.z, p2.u.x, p2.u.y);
test.u.cx = p1.u.x;
test.u.cy = p1.u.y;
test.u.sx = p2.u.x;
test.u.sy = p2.u.y;
printf("test=%d \n",test.z);
/*
unsigned char dd;
dd = 0;
test.z = 0;
printf("c=%d,s=%d \n", p1.z, p2.z);
printf("test=%d\n", test.z);
*/
//printf("triacode2 size %d\n", sizeof(triacodes2));
//triacodes2 t;
//triacode p, q;
/*
t.z = 0;
p.z = 0;
q.z = 0;
t.d.c = p;
t.d.s = q;
printf("test adder is c(%d,t.d.c=%d)+s(%d,t.d.s=%d)=c(%d)\n", p.z, t.d.c.z, q.z, t.d.s.z, t.z);

*/
printf("------------------------------------------------\n");
printf("8bit=%d, 16bit=%d", sizeof(triacode), sizeof(triacode8s));

printf("------------------------------------------------\n");
/*
triacode_balance1(a);
triacode_balance1(b);
triacode_balance1(c);
triacode_balance1(d);
printf("------------------------------------------------\n");
triacode_balance2(a);
triacode_balance2(b);
triacode_balance2(c);
triacode_balance2(d);

printf("------------------------------------------------\n");
triacode_positive(a);
triacode_positive(b);
triacode_positive(c);
triacode_positive(d);

printf("------------------------------------------------\n");
triacode_change_mode(nagative, a);
triacode_change_mode(nagative, b);
triacode_change_mode(nagative, c);
triacode_change_mode(nagative, d);

printf("------------------------------------------------\n");
triacode_change_mode(balance1, a);
triacode_change_mode(balance1, b);
triacode_change_mode(balance1, c);
triacode_change_mode(balance1, d);
printf("------------------------------------------------\n");
triacode_change_mode(balance2, a);
triacode_change_mode(balance2, b);
triacode_change_mode(balance2, c);
triacode_change_mode(balance2, d);

printf("------------------------------------------------\n");
triacode_change_mode(positive, a);
triacode_change_mode(positive, b);
triacode_change_mode(positive, c);
triacode_change_mode(positive, d);

*/


printf("------------------------------------------------\n");
triacode_adders(a, a, a);
triacode_adders(a, a, b);
triacode_adders(a, a, c);
triacode_adders(a, b, a);
triacode_adders(a, b, b);
triacode_adders(a, b, c);
/*
triacode_adders(a, c, a);
triacode_adders(a, c, b);
triacode_adders(a, c, c);
triacode_adders(b, c, c);
triacode_adders(b, b, c);
triacode_adders(c, c, c);
triacode_adders(d, d, a);
triacode_adders(d, d, b);
triacode_adders(d, d, c);
triacode_adders(b, b, b);

*/

/*
triacode_adder(a, a);
triacode_adder(a, b);
triacode_adder(a, c);
triacode_adder(b, a);
triacode_adder(b, b);
triacode_adder(b, c);
triacode_adder(c, a);
triacode_adder(c, b);
triacode_adder(c, c);
triacode_adder(d, a);
triacode_adder(d, b);
triacode_adder(d, c);
triacode_adder(a, d);
triacode_adder(b, d);
triacode_adder(c, d);
*/


getchar();
return 0;

}

/*

triacode_show(a);
triacode_show(b);
triacode_show(c);
triacode_show(d);

triacode_show(triacode_combine(a)); putchar('\n');
triacode_show(triacode_combine(b)); putchar('\n');
triacode_show(triacode_combine(c)); putchar('\n');
triacode_show(triacode_combine(d)); putchar('\n');

triacode_show(triacode_not(a)); putchar('\n');
triacode_show(triacode_not(b)); putchar('\n');
triacode_show(triacode_not(c)); putchar('\n');
triacode_show(triacode_not(d)); putchar('\n');

printf("------------------------------------------------\n");

triacode_sum(a,a);
triacode_sum(a,b);
triacode_sum(a,c);
triacode_sum(b,a);
triacode_sum(b,b);
triacode_sum(b,c);
triacode_sum(c,a);
triacode_sum(c,b);
triacode_sum(c,c);
printf("------------------------------------------------\n");
triacode_mor(a,a);
triacode_mor(a,b);
triacode_mor(a,c);
triacode_mor(b,a);
triacode_mor(b,b);
triacode_mor(b,c);
triacode_mor(c,a);
triacode_mor(c,b);
triacode_mor(c,c);
*/


