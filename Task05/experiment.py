import random,csv,time,bisect
random.seed(192521076)
def fifo(r,n):
 q=[];k=z=0
 for x in r:
  if x in q:continue
  z+=1
  if len(q)<n:q.append(x)
  else:q[k]=x;k=(k+1)%n
 return z
def lru(r,n):
 q=[];z=0
 for x in r:
  if x in q:q.remove(x);q.append(x);continue
  z+=1
  if len(q)==n:q.pop(0)
  q.append(x)
 return z
def opt(r,n):
 pos={}
 for i,x in enumerate(r):pos.setdefault(x,[]).append(i)
 ptr={};q=[];z=0
 for i,x in enumerate(r):
  ptr[x]=ptr.get(x,0)+1
  if x in q:continue
  z+=1
  if len(q)<n:q.append(x);continue
  nxt=[]
  for y in q:
   a=pos[y];k=ptr.get(y,0);nxt.append(a[k] if k<len(a) else len(r)+1)
  q[nxt.index(max(nxt))]=x
 return z
def clock(r,n):
 q=[None]*n;b=[0]*n;h=z=0
 for x in r:
  if x in q:b[q.index(x)]=1;continue
  z+=1
  while q[h] is not None and b[h]:b[h]=0;h=(h+1)%n
  q[h]=x;b[h]=1;h=(h+1)%n
 return z
loc=[random.randrange(4) if random.random()<.85 else random.randrange(20) for _ in range(100000)]
rnd=[random.randrange(1000) for _ in range(100000)]
with open('outputs/experiment.csv','w') as f:
 f.write('workload,algorithm,frames,faults,seconds\n')
 for wn,r in [('locality',loc),('random',rnd)]:
  for name,fn in [('FIFO',fifo),('LRU',lru),('Optimal',opt),('Clock',clock)]:
   for n in range(3,11):
    t=time.perf_counter();z=fn(r,n);d=time.perf_counter()-t;f.write(f'{wn},{name},{n},{z},{d:.6f}\n')
print('100k-reference fault and runtime data saved.')
