//Tic-Tac-Toe
//By Renzo Pereyra

#include<iostream>
using namespace std; 

char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'}; 
int checkIfWin(); 
void board(); 

int main()
{
	int player = 1, i, choice; 

	char mark; //this will be your X or O 

	do
	{
		board(); 
		player = ((player % 2) ? 1 : 2); //basically: if "player%2" is true, return 1, else return 2 
		cout << endl; 
		cout << "Player " << player << ", enter a number: "; 
		cin >> choice; 
		
		mark = ((player == 1) ? 'X' : '0'); //basically: if "player==1" is true, return X, else return O 

		if (choice == 1 && square[1] == '1')
			square[1] = mark;
		else if (choice == 2 && square[2] == '2')
			square[2] = mark; 
		else if (choice == 3 && square[3] == '3')
			square[3] = mark;
		else if (choice == 4 && square[4] == '4')
			square[4] = mark;
		else if (choice == 5 && square[5] == '5')
			square[5] = mark;
		else if (choice == 6 && square[6] == '6')
			square[6] = mark;
		else if (choice == 7 && square[7] == '7')
			square[7] = mark;
		else if (choice == 8 && square[8] == '8')
			square[8] = mark;
		else if (choice == 9 && square[9] == '9')
			square[9] = mark;
		else
		{
			cout << "Invalid code. Try again!" << endl;
			cout << "Press Enter to Continue."; 
			player--; 
			cin.ignore(); //clears characters from input buffer 
			cin.get(); //used for accessing character arrays, including whitespace characters, as opposed to "cin >> char" which ends once whitespace is found  
		}
		i = checkIfWin(); 
		player++; 
	} while (i == -1); //do-while loop

	board(); 

	if (i == 1)
	{
		cout << endl;
		cout << "==>\aPlayer " << --player << " wins! ";
	}
	else
	{
		cout << endl;
		cout << "==>\aGame Draw! ";
	}

	cin.ignore(); 
	cin.get(); 
	return 0; 
} 

int checkIfWin()
{
	if (square[1] == square[2] && square[2] == square[3]) //if three-in-a-row horizontally/vertically/diagonally
		return 1;
	else if (square[4] == square[5] && square[5] == square[6])
		return 1;
	else if (square[7] == square[8] && square[8] == square[9])
		return 1;
	else if (square[1] == square[4] && square[4] == square[7])
		return 1;
	else if (square[2] == square[5] && square[5] == square[8])
		return 1;
	else if (square[3] == square[6] && square[6] == square[9])
		return 1;
	else if (square[1] == square[5] && square[5] == square[9])
		return 1;
	else if (square[3] == square[5] && square[5] == square[7])
		return 1;
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5'
		&& square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9') //else if no squares are available
		return 0;
	else
		return -1; 
//Returns "1" if Game is Over with Result 
//Returns "-1" if Game is in Progress 
//Returns "0" if Game is a Draw 
}

void board()
{
	system("cls"); //clears screen? 
	cout << "\n\n\tTic Tac Toe\n\n"; 
	cout << "Player 1 (X) - Player 2 (0)" << endl; 
	cout << endl; 
	cout << "        |     |     " << endl; 
	cout << "     " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl; 
	cout << "   _____|_____|_____" << endl; 
	cout << "        |     |     " << endl; 
	cout << "     " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl; 
	cout << "   _____|_____|_____" << endl; 
	cout << "        |     |     " << endl; 
	cout << "     " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl; 
	cout << "        |     |     " << endl; 
}