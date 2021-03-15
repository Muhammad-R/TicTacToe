#include <iostream>
#include <cmath>
using namespace std;


char A[3][3]{{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn = 'X';
int row,column;
bool draw=false;


 void displayboard(){
    
     system("cls");
 cout<<"\t     |     |     \n";
    cout<<"\t "<<A[0][0]<<"   |  "<<A[0][1]<<"  |  "<<A[0][2]<<"  \n";
    cout<<"\t_____|_____|_____\n";
    cout<<"\t     |     |     \n";
    cout<<"\t "<<A[1][0]<<"   |  "<< A[1][1]<<"  |  "<< A[1][2]<<" \n";
    cout<<"\t_____|_____|_____\n";
    cout<<"\t     |     |     \n";
    cout<<"\t "<<A[2][0]<<"   |  " << A[2][1]<<"  |  "<< A[2][2]<<" \n";
    cout<<"\t     |     |     \n";
 };



void playerturn(){
        
        int choice;
        if (turn == 'X') {
        cout <<"\n\tPlayer Ones [X] turn ";
        
        } 
        
        if (turn == 'O') {
        cout <<"\n\tPlayer Twos [O] turn ";
        }
        cin>>choice;
        
        switch(choice){
            case 1:
                row = 0; column=0;
                break;
            case 2:
                row = 0; column=1;
                break;
            case 3:
                row = 0; column=2;
                break;
            case 4:
                row = 1; column=0;
                break;
            case 5:
                row = 1; column=1;
                break;
            case 6:
                row = 1; column=2;
                break;
            case 7:
                row = 2; column=0;
                break;
            case 8:
                row = 2; column=1;
                break;
            case 9:
                row = 2; column=2;
                break;
            default:
                cout << "Invalid Choice"<<endl;
                break;
        }
        if (turn == 'X' && A[row][column]!='X' && A[row][column]!='O')
        {
            A[row][column]='X';
            turn = 'O';
        }
        
        else if (turn == 'O'&& A[row][column]!='X'&& A[row][column]!='O'){
            A[row][column]='O';
            turn = 'X';
        }
            
        else{
            cout << "BOX FILLED TRY AGAIN!\n\n"<< endl;
            playerturn();
        }
}




bool gameover(){
    
    for (int i=0; i<3; i++)
    if ( A[i][0] == A[i][1] && A[i][1] == A[i][2])
    return false;
    
    for (int j=0; j<3; j++)
    if  (A[0][j] == A[1][j] && A[1][j] == A[2][j])
    return false;
    
    
    if ( A[0][0]== A[1][1]&&A[1][1]==A[2][2])
    return false;
    
    if ( A[2][0]== A[1][1]&&A[1][1]==A[0][2])
    return false;
    
     for (int i=0; i<3; i++)
     for (int j=0; j<3; j++)
     if ( A[i][j] !='X' && A[i][j] !='O')
        return true;
    
   //draw
   draw = true;
   return false;
    
}


int main()

{  
    
    
    
    cout<< endl;
	cout << "  T I C  T A C  T O E" << endl;
    cout << "\tPlayer One [X]\n";
    cout << "\tPlayer Two [O]\n";
    
    while(gameover())
    {
    displayboard();
    playerturn();
    displayboard();
    gameover();
    

    
    
    }
    
    if (turn=='O' && draw == false)
    cout << "Player One [X] Wins!!"<<endl;
     if (turn=='X' && draw == false)
    cout << "Player Two [O] Wins!!"<<endl;
    else if (draw==true)
    cout<<"Game Draw!\n";
        
}
