# Shift Cipher



def encrypt(msg, key):
    code = [ord(x)-97 for x in msg]
    print('The coded string is: ', code)

    ecode = [(x + key)%26 for x in code]
    print('The encypted code: ',ecode)

    encrypt = [chr(x + 97) for x in ecode]
    encrypt = ''.join([elem for elem in encrypt])
    print('The encrypted String is' ,encrypt)

def decrypt(msg,key):
    code = [ord(x)-97 for x in msg]
    print('The coded string is: ', code)

    ecode = [(x - key)%26 for x in code]
    print('The dectpted code: ',ecode)

    encrypt = [chr(x + 97) for x in ecode]
    encrypt = ''.join([elem for elem in encrypt])
    print('The decrypted String is' ,encrypt)


while(1):
    print('Enter 1 for encrytion')
    print('Enter 2 for decrytion')
    print('Enter 0 for exit')
    
    choice = int(input('Choice: '))

    if(choice==0):
        break

    if(choice==1):
        msg = input('Enter the string to be encrypted: ')
        key = int(input('Enter key: '))
        encrypt(msg,key)
        continue

    if(choice==2):
        msg = input('Enter the string to be decrypted: ')
        key = int(input('Enter key: '))
        decrypt(msg,key)
        continue


    





