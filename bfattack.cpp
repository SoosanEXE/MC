#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string decrypt(string ip, int k){
    for(int i=0;i<=ip.length();i++)
        if(isupper(ip[i])){
            int x = (ip[i] + k - 'A')%26;
            ip[i] = (x<0)? x + 'Z' +1:x+'A';
        }
        else{
            int x = (ip[i] + k - 'a')%26;
            ip[i] = (x<0)? x + 'z' +1:x+'a';
        }
    return ip;
}

void attack(string ip){
    cout <<"Starting attack... \n";
    for(int k = 0; k > -26; k--)
        cout << "key " << -k << " : " << decrypt(ip, k) << endl;
}

int main(){
    cout << "Enter cipher text: ";
    string ip;
    getline(cin, ip);
    attack(ip);
}