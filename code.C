#include<graphics.h>
#include<dos.h>
#include<stdio.h>
#include<conio.h>
// Akshay Singh
void loading()
{
int i,j=0;
setbkcolor(3);
setcolor(4);
// Akshay Singh
for(i=0;i<5;++i)
{
setcolor(14);
rectangle(0+i,0+i,639-i,479-i);
setcolor(4);
rectangle(5+i,5+i,634-i,474-i);
setcolor(14);
rectangle(10+i,10+i,629-i,469-i);
setcolor(4);
rectangle(15+i,15+i,624-i,464-i);
}
for (i = 0; i <= 215; ++j,++i)
{
sound(200+100*j);
delay(10);
sound(2000+100*j);
delay(10);
sound(50+5*i);
outtextxy(300, 294, "Loading....");
rectangle(224, 288, 224 + i, 306);
delay(10);
nosound();
}
clearviewport();
}
// Akshay Singh
int main()
{
int cr;
//640*480
int SCORE,SPEED=10;
int x = 300, y = 415,k, flag = 0, left = 0;
int i = 250, ch,ti,tx,ty;
int gdriver = DETECT,gmode;
clrscr();
initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
loading();
setbkcolor(14);
phirse:
for(i=0;i<5;++i)
{
setcolor(1);
rectangle(0+i,0+i,639-i,479-i);
setcolor(2);
rectangle(5+i,5+i,634-i,474-i);
setcolor(1);
rectangle(10+i,10+i,629-i,469-i);
setcolor(2);
rectangle(15+i,15+i,624-i,464-i);
}
setcolor(4);
outtextxy(200, 240, "DO YOU WANT TO PLAY THE GAME");
outtextxy(200, 260, "PRESS Y TO PLAY AND N TO EXIT");
ch = getch();
if (ch == 89 || ch == 121)
goto aage;
if (ch == 27)
{nosound();
return (0);}
if (ch == 110 || ch == 78)
{nosound();
return (0); }
else
goto phirse;
aage:
i = 250;
ti=i;
x = 300;
tx=x;
y = 415;
ty=y;
flag = 0;
left = 0;
cleardevice();
setcolor(4);
for(k=20;k>0;--k)
rectangle(10-k,20-k,640-10+k,480-20+k);
while (1)
{
sound(12000);
delay(SPEED);
sound(20);
setcolor(YELLOW);
for(cr=0;cr<16;++cr)
circle(tx,ty,cr);
setcolor(RED);
for(cr=0;cr<16;++cr)
circle(x, y, cr);
sound(8000);
tx=x;
ty=y;
setcolor(14);
rectangle(ti, 430, ti + 100, 440);
setcolor(1);
rectangle(i, 430, i+ 100, 440);
ti=i;
//for(k=10;k>=0;--k)
//rectangle(10-k,20-2*k,639-10+k,479-20+2*k);
setcolor(411);
outtextxy(10, 7, "Press Esc to Exit..");
outtextxy(350, 7,"SPEED WILL INCREASE WITH TIME");
setcolor(RED);
if (x >= 614 || x <= 25)
flag = !flag;
if (flag)
x = x - 1;
else
x = x + 1;
if ((y >= 416 && x <= i + 100 && x >= i) || y <= 35)
left = !left;
if (left)
y = y + 1;
else
y = y - 1;
if (y == 415 && x <= i + 100 && x >= i)
SCORE= SCORE + 1;
if(SCORE>(SCORE+10) && SPEED>=0)
--SPEED;
if (y >= 444)
goto lebel;
if (kbhit())
{
ch = getch();
if (ch == 75) //move left
{
if (i != 10)
i = i - 5;
}
if (ch == 77) //move right
{
if (i != 530)
i = i + 5;
}
if (ch == 27) //exit when esc pressed
{nosound();
exit(0);}

}
//delay(10);
//cleardevice();
ch = 0;
}
lebel:
outtextxy(280, 240, "GAME OVER");
sound(100);
delay(1000);
nosound();
ch = getch();
if (ch == 89 || ch == 121)
goto aage;
if (ch == 27)
{nosound();
return (0);}
if (ch == 110 || ch == 78)
{nosound();
return (0); }
else
{
cleardevice();
goto phirse;
nosound();
}
nosound();
}
// Akshay Singh