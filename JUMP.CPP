#include<graphics.h>
#include<iostream.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<process.h>
int i=250,j=250,y1=600,y2=640,x1=400,x2=400,score;
void main()
{
clrscr();
int gd=DETECT,gm,ch,x,y;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
while(1)
{
fillellipse(i,j,5,5);

if(kbhit())
{
ch=getch();
if(ch==97)
{
x=-10;y=0;
}
if(ch==100)
{
x=10;y=0;
}
if(ch==27)
{
ds:
cout<<"your score is: "<<score<<endl;
cout<<"Thanks For Playing"<<endl;
cout<<"Wait for FIVE seconds";
delay(5000);
exit(0);
}
if(ch==119)
{
x=0;y=-10;
}
if(ch==115)
{
x=0;y=10;
}
i=i+x;
j=j+y;
delay(17);
cleardevice();
}
else
{
x=0;y=1;
i=i+x;
j=j+y;
delay(17);
cleardevice();
line(y1,x1,y2,x2);
y1=y1-1.5;y2=y2-1.5;
if(j==x1 && i>=y1 && i<=y2)
{
while(!kbhit())
{
delay(17);
cleardevice();
line(y1,x1,y2,x2);
fillellipse(i,j,5,5);
i=i-1.5,y1=y1-1.5,y2=y2-1.5;
if(kbhit())
{
srand(time(NULL));
x2=x1=rand()%300+30;
y1=600;y2=640;
score=score+1;
continue;
}
}
}
if(y1==0)
{
goto ds;
}
if(j==460)
{
goto ds;
}
}
}
}
