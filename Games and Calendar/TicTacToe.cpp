#include<iostream>
#include<stdlib.h>
char board[10]={'0','1','2','3','4','5','6','7','8','9'};
using namespace std;
int checkwin();
int boardgame();
int main()
{ int i,player=1;
 int var=0;
 boardgame();
    do
    {
    if(player==1)
	cout<<"\n\n Player 1st Turn : ";
    else
    cout<<"\n\n Player 2nd Turn : ";
	cin>>i;
    if(i==1&&board[i]=='1')
    {
    if(player==1)
        board[i]='x';
    else
        board[i]='o';
    }
    else if(i==2&&board[i]=='2')
    {
     if(player==1)
        board[i]='x';
     else
        board[i]='o';
    }
    else if(i==3&&board[i]=='3')
    {
     if(player==1)
        board[i]='x';
     else
        board[i]='o';
    }
    else if(i==4&&board[i]=='4')
    {
     if(player==1)
        board[i]='x';
     else
        board[i]='o';
    }
    else if(i==5&&board[i]=='5')
    {
     if(player==1)
        board[i]='x';
     else
        board[i]='o';
    }
    else if(i==6&&board[i]=='6')
    {
     if(player==1)
        board[i]='x';
     else
        board[i]='o';
    }
    else if(i==7&&board[i]=='7')
    {
     if(player==1)
        board[i]='x';
     else
        board[i]='o';
    }
    else if(i==8&&board[i]=='8')
    {
     if(player==1)
        board[i]='x';
     else
        board[i]='o';
    }
    else if(i==9&&board[i]=='9')
    {
     if(player==1)
        board[i]='x';
     else
        board[i]='o';
    }
    else
    {
    cout<<"\n\t\tInvalid Option";
    if(player==1)
    {
        player=2;
    }
    else if(player==2)
    {
        player=1;
    }

	cin.ignore();
    cin.get();
    }
    system("cls");
    boardgame();
    if(checkwin()==1)
        break;
    if(board[1]!='1'&&board[2]!='2'&&board[3]!='3'&&board[4]!='4'&&board[5]!='5'&&board[6]!='6'&&board[7]!='7'&&board[8]!='8'&&board[9]!='9')
    {
    	var=1;
    	break;
    }
    if(player==1)
    {
        player=2;
    }
    else if(player==2)
    {
        player=1;
    }

    }while(1);
    if(player==1&&var!=1)
        cout<<"\n\n\t\tPlayer 1 wins\n";
    else if(player==2&&var!=1)
        cout<<"\n\n\t\tPlayer 2 wins\n";
    if(var==1)
    cout<<"\n\n\t\tGame Drawn";
    return 1;
}
int boardgame()
{
  cout<<"\n\n\t\tTic"<<(char)1<<"Tac"<<(char)1<<"Toe\n\n";
  cout<<"   ######Player 1=X______Player 2=o******\n\n\n";
  cout<<"\t\t"<<board[1]<<"  |  "<<board[2]<<"  |  "<<board[3]<<endl;
  cout<<"\t"<<"      _____|_____|_____"<<endl;
  cout<<"\t\t   |\t |"<<endl;
  cout<<"\t\t"<<board[4]<<"  |  "<<board[5]<<"  |  "<<board[6]<<endl;
  cout<<"\t"<<"      _____|_____|_____"<<endl;
  cout<<"\t\t   |\t |"<<endl;
  cout<<"\t\t"<<board[7]<<"  |  "<<board[8]<<"  |  "<<board[9]<<endl;
}
int checkwin()
{
   int i,j;
   for(i=1;i<=3;i++)
   {
       if(board[i]==board[i+3]&&board[i+3]==board[i+6])
        return 1;
   }
   for(i=1;i<=7;i+=3)
   {
       if(board[i]==board[i+1]&&board[i+1]==board[i+2])
        return 1;
   }
   if(board[1]==board[5]&&board[5]==board[9])
    return 1;
   if(board[3]==board[5]&&board[5]==board[7])
    return 1;
   return 0;
}
