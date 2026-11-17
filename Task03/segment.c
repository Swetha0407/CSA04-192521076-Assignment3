#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
typedef struct{unsigned base,limit;const char*name;}Seg;
int main(void){Seg s[]={{10000,4095,"code"},{20000,8191,"data"},{40000,2047,"stack"}};unsigned a[][2]={{0,0},{0,4095},{0,4096},{1,500},{1,8192},{2,2047}};for(int i=0;i<6;i++){unsigned n=a[i][0],o=a[i][1];if(n>=3)puts("invalid segment");else if(o>s[n].limit)printf("(%u,%u): protection fault (limit %u)\n",n,o,s[n].limit);else printf("(%u,%u) %s: physical %u\n",n,o,s[n].name,s[n].base+o);}printf("\n/proc/%ld/maps\n",(long)getpid());FILE*f=fopen("/proc/self/maps","r");if(f){char b[512];while(fgets(b,sizeof b,f))fputs(b,stdout);fclose(f);}return 0;}
