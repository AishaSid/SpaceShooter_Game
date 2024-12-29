#include <SFML/Graphics.hpp>
#include <string.h>
using namespace sf;
#include <iostream>
using namespace std;

class Bullets
{
public:
	Texture tex;
	Sprite sprite; int speed;
    string type;
    int a=10,b=10;
    Bullets()
    {  speed=1;
       {tex.loadFromFile("img/PNG/Lasers/laserGreen01.png");}
        sprite.setTexture(tex);
        sprite.setScale(0.7, 0.7);
    }
    Bullets( int x)
	{   
        tex.loadFromFile("img/PNG/Lasers/laserBlue01.png");
		sprite.setTexture(tex);
        sprite.setScale(0.7, 0.7);  
	}
    void sendvalues(float x,float y)
    { a=x; b=y; 
    }
    bool check_boundary()
    {
     if (sprite.getPosition().y< -10)
         { return 1;}
    return 0;
    }
    Bullets operator=( Bullets abc)
    {   this->tex = abc.tex; // sprite.setColor(Color::Black);
        this->a = abc.sprite.getPosition().x;
        this->b = abc.sprite.getPosition().y;
        this->sprite.setPosition(a,b);
        return *this;
    }
    void centre()
    {   
        sprite.setPosition(a,b);
    }

    void move2()
    {   
        sprite.setPosition(a-15,b+12);
    }
    void move(float d=0, float z=-2)
    {
        sprite.move(0+(d),z *speed);
        a += d;
        b += z;
    }
    int right()
	{ return (sprite.getPosition().x + 20);}
	int bottom()
	{ return (sprite.getPosition().y + 20);}
	int top()
	{ return (sprite.getPosition().y+2);}
	int left()
	{ return (sprite.getPosition().x -5);}
    ~Bullets()
    {}
};