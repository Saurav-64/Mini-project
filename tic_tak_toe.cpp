#include<iostream>
#include<ctime>

void DrawBoard(char * spaces);
void PlayerMove(char * spaces , char player1);
void COmputerMove(char * spaces, char computer);
bool CheckWinner(char * spaces , char player , char computer);
bool CheckTie(char *spaces);

int main(){
    char spaces[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

  DrawBoard(spaces);
  while(running){
    PlayerMove(spaces,player);
    DrawBoard(spaces);
    COmputerMove(spaces,computer);
    DrawBoard(spaces);
    if(CheckWinner(spaces,player,computer)){
        running = false;
        break;
    }

    else if(CheckTie(spaces)){
        running=false ;
        break;
    }
  }

}

void DrawBoard(char * spaces){
    std::cout<<"\n";
std::cout<<"     |     |     "<<std::endl;
std::cout<<"  "<<spaces[0]<< "  |  " <<spaces[1] << "  |  "<<spaces[2]<<std::endl;
std::cout<<"_____|_____|_____"<<std::endl;
std::cout<<"     |     |     "<<std::endl;
std::cout<<"  "<<spaces[3]<< "  |  " <<spaces[4] << "  |  "<<spaces[5]<<std::endl;
std::cout<<"_____|_____|_____"<<std::endl;
std::cout<<"     |     |     "<<std::endl;
std::cout<<"  "<<spaces[6]<< "  |  " <<spaces[7] << "  |  "<<spaces[8]<<std::endl;
std::cout<<"     |     |     "<<std::endl;
std::cout<<"\n";



}
void PlayerMove(char * spaces , char player){
int number;
do{
std::cout<< "Enter a spot to place a marker (1-9) : ";
std::cin>> number ;
number--;
if(spaces[number]==' '){
    spaces[number]=player;
    break;
}
}while(!number > 0 || !number < 8 );
}
void COmputerMove(char * spaces, char computer){
srand(time(NULL));

while(true){
    int number=rand()%9;
    if(spaces[number]==' '){
        spaces[number]=computer;
        break;
    }
}
}
bool CheckWinner(char * spaces , char player , char computer){
     
    if(spaces[0] != ' ' && spaces[0]==spaces[1]&&spaces[1]==spaces[2]){
        spaces[0]==player?std::cout<<"YOU WIN ! \n " : std::cout<<"YOU LOSE ! \n";
    }
    else if (spaces[3] != ' ' && spaces[3]==spaces[4]&&spaces[4]==spaces[5]){
        spaces[3]==player?std::cout<<"YOU WIN ! \n " : std::cout<<"YOU LOSE ! \n";
    }

    else if (spaces[6] != ' ' && spaces[6]==spaces[7]&&spaces[7]==spaces[8]){
        spaces[6]==player?std::cout<<"YOU WIN ! \n " : std::cout<<"YOU LOSE ! \n";
    }

    else if (spaces[0] != ' ' && spaces[0]==spaces[3]&&spaces[3]==spaces[6]){
        spaces[0]==player?std::cout<<"YOU WIN ! \n " : std::cout<<"YOU LOSE ! \n";
    }
    
    else if (spaces[1] != ' ' && spaces[1]==spaces[4]&&spaces[4]==spaces[7]){
        spaces[1]==player?std::cout<<"YOU WIN ! \n " : std::cout<<"YOU LOSE ! \n";
    }

    else if (spaces[2] != ' ' && spaces[2]==spaces[5]&&spaces[5]==spaces[8]){
        spaces[2]==player?std::cout<<"YOU WIN ! \n " : std::cout<<"YOU LOSE ! \n";
    }

    else if (spaces[0] != ' ' && spaces[0]==spaces[4]&&spaces[4]==spaces[8]){
        spaces[0]==player?std::cout<<"YOU WIN ! \n " : std::cout<<"YOU LOSE ! \n";
    }


    else if (spaces[2] != ' ' && spaces[2]==spaces[4]&&spaces[4]==spaces[6]){
        spaces[2]==player?std::cout<<"YOU WIN ! \n " : std::cout<<"YOU LOSE ! \n";
    }
    else{
        return false;
    }

    return true;



}
bool CheckTie(char *spaces){

    for(int i = 0 ; i < 9 ; i++){
        if(spaces[i]==' '){
            return false ;
        }
    }
    std::cout<<"IT'S TIE\n";
    return true ;
}