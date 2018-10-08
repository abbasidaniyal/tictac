#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <unistd.h>
#include <vector>



using namespace std;




class Player 
{
	string name;
	char sym;
	int score;

	public:
		Player() 
	    {
			score = 0;
			name="Bot";
		}

		void putname(string NAME) 
    	{
			name=NAME;
		}

		void putsym(char ch) 
    	{
			sym=ch;
		}

		string getname() 
    	{
			return name;
		}

		char getsym() 
    	{
			return sym;
		}

		void register_win() 
	    {
			score++;
		}

		int getScore() 
    	{
			return score;
		}
}p1, p2, ptemp;






class bot
{
	char sym;
	int score;

	public:
		bot()
		{
			sym='O';
			score=0;
		}


		
		void putsym(char ch) 
    	{
			sym=ch;
		}

		
		char getsym() 
    	{
			return sym;
		}

		void register_win() 
	    {
			score++;
		}

		int getScore() 
    	{
			return score;
		}

}b;


class Game 
{
	char GameBoard[9];


	public:
		Game() 
		{
			for (int i=0; i<9; ++i)
				GameBoard[i]='-';
		}

		bool check_pos(int pos) 
		{
			if (GameBoard[pos-1]=='-')
				return true;
			else
				return false;
		}

		char check_ele(int pos)
		{
			return GameBoard[pos-1];
		}

		void add(int pos, char sym) 
		{
			GameBoard[pos-1] = sym;
		}

		void display() 
		{
			system("CLS");
			cout<<endl;
			cout<<"\n\t   TIC TAC TOE"<<endl<<endl;
			for (int i=0; i<9 ; ++i) 
     		{
				cout<<'\t'<<GameBoard[i];
				if ((i+1)%3==0)
					cout<<endl<<endl;
			}
			cout<<endl;
		}

		int check_winner(char ch) 
    	{


			int flag=0;
			for (int i=0; i<7 ; i+=3) 
      		{
				if (GameBoard[i]==ch && GameBoard[i+1]==ch && GameBoard[i+2]==ch)
					flag++;
			}

			for (int i=0; i<3 ; i++) 
     		{
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

		void reset() 
	    {
			for (int i=0; i<9; ++i)
				GameBoard[i]='-';
		}
}G;



int calculatebot()
{

	int box_number;
	
	std::vector<int> free, occupied;


	for (int i = 0; i < 9; ++i)
	{
		if (G.check_pos((i+1)))
		{
			free.push_back(i+1);
		}
	}



	for (int i = 0; i < 9; ++i)
	{
		if (!G.check_pos((i+1)))
		{
			occupied.push_back(i+1);
		}
	}



	// if (occupied[0] && pos ==2)
	// {
	// 	/* code */
	// }







	box_number= NULL;


	return box_number;


}


void createplayer(int n) 
{
	string name;
  
	cout<<"\n\nEnter Name - "; 

	cin>>name;

	if (n==1) 
	{
		p1.putname(name);
		p1.putsym('X');
		cout<<endl<<"Your symbol is X"<<endl;

	} 
	else if (n==2) 
  	{
		p2.putname(name);
		p2.putsym('O');
		cout<<endl<<"Your symbol is O"<<endl;
		
	}
}


void signup()
{
	system("CLS");
	cout<<"\n\nEnter Player 1 details";
	createplayer(1);

	cout<<"\n\nEnter Player 2 details";
	createplayer(2);

	cout<<endl<<"Sign up complete! Press any key to continue.";
	getch();

}




void playmulti()
{


	int box_number;
	int flag_X = 0, flag_O = 0;


	for (int i=0; i<9; i++) 
  	{
		G.display();

		if (flag_X || flag_O )
			break;
		
		if (i%2==0) 
   		{
			cout<<p1.getname()<<" enter box number :- ";
			cin>>box_number;
			
			if (G.check_pos(box_number))
				G.add(box_number,'X');
			else 
     		{
				cout<<"Invalid Input"<<endl;
				sleep(2);
				--i;
				continue;
			}
		}
		else 
	    {
			
	    	box_number=calculatebot();
	    	G.add(box_number, 'O');


		}

		flag_X = G.check_winner('X');
		flag_O = G.check_winner('O');
	}

	G.display();
	
	if(flag_X) 
  	{
		cout<<"WINNER : X"<<"\nCongratulations "<<p1.getname()<<endl<<endl;
		p1.register_win();
	} 
  	else if(flag_O) 
  	{
		cout<<"WINNER : O"<<"\nCongratulations "<<p2.getname()<<endl<<endl;
		p2.register_win();
	} 
	else
		cout<<"\nMATCH DRAW\n"<<endl;



















}



void play() 
{		
	int box_number;
	int flag_X = 0, flag_O = 0;


	for (int i=0; i<9; i++) 
  	{
		G.display();

		if (flag_X || flag_O )
			break;
		
		if (i%2==0) 
   		{
			cout<<p1.getname()<<" enter box number :- ";
			cin>>box_number;
			
			if (G.check_pos(box_number))
				G.add(box_number,'X');
			else 
     		{
				cout<<"Invalid Input"<<endl;
				sleep(2);
				--i;
				continue;
			}
		}
		else 
	    {
			cout<<p2.getname()<<" enter box number :- ";
			cin>>box_number;
			
			if (G.check_pos(box_number))
				G.add(box_number,'O');
			else 
    		{
				cout<<"Invalid Input"<<endl;
       			sleep(2);
				--i;
				continue;
			}
		}

		flag_X = G.check_winner('X');
		flag_O = G.check_winner('O');
	}

	G.display();
	
	if(flag_X) 
  	{
		cout<<"WINNER : X"<<"\nCongratulations "<<p1.getname()<<endl<<endl;
		p1.register_win();
	} 
  	else if(flag_O) 
  	{
		cout<<"WINNER : O"<<"\nCongratulations "<<p2.getname()<<endl<<endl;
		p2.register_win();
	} 
	else
		cout<<"\nMATCH DRAW\n"<<endl;
}

void show_scoreboard() 
{
	cout<<endl;
	cout<<p1.getname()<<"'s Score: "<<p1.getScore()<<endl;

	cout<<endl;
	cout<<p2.getname()<<"'s Score: "<<p2.getScore()<<endl<<endl;

	getch();
}

int main() 
{
	int choice;
	char ex = 'N';
  	system("cls");


	cout<<"\n\t\tTIC TAC TOE"<<endl;
	cout<<"1. Play with Friend"<<endl;
	cout<<"2. Play with Bot"<<endl;
	cout<<"3. Exit"<<endl;

	cout<<"Choice - ";
	cin>>choice;

	switch(choice) 
	{
		case 1: 
			signup();
			do 
			{
				system("CLS");
				play();
				G.reset();
				{
					ptemp=p1;
					p1=p2;
					p2=ptemp;
				}
				cout<<"Play again?(Y/N) ...";
				cin>>ex;

			} while(ex!='N');
			show_scoreboard();
			break;

		case 2: 
			{	
				system("CLS");
				cout<<"\n\nEnter Player details";
				createplayer(1);
				playmulti();
			}
				
		case 3: return 0;
		default: cout<<"Invalid";sleep(2); main();
	}

	
	return 0;
}