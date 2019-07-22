v =  35 * [None]

v[1] = 1

for i in range(2, 35):
    v[i] = v[i-1] + 2**(i-1)

n = int(input())

while(n>0):
    n-=1;
    x = int(input())
    print(v[x])

