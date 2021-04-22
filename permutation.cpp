#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
void printArray(char *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}
void permutate(char *appended_arr, int appended_arr_len, int *key, int key_len)
{
    int i;
    int temp[key_len];
    for (i = 0; i < appended_arr_len; i += key_len)
    {
        for (int key_i = 0; key_i < key_len; key_i++)
        {
            temp[key_i] = appended_arr[i + key[key_i]];
        }
        for (int key_i = 0; key_i < key_len; key_i++)
        {
            appended_arr[i + key_i] = temp[key_i];
        }
    }
}
void encrypt()
{
    cout << "\nEncrypt a string" << endl;
    string str;
    int i, plaintext_i, plaintext_len, key_len;
    cin.ignore(1000, '\n');
    getline(cin, str);
    int len = str.length();
    char plaintext[len];
    cout << "Input Key length: ";
    cin >> key_len;
    int key[key_len];
    for (i = 0; i < key_len; i++)
    {
        cout << i + 1 << " ";
    }
    cout << endl;
    for (i = 0; i < key_len; i++)
    {
        cin >> key[i];
        key[i]--;
    }
    //Convert to Uppercase
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    cout << "Text : " << str << endl;
    //String to number array
    for (plaintext_i = 0, i = 0; i < len; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            plaintext[plaintext_i++] = str[i];
        }
    }
    plaintext_len = plaintext_i;
    cout << "PlainText Array: ";
    printArray(plaintext, plaintext_len);
    int appended_arr_len = plaintext_len / key_len;
    if (plaintext_len % key_len != 0)
        appended_arr_len++;
    appended_arr_len *= key_len;
    char appended_arr[appended_arr_len];
    char cypher[appended_arr_len];
    for (i = 0; i < plaintext_len; i++)
    {
        appended_arr[i] = plaintext[i];
    }
    for (; i < appended_arr_len; i++)
    {
        appended_arr[i] = '_';
    }
    permutate(appended_arr, appended_arr_len, key, key_len);
    cout << "Encrypted Text: ";
    for (int i = 0; i < appended_arr_len; i++)
    {
        cout << appended_arr[i];
    }
    cout << endl;
}
void decrypt()
{
    cout << "\nDecrypt a string" << endl;
    string str;
    int i, plaintext_i, plaintext_len, key_len;
    cin.ignore(1000, '\n');
    getline(cin, str);
    int len = str.length();
    char plaintext[len];
    cout << "Input Key length: ";
    cin >> key_len;
    int key[key_len];
    for (i = 0; i < key_len; i++)
    {
        cout << i + 1 << " ";
    }
    cout << endl;
    for (i = 0; i < key_len; i++)
    {
        int temp;
        cin >> temp;
        temp--;
        key[temp] = i;
    }
    //Convert to Uppercase
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    cout << "Text : " << str << endl;
    //String to number array
    for (plaintext_i = 0, i = 0; i < len; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            plaintext[plaintext_i++] = str[i];
        }
    }
    plaintext_len = plaintext_i;
    cout << "PlainText Array: ";
    printArray(plaintext, plaintext_len);
    int appended_arr_len = plaintext_len / key_len;
    if (plaintext_len % key_len != 0)
        appended_arr_len++;
    appended_arr_len *= key_len;
    char appended_arr[appended_arr_len];
    char cypher[appended_arr_len];
    for (i = 0; i < plaintext_len; i++)
    {
        appended_arr[i] = plaintext[i];
    }
    for (; i < appended_arr_len; i++)
    {
        appended_arr[i] = '_';
    }
    permutate(appended_arr, appended_arr_len, key, key_len);
    cout << "Decrypted Text: ";
    for (int i = 0; i < appended_arr_len; i++)
    {
        cout << appended_arr[i];
    }
    cout << endl;
}
void menu()
{
    int choice = -1;
    while (choice)
    {
        cout << "***Permutation Cipher***" << endl;
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
