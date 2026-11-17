import csv
ram=2048;tasks={'real_time_control':128,'machine_learning':1536,'logging':128};reserve=ram-sum(tasks.values());print('RAM budget',ram,'MiB');[print(k,v,'MiB') for k,v in tasks.items()];print('OS/driver reserve',reserve,'MiB');print('Extra 500MiB task exceeds reserve by',500-reserve,'MiB')
ref=[0,1,2,3,0,1,4,0,1,2,3,4]*10
def fifo(r,n):
 q=[];i=z=0
 for x in r:
  if x in q:continue
  z+=1
  if len(q)<n:q.append(x)
  else:q[i]=x;i=(i+1)%n
 return z
with open('outputs/memory_simulation.csv','w') as f:
 f.write('task,reserved_mib,frames,fifo_faults\n')
 for k,v in tasks.items():f.write(f'{k},{v},{max(1,v//4)},{fifo(ref,max(1,v//4))}\n')
