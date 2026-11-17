#include <stdio.h>
int main(void){volatile int*p=(int*)0;puts("Triggering invalid access");*p=1;return 0;}
