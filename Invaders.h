#include <SFML/Graphics.hpp>
#include <string.h>
#include "Enemy.h"
using namespace sf;
class Invaders : public Enemy
{
public:
	int x, y;
	string type;
	Invaders *ptr;
	int size_of_enemies;
	bool check;
	int leftcheck, rightcheck; 
	Clock bomb_time;
	int check_time;
	int time_limit;  bool left_right;
////////////////////////////////////////////////////////////////////////CONSTRUCTORS////////////////////////////////////
	Invaders()
	{ type_of_enemy="invaders"; 
	 bomb_time.restart();
	 check_time=0;
	 size_of_enemies=10;
	 b1= nullptr;
	 ptr = nullptr;
	 left_right=1;
	}
////////////////////////////////////////////
	void display( int level ) override
	{  int l=0;
	 	int a=rand() %3+1;   if (level==3) l=rand() %3+1;
		if(level == 1  ||( level ==3 && l==1) )
		{ 
       if(a==1)    //rectangle 
	  { 
		leftcheck = 0; rightcheck = 4;
		ptr[0].sprite.setPosition(350,50);
		ptr[1].sprite.setPosition(600,50);

		ptr[2].sprite.setPosition(350,150);

		ptr[3].sprite.setPosition(500,50);
		ptr[4].sprite.setPosition(750,50);

		ptr[5].sprite.setPosition(750,250);
		ptr[6].sprite.setPosition(500,250);
		ptr[7].sprite.setPosition(350,250);

		ptr[8].sprite.setPosition(750,150);

		ptr[9].sprite.setPosition(600,250);
	  } 
	  if(a==2)
     	{  //triangle 
		leftcheck = 3; rightcheck = 9;  
		ptr[0].sprite.setPosition(530,50);
		ptr[1].sprite.setPosition(460,150);
		ptr[2].sprite.setPosition(400,250);
		ptr[3].sprite.setPosition(340,350);
		ptr[4].sprite.setPosition(460,350);
		ptr[5].sprite.setPosition(580,150);
		ptr[6].sprite.setPosition(640,250);
	 //	ptr[7].sprite.setPosition(-200,-200); 
		ptr[7].check=0;
		ptr[8].sprite.setPosition(580,350);
		ptr[9].sprite.setPosition(700,350);
	}
    	if(a==3)
	 {		// cross
	 leftcheck = 7; rightcheck = 5;
	    ptr[0].sprite.setPosition(730,10);
		ptr[1].sprite.setPosition(630,100);
		ptr[2].sprite.setPosition(460,200);
		ptr[3].sprite.setPosition(570,200);
		ptr[4].sprite.setPosition(430,300);
		ptr[5].sprite.setPosition(730,400);
		ptr[6].sprite.setPosition(630,300);
		ptr[7].sprite.setPosition(330,400);
		ptr[8].sprite.setPosition(430,100);

		ptr[9].sprite.setPosition(330,10);
} 
 	  }
if(level==2  || ( level ==3 && l==2))
{ if(a==1)
{		// HEART
        leftcheck = 8; rightcheck = 1;
	    ptr[0].sprite.setPosition(640,50);
		ptr[1].sprite.setPosition(730+10+15,150);
		ptr[2].sprite.setPosition(400-5,250);
		ptr[3].sprite.setPosition(680+10+10,250);
		ptr[4].sprite.setPosition(420+5,350);

		ptr[5].sprite.setPosition(540,150);		
		ptr[6].sprite.setPosition(620+10+5,350);
		ptr[7].sprite.setPosition(530+10,450);
		ptr[8].sprite.setPosition(330,150);
		ptr[9].sprite.setPosition(440,50);
}
if(a==2)
{		// CIRCLE
        leftcheck = 8; rightcheck = 3;
	    ptr[0].sprite.setPosition(640,70+10);

		ptr[1].sprite.setPosition(680+10,130+10);

		ptr[2].sprite.setPosition(400-10,200+10+10);
		ptr[3].sprite.setPosition(680+15,200+10);

		ptr[4].sprite.setPosition(425+10,280+20);

		ptr[5].sprite.setPosition(540,10+10);

		ptr[6].sprite.setPosition(630+10,280+10);

		ptr[7].sprite.setPosition(540,360+10);

		ptr[8].sprite.setPosition(380-10,130+10);

		ptr[9].sprite.setPosition(440-10,70+10);
}

 if(a==3)
 {		// diamond
 leftcheck = 8; rightcheck = 1;
	    ptr[0].sprite.setPosition(640+10,10);
		ptr[1].sprite.setPosition(730+10,100);
		ptr[2].sprite.setPosition(400-10-5,200);
		ptr[3].sprite.setPosition(680+10,200);
		ptr[4].sprite.setPosition(420+5,300+20);

		ptr[5].sprite.setPosition(540,10);
		ptr[6].sprite.setPosition(620+10,300);
		ptr[7].sprite.setPosition(530+10,400);
		ptr[8].sprite.setPosition(330-10,100);

		ptr[9].sprite.setPosition(440-10,10);
} 
}   if( level ==3 && l==3)
 {  if(a==1)
	{     //pta nhi kia he yeh 
	leftcheck = 0; rightcheck = 4;
		ptr[0].sprite.setPosition(350,50);
		ptr[1].sprite.setPosition(600,50);

		ptr[2].sprite.setPosition(350,150);

		ptr[3].sprite.setPosition(500,50);
		ptr[4].sprite.setPosition(750,50);

		ptr[5].sprite.setPosition(600,150);
		ptr[6].sprite.setPosition(500,250);

		ptr[7].sprite.setPosition(500,150);

		ptr[8].sprite.setPosition(750,150);
		ptr[9].sprite.setPosition(600,250);
   } 
{  //triangle  filled 
        leftcheck = 3; rightcheck = 9;
		ptr[0].sprite.setPosition(530,50);
		ptr[1].sprite.setPosition(460,150);
		ptr[2].sprite.setPosition(400,250);
		ptr[3].sprite.setPosition(340,350);
		ptr[4].sprite.setPosition(460,350);
		ptr[5].sprite.setPosition(580,150);
		ptr[6].sprite.setPosition(640,250);
		ptr[7].sprite.setPosition(520,250);
		ptr[8].sprite.setPosition(580,350);
		ptr[9].sprite.setPosition(700,350);
}
    }   
	}
////////////////////////////////////////////
	void fire(int time) override
	{ 
      if((time-check_time) > time_limit)
	  { 
		check_time=time;		
		b1= new Bomb();
		b1->setpos(sprite.getPosition().x,sprite.getPosition().y);
	  }
	}
////////////////////////////////////////////
	int right() override
	{ return (sprite.getPosition().x + 65);}
	int bottom() override
	{ return (sprite.getPosition().y + 55);}
	int top() override
	{ return (sprite.getPosition().y);}
	int left() override
	{ return (sprite.getPosition().x);}
///////////////////////////////////////MOVEMENTS///////////////////////////////
virtual void move ()
{  

		  if(ptr[rightcheck].right() <1200  && left_right==1)
		  {  
			for(int i=0; i <size_of_enemies;i++)
		{      ptr[i].sprite.move(speed,0);   }
		  }
		 else{ left_right=0; }
		  if(ptr[leftcheck].left() >0 && left_right==0)
		  {  
			for(int i=0; i <size_of_enemies;i++)
		{   ptr[i].sprite.move(-speed,0);  }
		  }
		 else{left_right=1;}
}

virtual ~Invaders()
{}
};
///////////////////////////////////////////////////ALPHA ALPHA ////////////////////////////////////////////////////////
class Alpha : public Invaders
{ public:
	Alpha()
	{
		tex.loadFromFile("img/enemy_1.png");
		sprite.setTexture(tex);
		sprite.setScale(0.65, 0.65);
        check=1;
		type="alpha";
		time_limit=5;
	}
~Alpha() override
{
	//delete this;
}
};
class Beta : public Invaders
{ public:
	Beta()
	{
		tex.loadFromFile("img/enemy_2.png");
		sprite.setTexture(tex);
		sprite.setScale(0.6, 0.5);
        check=1;
		type="beta";
		time_limit=3;
	}
	~Beta () override
	{
		//delete this;
	}
};
class Gamma : public Invaders
{ public:
	Gamma()
	{
		tex.loadFromFile("img/enemy_3.png");
		sprite.setTexture(tex);
		sprite.setScale(0.48, 0.48);
        check=1;
		type="gamma";
		time_limit=2;
	}
	~Gamma () override
	{
		//delete this;
	}
};

Invaders* random_constructor(int size=10)
{   int a1=rand()%4+3,b1=rand()%4+2,g1;
    g1=10-(a1+b1);
	Invaders *abc = new Invaders();
	abc->size_of_enemies=10;
	abc->ptr= new Invaders[10];
    Alpha *apl = new Alpha[a1];
    Beta *bpg = new Beta [b1];
    Gamma *gbv = new Gamma [g1];
    for(int i=0;i<a1;i++)
    { abc->ptr[i] = apl[i]; }
    for(int i=a1;i<b1+a1;i++)
    { abc->ptr[i] = bpg[i-a1];}
    for(int i=b1+a1;i<b1+a1+g1;i++)
    { abc->ptr[i] = gbv[i-a1-b1];}
return abc;
}
