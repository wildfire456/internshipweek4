#include <SFML/Graphics.hpp>
#include<string.h>
#include <iostream>
#include "scatter.h"
#include <time.h>
using namespace std;
using namespace sf;


class Powerup
{
public:
Texture tex;
Sprite spr;
float speed=7.5;
float x,y;
bool spawn;
bool powerlife;

int taken;
int poweruptype;

Powerup()
{
tex.loadFromFile("img/PNG/Power-ups/heart.png");
spr.setTexture(tex);


x=-75;y=0;

poweruptype=0;
spr.setPosition(x,y);

spawn=0;
powerlife=0;


spr.setScale(1,1);



}



void spawner( float& firepoweruptimer, float& blasterduration,bool scatterlife)
{

 
 firepoweruptimer+=0.016666666666;


float temptime = firepoweruptimer;
if (scatterlife==1)
firepoweruptimer=0;

 
if (temptime>=5 && scatterlife==0) // every 16 seconds power up spawns
  {

  poweruptype=rand()%7+1;
   //poweruptype=6; //scatter  //for testing each powerup
   //poweruptype=1; // life
   //poweruptype=2; // fire
   //poweruptype=5; // slow
   
  spawn=1;
  powerlife=1;
  firepoweruptimer=0;


  if (poweruptype==1)
    { 
     tex.loadFromFile("img/PNG/Power-ups/heart.png");
     spr.setTexture(tex);
     
    spr.setScale(1.2,1.2);
    }
    
     if (poweruptype==2 ||poweruptype==3 )
    {
     tex.loadFromFile("img/PNG/Power-ups/powerupBlue_bolt.png");
     spr.setTexture(tex);
     
     spr.setScale(1,1);
    }
    
    if (poweruptype==4 || poweruptype==5)
    {
     tex.loadFromFile("img/PNG/Power-ups/slomo.png");
     spr.setTexture(tex);
     
    spr.setScale(1.3,1.3);
    }
    
     if (poweruptype==6 || poweruptype==7)
    {
     tex.loadFromFile("img/PNG/Power-ups/scattershot.png");
     spr.setTexture(tex);
     
    spr.setScale(1,1);
    }
    
    
     srand(time(NULL));
    y=rand()%281 + 380;   
     //generates random y coordinate between region where enemies not present)
    spr.setPosition(-75, y);
    x=-75;
  }
  
  
  
 if (x>=770)
    {
    spawn=0;
    powerlife=0;

    }
  
    
 if (taken==1)
    {
    blasterduration=0;
    spawn=0;
    powerlife=0;
     taken=0;
    }


  
  

  
}
void move(){ //movement of powerup


   if (powerlife==1)
     { 
      x+=3;
      spr.setPosition(x, y);
       
     }
   
  
  }
  

    
    //idea enemy bullets slow
    //bullets phase through 
    //score
    
    

};
