from math import gcd
from functools import reduce

a_arr = eval(input("Enter 'a' array: "))
m_arr = eval(input("Enter 'm' array: "))

print("Checking for coprime condition: ")
for i in range(len(m_arr)):
    for j in range(i+1, len(m_arr)):
        if gcd(m_arr[i], m_arr[j])!=1:
            print("m numbers are not coprime, exiting...")
            exit(1)
print("All m numbers are coprime!")


print("M = m1*m2*...*mn")
M = reduce(lambda a,b: a*b, m_arr)
print(f"Value of M: {M}\n")

print("Mi = M/mi")
M_arr = list(M/m_arr[i] for i in range(len(m_arr)))
print(f"Values of Mi:\n{M_arr}\n")

print("For value of Xi: (Xi*Mi)%mi = 1")
X_arr = []
for i in range(len(m_arr)):
    X = 1
    while True:
        if (M_arr[i]*X)%m_arr[i]==1:
            break
        X += 1
    X_arr.append(X)
print(f"Values of Xi:\n{X_arr}\n")

print("Value of x = M1*X1*a1 + M2*X2*a2 + ... + Mn*Xn*an")
x = 0
for i in range(len(a_arr)):
    x += M_arr[i]*X_arr[i]*a_arr[i]
x = int(x)%M
    
print(f"Value of x is: {x}")
