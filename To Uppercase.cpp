
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char input[11];
	cout << "Enter a string: " << endl;
	cin.get(input, 11);

	for (int i = 0; i < strlen(input); i++)
		input[i] = toupper(input[i]);
	cout << input;


	return 0;
}