#include <iostream>
#include <math.h>

using namespace std;

long int calcPow(long int a, int b, long int G){
    long long int po = 1;
    for(int i = 1; i<=b; i++){
        po = (po * a)%G;
    }
    return po;
}
int isPrimitiveRoot(long int G, long int n){
    long int array[G+1] = {0};
    int x;
    for(int i=1; i<G ;i++){
        x = (int)(calcPow(n, i, G));
        if (x>=G){
            return 0;
        }
        else if (array[x]!=0){
            return 0;
        }
        else  {
            array[x]+=1;
        }
    }
    return 1;
}

void calcPrimitiveRoot(long int G){
    for (int i = 2; i<G-1; i++){
        if(isPrimitiveRoot(G, i)){
            cout<<" "<<i;
        }
    }
}



int isPrime(long int n){
     for(int i=2; i<=sqrt(n); i++){
         if (n%i==0){
             return 0;
         }
         continue;
     }
     return 1;
 }
int isKeyValid(long int key, long int G){
    if (key< G && key>0){
        return 1;
    }
    else 
        return 0;
}

long int calcKey(long int pkey, long int P, long int G){
    if (pkey==1){
        return pkey;
    }
    else 
        return ((long int)calcPow(P, pkey,G));
}
int main() {
    long int P, G, x, a, y, b, ka, kb;
    
    cout<<"Enter the value of Global Prime Number: ";
    cin>>G;
    if(!isPrime(G)){
        cout<<"The Entered Global Prime Number is not a prime.Exiting ....";
        exit(1);
    }
     calcPrimitiveRoot(G);
     cout<<"\nEnter the value of Primitive root you want to use: ";
     cin>>P;

    
    cout<<"The calculated Primitive root is: "<<P;
    cout<<"\n\nEnter the sender(A) private key: ";
    cin>>a;
    if (!isKeyValid(a,G)){
        cout<<"The entered key is incorrect. Exiting...";
        exit(1);
    }
    
    x = calcKey(a, P, G);
    cout<<"The Universal Key for sender A is: "<<x;
    cout<<"\n\nEnter the reciever(B) private key ";
    cin>>b;
     if (!isKeyValid(b,G)){
        cout<<"The entered key is incorrect. Exiting...";
        exit(1);
    }
    
    y = calcKey(b, P, G);
    cout<<"\nThe Universal Key for reciever is :"<<y;
    ka = calcKey(a,y, G);
    cout<<"\n\nThe Common secret Key derived at Sender side is: "<<ka;
    kb = calcKey(b,x, G);
    cout<<"\nThe Common secret Key derived at Reciever side is: "<<kb;

    return 0;
}
