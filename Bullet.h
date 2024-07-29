#include <SFML/Graphics.hpp>
#include<string.h>
#include <iostream>


using namespace std;
using namespace sf;
class bullet: public Player
{
public:

void fire(bool destroyed, float firetime, Clock& playerfire, bool& blasterpowerup, bool invincible, bool scatterlife)
{
 if (invincible==0)
 tex.loadFromFile("img/player_ship.png");
 
 else
 tex.loadFromFile("img/invincible.png");
 
 if (blasterpowerup==1)
 {
 tex2.loadFromFile("img/PNG/Lasers/laserBlue02.png");
 laser1.setScale(0.85, 1.5);
 }
   
   else if (blasterpowerup==0 && laserlife==0)
    {
   tex2.loadFromFile("img/PNG/Lasers/laserGreen04.png");
   laser1.setScale(0.5, 1.2);
   }

if (destroyed==0)
{ 
  if (laserlife==0)
 {
  

  fireposx=x+29;
  fireposy=y-20;
  laser1.setPosition(fireposx, fireposy);

  }
  if (shoot==1 && laserlife==0 && firetime>=1 && scatterlife==0)
  {
  
    
    laserlife=1;       //sets firerate and whether to shoot
    firetime=0;
    }
 
   eff.setPosition(x+29,y-22);


 }
 if (laserlife==1)
   {
   fireposy-=13;
   laser1.setPosition(fireposx, fireposy);
   }
   
   
   if (fireposy<=-58.5)
     {
     
     laserlife=0;
     }
 
}


};
