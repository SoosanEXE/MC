#include <cmath>
#include <iostream>
using namespace std;
typedef long long int lli;


int main()
{
	long long int P, G, x, a, y, b, ka, kb;

	cout << " Enter The value of P :" ;
    cin>>P;

	cout << "Enter The value of G (primitive root): " ;
    cin>>G;

	cout << "Enter The private key a for A : " ;
    cin >> a;
	cout << "Enter The private key b for B : " ;
    cin >> b;

	x = (lli) pow(G, a) % P;
    cout << "A --- " << x << " ---> B" << endl;

	y = (lli) pow(G, b) % P;
    cout << "B --- " << y << " ---> A" << endl;

	ka = (lli)pow(y, a) % P; 
	kb = (lli)pow(x, b) % P; 
	cout << "Ka = " << ka << endl;
	cout << "Kb = " << kb << endl;

	return 0;
}
