#include <SFML/Graphics.hpp>
#include<string.h>
#include <iostream>
#include <time.h>


using namespace std;
using namespace sf;
class Bomb: public Invader
{
public:

void fire(bool movementlock, float alphareset, float betareset, float gammareset, bool slow, int level)  //only fire after in formation  
{
if (level==1)
  {
   bombtex.loadFromFile("img/PNG/Lasers/laserRed02.png");
  }

else if (level==2)
  {
   bombtex.loadFromFile("img/PNG/Lasers/laserYellow02.png");
  }
  
  else
   bombtex.loadFromFile("img/PNG/Lasers/laserPurple02.png");
   
  
if (movementlock==1 && check==0)
  {

  alpha=0;
  beta=0;
  gamma=0;
  timer=0;

   check=1;
  }
  
if (movementlock==1 && check==1)
  {
     alpha+=0.016666666666;
    beta+=0.016666666666;
    gamma+=0.016666666666;

  
  if (slow==0)
    {
    timer+=0.01666666666;

    }
  
  else
    {
    timer+=0.01666666666*0.1;

   
    }
  }


   if (defeat==0 && enemytype == 1  &&  timer<=gammareset && movementlock==1 && gamma>gammareset)
   {
   bomblife=1;
   }

   if (defeat==0 && enemytype == 2  &&  timer<=alphareset && movementlock==1 && alpha>alphareset )
   bomblife=1;

   if (defeat==0 && enemytype == 3  &&  timer<=betareset && movementlock==1 && beta>betareset )
    bomblife=1;
    

    if ( enemytype==1 && timer>=gammareset && movementlock==1)
    { 
     
      bomblife=0;
      timer=0;
      
      
    }
    
  if ( enemytype==2 && timer>=alphareset && movementlock==1)
    { 
      bomblife=0;
    timer=0;
     
      
    }
    if ( enemytype==3 && timer>=betareset && movementlock==1)
    { 
      bomblife=0;
      timer=0;
      
      
    } 
    
    if (level==1)
     speed=6;
     
    else if (level==2)
    speed=8;
    
    else if (level==3)
    speed=10.2;
   
   
     if (bomblife==1 && movementlock==1)
    {
    if (slow==1)
    bombposy+=speed*0.1;
     
     else
    bombposy+=speed;
    bomb.setPosition(bombposx, bombposy);
   }

if (bomblife==0 )
 {
  bombposx=x+28;
  bombposy=y+17;
  bomb.setPosition(bombposx, bombposy);
  }

 
 
}









};
