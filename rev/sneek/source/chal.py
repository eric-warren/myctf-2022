import dis

def func():
    f = ''
    z = 'p{dt'
    x = 'eyfp'
    v = 'nYZ'
    n = 'ddehhR'
    m = 'SdcT['
    a = z + x + v + n + m + 'OXdg'
    for i,b in enumerate(a):
        c = ord(b)
        c = c - 3
        c = c + i
        c = chr(c)
        f += c
    print(f)

def make():
    flag = r"myctf{its_almost_assembly}"
    f = ''
    for i,b in enumerate(flag):
        c = ord(b)
        c = c - i
        c = c + 3
        c = chr(c)
        f += c
    print(f)

print(dis.dis(func))
func()

