#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/resource.h>
int main(void){size_t n=32*1024*1024,ps=sysconf(_SC_PAGESIZE);volatile char*p=malloc(n);if(!p)return 1;for(size_t i=0;i<n;i+=ps)p[i]=1;struct rusage r;getrusage(RUSAGE_SELF,&r);printf("Before fork maxRSS=%ldKB minor=%ld\n",r.ru_maxrss,r.ru_minflt);pid_t x=fork();if(x==0){for(size_t i=0;i<n;i+=ps)p[i]=2;getrusage(RUSAGE_SELF,&r);printf("Child after writes maxRSS=%ldKB minor=%ld\n",r.ru_maxrss,r.ru_minflt);fflush(stdout);_exit(0);}if(x<0){perror("fork");return 1;}waitpid(x,0,0);free((void*)p);return 0;}
