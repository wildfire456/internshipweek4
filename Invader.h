#include <SFML/Graphics.hpp>
#include<string.h>
#include <iostream>
#include <time.h>
#include "enemy.h"


using namespace std;
using namespace sf;
class Invader: public Enemy
{
public:

Invader()
{
check=0;
gamma=0;
alpha=0;
beta=0;

temptimer=0;
  movecount=0;
  
int choice=rand()%3+1;
choice=rand()%3+1;
choice=rand()%3+1;
choice=rand()%3+1;
choice=rand()%3+1;


positionx=0;
positiony=0;
defeat=0;
end=0;
timer=0;
expdisp=1;

if (choice==1) //gamma invader
  {
    tex3.loadFromFile("img/enemy_1.png");
    bombtex.loadFromFile("img/PNG/Lasers/laserRed02.png");
    invader.setTexture(tex3);
    bomb.setTexture(bombtex);
    invader.setScale(0.6,0.6);
     bomb.setScale(0.5, 1.2);
     enemytype=choice;
   }
   
   if (choice==2) //alpha invader
    {
    tex3.loadFromFile("img/enemy_2.png");
    bombtex.loadFromFile("img/PNG/Lasers/laserRed02.png");
    invader.setTexture(tex3);
    bomb.setTexture(bombtex);
    invader.setScale(0.5,0.5);
     bomb.setScale(0.5, 1.2);
     enemytype=2;
   
   }
   
    if (choice==3)  //beta invader
    {
    tex3.loadFromFile("img/enemy_3.png");
    bombtex.loadFromFile("img/PNG/Lasers/laserRed02.png");
    invader.setTexture(tex3);
    bomb.setTexture(bombtex);
    invader.setScale(0.4,0.4);
    bomb.setScale(0.5, 1.2);
    enemytype=choice;
    
   }
    exp2t.loadFromFile("img/exp2.png");
    exp2.setTexture(exp2t);
   
    
    a[0]=IntRect(0, 0, 62.5, 62.5);
    a[1]=IntRect(62.5, 0, 62.5, 62.5);
    a[2]=IntRect(125, 0, 62.5, 62.5);
    a[3]=IntRect(187.5, 0, 62.5, 62.5);
    
    a[4]=IntRect(0, 62.5, 62.5, 62.5);
    a[5]=IntRect(62.5, 62.5, 62.5, 62.5);
    a[6]=IntRect(125, 62.5, 62.5, 62.5);
    a[7]=IntRect(187.5, 62.5, 62.5, 62.5);
    
    a[8]=IntRect(0, 125, 62.5, 62.5);
    a[9]=IntRect(62.5, 125, 62.5, 62.5);
    a[10]=IntRect(125, 125, 62.5, 62.5);
    a[11]=IntRect(187.5, 125, 62.5, 62.5);
    
    a[12]=IntRect(0,187.5, 62.5, 62.5);
    a[13]=IntRect(62.5, 187.5, 62.5, 62.5);
    a[14]=IntRect(125, 187.5, 62.5, 62.5);
     a[15]=IntRect(187.5, 187.5, 62.5, 62.5);
    
  exp2.setTextureRect(a[0]);
   
   
    x=34000;
    y=-5000;
invader.setPosition(x,y);
bomb.setPosition(x,y);
bombdrop=0;
bomblife=0;
bombposx=0;
bombposy=0;


}


virtual void fire(bool movementlock, float alphareset, float betareset, float gammareset, bool slow,int level)=0;  //only fire after in formation  

void move(bool& movementlock, bool& circle)  //entrance
{
 if (movementlock==0)
  {
  y+=7.5;
  invader.setPosition(x, y);


  movecount+=7.5;
 if (circle==1)
    {
     
      if (movecount==457.5)
     {
     circle=0;
        exp2.setPosition(x, y);
        positionx=x;
        positiony=y;
        movementlock=1;
     movecount=0;
     return;
  
      }
    
    
    
    
    }
    
  else if (movecount==322.5)
    {
     exp2.setPosition(x, y);
    positionx=x;
    positiony=y;
     movementlock=1;
     movecount=0;
     return;
  
    }
   
  }
}

void move2(string action , bool& enemyrestore)
{
 if (action=="left")
    {
    
     if (fix==0)
        {
         tempx=x;
         fix=1; //helps store the original position of the invader befre boss spawn
        }
   
     x-=7.5;
     invader.setPosition(x, y);
    }
    
 if (action=="right" )
    {
     if (x!=tempx)
      {
     x+=7.5;
    invader.setPosition(x, y);
    }
     
     else
      {
     fix=0;
     enemyrestore=0;
     }
   
    }


}




  










};
