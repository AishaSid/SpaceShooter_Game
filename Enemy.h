#include <SFML/Graphics.hpp>
#include <string.h>
#include "Bomb.h"
using namespace sf;
class Enemy
{
public:
	Texture tex;
	Sprite sprite;
	Bomb *light;
	Bomb *light_left , *light_right;
	int lsize=0,left_size,right_size;
	float x, y;
	float speed=0.5;
	Bomb *b1;

	string type_of_enemy;
	Enemy()
	{ 
		light=nullptr;
		light_left=nullptr;
		light_right=nullptr;
		b1=nullptr;
	}
 //virtual void pureVirtualMethod() = 0;
    	void speeds(int level)
	{ 
		if(level==1)
		speed  =0.5;
		if(level==2)
		speed =1;
		if(level==3)
		speed=1.5;
	}
    virtual void move() {} 
	virtual void display(int){}	
	virtual void fire()
	{}
	virtual void fire(int) 
	{}
	virtual int right()
	{ return (sprite.getPosition().x + 220);}
	virtual int bottom()
	{ return (sprite.getPosition().y + 220);}
	virtual int top()
	{ return (sprite.getPosition().y);}
	virtual  int left()
	{ return (sprite.getPosition().x);}
	virtual ~Enemy() 
	{}
};

class Monster :public Enemy
{
	public:
	bool right_left;
	Monster(string imgg)
	{
		tex.loadFromFile(imgg);
		sprite.setTexture(tex);
		sprite.setScale(0.65, 0.65);
		sprite.setPosition(60,-60);
		x=60,y=-60;
		light=nullptr;
	}
	void fire(int) override{}
	void display(int) override{}
	int right() override
	{ return (sprite.getPosition().x + 370);}
	int bottom() override
	{ return (sprite.getPosition().y + 370);}
	int top() override
	{ return (sprite.getPosition().y);}
	int left() override
	{ return (sprite.getPosition().x);}
	void move() override
	{ 
		if(y<=40)
		{sprite.move(0,2);
		  y+=2;
		}
		else
		{     if(right_left==1)
		    {if(this->right()< 1200)
			{sprite.move(speed,0);
			x+=speed;}
			else right_left=0;}
			else
			{  if(this->left()>0)
				{sprite.move(-speed,0);
			x-=speed; }
			else right_left=1;
			}
		}
	}
	void fire() override
{   

		{
		Bomb temp[lsize];
       for(int i=0; i<lsize; i++)
       {   temp[i] = light[i];
       }
	   if(lsize>1)
       delete[] light;(sprite.getPosition().y + 290) ;
       light = new Bomb[lsize+1];
       for(int i=0; i<lsize; i++)
       {   light[i] = temp[i];
       }
       light[lsize++].setpos((sprite.getPosition().x + 245),(sprite.getPosition().y + 360));
	   light[lsize-1].tecture();
	   }
}
~Monster () override
{
	if(light!=nullptr) { if(lsize>1) delete []light;else free(light);}
}
};

class Dragon :public Enemy
{
	public:
	bool right_left;
	Dragon(string imgg)
	{
		tex.loadFromFile(imgg);
		sprite.setTexture(tex);
		sprite.setScale(1.5, 1.5);
		sprite.setPosition(540,10);
		x=540,y=10;
		light=nullptr;
		light_left=nullptr, light_right=nullptr;
		lsize=0; left_size=0; right_size=0;
	}
	int right() override
	{ return (sprite.getPosition().x + 320);}
	int bottom() override
	{ return (sprite.getPosition().y + 290);}
	int top() override
	{ return (sprite.getPosition().y);}
	int left() override
	{ return (sprite.getPosition().x);}
	void move() override
	{ 
	}
	void fire( int  check=0 ) override
{   
	if(check == 0)     //mid
      { if(lsize<30)
		{
		Bomb temp[lsize];
       for(int i=0; i<lsize; i++)
       {   temp[i] = light[i];
       }
	   if(lsize>1)
       delete[] light;
       light = new Bomb[lsize+1];
       for(int i=0; i<lsize; i++)
       {   light[i] = temp[i];
       }
       light[lsize++].setpos((sprite.getPosition().x + 180),(sprite.getPosition().y + 290));
	   light[lsize-1].tecture();
	   }
	   }

	  else if(check == -1)   //left
      { if(left_size<30)
		{
		Bomb temp[left_size];
       for(int i=0; i<left_size; i++)
       {   temp[i] = light_left[i];
       }
	   if(left_size>1)
       delete[] light_left;
       light_left = new Bomb[left_size+1];
       for(int i=0; i<left_size; i++)
       {   light_left[i] = temp[i];
       }
       light_left[left_size++].setpos((sprite.getPosition().x + 180),(sprite.getPosition().y + 290));
	   light_left[left_size-1].tecture();
	   }
	   }

	  else if(check == 1)   //right
      { if(right_size<30)
		{
		Bomb temp[right_size];
       for(int i=0; i<right_size; i++)
       {   temp[i] = light_right[i];
       }
	   if(right_size>1)
       delete[] light_right;
       light_right = new Bomb[right_size+1];
       for(int i=0; i<right_size; i++)
       {   light_right[i] = temp[i];
       }
       light_right[right_size++].setpos((sprite.getPosition().x + 180),(sprite.getPosition().y + 290));
	   light_right[right_size-1].tecture();
	   }
	   }
}
~Dragon() override
{ 
	if(light!=nullptr) { if(lsize>1) delete []light;else free(light);}
	if(light_left!=nullptr) { if(left_size>1) delete []light_left;else free(light_left);}
	if(light_right!=nullptr) { if(right_size>1) delete []light_right;else free(light_right);}
}
};
