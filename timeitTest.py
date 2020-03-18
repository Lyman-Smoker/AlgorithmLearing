import timeit

def test ():
    li=[]
    for i in range(10000):
        li.append(i)

timer=timeit.Timer("test()","from __main__ import test")
#("函数","从哪里导入")
print("+:",timer.timeit(1000))
#(共进行次数)
