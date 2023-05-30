# from itertools import product
# a = ["1","2","3","20"]
# b = ["i","g","r","at"]
# print(list(product(a,b)))
# h = "0"
# print(h.startswith("0."))

def isprime(num):
    k = int(num ** 0.5) + 1
    for i in range(2,k):
        if num % i == 0:
            return False
    return True

print(isprime(99997))
for i in range(100):
    if isprime(i):
        print(i)
print(isprime(8))
