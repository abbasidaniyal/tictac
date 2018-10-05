#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

using namespace std;

class Player {
	string name;
	char sym;
	int score;

	public:
		Player() {
			score = 0;
		}

		void putname(string NAME) {
			name=NAME;
		}

		void putsym(char ch) {
			sym=ch;
		}

		string getname() {
			return name;
		}

		char getsym() {
			return sym;
		}

		void register_win() {
			score++;
		}

		int getScore() {
			return score;
		}
}p1, p2;

class Game {
	char GameBoard[9];

	public:
		Game() {
			for (int i=0; i<9; ++i)
				GameBoard[i]='-';
		}

		bool check_pos(int pos) {
			if (GameBoard[pos-1]=='-')
				return true;
			else
				return false;
		}

		void add(int pos, char sym) {
			GameBoard[pos-1] = sym;
		}

		void display() {
			system("CLS");
			cout<<endl;
			cout<<"\n\t\tTIC TAC TOE"<<endl<<endl;
			for (int i=0; i<9 ; ++i) {
				cout<<'\t'<<GameBoard[i];
				if ((i+1)%3==0)
					cout<<endl<<endl;
			}
			cout<<endl;
		}

		int check_winner(char ch) {
			int flag=0;
			for (int i=0; i<7 ; i+=3) {
				if (GameBoard[i]==ch && GameBoard[i+1]==ch && GameBoard[i+2]==ch)
					flag++;
			}

			for (int i=0; i<3 ; i++) {
				if (GameBoard[i]==ch && GameBoard[i+3]==ch && GameBoard[i+6]==ch)
					flag++;
			}
	
			if ((GameBoard[0]==ch && GameBoard[4]==ch && GameBoard[8]==ch)||(GameBoard[2]==ch && GameBoard[4]==ch && GameBoard[6]==ch))
				flag++;

			if (flag==1)
				return 1;
			else 
				return 0;
		}

		void reset() {
			for (int i=0; i<9; ++i)
				GameBoard[i]='-';
		}
}G;

//============================================================================================
//--------------------------------------------------------------------------------------------
//============================================================================================

void createplayer(int n) {
	string name;
	cout<<"\nEnter Name: "; 
	cin>>name;

	if (n==1) {
		p1.putname(name);
		p1.putsym('X');
		cout<<"Your symbol is X"<<endl;
		getch();
	} 
	else if (n==2) {
		p2.putname(name);
		p2.putsym('O');
		cout<<"Your symbol is O"<<endl;
		getch();
	}
}

void signup(){
	cout<<"\n\nEnter PLayer 1 details";
	createplayer(1);

	cout<<"\n\nEnter PLayer 2 details";
	createplayer(2);
}


void play() {		
	int box_number;
	int flag_X = 0, flag_O = 0;

	for (int i=0; i<9; i++) {
		G.display();

		if (flag_X || flag_O)
			break;
		
		if (i%2==0) {
			cout<<p1.getname()<<" Enter box number :- ";
			cin>>box_number;
			
			if (G.check_pos(box_number))
				G.add(box_number,'X');
			else {
				cout<<"Invalid Input"<<endl;
				--i;
				continue;
			}
		}
		else {
			cout<<p2.getname()<<" Enter box number :- ";
			cin>>box_number;
			
			if (G.check_pos(box_number))
				G.add(box_number,'O');
			else {
				cout<<"Invalid Input"<<endl;
				--i;
				continue;
			}
		}

		flag_X = G.check_winner('X');
		flag_O = G.check_winner('O');
	}

	if(flag_X) {
		cout<<"WINNER : X"<<"\nCongratulations "<<p1.getname()<<endl<<endl;
		p1.register_win();
	} else if(flag_O) {
		cout<<"WINNER : O"<<"\nCongratulations "<<p2.getname()<<endl<<endl;
		p2.register_win();
	} else
		cout<<"\nMATCH DRAW\n"<<endl;
}

void show_scoreboard() {
	cout<<endl;
	cout<<p1.getname()<<"'s Score: "<<p1.getScore()<<endl;

	cout<<endl;
	cout<<p2.getname()<<"'s Score: "<<p2.getScore()<<endl<<endl;
}

int main() {
	int choice;
	char ex = 'N';

	cout<<"\n\t\tTIC TAC TOE"<<endl;
	cout<<"1. Play"<<endl;
	cout<<"2. Exit"<<endl;

	cin>>choice;

	switch(choice) {
		case 1: 
			signup();
			do {
				system("CLS");
				play();
				G.reset();
				cout<<"Play again?(Y/N) ...";
				cin>>ex;
			} while(ex!='N');
			show_scoreboard();
			break;
		case 2: return 0;
		default: cout<<"Invalid"; main();
	}
	return 0;
}