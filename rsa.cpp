#include <iostream>
#include <cmath>
#include <string>

using namespace std;

long int n, d[200], e[200];

int prime(long int n) {
	int i;
	for (i=2; i<=sqrt(n); ++i) {
		if (n%i==0) {
			return 0;
		}
	}
	return 1;
}

void calc_n(long int p, long int q) {
	cout<<"Value of n = p x q = "<<p<<" x "<<q<<" = "<<p*q<<"\n";
	n = p*q;
}

long int phin(long int p, long int q) {
	cout<<"Value of phi n = (p-1) x (q-1) = "<<p-1<<" x "<<q-1<<" = "<<p*q<<"\n";
	return (p-1)*(q-1);
}

long int calc_d(long int e, long int phi) {
	long int k = 1;
	cout<<"(e x d)%phi_n = 1\n";
	while (1) {
		k += phi;
		if (!(k%e)) return (k/e);
	}
}

void calc_e(long int p, long int q, long int phi) {
	int i = 0, j;
	long int dee;
	cout<<"1<e<phi_n\ngcd(e, phi_n)=1\n";
	for (j=2; j<phi; ++j) {
		if (!(phi%j)) continue;
		if (prime(j) && j!=p && j!=q) {
			dee = calc_d(j, phi);
			if (dee) {
				e[i] = j;
				d[i] = dee;
				++i;
			}
		}
		if (i==199) break;
	}
}

string encrypt(string message) {
	string encrypted = "";
	char m;
	int i, j, k, key = e[0];
	for (i=0; i<message.length(); ++i) {
		k = 1;
		m = message[i] - 96;
		for (j=0; j<key; ++j) {
			k *= m;
			k %= n;
		}
		encrypted += (char)(k+96);
	}
	return encrypted;
}

string decrypt(string encrypted) {
	string decrypted = "";
	char m;
	long int key = d[0];
	int i, j, k;
	for (i=0; i<encrypted.length(); ++i) {
		m = encrypted[i] - 96;
		k = 1;
		for (j=0; j<key; ++j) {
			k *= m;
			k %= n;
		}
		decrypted += (char)(k+96);
	}
	return decrypted;
}

int main() {
	string message;
	long int p, q;
	cout<<"Enter first prime number: ";
	cin>>p;
	if (!prime(p)) {
		cout<<"Not Prime... Exiting";
		exit(1);
	}
	cout<<"Enter second prime number: ";
	cin>>q;
	if (!prime(q)) {
		cout<<"Not Prime... Exiting";
		exit(1);
	}
	fflush(stdin);
	cout<<"Enter message: ";
	cin>>message;
	calc_n(p, q);
	calc_e(p, q, phin(p, q));
	cout<<"\nPossible values of e are: ";
	for (int i=0; i<sizeof(e)/sizeof(e[0]); ++i) {
		if (e[i]==0) break;
		cout<<e[i]<<" ";
	}
	cout<<"\nSelected value of e: "<<e[0];
	cout<<"\nPossible values of d are: ";
	for (int i=0; i<sizeof(d)/sizeof(d[0]); ++i) {
		if (d[i]==0) break;
		cout<<d[i]<<" ";
	}
	cout<<"Selected value of d: "<<d[0];
	cout<<"\nEncrypted Message: "<<encrypt(message)<<"\n";
	cout<<"Decrypted Message: "<<decrypt(encrypt(message));
    return 0;
}

