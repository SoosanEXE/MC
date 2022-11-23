#include <bits/stdc++.h>
#include <openssl/md5.h>

using namespace std;

int main(){
    unsigned char d[] = "TEST", md[MD5_DIGEST_LENGTH];
    MD5(d, 4, md);
    for(int i = 0; i < MD5_DIGEST_LENGTH; i++)
        printf("%02x", md[i]);
}
