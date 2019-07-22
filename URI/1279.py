def bissexto(s):
    if ((s % 4 == 0 and s % 100 != 0) or s % 400 == 0):
        return True
    else:
        return False

def huluculu(s):
    if(s % 15 == 0): return True
    else: return False

def bulukulu(s):
    if(s % 55 == 0 and bissexto(s)): return True
    else: return False

line = False

while True:
    s = None
    try:
        s = int(input())
    except EOFError:
        break
    if line :
        print("")
    f = False
    if bissexto(s):
        print("This is leap year.")
        f = True
    if huluculu(s):
        print("This is huluculu festival year.")
        f = True
    if bulukulu(s):
        print("This is bulukulu festival year.")
        f = True
    if f == False:
        print("This is an ordinary year.")
    line = True
