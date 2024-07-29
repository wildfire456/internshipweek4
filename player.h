#include <SFML/Graphics.hpp>
#include<string.h>
#include <iostream>

using namespace std;
using namespace sf;

class Player
{
public:
Texture tex, tex2, texeff;
Sprite sprite, laser1, eff;
float speed=8;
float x,y;
bool shoot;
bool laserlife;
float fireposx;
float fireposy;

Player()
{

tex.loadFromFile("img/player_ship.png");
tex2.loadFromFile("img/PNG/Lasers/laserGreen04.png");
texeff.loadFromFile("img/PNG/Effects/fire06.png");
sprite.setTexture(tex);
laser1.setTexture(tex2);
eff.setTexture(texeff);

x=340;y=620;
sprite.setPosition(x,y);
laser1.setPosition(x,y);
eff.setPosition(x,y);
shoot=0;
laserlife=0;
fireposx=0;
fireposy=0;

sprite.setScale(0.7,0.7);
laser1.setScale(0.5, 1.2);
eff.setScale(0.9, 0.8);
}



virtual void fire(bool destroyed, float firetime, Clock& playerfire, bool& blasterpowerup, bool invincible, bool scatterlife)=0;

void move(std::string s){

float delta_x=0,delta_y=0;

//cout<<"X "<<x<<endl;
//cout<<"y "<<y<<endl;

if(s=="u")
{
	delta_y=-1;
	y+=speed*delta_y;
	}
if (s=="r")
{

   delta_x=1;
     x+=speed*delta_x;
   }
   
if (s=="l")
{
  delta_x=-1;
  x+=speed*delta_x;
  }
  
 if(s=="d")
 {
	delta_y=1;
	y+=speed*delta_y;
	}

delta_x*=speed;
delta_y*=speed;

sprite.move(delta_x, delta_y);
if (x>=770)
   {
   x=-71;
  sprite.setPosition(x, y);
   }
   
if (x<=-72)
   {
   x=769;
  sprite.setPosition(x, y);
   }
  
   
   if (y<=-58.5)
   {
   x=700-x;
   y=712;
  sprite.setPosition(x, y);
   }
  
  if (y>=713)
   {
   x=700-x;
   y=-58.4;
  sprite.setPosition(x, y);
   } 
   
   
  
}

};
