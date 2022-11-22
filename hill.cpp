#include <iostream>
#include <math.h>

using namespace std;

float en[3][1], de[3][1], a[3][3], b[3][3], mes[3][1], c[3][3];

void encryption()
{
    int i, j, k;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 1; j++)
            for (k = 0; k < 3; k++)
                en[i][j] = en[i][j] + a[i][k] * mes[k][j];
    cout << "\nCipher text: ";
    for (i = 0; i < 3; i++)
        cout << (char)(fmod(en[i][0], 26) + 65);
}


void getKeyMessage()
{
    int i, j;
    char msg[3];

    cout << "Enter key: \n";
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
        {
            cin >> a[i][j];
            c[i][j] = a[i][j];
        }
    cout << "Enter Plaintext: ";
    cin >> msg;
    for (i = 0; i < 3; i++)
        mes[i][0] = msg[i] - 65;
}

void inverse()
{
    int i, j, k;
    float p, q;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
        {

            if (i == j)
                b[i][j] = 1;
            else
                b[i][j] = 0;
        }
    for (k = 0; k < 3; k++)
    {
        for (i = 0; i < 3; i++)
        {
            p = c[i][k];
            q = c[k][k];
            for (j = 0; j < 3; j++)
            {
                if (i != k)
                {
                    c[i][j] = c[i][j] * q - p * c[k][j];
                    b[i][j] = b[i][j] * q - p * b[k][j];
                }
            }
        }
    }
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            b[i][j] = b[i][j] / c[i][i];
    cout << "\n\nInverse key:\n";
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            cout << b[i][j] << " ";
        cout << "\n";
    }
}

void decryption()
{
    int i, j, k;
    inverse();
    for (i = 0; i < 3; i++)

        for (j = 0; j < 1; j++)
            for (k = 0; k < 3; k++)
                de[i][j] = de[i][j] + b[i][k] * en[k][j];
    cout << "\nDecrypted string is: ";
    for (i = 0; i < 3; i++)
        cout << (char)(fmod(de[i][0], 26) + 65);
    cout << "\n";
}

int main() {
    getKeyMessage();
    encryption();
    decryption();
}