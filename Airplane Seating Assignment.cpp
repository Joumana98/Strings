#include <iostream>
#include<string>
#include <iomanip>

using namespace std;

const int N = 13;
const int M = 6;

void initialize(char array[][M]);
void printSeats(char array[][M], int startRow, int EndRow);
void determineChoices(string type, string smoking, int& sRow, int& eRow);
void determineChoice(char choice[], int s, int e, bool& valid, int& col, int& row);
void chooseSeat(char desired[], bool& validChoice, int& col, int& row, int sRow, int eRow);
bool checkIfOccupied(char array[][M], int row, int col);

int main()
{
	char seats[N][M];

	bool choose;
	cout << "Enter 1 if you want to choose a seat and 0 otherwise: " << endl;
	cin >> choose;
	cin.ignore();

	int sRow, eRow;
	char desired[4];
	bool validChoice = true;
	int col, row;

	bool check;

	string type;
	string smoking;

	initialize(seats);

	while (choose == 1)
	{

		cout << "Enter the Ticket type (First Class or Economy Class): " << endl;
		getline(cin, type);
		while (type != "First Class" && type != "Economy Class")
		{
			cout << "Wrong Ticket type!! Enter Ticket type again: " << endl;
			getline(cin, type);
		}

		if (type == "Economy Class")
		{
			cout << "Enter \" Smoking \" if you are a smoking person, and \" Non Smoking\" otherwise : " << endl;
			getline(cin, smoking);
			while (smoking != "Smoking" && smoking != "Non Smoking")
			{
				cout << "Invalid Answer!! Please answer again: " << endl;
				getline(cin, smoking);
			}

		}


		determineChoices(type, smoking, sRow, eRow);

		cout << "Please find below the list of available seats (marked as \"*\")" << endl;
		cout << endl;
		printSeats(seats, sRow - 1, eRow - 1);

		chooseSeat(desired, validChoice, col, row, sRow, eRow);

		check = checkIfOccupied(seats, row - 1, col);
		while (check == false)
		{
			cout << "This seat is occupied!!" << endl;
			chooseSeat(desired, validChoice, col, row, sRow, eRow);
			check = checkIfOccupied(seats, row - 1, col);
		}

		seats[row - 1][col] = 'X';
		cout << endl;
		cout << "Please find below the list of available seats after reserving your seat." << endl;
		cout << endl;
		printSeats(seats, 0, N - 1);

		cout << "Enter 1 if you want to choose a seat and 0 otherwise: " << endl;
		cin >> choose;
		cin.ignore();
	}

	return 0;
}

void initialize(char array[][M])
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			array[i][j] = '*';
}

void printSeats(char array[][M], int startRow, int EndRow)
{
	cout << "        A  B  C  D  E  F" << endl;
	for (int i = startRow; i <= EndRow; i++)
	{
		cout << "Row " << left << setw(4) << i + 1;
		for (int j = 0; j < M; j++)
			cout << array[i][j] << "  ";
		cout << endl;

	}
	cout << endl;

}

void determineChoices(string type, string smoking, int& sRow, int& eRow)
{
	if (type == "First Class")
	{
		sRow = 1;
		eRow = 2;
	}
	else
	{
		if (smoking == "Smoking")
		{
			sRow = 8;
			eRow = 13;
		}
		else if (smoking == "Non Smoking")
		{
			sRow = 3;
			eRow = 7;
		}
	}
}

void determineChoice(char choice[], int s, int e, bool& valid, int& col, int& row)
{
	if (choice[0] >= 'A' && choice[0] <= 'F')
	{
		col = static_cast<int> (choice[0]) - static_cast<int>('A');
	}

	else
	{
		cout << "Invalid seat Number!! Enter seat Number again: " << endl;
		valid = false;
		return;
	}

	int i1 = choice[1];
	int i2 = choice[2];
	if (choice[2] != '\0')
	{
		row = (static_cast<int>(choice[1]) - static_cast<int>('0')) * pow(10, 1);
		row = row + (static_cast<int>(choice[2]) - static_cast<int>('0')) * pow(10, 0);
	}
	else
		row = (static_cast<int>(choice[1]) - static_cast<int>('0')) * pow(10, 0);

	if (row<s || row>e)
	{
		cout << "Invalid seat Number!! Enter seat Number again: " << endl;
		valid = false;
		return;

	}

}

bool checkIfOccupied(char array[][M], int row, int col)
{
	if (array[row][col] == 'X')
		return false;
	else
		return true;

}

void chooseSeat(char desired[], bool& validChoice, int& col, int& row, int sRow, int eRow)
{
	cout << "Enter the desired seat: " << endl;
	cin >> desired;

	validChoice = true;
	determineChoice(desired, sRow, eRow, validChoice, col, row);
	while (validChoice == false)
	{
		cin >> desired;
		validChoice = true;
		determineChoice(desired, sRow, eRow, validChoice, col, row);
	}
}