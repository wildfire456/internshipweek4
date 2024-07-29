#include <SFML/Graphics.hpp>
#include<string.h>
#include <iostream>
#include <time.h>
using namespace std;
using namespace sf;

class Scatter
{
public:
float x;
float y;
int type;
bool life;
bool destroy;

Sprite s;
Texture st;
float lifeclock;




Scatter (int i)
 {
  if (i==1)
   {
   type=1;
   st.loadFromFile("img/scattershot/s1.png");

   
   }
   
   
 else if (i==2)
   {
   type=2;
   st.loadFromFile("img/scattershot/s2.png");
  
   
   }
  
 
 else if (i==3)
   {
   type=3;
   st.loadFromFile("img/scattershot/s3.png");

   
   }
 
  else if (i==4)
   {
   type=4;
   st.loadFromFile("img/scattershot/s4.png");
  
   
   }
  
   else if (i==5)
   {
   type=5;
   st.loadFromFile("img/scattershot/s5.png");
   
   
   }
   
    else if (i==6)
   {
   type=6;
   st.loadFromFile("img/scattershot/s6.png");
  
   
   }
    
     else if (i==7)
   {
   type=7;
   st.loadFromFile("img/scattershot/s7.png");
   
   
   }
 
 s.setTexture(st);
  s.setScale(0.5, 0.8);
 
 life=0;
 lifeclock=0;
 destroy=0;
 x=0;
 y=0;
 }
 
 void fire ( Player* p)
   {
   if (p->shoot==1)
     {
   life=1;
   
   }
   
   
   
   if (life==0)
    {
    
	     if (type==1)
	   {
	     x=p->x+38;
       y=p->y;
     
       s.setPosition(x, y);
	   }
   
   
	 else if (type==2)
	   {
 	      x=p->x+35;
       y=p->y;
       s.setPosition(x, y);
	   }
  
 
	 else if (type==3)
	   {
	     x=p->x+32;
       y=p->y;
       s.setPosition(x, y);
	   }
 
	  else if (type==4)
	   {
	     x=p->x+29;
       y=p->y;
       s.setPosition(x, y);
	   }
  
	   else if (type==5)
	   {
	     x=p->x+26;
       y=p->y;
       s.setPosition(x, y);
   
	   }
   
	    else if (type==6)
	   {
        x=p->x+23;
       y=p->y;
        s.setPosition(x, y);
   
	   }
    
	     else if (type==7)
	   {
        x=p->x+20;
       y=p->y;
   
       s.setPosition(x, y);
	   }
   
   }
   if (life==1)
     {
     lifeclock+=0.0166666;
     
      if (type==1)
	   {
	     x+=9.19*0.7;
	     y-=9.19*0.7;
       s.setPosition(x, y);
   
	   }
   
   
	 else if (type==2)
	   {
 	    x+=6.5*0.7;
	     y-=11.26*0.7;
     s.setPosition(x, y);
	   }
  
 
	 else if (type==3)
	   {
	   x+=3.365*0.7;
	   y-=12.557*0.7;
       s.setPosition(x, y);
	   }
 
	  else if (type==4)
	   {
	    
	     y-=13*0.7;
	     s.setPosition(x, y);
	   }
  
	   else if (type==5)
	   {
	    x-=3.365*0.7;
	     y-=12.557*0.7;
	     s.setPosition(x, y);
   
	   }
   
	    else if (type==6)
	   {
         x-=6.5*0.7;
	     y-=11.26*0.7;
      s.setPosition(x, y);
   
	   }
    
	     else if (type==7)
	   {
       x-=9.19*0.7;
	   y-=9.19*0.7;
      s.setPosition(x, y);
   
	   }
   
   
   
    }
   
   
   if (lifeclock>=1.7)
     {
   destroy=1;
   life=0;
   }
   
  }
    

};
