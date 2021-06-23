#include <iostream>
#include <conio.h>

using namespace std;

void printInputMatrix();
void printBoard();
bool setMark();
bool check();

char board[3][3] = {' ',' ',' ',
					' ',' ',' ',
					' ',' ',' '};
int turn = 1; //1-Player 1 | 0-Player 2
char mark = 'O'; //O-Player 1 | X-Player 2
int input;

int main(){
	bool won = false; // checks is anyone of the two won or not.
	bool validInput = false; // checks for the valid inputs.
	for(int i=0; i<9; i++){
		system("cls");
		cout<<endl<<endl<<"****TIC-TAC-TOE*****"<<endl<<endl;
		printBoard();
		if(turn)
			cout<<"Player 1 Turn (Symbol: O)"<<endl; // displaying the message about the chance if it's for Player 1.
		else 
			cout<<"Player 2 Turn (Symbol: X)"<<endl; // displaying the message about the chance if it's for Player 2.
		printInputMatrix();
		cout<<"Enter Input from Input Matrix: ";
		cin>>input;
		while(input<0 || input>9){ // corner cases handling (from 0-8 only)
			cout<<"Invalid Input. Please Re-Enter input: ";
			cin>>input;
		}
		if(turn) 
			mark = 'O'; // Player 1 chance , make mark 'O'.
		else 
			mark = 'X'; // Player 2 chance , make mark 'X'.
		
		validInput = setMark();
		if( validInput == false){
			i--;
			continue;
		}
		won = check();
		if(won == true){
			system("cls");
			printBoard();
			if(turn)
				cout<<endl<<"*** Player 1 - You Won ***";
			else
				cout<<endl<<"*** Player 2 - You Won ***";
			getch();
			break;
		}
		if(i==8){
			system("cls");
			printBoard();
			cout<<endl<<"*** MATCH DRAW ***"; // when no one wins / Match draw.
		}
		
		turn = !turn;
	}
	
	return 0;
}
void printInputMatrix(){
	cout<<endl<<endl<<"INPUT MATRIX"<<endl;
	cout<<" 1 | 2 | 3 "<<endl;
	cout<<"------------"<<endl;
	cout<<" 4 | 5 | 6 "<<endl;
	cout<<"------------"<<endl;
	cout<<" 7 | 8 | 9 "<<endl;
}
void printBoard(){
	cout<<" "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<" "<<endl; // 1st Row
	cout<<"------------"<<endl;
	cout<<" "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<" "<<endl; // 2nd Row
	cout<<"------------"<<endl;
	cout<<" "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<" "<<endl; // 3rd Row
}
bool setMark(){
	for(int i=0,k=1; i<3; i++ ){
		for(int j=0; j<3; j++,k++){
			if( k==input ) // check if we are in the same space which we are looking for.
				if(board[i][j] == ' '){ // check if space is already occupied by the Board.
					board[i][j] = mark;
					return true; // ValidInput
				}
				else{
					cout<<"Invalid Input";
					getch();
					return false; // InvalidInput
				}
		}
	}
}
bool check(){
	//checking rows
	if(board[0][0]==mark && board[0][1]==mark && board[0][2]==mark) return true; // 1st Row
	if(board[1][0]==mark && board[1][1]==mark && board[1][2]==mark) return true; // 2nd Row
	if(board[2][0]==mark && board[2][1]==mark && board[2][2]==mark) return true; //3rd Row

	//checking Columns
	if(board[0][0]==mark && board[1][0]==mark && board[2][0]==mark) return true; // 1st column
	if(board[0][1]==mark && board[1][1]==mark && board[2][1]==mark) return true; // 2nd column
	if(board[0][2]==mark && board[1][2]==mark && board[2][2]==mark) return true; // 3rd column
		
	//checking diagonals
	if(board[0][0]==mark && board[1][1]==mark && board[2][2]==mark) return true; // diagonal 1
	if(board[0][2]==mark && board[1][1]==mark && board[2][0]==mark) return true; // diagonal 2
	
	return 0;
}