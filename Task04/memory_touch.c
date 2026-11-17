#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <time.h>
static double tm(void){struct timespec t;clock_gettime(CLOCK_MONOTONIC,&t);return t.tv_sec+t.tv_nsec/1e9;}
int main(int c,char**v){size_t mb=c>1?strtoull(v[1],0,10):128,n=mb*1024*1024,ps=sysconf(_SC_PAGESIZE);unsigned char*p=malloc(n);if(!p){perror("malloc");return 1;}struct rusage a,b;getrusage(RUSAGE_SELF,&a);double t=tm();for(size_t i=0;i<n;i+=ps)p[i]++;double d=tm()-t;getrusage(RUSAGE_SELF,&b);printf("Sequential %.6fs minor=%ld major=%ld\n",d,b.ru_minflt-a.ru_minflt,b.ru_majflt-a.ru_majflt);getrusage(RUSAGE_SELF,&a);t=tm();for(size_t i=0;i<n/ps;i++){size_t k=(i*2654435761u)%(n/ps);p[k*ps]++;}d=tm()-t;getrusage(RUSAGE_SELF,&b);printf("Random %.6fs minor=%ld major=%ld\n",d,b.ru_minflt-a.ru_minflt,b.ru_majflt-a.ru_majflt);free(p);return 0;}
