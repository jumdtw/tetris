#include<conio.h>
#include<windows.h>
#include<cstring>
#include<string.h>
#include<iostream>
#include<random>
#include<time.h>
#include"main.hpp"

using namespace std;

char static_field[FIELD_HEIGHT][FIELD_WIDTH];
char display_field[FIELD_HEIGHT][FIELD_WIDTH];
//すべてのミノが４つのブロックで構成されていることを利用する。


int minoX=5,minoY=0,minoAngle=0,minotype=4;
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
            display_field[minoY+i][minoX+k] |= mino[minotype][minoAngle][i][k];
        }
    }
    //display print     
    for(int i=0;i<FIELD_HEIGHT;i++){
        for(int k=0;k<FIELD_WIDTH;k++){
            if(display_field[i][k]==1){
                cout << "O ";
            }else{
                cout << ". ";
            }
        }
        cout << "\n";
    }
}

bool hitcheck(int minoX,int minoY,int minotype,int minoangle){
    for(int i=0;i<MINO_HEIGHT;i++){
        for(int k=0;k<MINO_WIDTH;k++){
            if(mino[minotype][minoangle][i][k]&&static_field[minoY+i][minoX+k]){
                return false;
            }
        }
    }
    return true;
}

void update(){
    cout << minoX << endl;
    cout << minoY << endl;
    cout << minotype << endl;
    Print_field();
}

void castline(int y){
    for(int i=y;i>=0;i--){
        for(int k=1;k<FIELD_WIDTH-1;k++){
            static_field[i][k] = static_field[i-1][k];
        }
    }
}

void deleteline(int y){
    for(int i=1;i<FIELD_WIDTH-1;i++){
        static_field[y][i] = 0;
    }
    castline(y);
}

void checkline(){
    bool flag = true;
    int y = 0;
    for(int i=1;i<FIELD_HEIGHT-1;i++){
        y = i;
        for(int k=1;k<FIELD_WIDTH-1;k++){
            if(static_field[i][k]==0){
                flag = false;
            }
        }
        if(flag){
            deleteline(y);
        }else{
            flag = true;
        }
    }
    
}

int main(){
    char ch;
    int buftime = 0,keytime=1000;
    random_device rnd;
    init_field();
    for(;;){
        if(kbhit()!=0){
            switch(ch=getch()){
                
                //hard drop
                case 'i':
                    break;
                //左移動
                case 'j':
                    if(hitcheck(minoX-1,minoY,minotype,minoAngle)){
                        minoX--;
                    }
                    break;
                //下移動
                case 'k':
                    if(hitcheck(minoX,minoY+1,minotype,minoAngle)){
                        minoY++;
                    }
                    break;
                //右移動
                case 'l':
                    if(hitcheck(minoX+1,minoY,minotype,minoAngle)){
                        minoX++;
                    }
                    break;
                //反時計回り
                case 'a':
                    if(hitcheck(minoX,minoY,minotype,minoAngle-1)){
                        minoAngle--;
                        if(minoAngle<0){minoAngle=3;}
                    }
                    break;
                //時計回り
                case 'd':
                    if(hitcheck(minoX,minoY,minotype,minoAngle+1)){
                        minoAngle++;
                        if(minoAngle>3){minoAngle=0;}
                    }
                    break;
            }
            if(ch=='D'){return 0;}
        }
        system("cls");
        //drop mino with time
        buftime += 1000/60;
        if(buftime >= 100){
            buftime = 0;
            if(hitcheck(minoX,minoY+1,minotype,minoAngle)){
                minoY++;
            }else{
                for(int i=0;i<MINO_HEIGHT;i++){
                    for(int k=0;k<MINO_WIDTH;k++){
                        static_field[minoY+i][minoX+k] |= mino[minotype][minoAngle][i][k];
                    }
                }
                minotype += 1;
                minoX = 5;
                minoY = 0;
                if(minotype>=MINO_NUM){minotype=0;}
            }
        }
        checkline();
        update();
        Sleep(1000/60);
    }
    return 0;
}