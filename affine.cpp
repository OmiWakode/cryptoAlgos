#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

string format(string message)
{
    int i;
    for (i = 0; i < message.size(); ++i)
    {
        if (message[i]>=65 && message[i]<=90)
        {
            message[i] = message[i] + 32;
        }
        else if (message[i]<65 || (message[i]>90 && message[i]<97) || message[i]>122)
        {
            message.erase(i, 1);
            --i;
        }
    }
    return message;
}

string encrypt(string message, int a, int b) {
	cout<<"Encrypting\n";
	int i;
	for(i=0; message[i]!='\0'; ++i) {
		char ch = message[i];
		ch = ((a * (ch - 'a') + b) % 26) + 'a';
		cout<<message[i]<<": "<<(int) (message[i]-'a')<<" -> "<<"("<<a<<"x"<<(int) (message[i]-'a')<<"+"<<b<<")"<<"%26"<<" -> "<<(int) (ch-'a')<<": "<<ch<<"\n";
		message[i] = ch;
	}
	cout<<"\n\n";
	return message;
}

string decrypt(string message, int a, int b) {
	cout<<"Decrypting\n";
	int i, a_inverse = 0, remainder = 0;
	for (int i = 0; i < 26; i++) {
		remainder = (a * i) % 26;
		if (remainder == 1) {
			a_inverse = i;
		}
	}
	cout<<"Finding value of a inverse: (a*x)%26 = "<<"("<<a<<"x"<<a_inverse<<")"<<"%26\n";
	cout<<"Inverse is "<<a_inverse<<"\n";
	cout<<"Don't forget to pretend to try other values in paper\n\n";
	char ch;
	for(i=0; message[i]!='\0'; ++i) {
		ch = message[i];
		ch = (((a_inverse * ((ch - 'a') - b)) % 26) >= 0)
		?( ( a_inverse * ( ( ch - 'a' ) - b )) % 26 ) + 'a'
		:( ( a_inverse * ( ( ch - 'a' ) - b )) % 26 ) + 'z'+1;
		cout<<message[i]<<": "<<(int) (message[i]-'a')<<" -> "<<"("<<a_inverse<<"x"<<"("<<(int) (message[i]-'a')<<"-"<<b<<")"<<")"<<"%26"<<" -> "<<(int) (ch-'a')<<": "<<ch<<"\n";
		message[i] = ch;
	}
	cout<<"\n\n";
	return message;
}

int main()
{
	int a, b, choice;
    string message;
    cout<<"a: ";
    cin>>a;
    cout<<"b: ";
    cin>>b;
    cout<<"Enter message: ";
    cin>>message;
    string formattedMessage = format(message);
    cout<<"1. Encrypt then Decrypt\n2. Decrypt then Encrypt\nChoose: ";
    cin>>choice;
    if (choice==1) {
	    string encryptedMessage = encrypt(formattedMessage, a, b);
	    string decryptedMessage = decrypt(encryptedMessage, a, b);
	    cout<<"Original Message: "<<message<<"\n";
	    cout<<"Encrypted Message: "<<encryptedMessage<<"\n";
	    cout<<"Decrypted Message: "<<decryptedMessage<<"\n";
	} else {
	    string decryptedMessage = decrypt(formattedMessage, a, b);
		string encryptedMessage = encrypt(decryptedMessage, a, b);
	    cout<<"Original Message: "<<message<<"\n";
	    cout<<"Decrypted Message: "<<decryptedMessage<<"\n";
	    cout<<"Encrypted Message: "<<encryptedMessage<<"\n";
	}
    return 0;
}
