// Connor Ruff
#include<iostream>
#include<vector>

using namespace std;

#include"lifeboard.h"



// Creates Empty Boards
Life::Life() {

	
	// Initialize Top Border
	for (int i=0; i < DIM; ++i) {
		board[0][i] = '-';
		temp[0][i] ='-' ; }
	// Initialize Left Border
	for (int i=1; i < DIM-1 ; ++i) {
		board[i][0] = '|' ;
		temp[i][0] = '|'; }
	// Initialize Right Border
	for (int i = 1; i < DIM-1; ++i) {
		board[i][41] = '|';
		temp[i][41] = '|'; }
	// Initialize Bottom Border
	for (int i=0; i < DIM; ++i) {
		board[41][i] = '-';
		temp[41][i] = '-'; }

	// Initialize Rest of Board To Spaces
	for (int i=1; i < DIM-1; ++i) 
		for (int j=1; j < DIM-1; ++j) {
			board[i][j] = ' ';
			temp[i][j] = ' ';}

}

// Prints the Board
void Life::print() {

	system("clear");

	for(int i =0; i< DIM; ++i) {
		for(int j=0; j< DIM; ++j) {
			cout << board[i][j]; 
		}
		cout << endl;
	}
}



// Reads in Command Line From User



// Adds a Cell to the Board
void Life::add( int x, int y) {

	board[x][y] = 'X' ;
}

// Removes a Cell from the Board
void Life::remove(int x, int y) {

	board[x][y]= ' ' ;
}

// Graduates to the Next Iteration
void Life::next(int &go) {

	
	// Cycle Through Each Thingy in Board
	
	for(int i =1; i< DIM-1; ++i) {
		for(int j=1; j< DIM-1; ++j) {
			int count = 0;

			//Count Up Its Neighbors
			if (board[i][j+1] == 'X')
				count += 1;
			if (board[i][j-1]== 'X')
				count +=1;
			if (board[i+1][j] == 'X')
				count += 1;
			if (board[i-1][j] == 'X')
				count += 1;
			if (board[i-1][j-1] == 'X')
				count +=1;
			if (board[i+1][j+1] == 'X')
				count +=1;
			if (board[i+1][j-1] == 'X')
				count +=1;
			if (board[i-1][j+1] == 'X')
				count +=1;

			// Add New Cells
			if ((board[i][j] == ' ')&&(count ==3)) {
					temp[i][j] = 'X';}
			// Kill Cells
			else if ( (board[i][j] == 'X') && ((count != 2) && (count !=3))  ){
					temp[i][j] = ' ';}
			else if ( (board[i][j] == 'X') && ( (count ==2) || (count ==3)) ){
					temp[i][j] = 'X'; }

		}
	}
	// Check if the Board Has Gone Stagnant (To Stop Simulation)
	go = checkifequal();
	// Copy Temp Board Into Official Board
	copy();
	


}

// Copies Temp Board into Board Board
void Life::copy() {

	for (int i=1; i < DIM-1; ++i){
		for (int j=1; j< DIM-1 ; ++j) {
			board[i][j] = temp[i][j] ; 
		}
	}
}

// Determines if Simulation has come to a standstill
int Life::checkifequal() {
	
	// Counts Every Equal Slot
	int count = 0;
	for (int i=1; i < DIM-1; ++i){
		for (int j=1; j< DIM-1; ++j){
			if (board[i][j] == temp[i][j] ){
				count +=1;}
		}
	}
	// If Every Slot Is Equal, Return 0 to Go, Thus Stopping While loop
	if (count == (40*40) )
		return 0;
	else
		return 1;


}

void Life::cleartemp() {

	for(int i=1; i<= 40; ++i)
		for(int j=1; j<=40; ++j)
			temp[i][j] == ' ';

}
