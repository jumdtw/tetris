#include<conio.h>
#include<windows.h>
#include<string.h>
#include<iostream>
#include"main.hpp"

using namespace std;

char field[FIELD_HEIGHT][FIELD_WIDTH];

int main(){
    memset(field,0,sizeof(field));
    for(int i=0;i<FIELD_HEIGHT;i++){
        field[i][0] = 1;
    }
    for(;;){
        printf("a\n");
        if(kbhit()!=0){
            char ch = getch();
            if(ch=='D'){return 0;}
            cout << ch << "\n" << "--------" << endl;
            
        }
        Sleep(1000);
    }
    return 0;
}