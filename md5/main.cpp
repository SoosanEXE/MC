#include <iostream>
#include <bits/stdc++.h>
#include "md5.h"

using namespace std; 

int main()
{
    string ip;
    cout << "Enter plaintext: "; 
    getline(cin, ip);
    cout << "md5 hash value: " << md5(ip) << endl;
    return 0;
}