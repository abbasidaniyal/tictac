#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

class player
{
		string name;
		char sym;
	
	public :
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


}p1,p2;

class game
{
		char arr[10];

	public :

		game()
		{	
			int i;
			for ( i = 0; i < 9; ++i)
			{
				arr[i]='-';
			}
		}

		int check_pos(int pos)
		{
			if (arr[pos-1]=='-')
				return 1;
			else return 0;
		}

		void add(int pos,char sym)
		{
			arr[pos-1]=sym;
		}		


		void display()
		{
			int i;
			for (i = 0; i < 9 ; ++i)
			{
				cout<<arr[i];
				
				if ( (i+1)%3==0)
					cout<<endl;

			}
		}




		void check_game()
		{

			int flag=0;
			int i;
			for (i = 0; i < 9; ++i)
			{
				if (arr[i]=='-')
					flag++;
			}

			if (flag==0)
			{
				cout<<"\n Game Over!";

			}

		}


		int check_winner(char ch)
		{

			int flag=0;
			int i;
			for (i = 0; i <7 ; i+=3)
			{
				if (arr[i]==ch && arr[i+1]==ch && arr[i+2]==ch)
					flag++;
			}

			for (i = 0; i <3 ; i++)
			{
				if (arr[i]==ch && arr[i+3]==ch && arr[i+6]==ch)
					flag++;
			}
	
			if  ((arr[0]==ch && arr[4]==ch && arr[8]==ch)||(arr[2]==ch && arr[4]==ch && arr[6]==ch))
				flag++;


			if (flag==1)
			{
				return 1;
			}
			else return 0;
		}




}G;






void createplayer()
{
	static int n=1;
	string name;

	cout<<"\n\nEnter Name\n"; 
	// getline(cin, name);
	cin>>name;

	if (n==1)
	{
		p1.putname(name);
		p1.putsym('X');
		n++;
		cout<<"\nYour symbol is X"<<endl;
		return ;
	}

	if (n==2)
	{
		p2.putname(name);
		p2.putsym('O');
		cout<<"\nYour symbol is O"<<endl;
		return ;
	}



}

void signup()
{
	//system("cls");
	cout<<"\n\nEnter PLayer 1 details";
	createplayer();

	cout<<"\n\nEnter PLayer 2 details";
	createplayer();
}


void play()
{
	signup();
		
	int flag_X = 0, flag_O = 0;

	int i,no;


	int check=0;

	for (i = 0; i < 9; ++i)
	{
		//system("cls");
		G.display();


		flag_X=G.check_winner('X');	


		flag_O=G.check_winner('O');



		if (flag_X || flag_O)
			break ;


		G.check_game();
		

		if (i%2==0)
		{
			cout<<p1.getname()<<" Enter box no :- ";
			cin>>no;
			check=G.check_pos(no);
			if (check==1)
				G.add(no,'X');
			else
			{
				cout<<"Invalid Input"<<endl;
				i--;
				continue ;
			}
		}
		else
		{
			cout<<p2.getname()<<" Enter box no :- ";
			cin>>no;
			G.add(no,'O');
		}

	}


	if(flag_O) 
	{
		cout<<"WINNER : O"<<endl;
	}
	else if(flag_X) 
	{
		cout<<"WINNER : X"<<endl;
	}
	else 
	{
		cout<<"DRAW"<<endl;
	}


}






int main()
{
	int choice;

	// system("cls");

	cout<<"\n\t\tTIC TAC";

	cout<<"\n\n1. Play \n\n2. Exit\n";

	cin>>choice;

	switch(choice)
	{
		case 1: play();break;
		case 2: return 0 ;
		default: cout<<"Invalid"; main();
	}


	return 0;
}