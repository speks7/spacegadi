#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

int cor1[400][2];
int cor2[400][2];
int x1=156,y1=340,x2=349,y2=340;
long int score=0;

void load();

void main(){

    int gd=DETECT;
    int gm,h=1,i,j,z,m,d;
    long int c=1;char q;
    float n=40;
    initgraph(&gd,&gm,"C:\\TC3\\BGI");
    load();

}

void load(){

    int i;
    textcolor(BLACK); //background color
    moveto(200,180); //loading process
    outtext("Loading, please wait........");

}