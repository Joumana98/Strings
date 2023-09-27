// Programming Example
// Pig Latin Strings
// If string starts with a vowel, add "-way" at the end.
// 
// Otherwise, add "-" at the end, rotate characters of the string until the first character beomes a vowel
// and then add ay at the end;
//
// We consider y as a vowel
//
//Strings with no vowels, add "-way" at the end


#include <iostream>
#include <string>

using namespace std;

bool isVowel(char c);
bool hasVowel(string s, int& position);
string rotation(string s, int p);

int main()
{
	string str;
	cout << "Enter a string: " << endl;
	cin >> str;

	string pigLatin;

	char c = str[0];
	int p = 0;
	if (isVowel(c) == true)
		pigLatin = str + "-way";
	else if (hasVowel(str, p) == true)
	{
		pigLatin = str + '-';
		pigLatin = rotation(pigLatin, p);
		pigLatin = pigLatin + "ay";

	}

	else
		pigLatin = str + "-way";

	cout << "The pig Latin form of " << str << " is: " << pigLatin << endl;

	return 0;
}

bool isVowel(char c)
{
	switch (c)
	{
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
	case 'y':
	case 'A':
	case 'E':
	case 'I':
	case 'O':
	case 'U':
	case 'Y':
		return true;
	default:
		return false;
	}

}

bool hasVowel(string s, int& position)
{
	int l = s.size();
	// Loop should not check the first character, it is only called when the first character is not a vowel
	for (int i = 1; i < l; i++)
	{
		if (isVowel(s[i]) == true)
		{
			position = i;
			return true;
		}

	}
	return false;
}

string rotation(string s, int p)
{
	int l = s.size();
	string rotated = s.substr(p, l - p);
	rotated = rotated + s.substr(0, p);
	return rotated;

}