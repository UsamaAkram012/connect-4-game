/*
			Name:			Usama Akram
			Roll Number:	bitf19m514
			Task 2 (Home Work Number 1)
			Function:       Connect 4 Game
*/

#include<iostream>
#include<iomanip>
using namespace std;
class C4Game {    //class
private:					//private data members and functions
	int** array;
	int count;
	int player;
public:					//public data members and functions
	C4Game() {				//default ctor
		player = 2, count = 0;				//initializing data members
		array = new int*[7];
		for (int i = 0; i < 7; i++){				//creating dynamic array 
			array[i] = new int[7];
		}
		for (int i = 0; i < 7; i++) {				//initializing data functions
			for (int j = 0; j < 7; j++) {
				array[i][j] = NULL;
			}
		}
}
	void start() {     //starting game
		showBoard();
		system("\nPause");
		while (1) {    
			if (isBoardFull()) {   // execute if the board is full
				cout << "Board is Full. Match Drawn" << endl;
				break;
			}
			else {
				count++;
				int index;
				switchTurn();   //switches the user turn (1-2)
				cout << "Player " << player << " turn: ";
			loop1:
				cin >> index;
				if (index < 0 || index>7) {		// execute when column is not available.
					cout << "Invalid Input....Column Does not exist.Enter column no again: ";
					goto loop1;
				}
				if (array[0][index - 1] != 0) {    // execute when column is completely filled
					cout << "This column is completely filled. Try any other place: ";
					goto loop1;
				}
				if (player == 1) {			// input for player two
					for (int i = 6; i >= 0; i--) {
						if (array[i][index - 1] == 0) {
								array[i][index - 1] = 1;
								break;
						}
					}
				}
				else if (player == 2) {				// input for player two
					for (int i = 6; i >= 0; i--) {
						if (array[i][index - 1] == 0) {
								array[i][index - 1] = 2;
								break;
						}
					}
				}
				system("CLS");    //clearing screen
				showBoard();				//displaying board
				if (isWon(player)) {			//execute if any player wins
					cout << "Player " << player << " has won the match.\n"; return;
				}
			}
		}
	}
	void showBoard() {					//displaying board
		cout << setw(40) << "Connect 4 Game" << endl;
		cout << endl;
		for (int i = 1; i < 8; i++) {      //displaying column number
			cout<<setw(9) << i;
		}
		cout << endl;
		cout <<setw(68)<<"________________________________________________________________\n";
		for (int i = 0; i < 7; i++) {
			cout << "   |";
			for (int j = 0; j < 7; j++) {
				if (array[i][j] != 0) {
					cout << setw(5) << array[i][j] << "   |";  //displaying content of array 
				}
				else 
					cout << setw(5) << "-" << "   |";    //displaying dash (-) in board 
			}
			cout << endl;
		}
		cout << setw(68) << "----------------------------------------------------------------\n";

	}
	void switchTurn() {		//ftn to switch turn
		if (player == 1)
			player = 2;   //switching player to 2
		else
			player = 1;			//switching player to 1
	}
	bool isWon(int player) {
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 7; j++) {
				if (j<4) {			//Horizontal Check (right) 
					if (array[i][j] == player) {
						if (array[i][j] == player && array[i][j + 1] == player &&
							array[i][j + 2] == player && array[i][j + 3] == player)
							return true;				// return true if rows matches
					}
				}
				if(j<3) {				//Horizontal Check (left) 
					if (array[i][j] == player) {
						if (array[i][j] == player && array[i][j - 1] == player &&
							array[i][j - 2] == player && array[i][j - 3] == player)
							return true;				// return true if rows matches
					}
				}
				if (i<4) {			//Verticle Check (down) 
					if (array[i][j] == player) {
						if (array[i][j] == player && array[i + 1][j] == player &&
							array[i + 2][j] == player && array[i + 3][j] == player)
							return true;				// return true if verticle matches
					}
				}
				if(i>2) {					//Verticle (up) 
					if (array[i][j] == player) {
						if (array[i][j] == player && array[i - 1][j] == player &&
							array[i - 2][j] == player && array[i - 3][j] == player)
							return true;     // return true if column matches 
					}
				}
				if (i < 4 && j < 4) {    //Diagonal (right-up)
					if (array[i][j] == player) {
						if (array[i][j] == player && array[i + 1][j + 1] == player &&
							array[i + 2][j + 2] == player && array[i + 3][j + 3] == player)
							return true;				// return true if diagonal matches
					}
				}
				if(i > 2 && j < 3) {    //Diagonal (left-down)
					if (array[i][j] == player) {
						if (array[i][j] == player && array[i - 1][j - 1] == player &&
							array[i - 2][j - 2] == player && array[i - 3][j - 3] == player)
							return true;				// return true if diagonal matches
					}
				}
				if (i < 4 && j < 3) {    //Diagonal (left-down)
					if (array[i][j] == player) {
						if (array[i][j] == player && array[i + 1][j - 1] == player &&
							array[i + 2][j - 2] == player && array[i + 3][j - 3] == player)
							return true;			// return true if diagonal matches
					}
				}
				if(i > 2 && j < 4) {   //Diagonal (left-up)
					if (array[i][j] == player) {
						if (array[i][j] == player && array[i - 1][j + 1] == player &&
							array[i - 2][j + 2] == player && array[i - 3][j + 3] == player)
							return true;     // return true if diagonal matches
					}
				}
			}
		}
		return false;
	}
	bool isBoardFull() {   //Board is full?
		if (count == 49)
			return true;     //return if board is full 
		else
			return false;			//return if board is not full 
	}  
	~C4Game() {   //dtor to delete dynamic array 
		if (array != NULL) {				 //deleting columns
			for (int i = 0; i < 7; i++) {
				delete[] array[i];
			}
			delete[] array;				//deleting rows
		}
	}
};
int main() {
	C4Game obj1;    //object 
	obj1.start();    //calling start ftn in class C4Game
}