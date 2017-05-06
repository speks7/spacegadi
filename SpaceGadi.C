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
void over(long int);

void main(){

    int gd=DETECT;
    int gm,h=1,i,j,z,m,d;
    long int c=1;char q;
    float n=40;
    initgraph(&gd,&gm,"C:\\TC3\\BGI");
    load();
    boarder();
    for(i=0;i<10;i++)
    {
        cor1[i][0]=0;
        cor2[i][0]=0;
    }
    i=i-1;
    m=i;
    while(1){

        h++;
        if(c%20==0) //for first object system
	    {
		    i=i+1;
		    z=rand()%16;
		    if(z%3==0)
		    {
			    cor1[i][0]=156;
			    cor1[i][1]=25;
		    }
		    else
		    {
			    cor1[i][0]=251;
			    cor1[i][1]=25;
		    }
	    }
        for(j=i-8;j<=i;j++)
	    {
		    if(cor1[j][0]!=0)
		    {
			    if(cor1[j][0]==x1&&cor1[j][1]>y1&&y1+40>=cor1[j][1])
			        goto label;
			    if(cor1[j][1]>25)
				    objclr(cor1[j][0],cor1[j][1]-5);
			    if(cor1[j][1]+20>=418)
			    {
				    score++;
				    objclr(cor1[j][0],cor1[j][1]-5);
				    cor1[j][0]=0;
				    continue;
			    }
			    obj1(cor1[j][0],cor1[j][1]);
			    cor1[j][1]=cor1[j][1]+5;
		    }
	    }
        if(c%20==0) //for second object system
	    {
		    m=m+1;
		    z=rand()%16;
		    if(z%3==0)
		    {
			    cor2[m][0]=444;
			    cor2[m][1]=25;
		    }
		    else
		    {
			    cor2[m][0]=349;
			    cor2[m][1]=25;
		    }
	    }
        for(j=m-8;j<=m;j++)
	    {
		    if(cor2[j][0]!=0)
		    {
			    if(cor2[j][0]==x2&&cor2[j][1]>y2&&y2+40>=cor2[j][1])
				    goto label;
			    if(cor2[j][1]>25)
				    objclr(cor2[j][0],cor2[j][1]-5);
			    if(cor2[j][1]+25>=418)
			    {
				    score++;
				    objclr(cor2[j][0],cor2[j][1]-5);
				    cor2[j][0]=0;
				    continue;
			    }
			    obj2(cor2[j][0],cor2[j][1]);
			    cor2[j][1]=cor2[j][1]+5;
		    }
	    }
        nosound();
        if(kbhit()!=0)
	    {
		    q=getch();
		    if(q=='a')
		    {
			    sound(800);
			    gadiclr(x1,y1);
			    if(x1==156)
				    x1=251;
			    else
				    x1=156;
		    }
		    else if(q=='l')
		    {
			    sound(2000);
			    gadiclr(x2,y2);
			    if(x2==349)
				    x2=444;
			    else
				    x2=349;
		    }
		    else if (q==27)
		    {
			    q=esc();
			    if(q=='y')
				    exit();
			    else
			    {
				    clearviewport();
				    setviewport(0,0,639,479,1);
				    boarder();
				    goto label2;
			    }
		    }
	    }
    
    label: over(score);
    while(1)
    {
	    if(kbhit()!=0)
	    q=getch();
	    if(q==27)
		    exit();
	    delay(200);
    }
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

    setcolor(14);
    rectangle(126,20,513,420);
    setcolor(2);
    rectangle(127,21,512,419);
    setcolor(14);
    rectangle(128,22,511,418);//small
    setcolor(14);
    rectangle(318,23,321,417);//middle
    setfillstyle(1,2);
    floodfill(320,100,14); //outer
    setfillstyle(1,1);
    floodfill(50,20,14);
    rectangle(223,23,223,417);//left line
    rectangle(416,23,416,417);//right line

}

void over(long int a)
{
    char output[20];
    nosound();
    setviewport(200,200,420,279,1);
    setcolor(4);
    rectangle(0,0,220,79);
    rectangle(1,1,219,78);
    rectangle(2,2,218,77);
    setfillstyle(1,9);
    floodfill(10,10,4);
    outtextxy(75,4,"GAME OVER");
    outtextxy(87,20,"score");
    sprintf(output,"%Ld",a);
    outtextxy(100,40,output);
    outtextxy(45,55,"press esc to exit");
}