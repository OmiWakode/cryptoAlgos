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

string encrypt(string message, string key) {
	cout<<"Encrypting\n";
	int i;
	for(i=0; message[i]!='\0'; ++i) {
		char ch = message[i];
		ch = (ch - 'a') + (key[i%key.length()] - 'a');
		ch %= 26;
		ch += 'a';
		cout<<message[i]<<": "<<(int) (message[i]-'a')<<" -> "<<"("<<(int) (message[i]-'a')<<"+"<<(int) (key[i%key.length()])<<")"<<"%26"<<" -> "<<(int) (ch-'a')<<": "<<ch<<"\n";
		message[i] = ch;
	}
	cout<<"\n\n";
	return message;
}

string decrypt(string message, string key) {
	cout<<"Decrypting\n";
	int i;
	char ch;
	for(i=0; message[i]!='\0'; ++i) {
		ch = (message[i] - 'a') - (key[i%key.length()] - 'a') + 26;
		ch %= 26;
		ch += 'a';
		cout<<message[i]<<": "<<(int) (message[i]-'a')<<" -> "<<"("<<(int) (message[i]-'a')<<"-"<<(int) (key[i%key.length()])%26<<")"<<"%26"<<" -> "<<(int) (ch-'a')<<": "<<ch<<"\n";
		message[i] = ch;
	}
	cout<<"\n\n";
	return message;
}

int main()
{
	int choice;
    string message, key;
    cout<<"Enter message: ";
    cin>>message;
    cout<<"Enter key: ";
    cin>>key;
    string formattedMessage = format(message);
    cout<<"1. Encrypt then Decrypt\n2.Decrypt then Encrypt\nChoose: ";
    cin>>choice;
    if (choice==1) {
    	string encryptedMessage = encrypt(formattedMessage, key);
    	string decryptedMessage = decrypt(encryptedMessage, key);
    	cout<<"Original Message: "<<message<<"\n";
    	cout<<"Encrypted Message: "<<encryptedMessage<<"\n";
    	cout<<"Decrypted Message: "<<decryptedMessage<<"\n";
	} else {
    	string decryptedMessage = decrypt(formattedMessage, key);
		string encryptedMessage = encrypt(decryptedMessage, key);
    	cout<<"Original Message: "<<message<<"\n";
    	cout<<"Decrypted Message: "<<decryptedMessage<<"\n";
    	cout<<"Encrypted Message: "<<encryptedMessage<<"\n";
	}
    return 0;
}
