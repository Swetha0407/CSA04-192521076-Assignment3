import random,csv,subprocess
random.seed(192521076); sizes=[random.randint(1,50*1024*1024) for _ in range(100)]
with open('outputs/internal_fragmentation.csv','w') as f:
 f.write('page_bytes,total_waste,average_waste\n')
 for p in (1024,4096,2*1024*1024):
  x=sum((-s)%p for s in sizes);f.write(f'{p},{x},{x/100:.2f}\n')
with open('outputs/tlb_eat.csv','w') as f:
 f.write('hit_ratio,eat_ns\n')
 for h in (.8,.95,.99):f.write(f'{h},{10+h*100+(1-h)*200:.2f}\n')
open('outputs/page_size.txt','w').write(subprocess.getoutput('getconf PAGESIZE'))
