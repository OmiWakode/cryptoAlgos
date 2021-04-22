

def addtr(a, b):
    return (a+b)%26

def subtr(a, b):
    return(a-b)%26

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

def decrypt(msg, key):
    code = [ord(x)-97 for x in msg]
    codekey = [ord(x)-97 for x in key]
    print('The coded string is: ', code)
    print('The coded key is: ', codekey)
    

    ecode = list(map(subtr, code, codekey))
    print('The encypted code: ',ecode)

    encrypt = [chr(x + 97) for x in ecode]
    encrypt = ''.join([elem for elem in encrypt])
    print('The encrypted String is' ,encrypt)



while(1):
    print('Enter 1 for encrytion')
    print('Enter 2 for decrytion')
    print('Enter 0 for exit')
    
    choice = int(input('Choice: '))

    if(choice==0):
        break

    if(choice==1):
        msg = input('Enter the string to be encrypted: ')
        key = input('Enter key: ')
        encrypt(msg,key)
        continue

    if(choice==2):
        msg = input('Enter the string to be decrypted: ')
        key = input('Enter key: ')
        decrypt(msg,key)
        continue

