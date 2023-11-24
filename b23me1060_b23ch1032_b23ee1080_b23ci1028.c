#include<stdio.h>
#include<windows.h>
#include<conio.h>
int atx[1000];
int aty[1000];
int f1,f2,p1,p2,move,score=0,l=20,c=0;
int gameover=0;
void setup()
{
 p1=p2=l/2;
 label1:
    f1=rand()%20;
    if(f1==0 || f1==1 ||f1>=16)
    goto label1;
     label2:
    f2=rand()%20;
    if(f2==0 || f2==1 || f2>=16)
    goto label2;
}
void boundary()
{
   system("cls");
   for(int i=0;i<=20;i++) 
   {
    for(int j=0;j<=20;j++)
    {
        if(i==0 || i==20 || j==0 || j==20)
        {
            printf("#");
        }
        else
        {
   
          if(i==p1 && j==p2)
           printf("0");
           else if(i==f1 && j==f2)
           printf("$");
           else 
           {
            int a=0;
            for(int k=0;k<c;k++)
            {
               if(atx[k]==i && aty[k]==j)
               {
               printf("o");
               a=1;
               }
            }
            if(a!=1)
            printf(" ");
     } }
    }
    printf("\n");
   }
  printf("SCORE=%d\n",score);
   return;
   
}
void input()
{
   int py1,px1;
   int px=atx[0];
   int py=aty[0];
   aty[0]=p2;
   atx[0]=p1;
   for(int i=1;i<c;i++)
   {
px1=atx[i];
atx[i]=px;
px=px1;
py1=aty[i];
aty[i]=py;
py=py1;

   }
if(kbhit())
{
   switch(getch())
   {
      case 75:
      move=1;
      break;
      case 80:
      move=2;
      break;
      case 77:
      move=3;
      break;
      case 72:
      move=4;
      break;
   case 'x':
   gameover=1;
      break;
   }
}
}
void movement()
{
   switch(move)
   {
      case 1:
      p2--;
      break;
      case 2:
      p1++;
      break;
      case 3:
      p2++;
      break;
      case 4:
      p1--;
      break;

   }
    if(p1<=0 || p2<1 || p1>19 || p2>19)
    {
      gameover=1;
    }
      for(int i=0;i<c;i++)
      {
         if(atx[i]==p1 && aty[i]==p2)
         gameover=1;
      }
}
int main()
{
   printf("'$' DENOTE THE FOOD \n USE ARROW TO CONTROL THE MOVEMENT OF SNAKE \n PRESS 'x' TO EXIT\n");
   printf("PRESS ANY KEY TO START THE GAME\n");
   getch();
   setup();
    while(!gameover)
    {
    boundary();
    input();
    movement();
    for(int i=0;i<1000;i++)
    for(int j=0;j<1000;j++);
    if(p1==f1 && p2==f2)
    {
      c++;
      score=score+1;
label1:
    f1=rand()%20;
    if(f1==0 || f1==1 ||f1>=16)
    goto label1;
     label2:
    f2=rand()%20;
    if(f2==0 || f2==1 || f2>=16)
    goto label2;
    }
    }
printf("GAME OVER");
 return 0;
}
    


    
    
