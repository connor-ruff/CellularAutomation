// Connor Ruff
#include<iostream>
using namespace std;
#include"lifeboard.h"

int main(int argc, char *argv[]) {

	// Interactive Mode
	if (argc == 1) {
		// Declare Board Array
		Life b;
	
		// Run Until User Quits
		char a;
		while(a!= 'q') {
			b.print();
			cout << "COMMAND: ";
			cin >> a;

			int x,y;
			//User Selects to Add Cell
			if(a=='a') {
				cin >> x >> y;
				
				b.add(x,y);
			}
			//User Selects to Remove Cell
			else if (a=='r') {
				cin >> x >> y;
				b.remove(x,y);
			}
			// Next Iteration
			else if (a =='n') {
				int dummy =1;//Dummy needed since 'p' option requires a pass by ref. int
				b.next(dummy);
			}
			// Run Continously Until Stagnation
			else if (a=='p'){
				int go=1;
				while(go!=0) {
					b.print();
					usleep(500000);//Pause in between
					b.cleartemp();//Clear temp board
					b.next(go);
				}
			}



		}

		
		


		cout << endl;
	}

	// Batch Mode 
	else if (argc == 2) {

		// Create Board
		Life b;

		// Open File To Read
		ifstream ifs;
		ifs.open(argv[1]);

		if(!ifs) {
			cout << "Error Opening File" << endl;
			return 1;}
		
		// Add Each Element From File To Board
		char a;
		int x;
		int y;
		ifs >> a >> x >> y;
		while(a !='p'){
					
			//User Selects to Add Cell
			if(a=='a') {
				b.add(x,y);
			}
			//User Selects to Remove Cell
			else if (a=='r') {
				b.remove(x,y);
			}
			ifs >> a >> x >> y;


		}
		
		
		// Once 'p' is reached, run the simulation
		int go=1;
		while(go!=0) {
			b.print();
			usleep(5000);//Pause in between
			b.cleartemp();//Clear temp board
			b.next(go);
		}

	}
		
	
	// If the User Did Not Enter Approrpriate Amount of Arguments		
	else {
		cout << "Error. Must Include Zero or One Data Files" << endl;
		return 1; }

	



	return 0;
}
