# Shift Cipher

msg = input('Enter the string to be encrypted: ')
key = int(input('Enter key: '))

def encrypt(msg, key):
    code = [ord(x)-97 for x in msg]
    print('The coded string is: ', code)

    ecode = [(x + key)%26 for x in code]
    print('The encypted code: ',ecode)

    encrypt = [chr(x + 97) for x in ecode]
    encrypt = ''.join([elem for elem in encrypt])
    print('The encrypted String is' ,encrypt)


    
encrypt(msg,key)




