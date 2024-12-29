#include <SFML/Graphics.hpp>
#include "Addons.h"
#include <iostream>
using namespace std;
#include <string.h>
using namespace sf;
//1
class Shield_addon : public Addons
{
 public:
 Shield_addon()
 {  sprite.setScale(1,1);
 }
 void pure() override {}
~Shield_addon() override
{
}
};
//2
class Powerup_addon : public Addons
{
 public:
 Powerup_addon()
 {  sprite.setScale(0.5,0.5);
 }
 void pure() override {}
~Powerup_addon() override
{
}
};
//3
class Fire_addon : public Addons
{
 public:
 Fire_addon()
 { sprite.setScale(1,1);
 }
 void pure() override {}
~Fire_addon() override
{
}
};
//4
class Danger_addon : public Addons
{
 public:
 Danger_addon()
 { sprite.setScale(0.75,0.75);
 }
 void pure() override {}
~Danger_addon() override
{  
}
};
//5
class Lives_addon : public Addons
{
 public:
 Lives_addon()
 {  sprite.setScale(0.75+0.75,0.75*2);
 }
 void pure() override {}
~Lives_addon() override
{
}
};
//6
class Speed_addon : public Addons
{
 public:
 Speed_addon()
 {  sprite.setScale(1,1);
 }
 void pure() override {}
~Speed_addon() override
{
}
};
