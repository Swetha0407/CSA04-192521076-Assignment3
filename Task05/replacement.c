#include <stdio.h>
#define MAXF 8
int find(const int f[],int n,int p){for(int i=0;i<n;i++)if(f[i]==p)return i;return -1;}
int fifo(const int r[],int n,int fr){int f[MAXF],u=0,k=0,z=0;for(int i=0;i<n;i++){if(find(f,u,r[i])>=0)continue;z++;if(u<fr)f[u++]=r[i];else{f[k]=r[i];k=(k+1)%fr;}}return z;}
int lru(const int r[],int n,int fr){int f[MAXF],last[MAXF],u=0,z=0;for(int i=0;i<n;i++){int k=find(f,u,r[i]);if(k>=0){last[k]=i;continue;}z++;if(u<fr){f[u]=r[i];last[u++]=i;}else{int v=0;for(int j=1;j<fr;j++)if(last[j]<last[v])v=j;f[v]=r[i];last[v]=i;}}return z;}
int opt(const int r[],int n,int fr){int f[MAXF],u=0,z=0;for(int i=0;i<n;i++){if(find(f,u,r[i])>=0)continue;z++;if(u<fr){f[u++]=r[i];continue;}int v=0,far=-1;for(int j=0;j<fr;j++){int nx=n;for(int t=i+1;t<n;t++)if(r[t]==f[j]){nx=t;break;}if(nx>far){far=nx;v=j;}}f[v]=r[i];}return z;}
int main(void){int r[]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1},b[]={1,2,3,4,1,2,5,1,2,3,4,5};for(int f=3;f<=4;f++)printf("%d frames: FIFO %d, LRU %d, Optimal %d\n",f,fifo(r,20,f),lru(r,20,f),opt(r,20,f));printf("Belady string, FIFO: 3 frames %d faults, 4 frames %d faults\n",fifo(b,12,3),fifo(b,12,4));}
