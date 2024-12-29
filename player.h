#include <SFML/Graphics.hpp>
#include <string.h>
using namespace sf;
#include"Bullets.h"
#include <iostream>
using namespace std;
class Player
{
public:
	Texture tex;
	Sprite sprite;
	Bullets *b1=nullptr;
	int b1_size;
	float speed = 1; 
	float x, y;
	int a,b;
	Bullets *b2=nullptr;
	int b2_size;
	Bullets *b3=nullptr;
	int b3_size;
	Bullets *b4=nullptr;
	int b4_size;
	Bullets *b5=nullptr;
	int b5_size;
	Bullets *b6=nullptr;
	int b6_size;
	Bullets *b7=nullptr;
	int b7_size;

	Player(std::string png_path)
	{
		tex.loadFromFile(png_path);
		sprite.setTexture(tex);
		x = 520;
		y = 680;
		a=520,b=680;
		sprite.setPosition(x,y);
		sprite.setScale(0.6,0.6);
		//sprite.setScale(0.3,0.3);
		b1=nullptr;
		b1_size=0;
		b2=nullptr;
		b2_size=0;
		b3=nullptr;
		b3_size=0;
		b4=nullptr;
		b4_size=0;
		b5=nullptr;
		b6_size=0;
		b7=nullptr;
		b5_size=0;
		b6=nullptr;
		b7_size=0;
	}
///////////////////////////////////////////
void fir()
{
   Bullets *temp = new Bullets[++b1_size];
   for(int i=0;i<b1_size-1 ; i++)
   { temp[i] = b1[i];}
    Bullets *temp2 = b1;
   temp[b1_size-1].sendvalues(sprite.getPosition().x+28,sprite.getPosition().y -36);
   temp[b1_size-1].centre();
   b1 = temp;
   if(b1_size > 1)
   delete [] temp2;
   
}
void powerup_fire( int ghi = 7 )
{
	Bullets *temp, *temp2;
    if(ghi >=1 )
	{temp = new Bullets[++b2_size];
   for(int i=0;i<b2_size-1 ; i++)
   { temp[i] = b2[i];}
    temp2 = b2;
   temp[b2_size-1].sendvalues(sprite.getPosition().x-10,sprite.getPosition().y);
   temp[b2_size-1].centre();
   b2 = temp;
   if(b2_size > 1)
   delete [] temp2;}
  if(ghi >=2 )
  { temp = new Bullets[++b3_size];
   for(int i=0;i<b3_size-1 ; i++)
   { temp[i] = b3[i];}
    temp2 = b3;
   temp[b3_size-1].sendvalues(sprite.getPosition().x+28+28+10,sprite.getPosition().y);
   temp[b3_size-1].centre();
   b3 = temp;
   if(b3_size > 1)
   delete [] temp2;}
   if (ghi>=3)
   {temp = new Bullets[++b4_size];
   for(int i=0;i<b4_size-1 ; i++)
   { temp[i] = b4[i];}
    temp2 = b4;
   temp[b4_size-1].sendvalues(sprite.getPosition().x+10,sprite.getPosition().y-20);
   temp[b4_size-1].centre();
   b4 = temp;
   if(b4_size > 1)
   delete [] temp2;}
  if(ghi >=4)
  { temp = new Bullets[++b5_size];
   for(int i=0;i<b5_size-1 ; i++)
   { temp[i] = b5[i];}
    temp2 = b5;
   temp[b5_size-1].sendvalues(sprite.getPosition().x+28+28,sprite.getPosition().y-20);
   temp[b5_size-1].centre();
   b5 = temp;
   if(b5_size > 1)
   delete [] temp2;}
  if(ghi>=5)
  { temp = new Bullets[++b6_size];
   for(int i=0;i<b6_size-1 ; i++)
   { temp[i] = b6[i];}
    temp2 = b6;
   temp[b6_size-1].sendvalues(sprite.getPosition().x-20,sprite.getPosition().y+20);
   temp[b6_size-1].centre();
   b6 = temp;
   if(b6_size > 1)
   delete [] temp2;}
  if(ghi>=6)
  { temp = new Bullets[++b7_size];
   for(int i=0;i<b7_size-1 ; i++)
   { temp[i] = b7[i];}
    temp2 = b7;
   temp[b7_size-1].sendvalues(sprite.getPosition().x+28+28+20,sprite.getPosition().y+20);
   temp[b7_size-1].centre();
   b7 = temp;
   if(b7_size > 1)
   delete [] temp2;}
}
///////////////////////////////////////////////
void delete_chain(int j=0)
{  int k=0;
   if(b1_size >=1)
   {Bullets *temp = new Bullets[--b1_size];
   for(int i=0;i<b1_size+1 ; i++)
   {   if(i!= j) 
	temp[k++] = b1[i];
   }
	 Bullets *temp2 = b1;
	b1 = temp;
	if(b1_size+1 > 1)
   {delete [] temp2;
   }
   }
}
///////////////////////////////////////////////
	void move(std::string s)
	{
		float delta_x = 0, delta_y = 0;
		//if((y>3.815))
		{if (s == "u")
			{delta_y = -1;
			b+=delta_y;
			}
		}
		if((y<756))
		{if (s == "d")
		{delta_y = 1; 
		 b+=delta_y;}}
		if (s == "l") 
			{delta_x = -1;
			 a+=delta_x;}
		else if (s == "r") 
			{delta_x = 1;
			 a+=delta_x;}
		delta_x *= speed;
		delta_y *= speed;
		sprite.move(delta_x, delta_y);
		y+=delta_y; 
		x+=delta_x;
		if(y<=0)
		{ y=820;
			sprite.setPosition(x,820);}
       if(y>=820)
		{ y=0;
			sprite.setPosition(x,y);}
		if(x<0)
		{ x=1200;
			sprite.setPosition(x,y);}
       if(x>1200)
		{ x=0;
			sprite.setPosition(x,y);}
	}

	void speeds(int level)
	{ 
		if(level==1)
		speed  =1;
		if(level==2)
		speed =1.5;
		if(level==3)
		speed=1.8;
	}

	void destroy_ship(RenderWindow *ptr)
	{
		Clock c;
		c.restart();
		Sprite s;
		Texture t;
		int ti;
		t.loadFromFile("img/PNG/Damage/playerShip1_damage3.png");
		s.setTexture(t);
		s.setPosition(x,y);
		s.setScale(1,1);
	     while(1)
		{ ti  = c.getElapsedTime().asSeconds();
			if(ti<1)
		    t.loadFromFile("img/PNG/Damage/playerShip1_damage2.png");
			else if(ti<2)
		    t.loadFromFile("img/PNG/Damage/playerShip1_damage1.png");
			if (ti>2)
			break;
			(*ptr).draw(s);
		}
	}
	int right()
	{ return (sprite.getPosition().x + 50);}
	int bottom()
	{ return (sprite.getPosition().y + 30);}
	int top()
	{ return (sprite.getPosition().y);}
	int left()
	{ return (sprite.getPosition().x);}

~Player()
{
	if (b1!= nullptr && b1_size>1)
	{delete [] b1; b1_size=0; b1 = nullptr;}
	if (b1_size==1)
	free(b1); b1=nullptr;
}

};
