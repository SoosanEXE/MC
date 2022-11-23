#include <bits/stdc++.h>
using namespace std;

string encrypt(string pt, int k){
    string e = "";
    for(int i = 0; pt[i] != '\0';i++){
        if(islower(pt[i]))
            e += ((pt[i]+k)-'a') % 26 + 'a';
        else if(isupper(pt[i]))
            e += ((pt[i]+k)-'A') % 26 + 'A';
        else
            e += pt[i];
    }
    return e;
}

string decrypt(string e, int k){
    string d = "";
    for(int i = 0; e[i]!= '\0'; i++){
        if(islower(e[i]))
            d+= (e[i]-k-'a') % 26 < 0 ?  (e[i]-k-'a') % 26 + 'z' :(e[i]-k-'a') % 26 + 'a';
        else if(isupper(e[i]))
            d+= (e[i]-k-'A') % 26 < 0 ?  (e[i]-k-'A') % 26 + 'Z' :(e[i]-k-'A') % 26 + 'A';
        else d+= e[i];
    }
    return d;
}

int main(){
    string pt, e, d;
    cout << "Enter plaintext: "; getline(cin, pt);
    int k;
    cout << "Enter key: "; cin>>k;
    e = encrypt(pt, k);
    cout << e << endl;
    d = decrypt(e, k);
    cout << d<< endl;
}
