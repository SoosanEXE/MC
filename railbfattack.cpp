#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string decrypt(string cipher, int key)
{
	char rail[key][cipher.length()];
    if(key == 1) return cipher;

	for (int i=0; i < key; i++)
		for (int j=0; j < cipher.length(); j++)
			rail[i][j] = '\n';
        
	bool dir_down;

	int row = 0, col = 0;

	for (int i=0; i < cipher.length(); i++)
	{
		if (row == 0)
			dir_down = true;
		if (row == key-1)
			dir_down = false;

		rail[row][col++] = '*';

		dir_down?row++ : row--;
	}

	int index = 0;
	for (int i=0; i<key; i++)
		for (int j=0; j<cipher.length(); j++)
			if (rail[i][j] == '*' && index<cipher.length())
				rail[i][j] = cipher[index++];


	string result;

	row = 0, col = 0;
	for (int i=0; i< cipher.length(); i++)
	{
		if (row == 0)
			dir_down = true;
		if (row == key-1)
			dir_down = false;

		if (rail[row][col] != '*')
			result.push_back(rail[row][col++]);

		dir_down?row++: row--;
	}
	return result;
}

int main(){
    string ip;
    cout << "Enter cipher text: ";
    getline(cin, ip);
    cout << "Starting attack ";
    for(int i = 1; i<=ip.length(); i++)
        cout << "Key " << i << ": " << decrypt(ip, i) << endl;
}