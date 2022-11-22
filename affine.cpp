#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string encrypt(string ip, int a, int b){
    for(int i = 0; i <= ip.length(); i++){
        ip[i] = ip[i] - 'A';
        ip[i] = (a * ip[i] + b)%26;
        ip[i] = ip[i] + 'A';
    }
    return ip;
}

int mod_inv(int a){
    for (int x = 1; x < 26; x++)
        if ((a*x)%26 == 1)
            return x;
    return 1;
}

string decrypt(string ip, int a, int b){
    int a_inv = mod_inv(a);
    for(int i = 0; i <= ip.length(); i++){
        ip[i] = ip[i] - 'A';
        ip[i] = (a_inv*(ip[i] - b))%26;
        ip[i] = ip[i] + 'A';
    }
    return ip;
}

int main(){
    string ip;
    cout << "Enter plaintext: ";
    getline(cin, ip);
    cout << "Enter keys a and b (a being coprime to m): ";
    int a, b;
    cin>>a>>b;
    string c = encrypt(ip, a, b);
    cout << "Cipher text: " << c << endl;
    int a_inv = mod_inv(a);
    cout << "Inverse of key a: " << a_inv << endl;
    cout<< "Decrytpted cipher text: " << decrypt(c, a, b)<< endl;
}
