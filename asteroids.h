#include <SFML/Graphics.hpp>
#include<string.h>
#include <iostream>
#include <time.h>
using namespace std;
using namespace sf;
class Asteroid{
public:
Texture tex, tex2;
Sprite astr, warning;
float speed=7.5;
float x,y;
bool spawn;
bool astrlife;
bool warninglife;
bool dodge;

int hit;
int astrtype;
int leftspawn;
int rightspawn;
int randselect;

Asteroid()
{
tex.loadFromFile("img/PNG/Meteors/meteorBrown_med1.png");
tex2.loadFromFile("img/PNG/Meteors/danger.png");

warning.setTexture(tex2);
astr.setTexture(tex);

leftspawn=0;
rightspawn=0;
dodge=1;
randselect=rand()%2+1;


srand(time(NULL));
x=-75;    y=rand()%271 + 370;

astr.setPosition(x,y);
warning.setPosition(x,y);

astrtype=0;
spawn=0;
astrlife=0;
warninglife=0;


astr.setScale(1.8,1.8);
warning.setScale(1.2,1.2);



}



void spawner( float& asteroidtimer, bool& playalert, bool slow, int& score)
{


 srand(time(NULL));

if (slow==0)
asteroidtimer+=0.01666666666;

else 
asteroidtimer+=0.01666666666*0.1;

float temptime = asteroidtimer;
     
 if (leftspawn==1 && x>=820 && astrlife==1)
    {
    if (dodge==1 && x!=8000)
      {  
      score+=10;
        }
    
    astrlife=0;
       y=rand()%271 + 370;   
        randselect=rand()%2+1;
        
    }
    
  if (rightspawn==1 && x<=-90 && astrlife==1)
    {
       if (dodge==1 && x!=8000)
      {  
      score+=10;
        }
    astrlife=0;
       y=rand()%271 + 370;   
 randselect=rand()%2+1;
    }
    
    
 if (hit==1 && astrlife==1)
    {
    dodge=0;
    astrlife=0;
     hit=0;
        y=rand()%271 + 370;  
         randselect=rand()%2+1; 
    }

//to play alert sound
if (temptime>=9.7 && temptime<=9.8)
 playalert=1;


if (temptime>= 10.2 && randselect==1)
  {

   warninglife=1;
   warning.setPosition(730, y);
  
  }

else if (temptime>= 10.2 && randselect==2)
  {
   warninglife=1;
   warning.setPosition(15, y);
  
  }


if (temptime>=11) // every 11 seconds asteroid spawns
  {
  dodge=1;
  warninglife=0;
   srand(time(NULL));
    asteroidtimer=0;
    

      astrlife=1;
     
      
      if (randselect==1)
        {
         rightspawn=1;
         leftspawn=0;
        }
        
        else 
        {
         leftspawn=1;
         rightspawn=0;
        }
        
      
      astrtype=rand()%4+1;
      
       if (astrtype==1)
       tex.loadFromFile("img/PNG/Meteors/meteorBrown_med1.png");
       
       else if (astrtype==2)
       tex.loadFromFile("img/PNG/Meteors/meteorBrown_med3.png");
       
       else if (astrtype==3)
       tex.loadFromFile("img/PNG/Meteors/meteorGrey_med2.png");
       
       else 
       tex.loadFromFile("img/PNG/Meteors/meteorGrey_med1.png");
       
     
       
        if (leftspawn==1)
         {
          astr.setPosition(-70, y);
          x=-75;
          }
        else if (rightspawn==1)
          {
          astr.setPosition(820, y);
          x=820;
          }
        
        
     

  
  }
  


  
}
void move(bool slow){ //movement of asteroids
 
 

if (astrlife==0)
  x=-8000;

   if (astrlife==1 && leftspawn==1)
     { 
     if (slow==0)
      x+=6;
      
     else if (slow==1 && x>=-90 )
      x+=6*0.1;
      
      else 
       x+=6;
      
      
      astr.setPosition(x, y);
    
       
     }
     
     
   else if (astrlife==1 && rightspawn==1)
     { 
     if (slow==0)
      x-=6;
      
      else if (slow==1 && x<=800 )
      x-=6*0.1;
      
       else 
       x-=6;
      
      astr.setPosition(x, y);
      
     }
  
  }
  

    
    
    //idea enemy bullets slow
    //bullets phase through 
    //score
  
    

};
