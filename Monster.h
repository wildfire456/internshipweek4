#include <SFML/Graphics.hpp>
#include<string.h>
#include <iostream>
#include <time.h>



using namespace std;
using namespace sf;

//monster / boss
class Monster: public Enemy
{
public:

Monster()
 {
  buffer2.loadFromFile("songs/beam.wav");
  attack.setBuffer(buffer2);
  
  buffer3.loadFromFile("songs/monster.wav");
  monsttheme.setBuffer(buffer3);
  
  xdirn=1;
  monstert.loadFromFile("img/monster1.png");
  monster.setTexture(monstert);
 
   monsx=202.4;
  monsy=-300;
  monster.setScale(0.67,0.455);
  monster.setPosition(202.4,-300);

  
  
    hellfiret.loadFromFile("img/monsterfire.png");
    hellfire.setTexture(hellfiret);
    hellfire.setScale(0.85,0.8);
    hellfire.setPosition(monsx+120,monsy+265);

  hellfirex=0;
  hellfirey=0;
  
  monstertimer=0;
  monsterspawn=0;
  monsterduration=0;
  monsterlock=0;
  monsterwait=0;
  monsterwaitclock=0;
  

  center=0;
  disphf=0;
  enemymoveduration=0;
  enemyrestore=0;
 survive=1;
 
  
 }


void spawn(Formation* f, bool slow, bool movementlock, bool destroyed, bool& beamsound, bool& monstertheme, int level)
  {
  

 if (level>=2)  //only spawns if level is 2 or higher
  {
   
  if (monsterspawn==1)
   {
    if (destroyed==1)
     survive=0;
   
   }
 

  if (monsterspawn==0)
    {
     if (destroyed==0 && slow==0)
     monstertimer+=0.01666666;
     }
   
   else
   monstertimer=0;
   
   
   
   srand(time(NULL));
 
   int random = rand()%3; //1/3 chance that monster spanws after 25 seconds have elapsed)
  
   
   
   if (monstertimer>=25)
    {
    if (movementlock==1 && random==1)
      {
     monsterspawn=1;
     monstertheme=1;
      }
     
     else 
     monstertimer=0;
 
    }
   
   
    if (monsterspawn==1) 
       { 
        
       if (enemymoveduration<=2)
          {
          enemymoveduration+=0.0166666;
          
           for (int i=0; i<f->enemycount; i++)
               {
                f->arr[i].move2("left", enemyrestore);
               
               }
           }
        if (monsterlock==1)
         monsterduration+=0.0166666;
      
      }
      
      if (enemyrestore==1)
        {
        monsy-=5;
        monster.setPosition(monsx,monsy);
        
            for (int i=0; i<f->enemycount; i++)
               {
                f->arr[i].move2("right", enemyrestore);
               
               }
       if (enemyrestore==0)
            {
            
            monster.setPosition(202.4,-300);
            monsx=202.4;
            monsy=-300;
           
            }
        
        }
 
      
  
    }
  
  
  
  }

  void move(bool movementlock, int& score, bool& beamsound, bool& monsterend)
   {
   
   if (movementlock==1)
    {
   
    if (monsterlock==0 && monsterspawn==1 )
       {       
       monsy+=5;
        monster.setPosition(monsx, monsy);
        if (monsy>=20)
         {
         monsterlock=1;
         center=1;
         srand(time(NULL));
         xdirn=rand()%2;
         monsterwait=1;
         }
       }
       
    
       
         if ( monsterwait==0)
          {
           
           monsterwaitclock=0;
          }
       
         if (monsterwait==1 )
          {
          if (center==1)
           disphf=0;
           
          monsterwaitclock+=0.016666;
           
          
          }
        
        
       if (monsterlock==1 && monsterspawn==1 && monsterwait==0 && monsterduration<=18)
        {
         if (xdirn==1 && center==1) // right dirn
            {
            monsx+=6.5; //speed right dirn
             monster.setPosition(monsx, monsy);
             
             if (monsx>=550.333 && center==1)
              {
              monsterwait=1;
              center=0;
              }
       
            }
            
                      
            if (center==0 && monsterwait==0 && xdirn==1)  //recentering
              {
              monsx-=6.5;  //speed left dirn
             monster.setPosition(monsx, monsy);
             
             if (monsx<=202.4)
                 {
                 monsterwait=1;
                  center=1;
                  srand(time(NULL));
                  xdirn=rand()%2;
                 }
                
              }
              
             if (center==0 && monsterwait==0 && xdirn==0)  //recentering
              {
              monsx+=6.5;
             monster.setPosition(monsx, monsy);
             
             if (monsx>=202.4)
                 {
                 monsterwait=1;
                  center=1;
                  srand(time(NULL));
                  xdirn=rand()%2;
                 }
                
              }
              
            
           if (xdirn==0 && center==1) // right dirn
            {
            monsx-=6.5;
             monster.setPosition(monsx, monsy);
             
             if (monsx<=-160 && center==1)
              {
               monsterwait=1;
               center=0;
               }
            
            
            }
                   
        
        }
        

        
        if (monsterwaitclock>=1.2)
         {
          
             disphf=1;
         
          monsterwait=0;
          monsterwaitclock=0;
          }
     if (monsterduration>=18)  
      {
     
      enemyrestore=1;
        monstertimer=0;
        monsterduration=0;
       monsterlock=0;
        monsterwait=0;
       monsterwaitclock=0;
      monsterspawn=0;
      monsterend=1;
      
      if (survive==1)
      score+=40;
       
       survive=1;
        center=0;
        enemymoveduration=0;
      
      
      }
    }
   }
   
   
   void fire(bool& beam)
     {
      hellfirex=monsx+97;
      hellfirey=monsy+250;
      hellfire.setPosition(hellfirex,hellfirey);
      if (monsterspawn==1)
        {
         if (disphf==1)
           {
            
            beam=1;

           }
           
           else
           beam=0;

        }
     
     
     
     
     }
   
   



};
