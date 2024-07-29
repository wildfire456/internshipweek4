#include <SFML/Graphics.hpp>
#include<string.h>
#include <iostream>
#include <time.h>
#include "Invader.h"
#include "bomb.h"

using namespace std;
using namespace sf;
class Formation
{
public:
Invader* arr;
int enemycount;



Formation(int level, int phase, int(&phase_selector)[3], bool& circle, int& level2)
 {

 if (level==1)
  {
  srand(time(0));
  level2=level;

  if (phase_selector[phase]==1) //triangle shape
    {
    
    enemycount=8;
     arr=new Bomb[enemycount];
     for (int i=0; i<enemycount; i++)
        {
        
         if (i==0)
           {
             if (arr[i].enemytype == 1)//type1 is slightly misposisitioned so readjusting
             {   
                 arr[i].x = 21;
                 arr[i].y = -75;
                 arr[i].invader.setPosition(21, -75);
             }
             else
             {   
                 arr[i].x = 27;
                 arr[i].y = -75;
                 arr[i].invader.setPosition(27, -75);
             }
           }
           
          if (i==1)
           {
              if (arr[i].enemytype == 1)
              {   
                  arr[i].x = 174;
                  arr[i].y = -195;
                  arr[i].invader.setPosition(174, -195);
              }
            
              else
              {  
                  arr[i].x = 180;
                  arr[i].y = -195;
                  arr[i].invader.setPosition(180, -195);
              }
           }
           
              if (i==2)
           {
                  if (arr[i].enemytype == 1)
                  {  
                      arr[i].x = 169;
                      arr[i].y = -75;
                      arr[i].invader.setPosition(169, -75);
                  }
            //
                  else
                  {   
                      arr[i].x = 175;
                      arr[i].y = -75;
                      arr[i].invader.setPosition(175, -75);
                  }
           }
           
          if (i==3)
           {
              if (arr[i].enemytype == 1)
              {
                  arr[i].x = 340;
                  arr[i].y = -75;
                  arr[i].invader.setPosition(340, -75);
              }
            
              else
              { 
                  arr[i].x = 346;
                  arr[i].y = -75;
                  arr[i].invader.setPosition(346, -75);
              }
           }
           
           
         if (i==4)
           {
             if (arr[i].enemytype == 1)
             { 
                 arr[i].x = 674;
                 arr[i].y = -75;
                 arr[i].invader.setPosition(674, -75);
             }
            
             else
             { 
                 arr[i].x = 680;
                 arr[i].y = -75;
                 arr[i].invader.setPosition(680, -75);
             }
           }
           
          if (i==5)
           {
              if (arr[i].enemytype == 1)
              {
                  arr[i].x = 498;
                  arr[i].y = -195;
                  arr[i].invader.setPosition(498, -195);
              }
            
              else
              {
                  arr[i].x = 504;
                  arr[i].y = -195;
                  arr[i].invader.setPosition(504, -195);
              }
           }
           
          if (i==6)
           {
              if (arr[i].enemytype == 1)
              {
                  arr[i].x = 495;
                  arr[i].y = -75;
                  arr[i].invader.setPosition(495, -75);
              }
            
              else// 125 x 
              {
                  arr[i].x = 501;
                  arr[i].y = -75;
                  arr[i].invader.setPosition(501, -75);
              }
           }
           
           if (i==7)
           {
               if (arr[i].enemytype == 1)
               {  
                   arr[i].x = 340;
                   arr[i].y = -315;
                   arr[i].invader.setPosition(340, -315);
               }
            
               else
               {   
                   arr[i].x = 346;
                   arr[i].y = -315;
                   arr[i].invader.setPosition(346, -315);
               }
           }
           
           
           
           
           
        }
    
    
    }
    
    if (phase_selector[phase]==2) //rectangle shape
    {
    
    enemycount=12;
     arr=new Bomb[enemycount];
     for (int i=0; i<enemycount; i++)
        {
        
         if (i==0) 
           {

             if (arr[i].enemytype == 1)//type1 is slightly misposisitioned so readjusting
             {  
                 arr[i].x = 44;
                 arr[i].y = -72;
                 arr[i].invader.setPosition(44, -72);
             }
            
             else
             {  
                 arr[i].x = 50;
                 arr[i].y = -75;
                 arr[i].invader.setPosition(50, -75);
             }
           }
           
          if (i==1)
           {
              if (arr[i].enemytype == 1)
              {    
                  arr[i].x = 44;
                  arr[i].y = -192;
                  arr[i].invader.setPosition(44, -192);
              }
            
              else
              {  
                  arr[i].x = 50;
                  arr[i].y = -192;
                  arr[i].invader.setPosition(50, -195);
              }
           }
           
              if (i==2) 
           {
                  if (arr[i].enemytype == 1)
                  {  
                      arr[i].x = 44;
                      arr[i].y = -313;
                      arr[i].invader.setPosition(44, -313);
                  }
             
                  else
                  {  
                      arr[i].x = 50;
                      arr[i].y = -315;
                      arr[i].invader.setPosition(50, -315);
                  }
           }
           
          if (i==3)
           {
              if (arr[i].enemytype == 1)
              {  
                  arr[i].x = 340;
                  arr[i].y = -72;
                  arr[i].invader.setPosition(340, -72);
              }
            
              else
              {  
                  arr[i].x = 346;
                  arr[i].y = -75;
                  arr[i].invader.setPosition(346, -75);
              }
           }
           
           
         if (i==4) 
           {
             if (arr[i].enemytype == 1)
             { 
                 arr[i].x = 630;
                 arr[i].y = -72;
                 arr[i].invader.setPosition(630, -72);
             }
            
             else
             { 
                 arr[i].x = 634;
                 arr[i].y = -75;
                 arr[i].invader.setPosition(634, -75);
             }
           }
           
          if (i==5)
           {
              if (arr[i].enemytype == 1)
              {  
                  arr[i].x = 630;
                  arr[i].y = -192;
                  arr[i].invader.setPosition(630, -192);
              }
            
              else
              {  
                  arr[i].x = 634;
                  arr[i].y = -195;
                  arr[i].invader.setPosition(634, -195);
              }
           }
           
          if (i==6) 
           {
              if (arr[i].enemytype == 1)
              {  
                  arr[i].x = 630;
                  arr[i].y = -312;
                  arr[i].invader.setPosition(630, -312);
              }
            
              else
              { 
                  arr[i].x = 634;
                  arr[i].y = -315;
                  arr[i].invader.setPosition(634, -315);
              }
           }
           
           if (i==7)
           {
               if (arr[i].enemytype == 1)
               {  
                   arr[i].x = 340;
                   arr[i].y = -312;
                   arr[i].invader.setPosition(340, -312);
               }
            
               else
               { 
                   arr[i].x = 346;
                       arr[i].y = -315;
                   arr[i].invader.setPosition(346, -315);
               }
           }
           
           
           
          if (i==8) 
           {

             if (arr[i].enemytype == 1)//type1 is slightly misposisitioned so readjusting
             {  
                 arr[i].x = 196;
                 arr[i].y = -72;
                 arr[i].invader.setPosition(196, -72);
             }
            
             else
             {  
                 arr[i].x = 202;
                 arr[i].y = -75;
                 arr[i].invader.setPosition(202, -75);
             }
           }
           
           
           
         if (i==9) 
           {

             if (arr[i].enemytype == 1)//type1 is slightly misposisitioned so readjusting
             {  
                 arr[i].x = 485;
                 arr[i].y = -72;
                 arr[i].invader.setPosition(485, -72);
             }
            
             else
             {  
                 arr[i].x = 491;
                 arr[i].y = -75;
                 arr[i].invader.setPosition(491, -75);
             }
           }
           
           
           
          if (i==10) 
           {

             if (arr[i].enemytype == 1)//type1 is slightly misposisitioned so readjusting
             {  
                 arr[i].x = 196;
                 arr[i].y = -312;
                 arr[i].invader.setPosition(196, -312);
             }
            
             else
             {  
                 arr[i].x = 202;
                 arr[i].y = -315;
                 arr[i].invader.setPosition(202, -315);
             }
           }
           
           
           
         if (i==11) 
           {

             if (arr[i].enemytype == 1)//type1 is slightly misposisitioned so readjusting
             {  
                 arr[i].x = 485;
                 arr[i].y = -312;
                 arr[i].invader.setPosition(485, -312);
             }
            
             else
             {  
                 arr[i].x = 491;
                 arr[i].y = -315;
                 arr[i].invader.setPosition(491, -315);
             }
           }
           
           
           
           
        }
       }
      
      if (phase_selector[phase]==3) //cross shape
    {
    
    enemycount=9;
     arr=new Bomb[enemycount];
     for (int i=0; i<enemycount; i++)
        {
        
         if (i==0) //
           {
             if (arr[i].enemytype == 1)//type1 is slightly misposisitioned so readjusting
             { 
                 arr[i].x = 44;
                 arr[i].y = -75;
                 arr[i].invader.setPosition(44, -75);
             }
            
             else
             {  
                 arr[i].x = 50;
                 arr[i].y = -75;
                 arr[i].invader.setPosition(50, -75);
             }
           }
           
          if (i==1)
           {
              if (arr[i].enemytype == 1)
              {
                  arr[i].x = 195;
                      arr[i].y = -255;
                  arr[i].invader.setPosition(195, -255);
              }
            
              else
              {
                  arr[i].x = 206;
                      arr[i].y = -255;
                  arr[i].invader.setPosition(206, -255);
              }
           }
           
          if (i == 2)//
          {

              if (arr[i].enemytype == 1)
              { 
                  arr[i].x = 44;
                      arr[i].y = -315;
                  arr[i].invader.setPosition(44, -315);
              }

              else
              {
                  
                  arr[i].x = 50;
                  arr[i].y = -315;
                  arr[i].invader.setPosition(50, -315);
              }
          }
           
          if (i==3)
           {
              if (arr[i].enemytype == 1)
              {
                  arr[i].x = 340;
                      arr[i].y = -190;
                  arr[i].invader.setPosition(340, -190);
              }
            
              else
              { 
                  arr[i].x = 346;
                      arr[i].y = -190;
                  arr[i].invader.setPosition(346, -190);
              }
           }
           
           
         if (i==4)//
           {
             if (arr[i].enemytype == 1)
             {
                 arr[i].x = 630;
                 arr[i].y = -75;
                 arr[i].invader.setPosition(630, -75);
             }
            
             else
             { 
                 arr[i].x = 634;
                 arr[i].y = -75;
                 arr[i].invader.setPosition(634, -75);
             }
           }
           
          if (i==5)
           {
              if (arr[i].enemytype == 1)
              {
                  arr[i].x = 485;
                  arr[i].y = -120;
                  arr[i].invader.setPosition(479, -120);
              }
            
              else
              {
                  
                  arr[i].x = 485;
                  arr[i].y = -120;
                  arr[i].invader.setPosition(485, -120);
              }
           }
           
          if (i==6)//
           {
              if (arr[i].enemytype == 1)
              {
                  
                  arr[i].x = 630;
                  arr[i].y = -315;
                  arr[i].invader.setPosition(630, -315);
              }
            
              else
              {
                  arr[i].x = 634;
                  arr[i].y = -315;
                  arr[i].invader.setPosition(634, -315);
              }
           }
           
           if (i==7)
           {
               if (arr[i].enemytype == 1)
               { 
                   arr[i].x = 195;
                   arr[i].y = -120;
                   arr[i].invader.setPosition(195, -120);
               }
            
               else
               { 
                   arr[i].x = 206;
                   arr[i].y = -120;
                   arr[i].invader.setPosition(206, -120);
               }
           }
           
           if (i == 8)
           {
               if (arr[i].enemytype == 1)
               {
                   arr[i].x = 479;
                   arr[i].y = -255;
                   arr[i].invader.setPosition(479, -255);
               }

               else
               {  
                   arr[i].x = 485;
                   arr[i].y = -255;
                   arr[i].invader.setPosition(485, -255);
               }
           }
           
           
           
        }
       }
    
    
   

   }
   
   
   
   
   /////////////////////LEVEL2////////////////////////////////////////////////////
   
  else if (level==2)
   {   
 
      level2=level;
      if (phase_selector[phase]==1) //diamond shape
      {
     
       enemycount=8;
       arr=new Bomb[enemycount];
       for (int i=0; i<enemycount; i++)
        {
        
         if (i==0) 
           {
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 340;
                  arr[i].y = -75;
                  arr[i].invader.setPosition(340, -75);
              }
            
              else
              { 
                  arr[i].x = 346;
                  arr[i].y = -75;
                  arr[i].invader.setPosition(346, -75);
              }
            
           }
           
           
            if (i==1) 
           {
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 340;
                  arr[i].y = -315;
                  arr[i].invader.setPosition(340, -315);
              }
            
              else
              { 
                  arr[i].x = 346;
                  arr[i].y = -315;
                  arr[i].invader.setPosition(346, -315);
              }
            
           }
           
          if (i==2) 
           {
           //15 SMALLST X
           //688 MAX
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 688;
                  arr[i].y = -195;
                  arr[i].invader.setPosition(688, -195);
              }
            
              else
              { 
                  arr[i].x = 694;
                  arr[i].y = -195;
                  arr[i].invader.setPosition(694, -195);
              }
            
           }
           
             if (i==3) 
           {
          
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 15;
                  arr[i].y = -195;
                  arr[i].invader.setPosition(15, -195);
              }
            
              else
              { 
                  arr[i].x = 21;
                  arr[i].y = -195;
                  arr[i].invader.setPosition(21, -195);
              }
            
           }
           
           
       if (i==4) 
           {
          
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 171;
                  arr[i].y = -135;
                  arr[i].invader.setPosition(15, -135);
              }
            
              else
              { 
                  arr[i].x = 171;
                  arr[i].y = -135;
                  arr[i].invader.setPosition(21, -135);
              }
            
           }
           
            if (i==5) 
           {
          
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 171;
                  arr[i].y = -250;
                  arr[i].invader.setPosition(15, -255);
              }
            
              else
              { 
                  arr[i].x = 171;
                  arr[i].y = -255;
                  arr[i].invader.setPosition(21, -255);
              }
            
           }
          
                if (i==6) 
           {
          
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 508.25;
                  arr[i].y = -135;
                  arr[i].invader.setPosition(508.25, -135);
              }
            
              else
              { 
                  arr[i].x = 508.25;
                  arr[i].y = -135;
                  arr[i].invader.setPosition(508.25, -135);
              }
            
           }
           
            if (i==7) 
           {
          
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 508.25;
                  arr[i].y = -250;
                  arr[i].invader.setPosition(508.25, -255);
              }
            
              else
              { 
                  arr[i].x = 508.25;
                  arr[i].y = -255;
                  arr[i].invader.setPosition(508.25, -255);
              }
            
           }
        }
        
        
       }
       
       
        if (phase_selector[phase]==2) //heart shape
      {
     
       enemycount=10;
       arr=new Bomb[enemycount];
       for (int i=0; i<enemycount; i++)
        {
        
         if (i==0) 
           {
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 340;
                  arr[i].y = -25;
                  arr[i].invader.setPosition(340, -25);
              }
            
              else
              { 
                  arr[i].x = 346;
                  arr[i].y = -25;
                  arr[i].invader.setPosition(346, -25);
              }
            
           }
           
           
            if (i==1) 
           {
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 340;
                  arr[i].y = -195;
                  arr[i].invader.setPosition(340, -195);
              }
            
              else
              { 
                  arr[i].x = 346;
                  arr[i].y = -195;
                  arr[i].invader.setPosition(346, -195);
              }
            
           }
           
          if (i==2) 
           {
           //15 SMALLST X
           //688 MAX
           
           // -75
           //-315
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 688;
                  arr[i].y = -195;
                  arr[i].invader.setPosition(688, -195);
              }
            
              else
              { 
                  arr[i].x = 694;
                  arr[i].y = -195;
                  arr[i].invader.setPosition(694, -195);
              }
            
           }
           
             if (i==3) 
           {
          
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 15;
                  arr[i].y = -195;
                  arr[i].invader.setPosition(15, -195);
              }
            
              else
              { 
                  arr[i].x = 21;
                  arr[i].y = -195;
                  arr[i].invader.setPosition(21, -195);
              }
            
           }
           
           
       if (i==4) 
           {
          
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 171;
                  arr[i].y = -85;
                  arr[i].invader.setPosition(171, -85);
              }
            
              else
              { 
                  arr[i].x = 171;
                  arr[i].y = -85;
                  arr[i].invader.setPosition(177, -85);
              }
            
           }
           
            if (i==5) 
           {
          
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 93;
                  arr[i].y = -315;
                  arr[i].invader.setPosition(93, -315);
              }
            
              else
              { 
                  arr[i].x = 99;
                  arr[i].y = -315;
                  arr[i].invader.setPosition(99, -315);
              }
            
           }
          
                if (i==6) 
           {
          
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 508.25;
                  arr[i].y = -85;
                  arr[i].invader.setPosition(508.25, -85);
              }
            
              else
              { 
                  arr[i].x = 508.25;
                  arr[i].y = -85;
                  arr[i].invader.setPosition(508.25, -85);
              }
            
           }
           
            if (i==7) 
           {
          
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 430.25;   //-255
                  arr[i].y = -275;
                  arr[i].invader.setPosition(430.25, -275);
              }
            
              else
              { 
                  arr[i].x = 436.25;
                  arr[i].y = -275;
                  arr[i].invader.setPosition(436.25, -275);
              }
            
           }
           
              if (i==8) 
           {
          
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 586.25;   //-255
                  arr[i].y = -315;
                  arr[i].invader.setPosition(586.25, -315);
              }
            
              else
              { 
                  arr[i].x = 592.25;
                  arr[i].y = -315;
                  arr[i].invader.setPosition(592.25, -315);
              }
            
           }
           
           
              if (i==9) 
           {
          
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 249;   //-255
                  arr[i].y = -275;
                  arr[i].invader.setPosition(249, -275);
              }
            
              else
              { 
                  arr[i].x = 255;
                  arr[i].y = -275;
                  arr[i].invader.setPosition(255, -275);
              }
            
           }
        }
        
        
       }
       
      if (phase_selector[phase]==3) //circle shape
      {
       circle=1;
       enemycount=8;
       arr=new Bomb[enemycount];
       for (int i=0; i<enemycount; i++)
        {
  
           
            if (i==0) 
           {
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 340;
                  arr[i].y = -315;
               
              }
                     
              else
              { 
                  arr[i].x = 346;
                  arr[i].y = -315;
       
              }
            
           }
           
             if (i==1) 
           {
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 510;
                  arr[i].y = -250;
               
              }
                     
              else
              { 
                  arr[i].x = 516;
                  arr[i].y = -250;
       
              }
            
           }
           
            if (i==2) 
           {
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 170;
                  arr[i].y = -250;
               
              }
                     
              else
              { 
                  arr[i].x = 176;
                  arr[i].y = -250;
       
              }
            
           }
           
           
           if (i==3) 
           {
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 600;
                  arr[i].y = -100;
               
              }
                     
              else
              { 
                  arr[i].x = 606;
                  arr[i].y = -100;
       
              }
            
           }
           
            if (i==4) 
           {
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 80;
                  arr[i].y = -100;
               
              }
                     
              else
              { 
                  arr[i].x = 80;
                  arr[i].y = -100;
       
              }
            
           }
           
               if (i==5) 
           {
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 510;
                  arr[i].y = 50;
               
              }
                     
              else
              { 
                  arr[i].x = 516;
                  arr[i].y = 50;
       
              }
            
           }
           
            if (i==6) 
           {
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 170;
                  arr[i].y = 50;
               
              }
                     
              else
              { 
                  arr[i].x = 176;
                  arr[i].y = 50;
       
              }
            
           }
       
              if (i==7) 
           {
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 340;
                  arr[i].y = 115;
               
              }
                     
              else
              { 
                  arr[i].x = 346;
                  arr[i].y = 115;
       
              }
            
           }
           
           arr[i].y-=135;
        }
       
       }
       
     }
     





   /////////////////////LEVEL3////////////////////////////////////////////////////
   else if (level==3)
   {   
     
     level2=level;
     srand(time(NULL));
     
     int random;
    
     random=rand()%6+1;
    
     if (random==1)  // filled triangle
       { 
          enemycount=10;
     arr=new Bomb[enemycount];
     for (int i=0; i<enemycount; i++)
        {
        
         if (i==0)
           {
             if (arr[i].enemytype == 1)//type1 is slightly misposisitioned so readjusting
             {   
                 arr[i].x = 21;
                 arr[i].y = -75;
                 arr[i].invader.setPosition(21, -75);
             }
             else
             {   
                 arr[i].x = 27;
                 arr[i].y = -75;
                 arr[i].invader.setPosition(27, -75);
             }
           }
           
          if (i==1)
           {
              if (arr[i].enemytype == 1)
              {   
                  arr[i].x = 174;
                  arr[i].y = -195;
                  arr[i].invader.setPosition(174, -195);
              }
            
              else
              {  
                  arr[i].x = 180;
                  arr[i].y = -195;
                  arr[i].invader.setPosition(180, -195);
              }
           }
           
              if (i==2)
           {
                  if (arr[i].enemytype == 1)
                  {  
                      arr[i].x = 169;
                      arr[i].y = -75;
                      arr[i].invader.setPosition(169, -75);
                  }
            //
                  else
                  {   
                      arr[i].x = 175;
                      arr[i].y = -75;
                      arr[i].invader.setPosition(175, -75);
                  }
           }
           
          if (i==3)
           {
              if (arr[i].enemytype == 1)
              {
                  arr[i].x = 340;
                  arr[i].y = -75;
                  arr[i].invader.setPosition(340, -75);
              }
            
              else
              { 
                  arr[i].x = 346;
                  arr[i].y = -75;
                  arr[i].invader.setPosition(346, -75);
              }
           }
           
           
         if (i==4)
           {
             if (arr[i].enemytype == 1)
             { 
                 arr[i].x = 674;
                 arr[i].y = -75;
                 arr[i].invader.setPosition(674, -75);
             }
            
             else
             { 
                 arr[i].x = 680;
                 arr[i].y = -75;
                 arr[i].invader.setPosition(680, -75);
             }
           }
           
          if (i==5)
           {
              if (arr[i].enemytype == 1)
              {
                  arr[i].x = 498;
                  arr[i].y = -195;
                  arr[i].invader.setPosition(498, -195);
              }
            
              else
              {
                  arr[i].x = 504;
                  arr[i].y = -195;
                  arr[i].invader.setPosition(504, -195);
              }
           }
           
          if (i==6)
           {
              if (arr[i].enemytype == 1)
              {
                  arr[i].x = 495;
                  arr[i].y = -75;
                  arr[i].invader.setPosition(495, -75);
              }
            
              else// 125 x 
              {
                  arr[i].x = 501;
                  arr[i].y = -75;
                  arr[i].invader.setPosition(501, -75);
              }
           }
           
           if (i==7)
           {
               if (arr[i].enemytype == 1)
               {  
                   arr[i].x = 340;
                   arr[i].y = -315;
                   arr[i].invader.setPosition(340, -315);
               }
            
               else
               {   
                   arr[i].x = 346;
                   arr[i].y = -315;
                   arr[i].invader.setPosition(346, -315);
               }
           }
           
        
           
           
           
          if (i==8)
           {
              if (arr[i].enemytype == 1)
              {
                  arr[i].x = 282;
                  arr[i].y = -170;

              }
            
              else
              {
                  arr[i].x = 286;
                  arr[i].y = -170;

              }
           }
           
               
          if (i==9)
           {
              if (arr[i].enemytype == 1)
              {
                  arr[i].x = 390;
                  arr[i].y = -170;

              }
            
              else
              {
                  arr[i].x = 396;
                  arr[i].y = -170;
              }
           }
           
           
           
           
           
        }
     }
        
      if (random==2)  // filled rectangle
        {
            enemycount=15;
     arr=new Bomb[enemycount];
     for (int i=0; i<enemycount; i++)
        {
        
         if (i==0) 
           {

             if (arr[i].enemytype == 1)//type1 is slightly misposisitioned so readjusting
             {  
                 arr[i].x = 44;
                 arr[i].y = -72;
                 arr[i].invader.setPosition(44, -72);
             }
            
             else
             {  
                 arr[i].x = 50;
                 arr[i].y = -75;
                 arr[i].invader.setPosition(50, -75);
             }
           }
           
          if (i==1)
           {
              if (arr[i].enemytype == 1)
              {    
                  arr[i].x = 44;
                  arr[i].y = -192;
                  arr[i].invader.setPosition(44, -192);
              }
            
              else
              {  
                  arr[i].x = 50;
                  arr[i].y = -192;
                  arr[i].invader.setPosition(50, -195);
              }
           }
           
              if (i==2) 
           {
                  if (arr[i].enemytype == 1)
                  {  
                      arr[i].x = 44;
                      arr[i].y = -313;
                      arr[i].invader.setPosition(44, -313);
                  }
             
                  else
                  {  
                      arr[i].x = 50;
                      arr[i].y = -315;
                      arr[i].invader.setPosition(50, -315);
                  }
           }
           
          if (i==3)
           {
              if (arr[i].enemytype == 1)
              {  
                  arr[i].x = 340;
                  arr[i].y = -72;
                  arr[i].invader.setPosition(340, -72);
              }
            
              else
              {  
                  arr[i].x = 346;
                  arr[i].y = -75;
                  arr[i].invader.setPosition(346, -75);
              }
           }
           
           
         if (i==4) 
           {
             if (arr[i].enemytype == 1)
             { 
                 arr[i].x = 630;
                 arr[i].y = -72;
                 arr[i].invader.setPosition(630, -72);
             }
            
             else
             { 
                 arr[i].x = 634;
                 arr[i].y = -75;
                 arr[i].invader.setPosition(634, -75);
             }
           }
           
          if (i==5)
           {
              if (arr[i].enemytype == 1)
              {  
                  arr[i].x = 630;
                  arr[i].y = -192;
                  arr[i].invader.setPosition(630, -192);
              }
            
              else
              {  
                  arr[i].x = 634;
                  arr[i].y = -195;
                  arr[i].invader.setPosition(634, -195);
              }
           }
           
          if (i==6) 
           {
              if (arr[i].enemytype == 1)
              {  
                  arr[i].x = 630;
                  arr[i].y = -312;
                  arr[i].invader.setPosition(630, -312);
              }
            
              else
              { 
                  arr[i].x = 634;
                  arr[i].y = -315;
                  arr[i].invader.setPosition(634, -315);
              }
           }
           
           if (i==7)
           {
               if (arr[i].enemytype == 1)
               {  
                   arr[i].x = 340;
                   arr[i].y = -312;
                   arr[i].invader.setPosition(340, -312);
               }
            
               else
               { 
                   arr[i].x = 346;
                       arr[i].y = -315;
                   arr[i].invader.setPosition(346, -315);
               }
           }
           
           
           
          if (i==8) 
           {

             if (arr[i].enemytype == 1)//type1 is slightly misposisitioned so readjusting
             {  
                 arr[i].x = 196;
                 arr[i].y = -72;
                 arr[i].invader.setPosition(196, -72);
             }
            
             else
             {  
                 arr[i].x = 202;
                 arr[i].y = -75;
                 arr[i].invader.setPosition(202, -75);
             }
           }
           
           
           
         if (i==9) 
           {

             if (arr[i].enemytype == 1)//type1 is slightly misposisitioned so readjusting
             {  
                 arr[i].x = 485;
                 arr[i].y = -72;
                 arr[i].invader.setPosition(485, -72);
             }
            
             else
             {  
                 arr[i].x = 491;
                 arr[i].y = -75;
                 arr[i].invader.setPosition(491, -75);
             }
           }
           
           
           
          if (i==10) 
           {

             if (arr[i].enemytype == 1)//type1 is slightly misposisitioned so readjusting
             {  
                 arr[i].x = 196;
                 arr[i].y = -312;
                 arr[i].invader.setPosition(196, -312);
             }
            
             else
             {  
                 arr[i].x = 202;
                 arr[i].y = -315;
                 arr[i].invader.setPosition(202, -315);
             }
           }
           
           
           
         if (i==11) 
           {

             if (arr[i].enemytype == 1)//type1 is slightly misposisitioned so readjusting
             {  
                 arr[i].x = 485;
                 arr[i].y = -312;

             }
            
             else
             {  
                 arr[i].x = 491;
                 arr[i].y = -315;
                 arr[i].invader.setPosition(491, -315);
             }
           }
           
           if (i==12) 
           {

             if (arr[i].enemytype == 1)//type1 is slightly misposisitioned so readjusting
             {  
                 arr[i].x = 196;
                 arr[i].y = -192;
              
             }
            
             else
             {  
                 arr[i].x = 202;
                 arr[i].y = -192;
               
             }
           }
           
             if (i==13) 
           {

             if (arr[i].enemytype == 1)//type1 is slightly misposisitioned so readjusting
             {  
                 arr[i].x = 340;
                 arr[i].y = -192;
              
             }
            
             else
             {  
                 arr[i].x = 346;
                 arr[i].y = -192;
               
             }
           }
           
           
             if (i==14) 
           {

             if (arr[i].enemytype == 1)//type1 is slightly misposisitioned so readjusting
             {  
                 arr[i].x = 485;
                 arr[i].y = -192;
              
             }
            
             else
             {  
                 arr[i].x = 491;
                 arr[i].y = -192;
               
             }
           }
           
           
           
           
           
           
           
           
           
           
        }
       }
       
       
      
      if (random==3) //cross shape
    {
    
    enemycount=9;
     arr=new Bomb[enemycount];
     for (int i=0; i<enemycount; i++)
        {
        
         if (i==0) //
           {
             if (arr[i].enemytype == 1)//type1 is slightly misposisitioned so readjusting
             { 
                 arr[i].x = 44;
                 arr[i].y = -75;
                 arr[i].invader.setPosition(44, -75);
             }
            
             else
             {  
                 arr[i].x = 50;
                 arr[i].y = -75;
                 arr[i].invader.setPosition(50, -75);
             }
           }
           
          if (i==1)
           {
              if (arr[i].enemytype == 1)
              {
                  arr[i].x = 195;
                      arr[i].y = -255;
                  arr[i].invader.setPosition(195, -255);
              }
            
              else
              {
                  arr[i].x = 206;
                      arr[i].y = -255;
                  arr[i].invader.setPosition(206, -255);
              }
           }
           
          if (i == 2)//
          {

              if (arr[i].enemytype == 1)
              { 
                  arr[i].x = 44;
                      arr[i].y = -315;
                  arr[i].invader.setPosition(44, -315);
              }

              else
              {
                  
                  arr[i].x = 50;
                  arr[i].y = -315;
                  arr[i].invader.setPosition(50, -315);
              }
          }
           
          if (i==3)
           {
              if (arr[i].enemytype == 1)
              {
                  arr[i].x = 340;
                      arr[i].y = -190;
                  arr[i].invader.setPosition(340, -190);
              }
            
              else
              { 
                  arr[i].x = 346;
                      arr[i].y = -190;
                  arr[i].invader.setPosition(346, -190);
              }
           }
           
           
         if (i==4)//
           {
             if (arr[i].enemytype == 1)
             {
                 arr[i].x = 630;
                 arr[i].y = -75;
                 arr[i].invader.setPosition(630, -75);
             }
            
             else
             { 
                 arr[i].x = 634;
                 arr[i].y = -75;
                 arr[i].invader.setPosition(634, -75);
             }
           }
           
          if (i==5)
           {
              if (arr[i].enemytype == 1)
              {
                  arr[i].x = 485;
                  arr[i].y = -120;
                  arr[i].invader.setPosition(479, -120);
              }
            
              else
              {
                  
                  arr[i].x = 485;
                  arr[i].y = -120;
                  arr[i].invader.setPosition(485, -120);
              }
           }
           
          if (i==6)//
           {
              if (arr[i].enemytype == 1)
              {
                  
                  arr[i].x = 630;
                  arr[i].y = -315;
                  arr[i].invader.setPosition(630, -315);
              }
            
              else
              {
                  arr[i].x = 634;
                  arr[i].y = -315;
                  arr[i].invader.setPosition(634, -315);
              }
           }
           
           if (i==7)
           {
               if (arr[i].enemytype == 1)
               { 
                   arr[i].x = 195;
                   arr[i].y = -120;
                   arr[i].invader.setPosition(195, -120);
               }
            
               else
               { 
                   arr[i].x = 206;
                   arr[i].y = -120;
                   arr[i].invader.setPosition(206, -120);
               }
           }
           
           if (i == 8)
           {
               if (arr[i].enemytype == 1)
               {
                   arr[i].x = 479;
                   arr[i].y = -255;
                   arr[i].invader.setPosition(479, -255);
               }

               else
               {  
                   arr[i].x = 485;
                   arr[i].y = -255;
                   arr[i].invader.setPosition(485, -255);
               }
           }
           
           
        
       }
       
      }  
      
      
       
         if (random==4) //filed diamond shape
      {
     
       enemycount=10;
       arr=new Bomb[enemycount];
       for (int i=0; i<enemycount; i++)
        {
        
         if (i==0) 
           {
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 340;
                  arr[i].y = -75;
                  arr[i].invader.setPosition(340, -75);
              }
            
              else
              { 
                  arr[i].x = 346;
                  arr[i].y = -75;
                  arr[i].invader.setPosition(346, -75);
              }
            
           }
           
           
            if (i==1) 
           {
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 340;
                  arr[i].y = -315;
                  arr[i].invader.setPosition(340, -315);
              }
            
              else
              { 
                  arr[i].x = 346;
                  arr[i].y = -315;
                  arr[i].invader.setPosition(346, -315);
              }
            
           }
           
          if (i==2) 
           {
           //15 SMALLST X
           //688 MAX
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 688;
                  arr[i].y = -195;
                  arr[i].invader.setPosition(688, -195);
              }
            
              else
              { 
                  arr[i].x = 694;
                  arr[i].y = -195;
                  arr[i].invader.setPosition(694, -195);
              }
            
           }
           
             if (i==3) 
           {
          
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 15;
                  arr[i].y = -195;
                  arr[i].invader.setPosition(15, -195);
              }
            
              else
              { 
                  arr[i].x = 21;
                  arr[i].y = -195;
                  arr[i].invader.setPosition(21, -195);
              }
            
           }
           
           
       if (i==4) 
           {
          
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 171;
                  arr[i].y = -135;
                  arr[i].invader.setPosition(15, -135);
              }
            
              else
              { 
                  arr[i].x = 171;
                  arr[i].y = -135;
                  arr[i].invader.setPosition(21, -135);
              }
            
           }
           
            if (i==5) 
           {
          
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 171;
                  arr[i].y = -250;
                  arr[i].invader.setPosition(15, -255);
              }
            
              else
              { 
                  arr[i].x = 171;
                  arr[i].y = -255;
                  arr[i].invader.setPosition(21, -255);
              }
            
           }
          
                if (i==6) 
           {
          
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 508.25;
                  arr[i].y = -135;
                  arr[i].invader.setPosition(508.25, -135);
              }
            
              else
              { 
                  arr[i].x = 508.25;
                  arr[i].y = -135;
                  arr[i].invader.setPosition(508.25, -135);
              }
            
           }
           
            if (i==7) 
           {
          
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 508.25;
                  arr[i].y = -250;
                  arr[i].invader.setPosition(508.25, -255);
              }
            
              else
              { 
                  arr[i].x = 508.25;
                  arr[i].y = -255;
                  arr[i].invader.setPosition(508.25, -255);
              }
            
           }
           
             if (i==8) 
           {
          
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 278.625;   
                  arr[i].y = -195;

              }
            
              else
              { 
                  arr[i].x = 278.625+6;
                  arr[i].y = -195;

              }
            
           }
           
           
              if (i==9) 
           {
          
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 403.25;   
                  arr[i].y = -195;

              }
            
              else
              { 
                  arr[i].x = 403.25+6;
                  arr[i].y = -195;

              }
            
           }
        }
        
        
       }
       
       
        if (random==5) //filled heart shape
      {
     
       enemycount=13;
       arr=new Bomb[enemycount];
       for (int i=0; i<enemycount; i++)
        {
        
         if (i==0) 
           {
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 340;
                  arr[i].y = -25;
                  arr[i].invader.setPosition(340, -25);
              }
            
              else
              { 
                  arr[i].x = 346;
                  arr[i].y = -25;
                  arr[i].invader.setPosition(346, -25);
              }
            
           }
           
           
            if (i==1) 
           {
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 340;
                  arr[i].y = -195;
                  arr[i].invader.setPosition(340, -195);
              }
            
              else
              { 
                  arr[i].x = 346;
                  arr[i].y = -195;
                  arr[i].invader.setPosition(346, -195);
              }
            
           }
           
          if (i==2) 
           {
           //15 SMALLST X
           //688 MAX
           
           // -75
           //-315
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 688;
                  arr[i].y = -195;
                  arr[i].invader.setPosition(688, -195);
              }
            
              else
              { 
                  arr[i].x = 694;
                  arr[i].y = -195;
                  arr[i].invader.setPosition(694, -195);
              }
            
           }
           
             if (i==3) 
           {
          
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 15;
                  arr[i].y = -195;
                  arr[i].invader.setPosition(15, -195);
              }
            
              else
              { 
                  arr[i].x = 21;
                  arr[i].y = -195;
                  arr[i].invader.setPosition(21, -195);
              }
            
           }
           
           
       if (i==4) 
           {
          
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 171;
                  arr[i].y = -85;
                  arr[i].invader.setPosition(171, -85);
              }
            
              else
              { 
                  arr[i].x = 176;
                  arr[i].y = -85;
                  arr[i].invader.setPosition(177, -85);
              }
            
           }
           
            if (i==5) 
           {
          
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 93;
                  arr[i].y = -315;
                  arr[i].invader.setPosition(93, -315);
              }
            
              else
              { 
                  arr[i].x = 99;
                  arr[i].y = -315;
                  arr[i].invader.setPosition(99, -315);
              }
            
           }
          
                if (i==6) 
           {
          
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 508.25;
                  arr[i].y = -85;
                  arr[i].invader.setPosition(508.25, -85);
              }
            
              else
              { 
                  arr[i].x = 514.25;
                  arr[i].y = -85;
                  arr[i].invader.setPosition(508.25, -85);
              }
            
           }
           
            if (i==7) 
           {
          
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 430.25;   //-255
                  arr[i].y = -275;
                  arr[i].invader.setPosition(430.25, -275);
              }
            
              else
              { 
                  arr[i].x = 436.25;
                  arr[i].y = -275;
                  arr[i].invader.setPosition(436.25, -275);
              }
            
           }
           
              if (i==8) 
           {
          
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 586.25;   //-255
                  arr[i].y = -315;
                  arr[i].invader.setPosition(586.25, -315);
              }
            
              else
              { 
                  arr[i].x = 592.25;
                  arr[i].y = -315;
                  arr[i].invader.setPosition(592.25, -315);
              }
            
           }
           
           
              if (i==9) 
           {
          
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 249;   //-255
                  arr[i].y = -275;
                  arr[i].invader.setPosition(249, -275);
              }
            
              else
              { 
                  arr[i].x = 255;
                  arr[i].y = -275;
                  arr[i].invader.setPosition(255, -275);
              }
            
           }
           
           
          if (i==10) 
           {
          
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 171;   //-255
                  arr[i].y = -195;

              }
            
              else
              { 
                  arr[i].x = 177;
                  arr[i].y = -195;

              }
            
           }
           
        if (i==11) 
           {
          
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 508.25;   //-255
                  arr[i].y = -195;

              }
            
              else
              { 
                  arr[i].x = 514.25;
                  arr[i].y = -195;

              }
            
           }
           
          if (i==12) 
           {
          
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 340;   //-255
                  arr[i].y = -110;

              }
            
              else
              { 
                  arr[i].x = 346;
                  arr[i].y = -110;

              }
            
           }  
           
           
        }
        
        
       }
       
       
       
      if (random==6) //filled circle shape
      {
        circle=1;
       enemycount=11;
       arr=new Bomb[enemycount];
       for (int i=0; i<enemycount; i++)
        {
  
           
            if (i==0) 
           {
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 340;
                  arr[i].y = -315;
               
              }
                     
              else
              { 
                  arr[i].x = 346;
                  arr[i].y = -315;
       
              }
            
           }
           
             if (i==1) 
           {
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 510;
                  arr[i].y = -250;
               
              }
                     
              else
              { 
                  arr[i].x = 516;
                  arr[i].y = -250;
       
              }
            
           }
           
            if (i==2) 
           {
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 170;
                  arr[i].y = -250;
               
              }
                     
              else
              { 
                  arr[i].x = 176;
                  arr[i].y = -250;
       
              }
            
           }
           
           
           if (i==3) 
           {
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 600;
                  arr[i].y = -100;
               
              }
                     
              else
              { 
                  arr[i].x = 606;
                  arr[i].y = -100;
       
              }
            
           }
           
            if (i==4) 
           {
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 80;
                  arr[i].y = -100;
               
              }
                     
              else
              { 
                  arr[i].x = 80;
                  arr[i].y = -100;
       
              }
            
           }
           
               if (i==5) 
           {
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 510;
                  arr[i].y = 50;
               
              }
                     
              else
              { 
                  arr[i].x = 516;
                  arr[i].y = 50;
       
              }
            
           }
           
            if (i==6) 
           {
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 170;
                  arr[i].y = 50;
               
              }
                     
              else
              { 
                  arr[i].x = 176;
                  arr[i].y = 50;
       
              }
            
           }
       
              if (i==7) 
           {
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 340;
                  arr[i].y = 115;
               
              }
                     
              else
              { 
                  arr[i].x = 346;
                  arr[i].y = 115;
       
              }
            
           }
           
                if (i==8) 
           {
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 170;
                  arr[i].y = -100;
               
              }
                     
              else
              { 
                  arr[i].x = 176;
                  arr[i].y = -100;
       
              }
            
           }
           
           
           if (i==9) 
           {
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 340;
                  arr[i].y = -100;
               
              }
                     
              else
              { 
                  arr[i].x = 346;
                  arr[i].y = -100;
       
              }
            
           }
           
           
           if (i==10) 
           {
           if (arr[i].enemytype == 1)
              {
                  arr[i].x = 510;
                  arr[i].y = -100;
               
              }
                     
              else
              { 
                  arr[i].x = 516;
                  arr[i].y = -100;
       
              }
            
           }
           arr[i].y-=135;
           
        }
       
       }
       
       
       
       
       
    }  
       
 
      
     

       for (int i=0; i<enemycount; i++)  // readjusting
          {
          if(arr[i].enemytype!=2)
            arr[i].y+=15;
          
          
          
          }
     
     
     
     
     
   }
};
