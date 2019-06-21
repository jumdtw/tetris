#include<conio.h>
#include<windows.h>
#include<cstring>
#include<string.h>
#include<iostream>
#include"main.hpp"

using namespace std;

char static_field[FIELD_HEIGHT][FIELD_WIDTH];
char display_field[FIELD_HEIGHT][FIELD_WIDTH];
//すべてのミノが４つのブロックで構成されていることを利用する。


int minoX=5,minoY=5,minoAngle=0;
char mino[MINO_NUM][MINO_ALL_ANGLE][MINO_HEIGHT][MINO_WIDTH] ={
        // t mino 0
        0,0,0,0,
        0,1,0,0,
        1,1,1,0,
        0,0,0,0,
        // t mino 90
        0,0,0,0,
        0,1,0,0,
        0,1,1,0,
        0,1,0,0,
        //t mino 180
        0,0,0,0,
        0,0,0,0,
        1,1,1,0,
        0,1,0,0,
        //t mino 270
        0,0,0,0,
        0,1,0,0,
        1,1,0,0,
        0,1,0,0,


        // I mino 0
            0,1,0,0,
            0,1,0,0,
            0,1,0,0,
            0,1,0,0,
        // I mino 90 
            0,0,0,0,
            0,0,0,0,
            1,1,1,1,
            0,0,0,0,
        //I mino 180
            0,1,0,0,
            0,1,0,0,
            0,1,0,0,
            0,1,0,0,
        //I mino 270
            0,0,0,0,
            0,0,0,0,
            1,1,1,1,
            0,0,0,0,
        
        // O mino 0
            0,0,0,0,
            0,1,1,0,
            0,1,1,0,
            0,0,0,0,
        // O mino 90 
            0,0,0,0,
            0,1,1,0,
            0,1,1,0,
            0,0,0,0,
        // O mino 180
            0,0,0,0,
            0,1,1,0,
            0,1,1,0,
            0,0,0,0,
        // O mino 270
            0,0,0,0,
            0,1,1,0,
            0,1,1,0,
            0,0,0,0,
        
        // L mino 0
            0,0,0,0,
            0,1,0,0,
            0,1,0,0,
            0,1,1,0,
        // L mino 90
            0,0,0,0,
            0,0,0,0,
            1,1,1,0,
            1,0,0,0,
        // L mino 180 
            0,0,0,0,
            1,1,0,0,
            0,1,0,0,
            0,1,0,0,
        // L mino 270 
            0,0,0,0,
            0,0,1,0,
            1,1,1,0,
            0,0,0,0,
        
        // J mino 0
            0,0,0,0,
            0,1,0,0,
            0,1,0,0,
            1,1,0,0,
        // J mino 90
            0,0,0,0,
            1,0,0,0,
            1,1,1,0,
            0,0,0,0,
        // J mino 180 
            0,0,0,0,
            0,1,1,0,
            0,1,0,0,
            0,1,0,0,
        // J mino 270 
            0,0,0,0,
            0,0,0,0,
            1,1,1,0,
            0,0,1,0,
        
        // S mino 0
            0,0,0,0,
            0,1,1,0,
            1,1,0,0,
            0,0,0,0,
        // S mino 90 
            0,0,0,0,
            0,1,0,0,
            0,1,1,0,
            0,0,1,0,
        // S mino 180 
            0,0,0,0,
            0,1,1,0,
            1,1,0,0,
            0,0,0,0,
        // S mino 270
            0,0,0,0,
            0,1,0,0,
            0,1,1,0,
            0,0,1,0,
        
        // Z mino 0
            0,0,0,0,
            1,1,0,0,
            0,1,1,0,
            0,0,0,0,
        // Z mino 90
            0,0,0,0,
            0,0,1,0,
            0,1,1,0,
            0,1,0,0,
        // Z mino 180
            0,0,0,0,
            1,1,0,0,
            0,1,1,0,
            0,0,0,0,
        // Z mino 270
            0,0,0,0,
            0,0,1,0,
            0,1,1,0,
            0,1,0,0,
           
    };

void init_field(){
    memset(static_field,0,sizeof(static_field));
    for(int i=0;i<FIELD_HEIGHT;i++){
        static_field[i][0] = 1;
        static_field[i][FIELD_WIDTH-1] = 1;
    }
    for(int i=0;i<FIELD_WIDTH;i++){
        static_field[FIELD_HEIGHT-1][i] = 1;
    }
    memcpy(*display_field,*static_field,FIELD_HEIGHT*FIELD_WIDTH);
}



void Print_field(){
    //display_field init 
    memcpy(*display_field,*static_field,FIELD_HEIGHT*FIELD_WIDTH);
    // mino print 
    for(int i=0;i<MINO_HEIGHT;i++){
        for(int k=0;k<MINO_WIDTH;k++){
            display_field[minoY+i][minoX+k] = mino[MINO_I][MINO_0+minoAngle][i][k];
        }
    }
    //display print     
    for(int i=0;i<FIELD_HEIGHT;i++){
        for(int k=0;k<FIELD_WIDTH;k++){
            if(display_field[i][k]==1){
                cout << "W ";
            }else{
                cout << "  ";
            }
        }
        cout << "\n";
    }
}

void update(){
    Print_field();
}

int main(){
    char ch;
    init_field();
    for(;;){
        if(kbhit()!=0){
            switch(ch=getch()){
                //hard drop
                case 'i':
                    break;
                //反時計回転
                case 'j':
                    minoAngle--;
                    if(minoAngle<0){minoAngle=3;}
                    break;
                //下移動
                case 'k':
                    minoY++;
                    break;
                //時計回転
                case 'l':
                    minoAngle++;
                    if(minoAngle>3){minoAngle=0;}
                    break;
                case 'a':
                    minoX--;
                    if(minoX<1){minoX=1;}
                    break;
                case 'd':
                    minoX++;
                    if(minoX>FIELD_WIDTH-1){minoX=FIELD_WIDTH-1;}
            }
            if(ch=='D'){return 0;}
        }
        system("cls");
        update();
        Sleep(1000);
    }
    return 0;
}