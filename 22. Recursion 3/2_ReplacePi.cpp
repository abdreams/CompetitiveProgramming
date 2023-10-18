// A recursive C++ program to replace
// all pi in a given string with 3.14
// https://www.codechef.com/problems/CODEOW
#include <bits/stdc++.h>
using namespace std;

void replacePiHelper(char str[], int start)
{


	if (str[start] == '\0' || str[start + 1] == '\0') {
		return;
	}

	replacePiHelper(str, start + 1);

	if (str[start] == 'p' && str[start + 1] == 'i') {

		for (int i = strlen(str); i >= start + 2; i--) {
			str[i + 2] = str[i];
		}

		// Replacing with "3.14"
		str[start] = '3';
		str[start + 1] = '.';
		str[start + 2] = '1';
		str[start + 3] = '4';
	}
}

void replacePi(char str[])
{
	replacePiHelper(str, 0);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
	char str[100];
    cin>>str;

	replacePi(str);

	cout << str;

	return 0;
}
