def change(s):
    total = 0
    dic = {"I":1,"V":5,"X":10,"L":50,"C":100,"D":500,"M":1000}
    k = list(s)
    l = len(s)
    for i in range(0,l):
        try:
            if dic[k[i]] >= dic[k[i+1]]:
                total += dic[k[i]]
            else:
                total -= dic[k[i]]
        except:
            total += dic[k[i]]
    return total

print(change(input("please enter")))
