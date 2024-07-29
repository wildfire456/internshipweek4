
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <time.h>
#include "player.h"
#include "formation.h"
#include "powerup.h"
#include "Monster.h"
#include "asteroids.h"
#include "hitbox.h"
#include "Bullet.h"

#include <sstream>
#include <string>
#include <fstream>


const char title[] = "Space Shooter";
using namespace sf;

class Game
{
public:
  Font opensans;
  Text  scoredisp, livesdisp, leveldisp, phasedisp, high1disp, high2disp, high3disp, name1disp, name2disp, name3disp, prompt, scattershotcount;
  
   
   
Music theme;
Sound        alert, playershoot, playerexplode, blastersound, powerpickup, achievement, selection, lose, clocktick, warden, scattersound;
SoundBuffer buffer,   buffer2,     buffer3,     buffer4  ,    buffer5    ,  buffer6,    buffer7, buffer8, buffer9  , buffer10,  buffer11;

Sprite background, pause_menu, helpmenu, highmenu, gameovermenu, enter, explosion, bg1, bg2, bg3, bg4;
Texture bg_texture, pm,          hm,      himenu,    gomenu,     screen, anim,     f1,  f2,  f3 , f4;
Player* p; //player 
Formation* f;
Powerup* pow;
Asteroid* asteroid;
Monster* m;
Hitbox hitbox;
Scatter* a[7];
Scatter* b[7];
Scatter* c[7];


int lives;
int enemycount;
int level;
int level2; //for speed of enemy bombs
int phase;
int phase_selector[3];
int scattershots;

bool movementlock;
bool end;
float alphatimer;
float betatimer;
float gammatimer;

float alphareset; //after how many seconds alpha enemy fires a laser
float betareset;
float gammareset;
float invincibility_period;
float firetime;
int score;
int framecount;
float fy1;
float fy2;
float fy3;
float fy4;


bool destroyed;
bool invincible;
bool press;
bool play;
bool playalert;
bool playslow;
bool explode;
bool blasterpowerup;
bool slow;
bool blasterend;
bool scatterlife;
bool create;
bool paused;
bool phaseend;
bool helpdisp, highdisp;
bool segmentationfix;
bool respawn;
bool entercheck;
bool animationFinished;
bool circle;
bool beam;
bool beamsound;
bool monstertheme;
bool monsterend;


  IntRect frames[4];
  int currentFrame;
// add other game attributes


Game()
{
circle=0;
end=0;
level=1;
level2=1;
phase=0;
score=0;
enemycount=0;
lives=3;
play=1;
blasterpowerup=0;
slow=0;
blasterend=0;
scatterlife=0;
paused=0;
phaseend=0;
segmentationfix=0;
animationFinished=0;
beam=0;

p=new bullet;
pow= new Powerup();
asteroid= new Asteroid();
m= new Monster();
 
   for (int i=0; i<7; i++)
     {
     a[i]=new Scatter(i+1);
     b[i]=new Scatter(i+1);
     c[i]=new Scatter(i+1);
     
     
     }
 //scattershots=0;
 //scatterlife=0;
   
 opensans.loadFromFile("open-sans/OpenSans-Regular.ttf");
 scoredisp.setFont(opensans);
 livesdisp.setFont(opensans);
 leveldisp.setFont(opensans);
 phasedisp.setFont(opensans);
 high1disp.setFont(opensans);
 high2disp.setFont(opensans);
 high3disp.setFont(opensans);
 name1disp.setFont(opensans);
 name2disp.setFont(opensans);
 name3disp.setFont(opensans);
 prompt.setFont(opensans); 
 scattershotcount.setFont(opensans); 
    
 bg_texture.loadFromFile("img/background1.jpg");

 theme.openFromFile("songs/theme.ogg");
 theme.setLoop(true);

  
  //sounds
 buffer.loadFromFile("songs/alert.wav");
 buffer2.loadFromFile("songs/fire.wav");
 buffer3.loadFromFile("songs/playerexplode.wav");
 buffer4.loadFromFile("songs/blaster.wav");
 buffer5.loadFromFile("songs/powerpickup.wav");
 buffer6.loadFromFile("songs/achievement.wav");
 buffer7.loadFromFile("songs/interface.wav");
 buffer8.loadFromFile("songs/lose.wav");
 buffer9.loadFromFile("songs/slow.wav");
 buffer10.loadFromFile("songs/warden.wav");
 buffer11.loadFromFile("songs/scatterfire.wav");
 
 pm.loadFromFile("img/pause.png");
 pause_menu.setTexture(pm);
 pause_menu.setScale(1.6, 1.2);
 pause_menu.setPosition(140, 1.2);
 
 
 hm.loadFromFile("img/helpmenu.png");
 helpmenu.setTexture(hm);
 helpmenu.setScale(0.195, 0.21);
  
   
 gomenu.loadFromFile("img/GAMEOVER.png");
 gameovermenu.setTexture(gomenu);
 gameovermenu.setScale(1.6, 1.2);
 gameovermenu.setPosition(140, 40);
  
  
 himenu.loadFromFile("img/highscoremenu.png");
 highmenu.setTexture(himenu);
 highmenu.setScale(0.195, 0.275);
 highmenu.setPosition(0, -147);
 
 
 
 screen.loadFromFile("img/new.png");
 enter.setTexture(screen);
 enter.setScale(0.448, 0.597);
 enter.setPosition(0, 0);
 
  anim.loadFromFile("img/explosion.png");
  explosion.setTexture(anim);
  
  //moving background
  f1.loadFromFile("img/frame1.png");
  f2.loadFromFile("img/frame2.png");
  f3.loadFromFile("img/frame3.png");
  f4.loadFromFile("img/frame4.png");
  
  bg1.setTexture(f1);
  bg2.setTexture(f2);
  bg3.setTexture(f3);
  bg4.setTexture(f4);
  
  bg1.setScale(0.5, 0.5);
  bg2.setScale(0.5, 0.5);
  bg3.setScale(0.5, 0.5);
  bg4.setScale(0.5, 0.5);
  
  
  fy1=0;
  fy2=-740;
  fy3=-1480;
  fy4=-2220;
  
  
  bg1.setPosition(0, fy1);
  bg2.setPosition(0, fy2);
  bg3.setPosition(0, fy3);
  bg4.setPosition(0, fy4);
  
  
  
//player explosion sprite

   frames[0] = IntRect(0, 0, 138, 138);
   frames[1] = IntRect(138, 0, 138, 138);
   frames[2] = IntRect(276, 0, 138, 138);
   frames[3] = IntRect(414, 0, 138, 138);
    currentFrame=0;
 
 alert.setBuffer(buffer);
 playershoot.setBuffer(buffer2);
 playerexplode.setBuffer(buffer3);
 blastersound.setBuffer(buffer4);
 powerpickup.setBuffer(buffer5);
 achievement.setBuffer(buffer6);
 selection.setBuffer(buffer7);
 lose.setBuffer(buffer8);
 clocktick.setBuffer(buffer9);
 warden.setBuffer(buffer10);
 scattersound.setBuffer(buffer11);
 
 
background.setTexture(bg_texture);
background.setScale(0.66, 0.8);
movementlock=0;
alphatimer=0;
betatimer=0;  //time elapsed since laser fired by different enemies
gammatimer=0;
firetime=0;
helpdisp=0;
highdisp=0;


alphareset=3.00000;
gammareset=2.00000;
betareset=5.00000;
destroyed=0;
invincibility_period=0;
invincible=0;
press=1;

playalert=0;
playslow=0;
explode=0;
beamsound=0;
monstertheme=0;
monsterend=0;
scattershots=0;
create=1;




entercheck=0;
respawn=0;
framecount=0;
 srand(time(NULL));
  //Selects random phase and ensures that its not repeated
for (int i=0; i<3; i++)
    {
     
    if (i==0)
     phase_selector[i]=rand()%3+1;
    
    else 
      {
      int count=0;
      int temp;
      while (count!=i)
         {
         count=0;
         temp=rand()%3+1;
         
         for (int j=i-1; j>=0; j--)
           {
            if (phase_selector[j]!=temp)
             count++;
           }
           phase_selector[i]=temp;
         }
       }
    
    }
}
 // variables for highscore
    int highscore1, highscore2, highscore3, tempscore1;
    string highname, midname, lowname, tempname;
    string displayscore;
    string input;

void start_game()
{   

  
 
    srand(time(0));
    RenderWindow window(VideoMode(780, 740), title);
    window.setFramerateLimit(60);
    Clock clock, clock2, invincibilityclock;
    Clock playerfire, blaster;
    float timer=0;
    float time=0;
    float time2=0;
    float repeat=0;
    float firepoweruptimer=0;
    float asteroidtimer=0;
    float blasterduration=0;
    float slowduration=0;
    float phasedelay=0;
    float animation=0;
    

    
    
    
   input="E TO RESPAWN";
     prompt.setScale(0.6,0.6); 
     prompt.setPosition(340,360);
     prompt.setString(input);
    
   theme.play();
   
   
    
    while (window.isOpen())
    { 
     
        //setting highscores so that they may be updated midgame********************************
   	  ifstream score1("score/highscore1.txt");    
   	  score1>>highscore1;
  	  score1.close();
    
  	  ifstream name1("score/name1.txt");
  	  name1>>highname;
  	  name1.close();
     
     
     
   	  ifstream score2("score/highscore2.txt");
   	  score2>>highscore2;
   	  score2.close();
    
  	  ifstream name2("score/name2.txt");
  	  name2>>midname;
   	  name2.close();
    
    
    
    
  	  ifstream score3("score/highscore3.txt");
  	  score3>>highscore3;
   	  score3.close();
    
   	  ifstream name3("score/name3.txt");
   	  name3>>lowname;
   	  name3.close(); 
   	 
   	  string high1= to_string(highscore1);
    	  string high2= to_string(highscore2);
   	  string high3= to_string(highscore3);
    
    
         displayscore = to_string(score);
         
      scoredisp.setString(displayscore);
      high1disp.setString(high1);
      high2disp.setString(high2);
      high3disp.setString(high3);
      name1disp.setString(highname);
      name2disp.setString(midname);
      name3disp.setString(lowname);
   
       
     
     
     
     
     
     
     
     if (paused==0)
     {
     
      if (enemycount==0)
       phasedelay +=0.016666666;
       
       
     p->shoot=0;
         time +=0.016666666; 
         time2 +=0.016666666;
        firetime +=0.016666666;
        
  
   
   
    
        
        
        // blaster powerup uptime
        if (blasterpowerup==1)
         {
        blasterduration +=0.016666666;
         firepoweruptimer=0;
         }
       
       
        

          
         if (blasterpowerup==1 &&  blasterduration>=5.00 && blasterend==1)
          {
           blasterpowerup=0;
           firepoweruptimer=0;
           blasterduration=0;
           invincible=0;
           }
         
       blasterend=0; //ensures that round fired prior to powerup running out still has its effects for the duration of that particular
                     // laser life
      
        
        
        //slow mo power up 
        if (slow==1)
         {
         if (playslow==1)
          {
           clocktick.play(); //sound effect
           playslow=0;
           theme.pause();
          }
        slowduration +=0.016666666;
        firepoweruptimer=0;
        }
        
        if (slow==1 && slowduration>=11.1)
          {
          theme.play();
          slow=0;
          slowduration=0;
          firepoweruptimer=0;
          }


        if (invincible==1)
         { 
          invincibility_period+=0.016666666; 
          
          if (invincibility_period>=3.00 && blasterpowerup==0)
           invincible=0;
         }
         
         else
         invincibility_period=0;
         
        clock.restart();
        timer += time;   
       }
       
       
 	Event e;
        while (window.pollEvent(e))
        {  
            if (e.type == Event::Closed) // If cross/close is clicked/pressed
              {
              
                window.close(); //close the game  
                         	    
               }     
        }
          
          if (paused==0 && destroyed==0 && lives!=0)
          {
	if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A) ) //If left key is pressed
            p->move("l");    // Player will move to left
	if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))// If right key is pressed
            p->move("r");  //player will move to right
	if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)) //If up key is pressed
            p->move("u");    //playet will move upwards
	if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)) // If down key is pressed
            p->move("d");  //player will move downwards
         }
      if (destroyed==1 && lives>0 && respawn==0)   
       { 
       if (m->monsterspawn==0)
           {
            respawn=1;
            lives--;
            }
     
         }
         
         if (lives==0)
          {
          end=1;
          
          }
         
         
            if ( (m->monsterspawn==1 || Keyboard::isKeyPressed(Keyboard::E)) && respawn==1) // respawn button and temporarily invincible
           { 
           framecount=0;
           respawn=0;
            explode=0;
             destroyed=0;
             invincible=1;
             
             }
             
            
       
               
               if(time2>=1.1)
                blasterend=1;
            
            
         if (Keyboard::isKeyPressed(Keyboard::Space) && p->laserlife==0 && press==0 && time2>=1.2 && scatterlife==0) // If space key is pressed
           {
           p->shoot=true;
            press=1;
            time2=0;
            
           if (blasterpowerup==1)
             blastersound.play();
             
             else
              playershoot.play();
              
              
            }
            
           if (enemycount==0)
            {
            if (slow==1)
             {
             slow=0;
             clocktick.stop();
             slowduration=0;
             theme.play();
             
             }
            }
           
           if (enemycount==0)
             {
           
               m->monstertimer-=0.0166666666;
               }
           
           if (enemycount==0 && paused==0 && m->monsterspawn==0)
            { 
         
           
            
           phasedelay+=0.0166666666;
           }
           
            else phasedelay=0;
            
         
           
           
         if (phasedelay>=3.5)
          {
         phaseend=1;
         phasedelay=0;
         }
          
           
        if (m->monsterspawn==0 && phaseend==1 && phasedelay==0)
          { 
           
          
           if (segmentationfix==1)
           {
             delete[] f->arr;
           delete f;
           }
           
           segmentationfix=1;
           
            phaseend=0;
            
             f = new Formation(level, phase, phase_selector, circle, level2);
	    enemycount=f->enemycount;
	    movementlock=0;
	    
	    phase++;
	    if (phase==3)
	     {
	     if (level!=3)
	       {
	        phase=0;
	       level++;
	       }
	     }
	   
	  }
	 
	  
	  
          if (paused==0 && end==0)
          {
	//////////////////////////////////////////////// FUNCTIONS ////////////////////////////////////////////////////////////
	
	
	 p->fire(destroyed, firetime, playerfire, blasterpowerup, invincible, scatterlife);
	 
	 
	 
	 
	 
 if (segmentationfix==1)
       {
	 for (int i=0; i<f->enemycount; i++)
	    {                                      // enemy entrance animation
	     f->arr[i].move(movementlock, circle);
	    }
	 
	   
	   
	 for (int i=0; i<f->enemycount; i++)  // enemies fire function
	    {
	     f->arr[i].fire(movementlock,  alphareset, betareset, gammareset, slow, level2);
	    }
	    
	    hitbox.check_enemycollision( p, f, invincible, destroyed, blasterpowerup, enemycount, movementlock, score, level, m);
	  
	  
	  
	  
	  // Monster functions  
	 m->spawn(f, slow, movementlock, destroyed, beamsound, monstertheme, level2);
         m->move(movementlock, score, beamsound, monsterend);
         m->fire(beam);
         hitbox.check_monstercollision( p, m,  destroyed, invincible);
        }
	   
	   pow->spawner(firepoweruptimer, blasterduration, scatterlife); //spawns powerup
	    
	    if (m->monsterspawn==1)
          {
           pow->powerlife=0;
           firepoweruptimer=0;
           }; 
	   
	   pow->move();// animates powerup
	   
	   
	   hitbox.check_powerupcollision( p, pow, lives, destroyed, blasterpowerup, slow, invincible, playslow, scattershots, scatterlife);
	   
	   
	   
	    asteroid->spawner(asteroidtimer, playalert, slow, score); //spawns asteroid
	   
	   asteroid->move(slow);// animates asteroid
	   
	   hitbox.check_asteroidcollision(p, asteroid, destroyed, invincible); //checks if player has impacted with asteroid
	   
	
	/////  Call your functions here            ////
	//////////////////////////////////////////////
      }
	window.clear(Color::Black); //clears the screen
	
	
	
	///////////////MONSTER SOUNDS/////////////////
	if (monstertheme==1)
	  {
	  monstertheme=0;
	  theme.pause();
	   m->monsttheme.play();
	   warden.play();
	  }
	  
	  if (monsterend==1)
	   { 
	   monsterend=0;
	   theme.play();
	   beamsound=0;
	   
	   }
	   
	   if (m->disphf==1 && beamsound==0)
	     {
	     beamsound=1;     
	      m->attack.play();
	     }
	     
	
	     if (m->disphf==0 && beamsound==1)
	      {
	       m->attack.stop();
	       beamsound=0;
	      }
	
///////////////////////////////////////	
	
	
	
	if (paused==0 && end==0)
	  {
	
	  if (slow==1)
	   {
	  fy1+=1*0.1;
	  fy2+=1*0.1;
	  fy3+=1*0.1;
	  fy4+=1*0.1;
	  }
	
	
	else
	 {
	fy1+=1;
	fy2+=1;
	fy3+=1;
	fy4+=1;
	 }
	
	if (fy1>=740)
	fy1=-2220;
	
	if (fy2>=740)
	fy2=-2220;
	
	if (fy3>=740)
	fy3=-2220;
	
	if (fy4>=740)
	fy4=-2220;
	
	
	 bg1.setPosition(0, fy1);
         bg2.setPosition(0, fy2);
        bg3.setPosition(0, fy3);
        bg4.setPosition(0, fy4);
	
	 }

	  
	window.draw(bg1);  // setting background
	window.draw(bg2);
	window.draw(bg3);
	window.draw(bg4);



	if (asteroid->astrlife==1)
	window.draw(asteroid->astr);
	
	if (asteroid->warninglife==1)
	{

	window.draw(asteroid->warning);
	}
	
	if (pow->powerlife==1)
	window.draw(pow->spr);
	
	
	
	if (destroyed==0 && lives>0)
	window.draw(p->sprite);   // setting player on screen
	
	if (destroyed==1)
	{ 
          if(explode==0)
          {
          playerexplode.play();
          }
          explode=1;
         }
	
	if (p->laserlife==1)
	window.draw(p->laser1);
	
	
	
	
   if (segmentationfix==1)
     { 
	for (int i=0; i<f->enemycount; i++)
	  {
	   if (f->arr[i].bomblife==1)
	   window.draw(f->arr[i].bomb);
	  }
	
	
	
	if (enemycount!=0)
	   {
	    for (int i=0; i<f->enemycount; i++) 
	     {
	     if (f->arr[i].defeat==0)         //display undefeated invaders only
	     window.draw(f->arr[i].invader);
	   
	    }
	   
	   }
	   
     }
     
      
	 if (pow->taken==1)
	 {
	 powerpickup.play();
	 pow->taken=0;
	 }
	    if (beam==1)
         window.draw(m->hellfire);
   
	 window.draw(m->monster);
	
	//enemy explode animation
	//checks entire array of formation
if (segmentationfix==1) 
  {  
     

     for (int i=0; i<f->enemycount; i++)
        {
         
           //playing sound
           if (f->arr[i].defeat==1 && f->arr[i].play==1)
             {
             f->arr[i].explosion.play();
              f->arr[i].play=0;
             }
          
          
      if (f->arr[i].defeat==1 && f->arr[i].currentFrame<16 && f->arr[i].expdisp==1)
           {
           if (slow==0)
            f->arr[i].animation2+=0.16666666;
            
            else
             f->arr[i].animation2+=0.16666666*0.1;
            
          if (f->arr[i].currentFrame==0)
	     {
	     if ( f->arr[i].enemytype == 3)
	     f->arr[i].exp2.setPosition(f->arr[i].x+3, f->arr[i].y-3);
	     
	     else if 
	      (f->arr[i].enemytype == 1)
	      f->arr[i].exp2.setPosition(f->arr[i].x+5, f->arr[i].y-3);
	     
	     else
             f->arr[i].exp2.setPosition(f->arr[i].x+0.5, f->arr[i].y+5);
             
             f->arr[i].exp2.setScale(1.1, 1.1);
              }
	 	
  	  if (f->arr[i].animation2 > 0.15)
  	      {

             f->arr[i].exp2.setTextureRect(f->arr[i].a[f->arr[i].currentFrame]);
             f->arr[i].currentFrame++;
             f->arr[i].animation2=0;
                }
              
      
          window.draw(f->arr[i].exp2);
          
          if (f->arr[i].currentFrame==15)
           {
            f->arr[i].currentFrame=0;
            f->arr[i].expdisp=0;
            }
            
            
         }
              
              
              
         else
         f->arr[i].animation2=0;
              
     
     }
	
 }
	
	//player explode animation
	explosion.setTextureRect(frames[framecount]);
	
	if (destroyed==1 && framecount<4)
	 {	
	if (m->monsterspawn==1 && framecount==3) // if monster is spawned ten auto spawn to avoid afk behaviour to dodge monster
	  {
	   respawn=1;
	   lives--;
	  }
	animation+=0.016666666;
	
	  if (framecount==0)
	   {
          explosion.setPosition(p->x, p->y);
          explosion.setScale(0.7, 0.7);
          }
	 	
  	if (animation > 0.12)
  	  {
  	
       
           explosion.setTextureRect(frames[framecount]);
             framecount++;
           animation=0;
          }
         
      
          window.draw(explosion);
       
    
        }
        
	else 
	animation=0;
	
	
///////////////////////SCATTERSHOT POWERUP////////////////////////////
if (scatterlife==1 && paused==0)
  {
   if (create==1)
     {
    
     
    
      for (int i=0; i<7; i++)
       {
        a[i]=new Scatter(i+1);
        b[i]=new Scatter(i+1);
        c[i]=new Scatter(i+1);
        
        }
     create=0;
     }
      if (Keyboard::isKeyPressed(Keyboard::Space) && press==0)
       {
       if (scattershots!=0)
       scattersound.play();
       p->shoot=1;
       press=1;
       }
      
  
  if (p->shoot==1 && scattershots==3)
     {
      for (int i=0; i<7; i++)
     a[i]->fire(p);
     scattershots--;
     p->shoot=0;
     }
   
    
    if (p->shoot==1 && scattershots==2)
     {
      for (int i=0; i<7; i++)
     b[i]->fire(p);
     scattershots--;
     p->shoot=0;
     }
   
    if (p->shoot==1 && scattershots==1)
     {
      for (int i=0; i<7; i++)
     c[i]->fire(p);
     
     scattershots--;
     p->shoot=0;
     }    
     
     if (p->shoot==0)
      {
     
      for (int i=0; i<7; i++)
         {
         a[i]->fire(p);
         b[i]->fire(p);
         c[i]->fire(p);
         }
      }
  
 
   if (scattershots==0)  //if all 7 scatters are finished only then scatterlife=0
    {
     
     int tempcount=0;
  for (int i=0; i<7; i++)
        {
         if (c[i]->life==0)
          tempcount++;
        }
   
        if (tempcount==7)
         {
       
          scatterlife=0;
          press=1;
          create=1;
          
         
         }
         
     

     }
    
  
  }
  
      

     if (scatterlife==1)
     {
     for (int i=0; i<7; i++)
      {
      if (a[i]->life==1)
       window.draw(a[i]->s);
       
       if (b[i]->life==1)
       window.draw(b[i]->s);
       
       if (c[i]->life==1)
       window.draw(c[i]->s);
       
       }
     
       hitbox.check_scattercollision(a, f, scatterlife, m, enemycount, score,  movementlock, level );    
       hitbox.check_scattercollision(b, f, scatterlife, m, enemycount, score,  movementlock, level );
       
       hitbox.check_scattercollision(c, f, scatterlife, m, enemycount, score,  movementlock, level );
     
     
    }
   

	
	 if (!Keyboard::isKeyPressed(Keyboard::Space)) //ensures that space has to be let go and pressed again for next round to fire
               press=0;
/////////////////////HUD overlay////////////////////////////////////////
  scoredisp.setScale(0.6,0.6); 
  livesdisp.setScale(0.6,0.6); 
  leveldisp.setScale(1,1); 
  phasedisp.setScale(1,1); 
  scattershotcount.setScale(0.6, 0.6);
  
  scoredisp.setOrigin(-25,-1120); 
  livesdisp.setOrigin(-1160,-1120); 
  leveldisp.setOrigin(-340,-300); 
  phasedisp.setOrigin(-337,-350); 
  scattershotcount.setOrigin(-490,-1120);
  
  
  string displayscore = "SCORE: ";
  string displaylives = "LIVES: ";
  string displaylevel = "LEVEL ";
  string displayphase = "PHASE ";
  string displayss = "SCATTERSHOTS: ";
  
  
  displaylives+=to_string(lives);
  displayscore+= to_string(score);
  displaylevel+= to_string(level);
  displayphase+= to_string(phase+1);
  displayss += to_string(scattershots);
  
  scoredisp.setString(displayscore);
  livesdisp.setString(displaylives);
  leveldisp.setString(displaylevel);
  phasedisp.setString(displayphase);
  scattershotcount.setString(displayss);
  
    //level and phase as hud. Shown only if not in a menu
if (highdisp==0 && helpdisp==0)
{
  window.draw(scoredisp);
  window.draw(livesdisp);
  

 if (enemycount==0 && phasedelay<=3.5 && level!=3  )
  {
  window.draw(leveldisp);
  window.draw(phasedisp);
  }

   if (enemycount==0 && phasedelay<=3.5 && level==3  && phase==0 )
  {
  window.draw(leveldisp);
  }
  
} 

if (destroyed==1 && end==0 && lives!=0 && m->monsterspawn==0 )
window.draw(prompt);


if (scattershots>0)
window.draw(scattershotcount);

//////////////////////////////////////////////////////PAUSE MENU////////////////////////////////////////////////////////
	
	
	if(p->laserlife==1 && time2<=0.35 )
         window.draw(p->eff);

        if (Keyboard::isKeyPressed(Keyboard::P))
         {
            paused = true;
            theme.pause();
            
            if (asteroid->warninglife==1)
            alert.pause();
            if (slow==1)
             clocktick.pause();
             
             if (m->monsterspawn==1)
             m->monsttheme.pause();
            }
   
        if (paused==1)   
       {
        window.draw(pause_menu); 
        
        //resume game
          if (Keyboard::isKeyPressed(Keyboard::Num5))
            {  
             selection.play();
               paused = false;
                theme.play();
                
                if (asteroid->warninglife==1)
                alert.play();
                
                if (slow==1)
                clocktick.play();
                
                  if (m->monsterspawn==1)
                 m->monsttheme.play();
               
                }
        
            sf::sleep(sf::milliseconds(10));
            
            
            
        //help menu
    if (Keyboard::isKeyPressed(Keyboard::Num3) && highdisp==0 ) 
    { 
        selection.play();
     helpdisp=1;
 
    }
    
    
    if (helpdisp==1)
     {
      window.draw(helpmenu);
      
           if (Keyboard::isKeyPressed(Keyboard::Escape) ) 

             { 
             selection.play();
              helpdisp=0;
 
              }
      
      }
 
 //highscoremenu
   if (Keyboard::isKeyPressed(Keyboard::Num2) && helpdisp==0 ) 

    { 
        selection.play();
     highdisp=1;
 
    }
    
    
    if (highdisp==1)
     {
      window.draw(highmenu);
      
        high1disp.setPosition(550,350);
        window.draw(high1disp);
     
        high2disp.setPosition(550,464);
        window.draw(high2disp);
     
        high3disp.setPosition(550,570);
        window.draw(high3disp);
     
       name1disp.setPosition(180, 350);
       window.draw(name1disp);
     
       name2disp.setPosition(180, 464);
      window.draw(name2disp);
     
       name3disp.setPosition(180, 570);
       window.draw(name3disp);
     
      
           if (Keyboard::isKeyPressed(Keyboard::Escape) ) 

             { 
             selection.play();
              highdisp=0;
 
              }
      
      }
 
 
 
 
 
 
 
 
 
 //close game
   if (Keyboard::isKeyPressed(Keyboard::Num4) && helpdisp==0 && highdisp==0 ) 

    { 
        
      window.close();
 
    }
        
        

        
        //restart game
        
          if (Keyboard::isKeyPressed(Keyboard::Num1))
          {
            paused = false;
          p->sprite.setPosition(340, 620);
          phase=0;
          timer=0;
    	 time=0;
  	   time2=0;
   	  repeat=0;
  	   firepoweruptimer=0;
   	  asteroidtimer=0;
    	 blasterduration=0;
    	 slowduration=0;
    	 phasedelay=0;
    	 animation=0;
           repeat=0;
           firepoweruptimer=0;
           level=1;
	   phase=0;
	   score=0;
          enemycount=0;
          lives=3;
          play=1;
          blasterpowerup=0;
           blasterend=0;
           paused=0;
	if (segmentationfix==1)
	 {
	 
	 delete[] f->arr;
         delete f;
         delete m;
         }
         delete p;
         delete pow;
         delete asteroid;
    if (scatterlife==1)
  	  {
     
   	   for (int i=0; i<7; i++)
   	    { 
   	    delete a[i];
   	    delete b[i];
   	    delete c[i];
    	   }
     
         }
         
	  p=new bullet();
	  pow= new Powerup();
	  asteroid= new Asteroid();
	  m=new Monster();
     
         segmentationfix=0;
	  movementlock=0;
         alphatimer=0;
	 betatimer=0; 
	 gammatimer=0;
	 firetime=0;
	 destroyed=0;
	 invincibility_period=0;
	 invincible=0;
	 press=1;
        framecount=0;
        animation=0;
	 playalert=0;
	 explode=0;
	beam=0;
	beamsound=0;
	monstertheme=0;
	monsterend=0;
       create=1;
      scattershots=0 ;
      scatterlife=0;
      p->laserlife=0;
      p->shoot=0;
	entercheck=0;
	respawn=0;
         framecount=0;
	 firepoweruptimer=0;
	 blasterduration=0;
	 asteroidtimer=0;
	 theme.play();
	 
	 
	 
	 
	 
	
  //Selects random phase and ensures that its not repeated
	for (int i=0; i<3; i++)
	    {
     
	    if (i==0)
	     phase_selector[i]=rand()%3+1;
    
	    else 
	      {
	      int count=0;
	      int temp;
	      while (count!=i)
	         {
	         count=0;
	         temp=rand()%3+1;
	         
	         for (int j=i-1; j>=0; j--)
	           {
	            if (phase_selector[j]!=temp)
	             count++;
	           }
	           phase_selector[i]=temp;
	         }
	       }
    
	    }
	 
	 
	 
          }
    }
    
    
    
    
 
    
    
    
    
    
 ///////////////////////////////////////GAMEOVERMENU/////////////////////////// 

 if (end==1)
  {
            if (entercheck==1)
          {
          window.draw(enter);
         
          }
          
       if (score>=highscore3 && score!=0)
       {
       if (entercheck==0)
       achievement.play();
       entercheck=1;
        
  
          if (Keyboard::isKeyPressed(Keyboard::Enter)) 
         {    
           selection.play();
           entercheck=0;
          }

        }
     
     theme.stop();
     m->attack.stop();
      clocktick.stop();
      m->monsttheme.stop();
      
     if (entercheck==0)
     window.draw(gameovermenu);
        
       //saving highscores
        if (score>=highscore1 && score!=0 && entercheck==0)
          { 
            
            cout<<"Enter name"<<endl;
            cin>>tempname;
            
          
  
          ofstream write1("score/highscore3.txt");
          write1<<highscore2;
          write1.close();
          
          ofstream write2("score/highscore2.txt");
          write2<<highscore1;
          write2.close();
          
          ofstream write3("score/highscore1.txt");
          write3<<score;
          write3.close();
          
          
          
          ofstream write4("score/name3.txt");
          write4<<midname;
          write4.close();
          
          
          ofstream write5("score/name2.txt");
          write5<<highname;
          write5.close();
          
          
          ofstream write6("score/name1.txt");
          write6<<tempname;
          write6.close();
     
          score=0;
           }
           
        else if (score>=highscore2 && score!=0 && entercheck==0)
          {
          
            
            cout<<"Enter name"<<endl;
            cin>>tempname;
            
          
  
            ofstream write1("score/highscore3.txt");
            write1<<highscore2;
            write1.close();
          
            ofstream write2("score/highscore2.txt");
            write2<<score;
            write2.close();
          
    
          
            ofstream write4("score/name3.txt");
            write4<<midname;
            write4.close();
          
          
            ofstream write5("score/name2.txt");
            write5<<tempname;
            write5.close();
          

            score=0;
           }
           
          else if (score>=highscore3 && score!=0 && entercheck==0)
          {
           
           cout<<"score/Enter name"<<endl;
           cin>>tempname;
           
          
  
           ofstream write1("score/highscore3.txt");
           write1<<score;
           write1.close();
          
 
           ofstream write4("score/name3.txt");
           write4<<tempname;
           write4.close();
          

           score=0;
           }
      
      
      

  //helpmenu///  
     
      if (Keyboard::isKeyPressed(Keyboard::Num3) && highdisp==0 ) 
    { 
        selection.play();
     helpdisp=1;
 
    }
    
    
    if (helpdisp==1)
     {
      window.draw(helpmenu);
      
           if (Keyboard::isKeyPressed(Keyboard::Escape) ) 

             { 
               selection.play();
              helpdisp=0;
 
              }
      
      }
 
 //highscoremenu
   if (Keyboard::isKeyPressed(Keyboard::Num2) && helpdisp==0 ) 

    { 
         selection.play();
     highdisp=1;
 
    }
    
    
    if (highdisp==1)
     {
      window.draw(highmenu);
      
        high1disp.setPosition(550,350);
        window.draw(high1disp);
     
        high2disp.setPosition(550,464);
        window.draw(high2disp);
     
        high3disp.setPosition(550,570);
        window.draw(high3disp);
     
       name1disp.setPosition(180, 350);
       window.draw(name1disp);
     
       name2disp.setPosition(180, 464);
      window.draw(name2disp);
     
       name3disp.setPosition(180, 570);
       window.draw(name3disp);
     
      
           if (Keyboard::isKeyPressed(Keyboard::Escape) ) 

             { 
             selection.play();
              highdisp=0;
 
              }
      
      }
 
 
 
 
 
 
 
 
 
 //close game
   if (Keyboard::isKeyPressed(Keyboard::Num4) && helpdisp==0 && highdisp==0 ) 

    { 
        
      window.close();
 
    }
        
        

        
        //restart game
        
          if (Keyboard::isKeyPressed(Keyboard::Num1))
          {
            end = false;
          p->sprite.setPosition(340, 620);
          phase=0;
           timer=0;
  	   time=0;
    	 time2=0;
   	  repeat=0;
    	 firepoweruptimer=0;
   	  asteroidtimer=0;
  	   blasterduration=0;
   	  slowduration=0;
   	  phasedelay=0;
   	  animation=0;
           repeat=0;
           firepoweruptimer=0;
           level=1;
	   phase=0;
	   score=0;
          enemycount=0;
          lives=3;
          play=1;
          blasterpowerup=0;
           blasterend=0;
           paused=0;
           
	 if (segmentationfix==1)
	 {
	  delete[] f->arr;
         delete f;
         delete m;
         }
         delete p;
         delete pow;
         delete asteroid;
         
         if (scatterlife==1)
  	  {
     
   	   for (int i=0; i<7; i++)
   	    { 
   	    delete a[i];
   	    delete b[i];
   	    delete c[i];
    	   }
     
         }
         
	  p=new bullet();
	  pow= new Powerup();
	  asteroid= new Asteroid();
	  m=new Monster();

	  movementlock=0;
         alphatimer=0;
	 betatimer=0; 
	 gammatimer=0;
	 firetime=0;
	 destroyed=0;
	 invincibility_period=0;
	 invincible=0;
	 press=1;
	   framecount=0;
        animation=0;
         segmentationfix=0;
         
	 playalert=0;
	 explode=0;
	beam=0;
	beamsound=0;
	monstertheme=0;
	monsterend=0;
       create=1;
       scattershots=0;
        scatterlife=0;
      p->laserlife=0;
      p->shoot=0;

	entercheck=0;
	respawn=0;
         framecount=0;
	 firepoweruptimer=0;
	 blasterduration=0;
	 asteroidtimer=0;
	
	 theme.play();
	 
	 
	 
	 
	
  //Selects random phase and ensures that its not repeated
	for (int i=0; i<3; i++)
	    {
     
	    if (i==0)
	     phase_selector[i]=rand()%3+1;
    
	    else 
	      {
	      int count=0;
	      int temp;
	      while (count!=i)
	         {
	         count=0;
	         temp=rand()%3+1;
	         
	         for (int j=i-1; j>=0; j--)
	           {
	            if (phase_selector[j]!=temp)
	             count++;
	           }
	           phase_selector[i]=temp;
	         }
	       }
    
	    }
	 
	 
	 
          }
     
     
     
     
     
     
     
     
     
     
     
     
     
     }
    
    
    
    
    
    
    
    
    

     
	window.display();  //Displying all the sprites
	
	

	 if (playalert==1)
	   {
	   
	    alert.play();
	    playalert=0;
	   }
    }


}


};

