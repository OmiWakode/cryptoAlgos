#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}
void encrypt()
{
    cout << "\nEncrypt a string" << endl;
    string str;
    int i, plaintext_i, plaintext_len;
    cin.ignore(1000, '\n');
    getline(cin, str);
    int len = str.length();
    int plaintext[len], key[len];
    char specialChars[len], cypher[len];

    //Initialise specialChars Array to \0
    for (i = 0; i < len; i++)
        specialChars[i] = '\0';

    cout << "Input Key, k: ";
    cin >> key[0];

    //Convert to Uppercase
    transform(str.begin(), str.end(), str.begin(), ::toupper);

    cout << "Text : " << str << endl;

    //String to number array
    for (plaintext_i = 0, i = 0; i < len; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            plaintext[plaintext_i++] = (str[i] - 'A');
        }
        else
        {
            specialChars[i] = str[i];
        }
    }
    plaintext_len = plaintext_i;

    cout << "Number Array: ";
    printArray(plaintext, plaintext_len);

    //Create key array
    for (i = 1; i < plaintext_len; i++)
    {
        key[i] = plaintext[i - 1];
    }

    //Add key to number array
    for (i = 0; i < plaintext_len; i++)
    {
        plaintext[i] = (plaintext[i] + key[i]) % 26;
    }

    cout << "Shifted Number Array: ";
    printArray(plaintext, plaintext_len);

    //char Array
    for (i = 0, plaintext_i = 0; i < len; i++)
    {

        if (specialChars[i] != '\0')
        {
            cypher[i] = specialChars[i];
        }
        else
        {
            cypher[i] = plaintext[plaintext_i++] + 'A';
        }
    }

    cout << "Encrypted code: ";
    for (i = 0; i < len; i++)
    {
        cout << cypher[i];
    }
    cout << endl;
}
void decrypt()
{
    cout << "\nDecrypt a string" << endl;
    string str;
    int i, plaintext_i, plaintext_len;
    cin.ignore(1000, '\n');
    getline(cin, str);
    int len = str.length();
    int plaintext[len], key;
    char specialChars[len], output[len];

    //Initialise specialChars Array to \0
    for (i = 0; i < len; i++)
        specialChars[i] = '\0';

    cout << "Input Key, k: ";
    cin >> key;

    //Convert to Uppercase
    transform(str.begin(), str.end(), str.begin(), ::toupper);

    cout << "Cipher Text : " << str << endl;

    //String to number array
    for (plaintext_i = 0, i = 0; i < len; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            plaintext[plaintext_i++] = (str[i] - 'A');
        }
        else
        {
            specialChars[i] = str[i];
        }
    }
    plaintext_len = plaintext_i;

    cout << "Number Array: ";
    printArray(plaintext, plaintext_len);

    plaintext[0] = (plaintext[0] - key + 26)%26;

        //Shiftting
        for (i = 1; i < len; i++)
    {
        plaintext[i] = (plaintext[i] - plaintext[i - 1] + 26) % 26;
    }

    cout << "Shifted Number Array: ";
    printArray(plaintext, plaintext_len);

    //char Array
    for (i = 0, plaintext_i = 0; i < len; i++)
    {

        if (specialChars[i] != '\0')
        {
            output[i] = specialChars[i];
        }
        else
        {
            output[i] = plaintext[plaintext_i++] + 'A';
        }
    }

    cout << "Encrypted code: ";
    for (i = 0; i < len; i++)
    {
        cout << output[i];
    }
    cout << endl;
}
void menu()
{
    int choice = -1;
    while (choice)
    {
        cout << "***Autokey Cypher***" << endl;
        cout << endl;
        cout << "1. Encrypt a string" << endl;
        cout << "2. Decrypt a code to string" << endl;
        cout << "0. Exit" << endl;
        cout << endl;
        cout << "Enter a choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            encrypt();
            break;
        case 2:
            decrypt();
            break;
        case 0:
            cout << "Exiting...";
            break;
        default:
            cout << "Invalid choice. Try again!" << endl;
        }
    }
}
int main()
{
    menu();
    return 0;
}