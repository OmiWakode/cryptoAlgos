from math import ceil
import numpy as np

def matrix_cofactor(matrix):
    return np.linalg.inv(matrix).T * np.linalg.det(matrix)

message = input("Enter message: ")
key = eval(input("Enter key matrix: "))

num_message = list(ord(x)-97 for x in message)
encrypted = ''
decrypted= ''

print(f"Encrypting...\n")
for i in range(ceil(len(message)/len(key))):
    sub_string_num = np.matmul(key, num_message[i*len(key):(i+1)*len(key)])
    sub_string_num_mod = list(x%26 for x in sub_string_num)
    sub_string = ''.join(chr(x+97) for x in sub_string_num_mod)
    encrypted += sub_string
    print(f"Key x {num_message[i*len(key):(i+1)*len(key)]} = {sub_string_num} % 26 = {sub_string_num_mod} = {sub_string}")
num_encrypted = list(ord(x)-97 for x in encrypted)
print(f"Encrypted String: {encrypted}")

print(f"Cofactor of key matrix:\n{matrix_cofactor(key)}")
print(f"Adjoint:\n{matrix_cofactor(key).T}")
print(f"Determinant: {np.linalg.det(key)}")

inv_det = -1

for i in range(2, 26):
    if (np.linalg.det(key)*i)%26==0:
        inv_det = i
        break

inverted_key = (inv_det*matrix_cofactor(key).T)%26
print(f"Inverted key:\n{inverted_key}")

print(f"Decrypting...\n")
for i in range(ceil(len(message)/len(inverted_key))):
    sub_string_num = np.matmul(inverted_key, num_encrypted[i*len(inverted_key):(i+1)*len(inverted_key)])
    sub_string_num = np.rint(sub_string_num)
    sub_string_num_mod = list(x%26 for x in sub_string_num)
    sub_string = ''.join(chr(int(x)+97) for x in sub_string_num_mod)
    decrypted += sub_string
    print(f"Inverted Key x {num_encrypted[i*len(inverted_key):(i+1)*len(inverted_key)]} = {sub_string_num} % 26 = {sub_string_num_mod} = {sub_string}")
print(f"Decrypted String: {decrypted}")
