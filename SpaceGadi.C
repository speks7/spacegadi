#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

int cor1[400][2];
int cor2[400][2];
int x1=156,y1=340,x2=349,y2=340;
long int score=0;

void load();
void boarder();

void main(){

    int gd=DETECT;
    int gm,h=1,i,j,z,m,d;
    long int c=1;char q;
    float n=40;
    initgraph(&gd,&gm,"C:\\TC3\\BGI");
    load();
    boarder();

}

void load(){

    int i;
    textcolor(BLACK); //background color
    moveto(200,180); //loading process
    outtext("Loading, please wait........");
    for(i=0;i<600;i+=2)
    {
        setcolor(3); //loading bar color
        line(20,380,i+39,380);
        delay (10);
    }
    setcolor(WHITE);
    moveto(240,200);
    outtext("Loading Completed!"); //loading
    delay(1000);
    clrscr();

}

void boarder(){

}