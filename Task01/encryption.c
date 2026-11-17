#include <stdio.h>
void encrypt_message(const char *s){printf("Encryption library v1: ");while(*s)putchar((unsigned char)*s++ ^ 0x20);putchar('\n');}
