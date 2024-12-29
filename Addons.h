#include <SFML/Graphics.hpp>
#include <string.h>
using namespace sf;
#include <iostream>
using namespace std;
class Addons
{
public:
	Texture tex;
	Sprite sprite;
	Sprite fire; 
    Texture bg_text;
	string type;
	float speed = 0.5; // 0.1 default.
	float x, y;
	virtual void pure()=0;
	Addons()
	{ 		
	}
    void make_addon(std::string png_path, string a)
    {   //srand(time(0));
		type = a;
        tex.loadFromFile(png_path);
		sprite.setTexture(tex);
		x = rand()%1000+80;
		y = 0;
		sprite.setPosition(x,y);	
    }
	void move(int level=0)
    {
		if(level==1)
		speed  =0.5;
		if(level==2)
		speed =1;
		if(level==3)
		speed=1.5;
        sprite.move(0,speed);
        y+=speed;
    }
    bool check_boundary()
    {
        if(y>=780)
        { return 0;}
    return 1;
    }
	int right()
	{ return (sprite.getPosition().x + 30);}
	int bottom()
	{ return (sprite.getPosition().y + 20);}
	int top()
	{ return (sprite.getPosition().y);}
	int left()
	{ return (sprite.getPosition().x);}
virtual ~Addons()
{
}
};
