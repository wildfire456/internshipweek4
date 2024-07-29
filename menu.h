
#include "game.h"
class Menu
{
public:
 Sprite menu, helpmenu, highmenu;
 Music maintheme;
 Sound selection;
 SoundBuffer buffer, buffer1;
 Texture menu_bg, hm, himenu;
  Font opensans;
  Text  scoredisp, livesdisp, leveldisp, phasedisp, high1disp, high2disp, high3disp, name1disp, name2disp, name3disp;
 bool helpdisp, highdisp;
  Game g; 
  int highscore1, highscore2, highscore3, tempscore1;
    string highname, midname, lowname, tempname;
    string displayscore;
 
//add menu attributes here
Menu()
{
 opensans.loadFromFile("open-sans/OpenSans-Regular.ttf");
 buffer.loadFromFile("songs/achievement.wav");
  buffer1.loadFromFile("songs/interface.wav");
  maintheme.openFromFile("songs/maintheme.wav");
  maintheme.setLoop(true);
 selection.setBuffer(buffer1);
 high1disp.setFont(opensans);
 high2disp.setFont(opensans);
 high3disp.setFont(opensans);
 name1disp.setFont(opensans);
 name2disp.setFont(opensans);
 name3disp.setFont(opensans);
 
 
  helpdisp=0;
  highdisp=0;
 menu_bg.loadFromFile("img/menu.jpg");
 hm.loadFromFile("img/helpmenu.png");
 himenu.loadFromFile("img/highscoremenu.png");
 
 menu.setTexture(menu_bg);
 helpmenu.setTexture(hm);
 highmenu.setTexture(himenu);
 
 menu.setScale(0.141, 0.21);
  helpmenu.setScale(0.195, 0.21);
    highmenu.setScale(0.195, 0.275);
    highmenu.setPosition(0, -147);
 
 
//constructors body
}

void display_menu()

{


//display highscores
maintheme.play();
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
    





   high1disp.setString(high1);
      high2disp.setString(high2);
      high3disp.setString(high3);
      name1disp.setString(highname);
      name2disp.setString(midname);
      name3disp.setString(lowname);
 
   RenderWindow menuwindow(VideoMode(780, 740), "menu");
    menuwindow.setFramerateLimit(30);
   while (menuwindow.isOpen())  
   { 
   
     Event ev;
        while (menuwindow.pollEvent(ev))
        {  
            if (ev.type == Event::Closed) // If cross/close is clicked/pressed
                menuwindow.close(); //close the game                        	    
        }
      
      menuwindow.clear();
      if (helpdisp==0 && highdisp==0)
        menuwindow.draw(menu);
        
        
     
           
           
  if (Keyboard::isKeyPressed(Keyboard::Num1) ) //If left key is pressed

    {  
    maintheme.stop();
        menuwindow.close();
     selection.play();
      g.start_game();
  
 
    }
    
    
    
     if (Keyboard::isKeyPressed(Keyboard::Num3) && highdisp==0 ) 

    { 
        selection.play();
     helpdisp=1;
 
    }
    
    
    if (helpdisp==1)
     {
      menuwindow.draw(helpmenu);
      
           if (Keyboard::isKeyPressed(Keyboard::Escape) ) 

             { 
            selection.play();
              helpdisp=0;
 
              }
      
      }
   
   
     if (Keyboard::isKeyPressed(Keyboard::Num2) && helpdisp==0 ) 

    { 
        selection.play();
     highdisp=1;
 
    }
    
    
    if (highdisp==1)
     {
      menuwindow.draw(highmenu);
      
           if (Keyboard::isKeyPressed(Keyboard::Escape) ) 

             { 
        selection.play();
              highdisp=0;
 
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
      menuwindow.draw(highmenu);
      
        high1disp.setPosition(550,350);
        menuwindow.draw(high1disp);
     
        high2disp.setPosition(550,464);
        menuwindow.draw(high2disp);
     
        high3disp.setPosition(550,570);
        menuwindow.draw(high3disp);
     
       name1disp.setPosition(180, 350);
       menuwindow.draw(name1disp);
     
       name2disp.setPosition(180, 464);
      menuwindow.draw(name2disp);
     
       name3disp.setPosition(180, 570);
       menuwindow.draw(name3disp);
     
      
           if (Keyboard::isKeyPressed(Keyboard::Escape) ) 

             { 
           selection.play();
              highdisp=0;
 
              }
      
      }
 
   
   
   
   
   if (Keyboard::isKeyPressed(Keyboard::Num4) && helpdisp==0 && highdisp==0 ) 

    { 
        selection.play();
      menuwindow.close();
 
    }
    
    
       menuwindow.display();
        
  }

    
  


}


};
