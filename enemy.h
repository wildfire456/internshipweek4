#include <SFML/Graphics.hpp>
#include<string.h>
#include <iostream>
#include <time.h>


using namespace std;
using namespace sf;
class Enemy
{
public:
Texture tex3, bombtex, exp2t, monstert, hellfiret; 
Sprite invader, bomb, exp2, monster, hellfire;
Sound explosion, attack, monsttheme;
SoundBuffer buffer1, buffer2, buffer3;

float x,y;

float tempx, tempy;
float bombposx,bombposy;
float animation2;
int temptimer;
int enemytype;
float bombspeed;


float movecount;
float positionx, positiony;
float speed=11.5;
float alpha;
float beta;
float gamma;
float timer;

bool fix;
bool defeat;
bool end;
bool check;
bool bombdrop;
bool bomblife;
bool expdisp;
bool play;
bool disphf;
bool survive;

 IntRect a[16];
  int currentFrame;
  
  
  // monsterclass variables
  bool xdirn; // chooses what dirn monster goes first


 float monsx;
 float monsy;
  
 float hellfirex;
 float hellfirey;
 
 float monstertimer;
 float monsterduration;
 float enemymoveduration;
 float monsterwaitclock;

 
 bool monsterspawn;
 bool monsterwait;
 bool monsterlock; 
 bool center;
 bool enemyrestore;

Enemy()
{
play=1;
buffer1.loadFromFile("songs/explosion.wav");
explosion.setBuffer(buffer1);

fix=0;
check=0;
gamma=0;
alpha=0;
beta=0;
expdisp=1;
animation2=0;
bombspeed=7;

currentFrame=0; 
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

    
   
 



}


  










};
