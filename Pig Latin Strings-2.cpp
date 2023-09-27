// Programming Exercise 3
// Pig Latin processing a text consisting of multiple words


#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool isVowel(char c);
bool hasVowel(string s, int& position);
string rotation(string s, int p);
string toPigLatin(string str);
bool isPunctuation(char c);

int main()
{
	ifstream inFile;
	ofstream outFile;

	inFile.open("C:\\inData.txt");
	outFile.open("C:\\outData.txt");

	if (!inFile)
	{
		cout << "The file doe not exist!" << endl;
		cout << "Program terminates!" << endl;
		return 1;
	}

	string word;
	inFile >> word;

	int l;

	while (inFile)
	{
		l = static_cast <int> (word.size());

		if (isPunctuation(word[l - 1]) == true)
		{
			string temp = word.substr(0, l - 1);
			outFile << toPigLatin(temp) + word[l - 1];

		}
		else
			outFile << toPigLatin(word);

		outFile << " ";
		inFile >> word;

	}

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
	int l = static_cast <int> (s.size());
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

string toPigLatin(string str)
{
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

	return pigLatin;
}

bool isPunctuation(char c)
{
	switch (c)
	{
	case '.':
	case ',':
	case ';':
	case '?':
	case ':':
	case '!':
		return true;
	default:
		return false;
	}

}