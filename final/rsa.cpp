#include <iostream>
#include <math.h>
using namespace std;

int gcd(int a, int h)
{
	int temp;
	while (1)
	{
		temp = a%h;
		if (temp == 0)
		return h;
		a = h;
		h = temp;
	}
}

double mod_inv(int a, int m){
    for (int x = 1; x < m; x++)
        if ((a*x)%m == 1)
            return x;
    return 1;
}
// Code to demonstrate RSA algorithm
int main()
{
	double p, q;
    cout << "Enter 2 prime nos: ";
    cin >> p >> q;

	double n = p*q;

	double e;
	double phi = (p-1)*(q-1);
	while (e < phi)
	{
		if (gcd(e, phi)==1)
			break;
		else
			e++;
	}
    cout << e << endl;
	double d = mod_inv(e, phi);
    cout << d << endl;

	double msg;
    cout << "Enter plaintext: ";
    cin >> msg;

	double c = pow(msg, e);
	c = fmod(c, n);
    cout << "Cipher text: " << c << endl;
    long double m = pow(c, d);
	m = fmod(m, n);
    cout << "decrypted cipher text: " << m << endl;

	return 0;
}
