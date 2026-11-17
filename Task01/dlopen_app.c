#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
typedef void(*fn)(const char*);
int main(int c,char**v){const char*p=c>1?v[1]:"./libencrypt.so";void*h=dlopen(p,RTLD_NOW);if(!h){fprintf(stderr,"dlopen: %s\n",dlerror());return 2;}dlerror();fn f=(fn)dlsym(h,"encrypt_message");const char*e=dlerror();if(e){fprintf(stderr,"dlsym: %s\n",e);dlclose(h);return 3;}f("BANK-TRANSACTION");printf("PID %ld; see /proc/%ld/maps\n",(long)getpid(),(long)getpid());FILE*m=fopen("/proc/self/maps","r");if(m){char b[512];while(fgets(b,sizeof b,m))fputs(b,stdout);fclose(m);}dlclose(h);return 0;}
