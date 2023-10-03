#include <iostream>
#include <fstream>
#include <cstring>
#include<iomanip>

using namespace std;

const int Q = 21;
const int S = 200;

void readAnswers(ifstream& inFile, ofstream& outFile, char array[], string& ID);
int calculateScore(const char array[], const char answers[]);
char calculateGrade(int score);

int main()
{

	ifstream inFile;
	ofstream outFile;

	inFile.open("C:\\inData.txt");
	if (!inFile)
	{
		cout << "The file does not exist!!" << endl;
		cout << "The program terminates!!" << endl;
		return 1;
	}

	outFile.open("C:\\outData.txt");

	char correctAnswers[Q];
	inFile >> correctAnswers;

	string ID;
	char answers[Q];

	int score = 0;

	readAnswers(inFile, outFile, answers, ID);
	while (inFile)
	{
		score = calculateScore(answers, correctAnswers);
		outFile << "    " << setw(10) << " Grade: " << calculateGrade(score) << endl;
		readAnswers(inFile, outFile, answers, ID);
	}



	return 0;
}

void readAnswers(ifstream& inFile, ofstream& outFile, char array[], string& ID)
{
	inFile >> ID;

	if (inFile)
	{
		outFile << ID << "  ";
		char a;
		inFile.get(a);
		int i = 0;
		while (a != '\n')
		{
			outFile << a << " ";
			array[i] = a;
			i++;
			inFile.get(a);
		}
	}

}

int calculateScore(const char array[], const char answers[])
{
	int score = 0;
	for (int i = 0; i < strlen(array); i++)
	{
		if (array[i] == ' ')
			continue;
		else if (array[i] == answers[i])
			score = score + 2;
		else
			score = score - 1;

	}

	return score;
}

char calculateGrade(int score)
{
	switch (score / 10)
	{
	case 10:
	case 9:
		return 'A';
	case 8:
		return 'B';
	case 7:
		return 'C';
	case 6:
		return 'D';
	case 5:
	case 4:
	case 3:
	case 2:
	case 1:
	case 0:
		return 'F';
	}
}