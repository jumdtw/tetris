#include<conio.h>
#include<windows.h>
#include<string.h>
#include<iostream>
#include"main.hpp"

using namespace std;

char field[FIELD_HEIGHT][FIELD_WIDTH];
//すべてのミノが４つのブロックで構成されていることを利用する。
char mino[MINO_NUM][MINO_ALL_ANGLE][4][4];

void init_field(){
    memset(field,0,sizeof(field));
    for(int i=0;i<FIELD_HEIGHT;i++){
        field[i][0] = 1;
        field[i][FIELD_WIDTH-1] = 1;
    }
    for(int i=0;i<FIELD_WIDTH;i++){
        field[FIELD_HEIGHT-1][i] = 1;
    }
}

void update(){
    for(int i=0;i<FIELD_HEIGHT;i++){
        for(int k=0;k<FIELD_WIDTH;k++){
            if(field[i][k]==1){
                cout << "W";
            }else{
                cout << "S";
            }
        }
        cout << "\n";
    }
}

int main(){
    init_field();
    //updateで描画もおこなう
    for(;;){
        if(kbhit()!=0){
            char ch = getch();
            if(ch=='D'){return 0;}
            cout << ch << "\n" << "--------" << endl;
            
        }
        Sleep(1000);
    }
    return 0;
}