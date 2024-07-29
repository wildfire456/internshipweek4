#include <SFML/Graphics.hpp>
#include<string.h>
#include <iostream>



using namespace std;
using namespace sf;
class Hitbox
 {
public:

 void check_asteroidcollision(Player* p, Asteroid* astr, bool& destroyed, bool invincible)
   {
   if (astr->astrlife==1)
    {
     float pxmax = p->x+36.05;
     float pxmin = p->x-36.05;
     
     float pymax = p->y+37.45;
     float pymin = p->y-37.45;
    
    
    float axmax = astr->x+38.7;
    float axmin = astr->x-38.7;
    
    float aymax = astr->y+38.7;
    float aymin = astr->y-38.7;
    
     if (invincible==0 && destroyed==0 && (pxmax>=axmin && pxmax<=axmax && pymax>=aymin && pymax<=aymax || pxmax>=axmin && pxmax<=axmax && aymax>=pymin && aymax<=pymax|| axmax>=pxmin && axmax<=pxmax && aymax>=pymin && aymax<=pymax || axmax>=pxmin && axmax<=pxmax && pymax>=aymin && pymax<=aymax))
      {
       astr->astrlife==0;
       destroyed=1;
       astr ->hit=1;
      }
    }
  }
  
  
  
  
  
 void check_enemycollision(Player* p, Formation* a, bool invincible, bool& destroyed, bool blasterpowerup, int& enemycount, bool movementlock, int& score, int level, Monster* m)
 {
         float pxmax = p->x+72.1;
     float pxmin = p->x;
     
     float pymax = p->y+74.9;
     float pymin = p->y;
         
         float axmax=0;
         float axmin=0;
           float aymax=0;
         float aymin=0;
         
 for (int i=0; i< a->enemycount; i++)
   {
   pxmax = p->x+72.1;
   pxmin = p->x;
     
   pymax = p->y+74.9;
   pymin = p->y; 
   if (a->arr[i].defeat==0 && invincible==0 && destroyed==0)  // checking collision for enemy and player spacecraft
     { 
     
      if (a->arr[i].enemytype==1)
       {

         axmax = a->arr[i].x+74.4;
         axmin = a->arr[i].x;
    
         aymax = a->arr[i].y+65.72;
         aymin = a->arr[i].y;
       }
     
    else if (a->arr[i].enemytype==2)
       {

         axmax = a->arr[i].x+60;
         axmin = a->arr[i].x;
    
         aymax = a->arr[i].y+77;
         aymin = a->arr[i].y;
       }
       
   else  
       {

         axmax = a->arr[i].x+69.2;
         axmin = a->arr[i].x;
    
         aymax = a->arr[i].y+52.8;
         aymin = a->arr[i].y;
       }
     
      if (destroyed==0 && (pxmax>=axmin && pxmax<=axmax && pymax>=aymin && pymax<=aymax || pxmax>=axmin && pxmax<=axmax && aymax>=pymin && aymax<=pymax|| axmax>=pxmin && axmax<=pxmax && aymax>=pymin && aymax<=pymax || axmax>=pxmin && axmax<=pxmax && pymax>=aymin && pymax<=aymax))
         {
         
          destroyed=1;
         
         }
      }
      
      if ( invincible==0 && destroyed==0 && a->arr[i].bomblife==1 )  // checking collision b/w bomb and player ship
        {
          axmax = a->arr[i].bombposx+6.5;
         axmin =  a->arr[i].bombposx;
    
         aymax =   a->arr[i].bombposy+44.4;
         aymin =  a->arr[i].bombposy;
         
              if (  invincible==0 && destroyed==0 && (pxmax>=axmin && pxmax<=axmax && pymax>=aymin && pymax<=aymax || pxmax>=axmin && pxmax<=axmax && aymax>=pymin && aymax<=pymax|| axmax>=pxmin && axmax<=pxmax && aymax>=pymin && aymax<=pymax || axmax>=pxmin && axmax<=pxmax && pymax>=aymin && pymax<=aymax))
               {
                destroyed=1;
                a->arr[i].bomblife=0;
               }
        
        }
        
        
        
        
        if (a->arr[i].defeat==0 && p->laserlife==1)  // checking collision for enemies vs players laser
          {
          
     		 if (a->arr[i].enemytype==1)
    		   {
	
   		      pxmax = a->arr[i].x+74.4;
    		     pxmin = a->arr[i].x;
    
    		     pymax = a->arr[i].y+65.72;
     		    pymin = a->arr[i].y;
     		  }
     
   		 else if (a->arr[i].enemytype==2)
   		    {

    		     pxmax = a->arr[i].x+60;
    		     pxmin = a->arr[i].x;
    
      		   pymax = a->arr[i].y+77;
      		   pymin = a->arr[i].y;
     		  }
       
 		  else  
   		    {

     		    pxmax = a->arr[i].x+69.2;
       	    pxmin = a->arr[i].x;
    
                   pymax = a->arr[i].y+52.8;
   	           pymin = a->arr[i].y;
                   }
         
           if (blasterpowerup==0)  // if blaster powerup is active
            {
             axmax = p->fireposx + 6.5;
             axmin =  p->fireposx;
    
             aymax =   p->fireposy + 44.4;
             aymin =  p->fireposy;
           }
           
           else 
            {
             axmax = p->fireposx + 11.05;
             axmin =  p->fireposx;
    
             aymax =   p->fireposy + 55.5;
             aymin =  p->fireposy;
            
            
            }
            
        if(m->monsterspawn==0)
           {
          if (a->arr[i].end==0 && p->laserlife==1 && movementlock==1 && (pxmax>=axmin && pxmax<=axmax && pymax>=aymin && pymax<=aymax || pxmax>=axmin && pxmax<=axmax && aymax>=pymin && aymax<=pymax|| axmax>=pxmin && axmax<=pxmax && aymax>=pymin && aymax<=pymax || axmax>=pxmin && axmax<=pxmax && pymax>=aymin && pymax<=aymax))
             {
              a->arr[i].defeat=1;
     
    	      if (blasterpowerup==0 )
              p->laserlife=0;
              enemycount--;
              
              if (a->arr[i].enemytype==1)
               score+=level*30;
               
                if (a->arr[i].enemytype==2)
               score+=level*20;
               
                if (a->arr[i].enemytype==3)
               score+=level*10;
             
             }
           }
           
           
           
        }
  
        
    }
 }
 
 void check_powerupcollision(Player* p, Powerup* pow, int& lives, bool destroyed, bool& blasterpowerup, bool& slow, bool& invincible, bool& playslow, int& scattershots, bool& scatterlife)
 {  
 if (pow->powerlife==1)
     {
       float pxmax = p->x+72.1;
     float pxmin = p->x;
     
     float pymax = p->y+74.9;
     float pymin = p->y;
    
    
    float axmax = pow->x+34;
    float axmin = pow->x;
    
    float aymax = pow->y+33;
    float aymin = pow->y;
  
      if (destroyed==0 && (pxmax>=axmin && pxmax<=axmax && pymax>=aymin && pymax<=aymax || pxmax>=axmin && pxmax<=axmax && aymax>=pymin && aymax<=pymax|| axmax>=pxmin && axmax<=pxmax && aymax>=pymin && aymax<=pymax || axmax>=pxmin && axmax<=pxmax && pymax>=aymin && pymax<=aymax))
         {
             pow->powerlife=0;
           pow->taken=1;
           
            if (pow->poweruptype==1)
            lives++;
            
             if (pow->poweruptype==2 || pow->poweruptype==3)
             {
             blasterpowerup=1;
             invincible=1;
             }
             
            if (pow->poweruptype==4  || pow->poweruptype==5)
             {
             playslow=1;
             slow=1;
             
             }
             
            if (pow->poweruptype==6  || pow->poweruptype==7)
             {
             scattershots=3;
             scatterlife=1;
             
             }
             
          }
     
     }

 }

void check_monstercollision(Player* p, Monster* m, bool& destroyed, bool invincible)
  {
  
   if (m->monsterspawn==1)
    {
      float pxmax = p->x+72.1;
     float pxmin = p->x;
     
     float pymax = p->y+74.9;
     float pymin = p->y;
       
       
       
       // hellfire coordinates  
     float axmax=m->hellfirex+187;
     float axmin=m->hellfirex;
     float aymax=m->hellfirey+485.6;
     float aymin=m->hellfirey;
     
       if (destroyed==0 && invincible==0 && m->disphf==1 && (pxmax>=axmin && pxmax<=axmax && pymax>=aymin && pymax<=aymax || pxmax>=axmin && pxmax<=axmax && aymax>=pymin && aymax<=pymax|| axmax>=pxmin && axmax<=pxmax && aymax>=pymin && aymax<=pymax || axmax>=pxmin && axmax<=pxmax && pymax>=aymin && pymax<=aymax))
         {
          destroyed=1;
             
          }
          
        // monster coordinates
      axmax = m->monsx+375.2;
      axmin = m->monsx;
      aymax = m->monsy+293.02;
      aymin = m->monsy;
  
  
    if (destroyed==0 && invincible==0 &&  (pxmax>=axmin && pxmax<=axmax && pymax>=aymin && pymax<=aymax || pxmax>=axmin && pxmax<=axmax && aymax>=pymin && aymax<=pymax|| axmax>=pxmin && axmax<=pxmax && aymax>=pymin && aymax<=pymax || axmax>=pxmin && axmax<=pxmax && pymax>=aymin && pymax<=aymax))
         {
          destroyed=1;
             
          }
    }
    
      
  
  }
  
  
  void check_scattercollision(Scatter* s[], Formation* a, bool scatterlife, Monster* m, int& enemycount, int& score, bool movementlock, int level )
 {
   
   if (scatterlife==1)
  {
    float pxmax=0;
    float pxmin=0;
      float pymax=0;
    float pymin=0;
    
     float axmax=0;
    float axmin=0;
      float aymax=0;
    float aymin=0;
    
   for (int i=0; i<a->enemycount; i++)
    {  
      for (int j=0; j<7; j++) 
        {
        
         if (j==0)
           {
           axmin=s[j]->x;
           aymin=s[j]->y;
           
            axmax=s[j]->x+31;
            aymax=s[j]->y+31;
           }
           
         else if (j==1)
           {
            axmin=s[j]->x;
           aymin=s[j]->y;
           
           axmax=s[j]->x+26;
            aymax=s[j]->y+35;
           }
         
         else if (j==2)
           {
            axmin=s[j]->x;
           aymin=s[j]->y;
           
           axmax=s[j]->x+21;
            aymax=s[j]->y+37;
           }
           
             else if (j==3)
           {
            axmin=s[j]->x;
           aymin=s[j]->y;
           
           axmax=s[j]->x+13;
            aymax=s[j]->y+37;
           }
           
             else if (j==4)
           {
            axmin=s[j]->x;
           aymin=s[j]->y;
           axmax=s[j]->x+21;
            aymax=s[j]->y+37;
           }
           
             else if (j==5)
           {
            axmin=s[j]->x;
           aymin=s[j]->y;
           
           axmax=s[j]->x+26;
            aymax=s[j]->y+35;
           }
           
             else if (j==6)
           {
            axmin=s[j]->x;
           aymin=s[j]->y;
           
           axmax=s[j]->x+31;
            aymax=s[j]->y+31;
           }
    
          if (a->arr[i].enemytype==1)
    		   {
	
   		      pxmax = a->arr[i].x+74.4;
    		     pxmin = a->arr[i].x;
    
    		     pymax = a->arr[i].y+65.72;
     		    pymin = a->arr[i].y;
     		  }
     
   		 else if (a->arr[i].enemytype==2)
   		    {

    		     pxmax = a->arr[i].x+60;
    		     pxmin = a->arr[i].x;
    
      		   pymax = a->arr[i].y+77;
      		   pymin = a->arr[i].y;
     		  }
       
 		  else  
   		    {

     		    pxmax = a->arr[i].x+69.2;
       	    pxmin = a->arr[i].x;
    
                   pymax = a->arr[i].y+52.8;
   	           pymin = a->arr[i].y;
                   }
                   
          if(m->monsterspawn==0)
           {
          if (a->arr[i].end==0 && a->arr[i].defeat==0 && s[j]->life==1 && movementlock==1 && (pxmax>=axmin && pxmax<=axmax && pymax>=aymin && pymax<=aymax || pxmax>=axmin && pxmax<=axmax && aymax>=pymin && aymax<=pymax|| axmax>=pxmin && axmax<=pxmax && aymax>=pymin && aymax<=pymax || axmax>=pxmin && axmax<=pxmax && pymax>=aymin && pymax<=aymax))
             {
              a->arr[i].defeat=1;
              s[j]->life=0;
              enemycount--;
              
              if (a->arr[i].enemytype==1)
               score+=level*30;
               
                if (a->arr[i].enemytype==2)
               score+=level*20;
               
                if (a->arr[i].enemytype==3)
               score+=level*10;
             
             }
           }        
                   
                   
                   
                   
                   
          }
   
        }
        
        
    }
    
    
    
  }

};
