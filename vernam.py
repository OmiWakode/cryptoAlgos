
from operator import sub
msg = input('Enter the string to be encrypted: ')
key = input('Enter key: ')

def addtr(a, b):
    return (a+b)%26

def encrypt(msg, key):
    code = [ord(x)-97 for x in msg]
    codekey = [ord(x)-97 for x in key]
    print('The coded string is: ', code)
    print('The coded key is: ', codekey)
    

    ecode = list(map(addtr, code, codekey))
    print('The encypted code: ',ecode)

    encrypt = [chr(x + 97) for x in ecode]
    encrypt = ''.join([elem for elem in encrypt])
    print('The encrypted String is' ,encrypt)


    
encrypt(msg,key)

