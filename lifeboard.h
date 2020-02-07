// Connor Ruff
#include<iostream>
#include<vector>
#include<cstdlib>
#include<unistd.h>
#include<fstream>
using namespace std;

const int DIM = 42;

class Life {

	public:
	Life();
	void create();
	void command();
	void add(int,int);
	void print();
	void remove(int,int);
	void next(int &);
	void copy();
	int checkifequal();
	void cleartemp();
	private:
	char board[DIM][DIM];
	char temp[DIM][DIM];

};
