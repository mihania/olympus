s = "SOCONSUCORS SEDO PSOROGSAROSAMOSERO"
res = ""
def iv(ch): 
    return (ch == 'A' or ch == 'O' or ch == 'U' or  ch == 'I' or ch == 'E') and ch.isalpha()
       
def ic(ch):
    return ch.isalpha() and iv(ch) != True

i = len(s) - 1

while i >= 0 :
    if iv(s[i]):
        if s[i] == 'O' and i > 0 and ic(s[i - 1]):
            res = s[i - 1] + s[i - 2] + res
            i -= 4
        else:
            res = s[i] + res
            i -= 1
    else:
        res = s[i] + res
        i -= 1
print(res)
