#define _GNU_SOURCE
#include <stdio.h>
#include <time.h>
#include <sys/mman.h>
#include <sys/resource.h>
#include <errno.h>
#include <string.h>
#define N 200000
static double ns(void){struct timespec t;clock_gettime(CLOCK_MONOTONIC,&t);return t.tv_sec*1e9+t.tv_nsec;}
static void test(const char*s){volatile unsigned char a[4096]={0};double max=0,sum=0;for(int i=0;i<N;i++){double x=ns();a[i%4096]++;double d=ns()-x;if(d>max)max=d;sum+=d;}printf("%s avg %.1f ns worst observed %.1f ns (not hard RT)\n",s,sum/N,max);}
int main(void){test("without mlockall");if(mlockall(MCL_CURRENT|MCL_FUTURE)==0){puts("mlockall succeeded");test("with mlockall");}else printf("mlockall failed: %s\n",strerror(errno));struct rlimit r;if(getrlimit(RLIMIT_MEMLOCK,&r)==0)printf("RLIMIT_MEMLOCK soft=%ld hard=%ld\n",(long)r.rlim_cur,(long)r.rlim_max);return 0;}
