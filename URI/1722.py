fib = [1, 2, 3]

n = 3
i = 3

while n <= 10 ** 100:
    n = fib[i-1] + fib[i-2]
    fib.append(n)
    i+=1

while True:
    a, b = map(int, input().split())
    size = len(fib)
    if a+b == 0:
        break
    i = 0
    while i < size:
        if fib[i] >= a:
            break
        i+=1
    j = 0
    while j < size:
        if fib[j] > b:
            break
        j+=1

    print("%d" % (j-i))
    
        
