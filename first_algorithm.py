#如果a+b+c=1000,且a^2+b^2=c^2(a，b，c为自然数)，试求abc所有可能组合
import time
def solution1(sum):
    for a in range(0,sum+1):
        for b in range(0,sum+1):
            for c in range(0,sum+1):
                if a+b+c==sum and a**2+b**2==c**2:
                    print(a)
                    print(b)
                    print(c)

def solution2(sum):
    for a in range(sum):
        for b in range(sum):
            c=sum-b
            c=c-a
            if pow(a,2)+pow(b,2)==pow(c,2):
                print(a)
                print(b)
                print(c)

start_time=time.time()
solution1(1000)
end_time=time.time()
print("time=%d"%(end_time-start_time))