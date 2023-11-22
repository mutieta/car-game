#include <iostream>
#include <conio.h>
#include <dos.h>
#include <windows.h>
#include <time.h>

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

int enemyY[3];
int enemyX[3];
int enemyFlag[3];
int car[4][4] = { ' ','+','+',' ',
                '+', '+', '+','+',
                ' ', '+', '+', ' ',
                '+', '+', '+', '+'};
int carPos = WIN_WIDTH/2;
int score = 0;

void gotoxy(int x, int y){
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoloeCursorPosition(console, CursorPosition);
}

void setcursor(bool visible, DWORD size){
    if(size == 0)
    size = 20;

    CONSOLE_SURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(console,&lpCursor);
}

void drawBorder(){
    for(int i = 0; i < SCREEN_HEIGHT; i++){
        for (int j=0; j < 17; j++){
            gotoxy(0+j,i); cout<< "+";
            gotoxy(WIN_WIDTH-j,i); cout<<"+";
        }
    }
    for (int i = 0; i<SCREEN_HEIGHT; i++){
        gotoxy(SCREEN_WIDTH,i); cout<<"+";
    }
}

void genEnemy(int ind){
    enemyX[ind] = 17 + rand()%(33);
}

void drawEnemy(int ind){
    if (enemyFlag[ind] == true){
        gotoxy(enemyX[ind], enemyY[ind]); cout<<"****";
        gotoxy(enemyX[ind], enemyY[ind]+1); cout<<" ** ";
        gotoxy(enemyX[ind], enemyY[ind]+2); cout<<"****";
        gotoxy(enemyX[ind], enemyY[ind]+3); cout<<" ** ";
    }
}

void eraseEnemy(int ind){
    if(enemyFlag[ind] == true ){
        gotoxy(enemyX[ind], enemyY[ind]); cout<<"    ";
        gotoxy(enemyX[ind], enemyY[ind]+1); cout<<"    ";
        gotoxy(enemyX[ind], enemyY[ind]+2); cout<<"    ";
        gotoxy(enemyX[ind], enemyY[ind]+3); cout<<"    ";
        
    }
}

void resetEnemy(int ind){
    eraseEnemy(ind);
    enemyY[ind] = 1;
    genEnemy(ind);
}

void drawCar(){
    for(int i = 0; i<4; i++){
        for (int j=0; j<4; j++){
            gotoxy(j+carPos, i+22); cout<<car[i][j];
        }
    }
}

void eraseCar(){
    for (int i = 0; i <4; i++){
        for(int j=0; j<4; j++){
            gotoxy(j+carPos, i+22); cout<<" ";
        }
    }
}

int collision(){
    if( enemyY[0]+4 >= 23){
        if(enemyX[0] + 4 - carPos >= 0 && enemyX[0] + 4 - carPos < 9){
           return 1; 
        }
    }
    return 0;
}

void gameover(){
    system("cls");
    cout<<endl;
    cout<<"\t\t----------------------------"<<endl;
    cout<<"\t\t-------- Game Over ---------"<<endl;
    cout<<"\t\t----------------------------"<<endl<<endl;
    cout<<"\t\tPress any key to go back to the menu.";
    getch();
}

void updateScore(){
    gotoxy(WIN_WIDTH + 7, 5); cout<<"Score: "<<score<<endl;
}

void instruction(){

    system("cls");
    cout<<"Instructions";
    cout<<"\n---------------------";
    cout<<"\n Avoid Cars by moving left or right. ";
    cout<<"\n\n Press 'a' to move left";
    cout<<"\n Press 'd' to move right";
    cout<<"\n Press 'escape' to exit";
    cout<<"\n\nPress any key to go back to the menu";
    getch;
}
 void play(){
    carPos = -1 + WIN_WIDTH/2;
    score = 0;
    enemyFlag[0] = 1;
    enemyFlag[1] = 0;
    enemyY[0] = enemyY[1] = 1;

    system ("cls");
    drawBorder();
    updateScore();
    genEnemy[0];
    genEnemy[1];

    gotoxy(18, 5); cout<<"Press any key to start";
     
 }