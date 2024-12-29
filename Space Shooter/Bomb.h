#include <SFML/Graphics.hpp>
#include <string.h>
using namespace sf;
#include <iostream>
using namespace std;
class Bomb
{public:
	Texture texts;
	Sprite sprite;
    float speed;
    float a=100,b=100;
    Bomb()
	{ texts.loadFromFile("img/PNG/Lasers/laserRed08.png");
		sprite.setTexture(texts);
        sprite.setScale(0.75, 0.75);  
      
	}
    void tecture()
    {    sprite.setColor(Color::Red);
         sprite.setScale(1, 1) ;
    }
    void setpos(int x,int y)
    {
       a=x; b=y;
       sprite.setPosition(a,b); 
    }
    void move(int z=1)
    {
        if(z==1)
		speed=0.5;
		if(z==2)
		speed =1;
		if(z==3)
		speed=1.5;
        if(z==1)
        {sprite.move(0,speed);
         b+=speed;
        }
        else
        {sprite.move(0,speed);
        b+=speed;}
    }
    bool check_boundary()
    {
        if(b>=800)
        { return 0;}
    return 1;
    }
     int right()
	{ return (sprite.getPosition().x + 25);}
	int bottom()
	{ return (sprite.getPosition().y + 25);}
	int top()
	{ return (sprite.getPosition().y);}
	int left()
	{ return (sprite.getPosition().x);}
    Bomb operator = (Bomb abc)
    {
        this->a = abc.a;
        this->b = abc.b;
        this->sprite.setPosition(a,b);
        return *this;
    }
    void move_dragon(int z=1 ,int  x =0)
    { 
        if(z==1)
		speed=0.5;
		if(z==2)
		speed =1;
		if(z==3)
		speed=1.5;
        sprite.move(x*speed,speed);
        a+=x*speed;
        b+=speed;
    }
    ~Bomb()
    {}
};