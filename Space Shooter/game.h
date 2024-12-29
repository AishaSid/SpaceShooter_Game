
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
using namespace std;
#include "player.h"
#include "Child_addons.h"
#include "Invaders.h"
const char title[] = "AISHA SIDDIQA";
using namespace sf;
class Game
{
public:
    int Scores = 0;
    int level;
    Sprite background; // Game background sprite
    Texture bg_texture;
    Sprite livess;
    Texture lifes;
    Sprite levelss;
    Texture levels;
    sf::Text text, lvl;
    sf::Font font;
    /////////////////////////////////OBJECTS///////////////////////
    Gamma bonus[2];
    Player *p; // player
    Enemy *en;
    Addons *a;
    Invaders *abc;
    int lives, addone;
    bool play;
    bool ver = 0;
    int alp;
    bool enemy_arrive;
    int fffff;
    Game()
    {
        level = 1;
        alp = 1;
        lives = 3;
        p = new Player("img/player_ship.png");
        en = nullptr;
        a = nullptr;
        abc = nullptr;
        bg_texture.loadFromFile("img/blue1.jpg");
        background.setTexture(bg_texture);
        background.setScale(0.75, 0.75);
        lifes.loadFromFile("img/PNG/UI/playerLife1_blue.png");
        livess.setTexture(lifes);
        livess.setScale(1, 1);
        play=0;
        enemy_arrive=0;
        fffff=15;
    }
    ////////////////////////////////////////////////PAUSE SCREEN////////////////////////////////////////////////
    void display_pause(RenderWindow *window)
    {
        Sprite pause;
        Texture bg_text;
        bg_text.loadFromFile("img/pause3.png");
        pause.setTexture(bg_text);
        pause.setScale(1.1, 1.1);
        RenderWindow window2(VideoMode(650, 550), "AISHA SIDDIQA");
        while (window2.isOpen())
        {
            Event e;
            while (window2.pollEvent(e))
            {
                if (e.type == Event::Closed)
                    window2.close();
            }
            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                window2.close();
            }
            if (Keyboard::isKeyPressed(Keyboard::RShift))
            {
                window2.close();
                (*window).close();
                Game restart;
                restart.start_game();
            }
            window2.clear(Color::Black);
            window2.draw(pause);
            if (Keyboard::isKeyPressed(Keyboard::R))
                window2.close();
            window2.display();
        }
    }
    ////////////////////////////////////////////////////GAME OVER///////////////////////////////////////////////
    bool display_game_over()
    {
        Sprite gameover;
        Texture bg_text;
        bg_text.loadFromFile("img/gameover3.png");
        gameover.setTexture(bg_text);
        gameover.setScale(0.9, 0.9);
        RenderWindow window2(VideoMode(550, 450), "AISHA SIDDIQA");
        while (window2.isOpen())
        {
            Event e;
            while (window2.pollEvent(e))
            {
                if (e.type == Event::Closed)
                    window2.close();
            }
            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                window2.close();
            }
            window2.clear(Color::Black);
            window2.draw(gameover);
            if (Keyboard::isKeyPressed(Keyboard::R))
            {
                window2.close();
                return true;
            }
            window2.display();
        }
        return false;
    }
    /////////////////////////////////////////////////////COLLISION WITH ENEMIES/////////////////////////////////////////////////////
    bool collision1() // en & player
    {
        if (en != nullptr)
        {
            if (en->type_of_enemy == "monster" || en->type_of_enemy == "dragon")
            {
                int b;
                if ((en->bottom() > p->top()) && (en->left() < p->left()) && (en->right() > p->left()) && (en->top() < p->bottom()))
                    return 1;
                if ((en->bottom() > p->top()) && (en->left() < p->right()) && (en->left() > p->left()) && (en->top() < p->bottom()))
                    return 1;
            }
        }
        return 0;
    }
    bool collision6(int i) // en & bullet
    {
        if (en != nullptr)
        {
            if (en->type_of_enemy == "monster" || en->type_of_enemy == "dragon")
            {
                int b;
                if ((en->bottom() > p->b1[i].top()) && (en->left() < p->b1[i].left()) && (en->right() > p->b1[i].left()) && (en->top() < p->b1[i].bottom()))
                    return 1;
                if ((en->bottom() > p->b1[i].top()) && (en->left() < p->b1[i].right()) && (en->left() > p->b1[i].left()) && (en->top() < p->b1[i].bottom()))
                    return 1;
            }
        }

        return 0;
    }
    bool collision1_1(int i, int j) // invaders & bullet
    {
        if (abc != nullptr && p->b1 != nullptr)
        {
            if ((abc->ptr[i].bottom() > p->b1[j].top()) && (abc->ptr[i].left() < p->b1[j].left()) && (abc->ptr[i].right() > p->b1[j].left()) && (abc->ptr[i].top() < p->b1[j].bottom()))
                return 1;
            if ((abc->ptr[i].bottom() > p->b1[j].top()) && (abc->ptr[i].left() < p->b1[j].right()) && (abc->ptr[i].right() > p->b1[j].left()) && (abc->ptr[i].top() < p->b1[j].bottom()))
                return 1;
        }
        return 0;
    }
    bool collision1_2(int i, int j) // invaders & bullet
    {
        if (abc != nullptr && p->b2 != nullptr)
        {
            if ((abc->ptr[i].bottom() > p->b2[j].top()) && (abc->ptr[i].left() < p->b2[j].left()) && (abc->ptr[i].right() > p->b2[j].left()) && (abc->ptr[i].top() < p->b2[j].bottom()))
                return 1;
            if ((abc->ptr[i].bottom() > p->b2[j].top()) && (abc->ptr[i].left() < p->b2[j].right()) && (abc->ptr[i].right() > p->b2[j].left()) && (abc->ptr[i].top() < p->b2[j].bottom()))
                return 1;
        }
        return 0;
    }
    bool collision1_3(int i, int j) // invaders & bullet
    {
        if (abc != nullptr && p->b3 != nullptr)
        {
            if ((abc->ptr[i].bottom() > p->b3[j].top()) && (abc->ptr[i].left() < p->b3[j].left()) && (abc->ptr[i].right() > p->b3[j].left()) && (abc->ptr[i].top() < p->b3[j].bottom()))
                return 1;
            if ((abc->ptr[i].bottom() > p->b3[j].top()) && (abc->ptr[i].left() < p->b3[j].right()) && (abc->ptr[i].right() > p->b3[j].left()) && (abc->ptr[i].top() < p->b3[j].bottom()))
                return 1;
        }
        return 0;
    }
    bool collision1_4(int i, int j) // invaders & bullet
    {
        if (abc != nullptr && p->b4 != nullptr)
        {
            if ((abc->ptr[i].bottom() > p->b4[j].top()) && (abc->ptr[i].left() < p->b4[j].left()) && (abc->ptr[i].right() > p->b4[j].left()) && (abc->ptr[i].top() < p->b4[j].bottom()))
                return 1;
            if ((abc->ptr[i].bottom() > p->b4[j].top()) && (abc->ptr[i].left() < p->b4[j].right()) && (abc->ptr[i].right() > p->b4[j].left()) && (abc->ptr[i].top() < p->b4[j].bottom()))
                return 1;
        }
        return 0;
    }
    bool collision1_5(int i, int j) // invaders & bullet
    {
        if (abc != nullptr && p->b5 != nullptr)
        {
            if ((abc->ptr[i].bottom() > p->b5[j].top()) && (abc->ptr[i].left() < p->b5[j].left()) && (abc->ptr[i].right() > p->b5[j].left()) && (abc->ptr[i].top() < p->b5[j].bottom()))
                return 1;
            if ((abc->ptr[i].bottom() > p->b5[j].top()) && (abc->ptr[i].left() < p->b5[j].right()) && (abc->ptr[i].right() > p->b5[j].left()) && (abc->ptr[i].top() < p->b5[j].bottom()))
                return 1;
        }
        return 0;
    }
    bool collision1_6(int i, int j) // invaders & bullet
    {
        if (abc != nullptr && p->b6 != nullptr)
        {
            if ((abc->ptr[i].bottom() > p->b6[j].top()) && (abc->ptr[i].left() < p->b6[j].left()) && (abc->ptr[i].right() > p->b6[j].left()) && (abc->ptr[i].top() < p->b6[j].bottom()))
                return 1;
            if ((abc->ptr[i].bottom() > p->b6[j].top()) && (abc->ptr[i].left() < p->b6[j].right()) && (abc->ptr[i].right() > p->b6[j].left()) && (abc->ptr[i].top() < p->b6[j].bottom()))
                return 1;
        }
        return 0;
    }
    bool collision1_7(int i, int j) // invaders & bullet
    {
        if (abc != nullptr && p->b7 != nullptr)
        {
            if ((abc->ptr[i].bottom() > p->b7[j].top()) && (abc->ptr[i].left() < p->b7[j].left()) && (abc->ptr[i].right() > p->b7[j].left()) && (abc->ptr[i].top() < p->b7[j].bottom()))
                return 1;
            if ((abc->ptr[i].bottom() > p->b7[j].top()) && (abc->ptr[i].left() < p->b7[j].right()) && (abc->ptr[i].right() > p->b7[j].left()) && (abc->ptr[i].top() < p->b7[j].bottom()))
                return 1;
        }
        return 0;
    }
    /////////////////////////////////////////////////////COLLISION WITH ADDONS/////////////////////////////////////////////////////
    bool collision2() // addon & player
    {
        if (a != nullptr)
        {
            if ((a->bottom() > p->top()) && (a->left() < p->left()) && (a->right() > p->left()) && (a->top() < p->bottom()))
                return 1;
            if ((a->bottom() > p->top()) && (a->left() < p->right()) && (a->left() > p->left()) && (a->top() < p->bottom()))
                return 1;
        }
        return 0;
    }
    bool collision5(int i) // playr & invaders
    {
        if (abc != nullptr)
        {
            if ((abc->ptr[i].bottom() > p->top()) && (abc->ptr[i].left() < p->left()) && (abc->ptr[i].right() > p->left()) && (abc->ptr[i].top() < p->bottom()))
                return 1;
            if ((abc->ptr[i].bottom() > p->top()) && (abc->ptr[i].left() < p->right()) && (abc->ptr[i].left() > p->left()) && (abc->ptr[i].top() < p->bottom()))
                return 1;
        }
        return 0;
    }
    bool collision3() // player &  en bombs
    {
        if (en->light != nullptr)
            for (int i = 0; i < en->lsize; i++)
            {
                int b;
                if ((en->light[i].bottom() > p->top()) && (en->light[i].left() < p->left()) && (en->light[i].right() > p->left()) && (en->light[i].top() < p->bottom()))
                    return 1;
                if ((en->light[i].bottom() > p->top()) && (en->light[i].left() < p->right()) && (en->light[i].left() > p->left()) && (en->light[i].top() < p->bottom()))
                    return 1;
            }
        return 0;
    }
    bool collision3_left() // player &  en bombs
    {
        if (en->light_left != nullptr)
            for (int i = 0; i < en->left_size; i++)
            {
                int b;
                if ((en->light_left[i].bottom() > p->top()) && (en->light_left[i].left() < p->left()) && (en->light_left[i].right() > p->left()) && (en->light_left[i].top() < p->bottom()))
                    return 1;
                if ((en->light_left[i].bottom() > p->top()) && (en->light_left[i].left() < p->right()) && (en->light_left[i].left() > p->left()) && (en->light_left[i].top() < p->bottom()))
                    return 1;
            }
        return 0;
    }
    bool collision3_right() // player &  en bombs
    {
        if (en->light_right != nullptr)
            for (int i = 0; i < en->right_size; i++)
            {
                int b;
                if ((en->light_right[i].bottom() > p->top()) && (en->light_right[i].left() < p->left()) && (en->light_right[i].right() > p->left()) && (en->light_right[i].top() < p->bottom()))
                    return 1;
                if ((en->light_right[i].bottom() > p->top()) && (en->light_right[i].left() < p->right()) && (en->light_right[i].left() > p->left()) && (en->light_right[i].top() < p->bottom()))
                    return 1;
            }
        return 0;
    }
    bool collision4(int i) // player & invaders bombs
    {
        {
            if ((abc->ptr[i].b1->bottom() > p->top()) && (abc->ptr[i].b1->left() < p->left()) && (abc->ptr[i].b1->right() > p->left()) && (abc->ptr[i].b1->top() < p->bottom()))
                return 1;
            if ((abc->ptr[i].b1->bottom() > p->top()) && (abc->ptr[i].b1->left() < p->right()) && (abc->ptr[i].b1->left() > p->left()) && (abc->ptr[i].b1->top() < p->bottom()))
                return 1;
        }
        return 0;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////START GAME////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void start_game()
    {
        Texture shld;
        Sprite shields_image;
        shld.loadFromFile("img/PNG/Effects/shield2.png");
        shields_image.setTexture(shld);
        shields_image.setScale(0.75, 0.75);
        Text blish ,blish1;
        blish.setFont(font);
        blish.setString("Level 2");
        blish.setCharacterSize(70);
        blish.setFillColor(sf::Color::White);
        blish.setPosition(100, 100);
        blish1.setFont(font);
        blish1.setString("Phase 1");
        blish1.setCharacterSize(40);
        blish1.setFillColor(sf::Color::White);
        blish1.setPosition(300, 300);
        font.loadFromFile("ghostclanlaser.ttf");
        text.setFont(font);
        text.setString("SCORES");
        text.setCharacterSize(28);
        text.setFillColor(sf::Color::White);
        text.setPosition(1050, 30);
        lvl.setFont(font);
        lvl.setString("LEVEL");
        lvl.setCharacterSize(28);
        lvl.setFillColor(sf::Color::White);
        lvl.setPosition(1050, 120);
        sf::Text texts, lvls;
        texts.setFont(font);
        texts.setCharacterSize(28);
        texts.setFillColor(sf::Color::White);
        texts.setPosition(1050, 70);
        lvls.setFont(font);
        lvls.setCharacterSize(28);
        lvls.setFillColor(sf::Color::White);
        lvls.setPosition(1050, 160);
        srand(time(0));
        RenderWindow window(VideoMode(1200, 820), title);
        Clock clock;
        Clock bomb_Delay;
        Clock delay;
        float timer = 0;
        int ff = 0, rr = 0, nn;
        int time_check_monster = 0;
        bool allow_monster = 0;
        bool allow_dragon = 1;
        bool allow_fire = 1;
        bool dd;
        bool bomb_direction = 1;
        bool shield = 1;
        int dragon_bomb_check = 0;
        bool player_speed = 0;
        int addone_timer = 0, fire_timer = 0, powerup_timer = -5, speed_timer = -5;
        int time_randomizer = 0;
bonus[0].x= -5;
bonus[0].y=200;
bonus[1].x=1200;
bonus[1].y=200;
bonus[0].sprite.setPosition(-5,200);
bonus[1].sprite.setPosition(1200,200);

        while (window.isOpen()) ////////////////////////////////////INFINITE LOOP///////////////////////////////////////////
        {       
            bool invaders_bullet_collide = 0;
            bool bomb_collide = 0;
            bool bullet_collide_enemy = 0;
            bool enemy_collide = 0;
            if (en != nullptr)
                enemy_collide = collision1();
            bool addon_collide = 0; // COLLISION2();
            float time = clock.getElapsedTime().asSeconds();
            int delayy = delay.getElapsedTime().asMilliseconds();
            clock.restart();
            delay.restart();
            timer += time;
            int n = timer;
            bool tt = 0;
            ver = false;
            if (n % 2 == 0)
                ver = true;
            Event e;
            while (window.pollEvent(e))
                if (e.type == Event::Closed) // If cross/close is clicked/pressed
                    window.close();          // close the game
            if (Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();
            ////////////////////////////////////////MOVEMENTS////////////////////////////////////////////
            {
                if (Keyboard::isKeyPressed(Keyboard::Left)) // If left key is pressed
                {
                    p->move("l");
                }                                            // Player will move to left
                if (Keyboard::isKeyPressed(Keyboard::Right)) // If right key is pressed
                {
                    p->move("r");
                }                                         // player will move to right
                if (Keyboard::isKeyPressed(Keyboard::Up)) // If up key is pressed
                {
                    p->move("u");
                    ff = 0;
                    rr = 0;
                    p->tex.loadFromFile("img/player_ship.png");
                    p->sprite.setScale(0.6, 0.6);
                }                                           // playet will move upwards
                if (Keyboard::isKeyPressed(Keyboard::Down)) // If down key is pressed
                {
                    p->move("d");
                } // player will move downwards
                if ((Keyboard::isKeyPressed(Keyboard::Left)) && (Keyboard::isKeyPressed(Keyboard::Up)))
                {
                    p->tex.loadFromFile("img/diagonal3.png");
                    p->sprite.setScale(0.8, 0.8);
                    ff = -30;
                    rr = -2;
                }
                if ((Keyboard::isKeyPressed(Keyboard::Left)) && (Keyboard::isKeyPressed(Keyboard::Down)))
                {
                    p->tex.loadFromFile("img/diagonal4.png");
                    p->sprite.setScale(0.8, 0.8);
                    ff = -30;
                    rr = -2;
                }
                if ((Keyboard::isKeyPressed(Keyboard::Right)) && (Keyboard::isKeyPressed(Keyboard::Down)))
                {
                    p->tex.loadFromFile("img/diagonal2.png");
                    p->sprite.setScale(0.8, 0.8);
                    ff = -30;
                    rr = -2;
                }
                if ((Keyboard::isKeyPressed(Keyboard::Right)) && (Keyboard::isKeyPressed(Keyboard::Up)))
                {
                    p->tex.loadFromFile("img/diagonal1.png");
                    p->sprite.setScale(0.8, 0.8);
                    ff = 30;
                    rr = 2;
                }
            }
            
            ////////////////////////////////////////MENU FUNTIONALITIES////////////////////////////////////////////
            if (Keyboard::isKeyPressed(Keyboard::P))
            {
                display_pause(&window);
            }
            if (Keyboard::isKeyPressed(Keyboard::Space))
            {
                if (bomb_Delay.getElapsedTime().asMilliseconds() >= 200)
                { 
                    p->fir();
                    if (allow_fire)
                        p->powerup_fire();
                    bomb_Delay.restart();
                }
            }
            if (en != nullptr && abc == nullptr)
            {
            }
            else if ((en == nullptr && abc == nullptr) && timer>=3)
            {
                abc = random_constructor(10);
                abc->display(level);
            }
            if (alp % 4 == 0)
            {
                alp = 1;
                if(level<3)
                level++;
                Clock c;
		         float f =  c.getElapsedTime().asSeconds();
                 c.restart();
bonus[0].sprite.setPosition(-5,200);
bonus[1].sprite.setPosition(1200,200);
                 if (level==2)
                {while(f < 5)
                {  f =  c.getElapsedTime().asSeconds();
                  bg_texture.loadFromFile("img/bluephase.jpg");
                  background.setScale(0.75,0.9);
                  window.clear();
window.draw(background);
window.draw(blish);
window.draw(blish1);
{ if(bonus[0].right()<= bonus[1].sprite.getPosition().x)
{
      bonus[0].sprite.move(2.3,0);
      bonus[1].sprite.move(-2.4,0);
      window.draw(bonus[0].sprite);
      window.draw(bonus[1].sprite);
} else break;
}                 
                  window.display();
                } bg_texture.loadFromFile("img/pink3.jpg");
                 background.setScale(0.75,0.75); blish.setString("LEVEL 3");}
                else
                {
                {while(f < 3)
                {  f =  c.getElapsedTime().asSeconds();
                  bg_texture.loadFromFile("img/redphase.jpg");
                  window.clear();
                  window.draw(background);
                  window.draw(blish);
                  window.draw(blish1);
{ if(bonus[0].right()<= bonus[1].sprite.getPosition().x)
{
    bonus[0].sprite.move(2.3,0);
    bonus[1].sprite.move(-2.4,0);
      window.draw(bonus[0].sprite);
      window.draw(bonus[1].sprite);
} else break;
} 
                  window.display();
                } bg_texture.loadFromFile("img/red2.jpg");
                 }
                }
            }
            ////////////////////////////////////////MONSTERss////////////////////////////////////////////
            {
                if (timer - time_randomizer >= fffff)
                {
                    int rands = rand() % 10 + 1;
                    if (rands == 1)
                    {
                        allow_monster = 1;
                    }
                    else if (rands == 2)
                        allow_dragon = 1;
                }
            }
            if (allow_monster == 1 && allow_dragon == 1)
            {
                int rands = rand() % 2 + 1;
                if (rands == 1)
                {
                    allow_monster = 0;
                }
                else if (rands == 2)
                    allow_dragon = 0;
            }
            ////////////////                  DRAGON
            if (allow_dragon == 1 && (timer - time_check_monster) >= fffff)
            {
                if (en != nullptr)
                    delete en;
                // Dragon d(("img/dragon1.png"));
                enemy_arrive=1;
                en = new Dragon("img/dragon1.png");
                (en->type_of_enemy = "dragon");
                allow_dragon = 0;
                allow_monster = 0;
                time_check_monster = timer;
                fffff= rand()%15+6;
            }
            /////////////////////       MONSTER
            // Enemy abcdef;
            if (allow_monster == 1 && (timer - time_check_monster) >= fffff)
            {
                if (en != nullptr)
                    delete en;
                // Monster m(("img/monster1.png"));
                enemy_arrive=1;
                en = new Monster("img/monster1.png");
                (en->type_of_enemy = "monster");
                allow_monster = 0;
                allow_dragon = 0;
                time_check_monster = timer;
                fffff= rand()%15+6;
            }
            if (en != nullptr && abc != nullptr)
            {
                enemy_arrive=1;
                // if (abc->b1 != nullptr)
                //     for (int i = 0; i < abc->size_of_enemies; i++)
                //     {
                //         delete abc->ptr[i].b1;
                //     }
                // if (abc->size_of_enemies > 1)
                //     delete[] abc->ptr;
                // abc->ptr = nullptr;
                // delete abc;
                // abc = nullptr;
            }
            ////////////////////////////////////////BOMBS MOVEMENTS////////////////////////////////////////////
            if (lives == 1)
                p->sprite.setColor(Color::Red);
            else
                p->sprite.setColor(Color::White);
            ////////////////////////////////////////ADD-ONS ADD-ONS////////////////////////////////////////////
            if (a != nullptr)
            {
                a->move(level);
                addon_collide = collision2();
                play = a->check_boundary();
                if (play == 0)
                {
                    if (a->type == "danger")
                        Scores += 5;
                    delete a;
                    a = nullptr;
                }
            }
            if (addon_collide == 1 && a->type == "lives")
            {
                delete a;
                a = nullptr;
                if (lives < 3)
                    lives++;
                addon_collide = 0;
            }
            if (addon_collide == 1 && a->type == "danger")
            {
                if (shield == 0)
                {
                    p->destroy_ship(&window);
                    p->sprite.setPosition(520,680);
                    p->x = 520;
                    p->y=680;
                    lives--;
                    shield = 1;
                    addone_timer = timer;
                }
                delete a;
                a = nullptr;
                addon_collide = 0;
            }
            if (addon_collide == 1 && a->type == "fire")
            {
                delete a;
                a = nullptr;
                fire_timer = timer; // ( powerup &shield timer (basically shield timer now))
                addon_collide = 0;
                for (int i = 0; i < p->b1_size; i++)
                {
                    p->b1[i].type = "fire";
                }
            }
            if (addon_collide == 1 && a->type == "powerup")
            {
                delete a;
                a = nullptr;
                shield = true;
                shields_image.setPosition(p->left() - 22, p->top() - 17);
                addone_timer = timer;
                addon_collide = 0;
                powerup_timer = timer;
            }
            if (addon_collide == 1 && a->type == "Shield")
            {
                delete a;
                a = nullptr;
                shield = true;
                shields_image.setPosition(p->left() - 22, p->top() - 17);
                addone_timer = timer;
                addon_collide = 0;
            }
            if (addon_collide == 1 && a->type == "Speed")
            {
                delete a;
                a = nullptr;
                addon_collide = 0;
                speed_timer = timer;
                player_speed = 1;
            }
            if (timer - speed_timer <= 5)
            {
                p->speed = 1.75;
            }
            else
            {
                p->speeds(level);
            }
            if (timer - fire_timer <= 5)
            {
                for (int i = 0; i < p->b1_size; i++)
                {
                    p->b1[i].type = "fire";
                    p->b1[i].sprite.setColor(Color::Red);
                }
                if (p->b2 != nullptr && p->b3 != nullptr)
                {
                    for (int i = 0; i < p->b2_size, i < p->b3_size; i++)
                    {
                        p->b2[i].type = "fire";
                        p->b3[i].type = "fire";
                        p->b2[i].sprite.setColor(Color::Red);
                        p->b3[i].sprite.setColor(Color::Red);
                    }
                }
                if (p->b4 != nullptr && p->b5 != nullptr)
                {
                    for (int i = 0; i < p->b4_size, i < p->b5_size; i++)
                    {
                        p->b4[i].type = "fire";
                        p->b5[i].type = "fire";
                        p->b4[i].sprite.setColor(Color::Red);
                        p->b5[i].sprite.setColor(Color::Red);
                    }
                }
                if (p->b6 != nullptr && p->b7 != nullptr)
                {
                    for (int i = 0; i < p->b7_size, i < p->b6_size; i++)
                    {
                        p->b6[i].type = "fire";
                        p->b7[i].type = "fire";
                        p->b6[i].sprite.setColor(Color::Red);
                        p->b7[i].sprite.setColor(Color::Red);
                    }
                }
            }
            else
            {
                for (int i = 0; i < p->b1_size; i++)
                {
                    p->b1[i].type = " ";
                    p->b1[i].sprite.setColor(Color::White);
                }
                if (p->b2 != nullptr && p->b3 != nullptr)
                {
                    for (int i = 0; i < p->b2_size, i < p->b3_size; i++)
                    {
                        p->b2[i].type = "  ";
                        p->b3[i].type = "  ";
                        p->b2[i].sprite.setColor(Color::White);
                        p->b3[i].sprite.setColor(Color::White);
                    }
                }
                if (p->b4 != nullptr && p->b5 != nullptr)
                {
                    for (int i = 0; i < p->b4_size, i < p->b5_size; i++)
                    {
                        p->b4[i].type = "  ";
                        p->b5[i].type = "  ";
                        p->b4[i].sprite.setColor(Color::White);
                        p->b5[i].sprite.setColor(Color::White);
                    }
                }
                if (p->b6 != nullptr && p->b7 != nullptr)
                {
                    for (int i = 0; i < p->b7_size, i < p->b6_size; i++)
                    {
                        p->b6[i].type = "  ";
                        p->b7[i].type = "  ";
                        p->b6[i].sprite.setColor(Color::White);
                        p->b7[i].sprite.setColor(Color::White);
                    }
                }
            }
            if (timer - addone_timer <= 5)
            {
                shields_image.setPosition(p->left() - 22, p->top() - 17);
                shield = true;
            }
            else
            {
                shield = 0;
            }
            if (timer - powerup_timer <= 5)
            {
                allow_fire = 1;
            }
            else
            {
                allow_fire = 0;
                if (p->b2 != nullptr)
                {
                    delete[] p->b2;
                    p->b2 = nullptr;
                    p->b2_size = 0;
                }
                if (p->b3 != nullptr)
                {
                    delete[] p->b3;
                    p->b3 = nullptr;
                    p->b3_size = 0;
                }
                if (p->b4 != nullptr)
                {
                    delete[] p->b4;
                    p->b4 = nullptr;
                    p->b4_size = 0;
                }
                if (p->b5 != nullptr)
                {
                    delete[] p->b5;
                    p->b5 = nullptr;
                    p->b5_size = 0;
                }
                if (p->b6 != nullptr)
                {
                    delete[] p->b6;
                    p->b6 = nullptr;
                    p->b6_size = 0;
                }
                if (p->b7 != nullptr)
                {
                    delete[] p->b7;
                    p->b7 = nullptr;
                    p->b7_size = 0;
                }
            }
            if (timer >= 3 && a == nullptr)
            {
                addone =rand() % 6 + 1;
                switch (addone)
                {
                case 1:
                { ////////LIVES////////
                    a = new Lives_addon();
                    a->make_addon("img/heart.png", "lives");
                    break;
                }
                case 2:
                { ///////DANGER///////
                    a = new Danger_addon();
                    a->make_addon("img/PNG/Meteors/meteorGrey_med2.png", "danger");
                    break;
                }
                case 3:
                { ////////FIRE////////
                    a = new Fire_addon();
                    a->make_addon("img/PNG/Power-ups/bolt_bronze.png", "fire");
                    break;
                }
                case 4:
                { ////////POWER-UP/////
                    a = new Powerup_addon();
                    a->make_addon("img/PNG/ufoGreen.png", "powerup");
                    break;
                }
                case 5:
                { ////////POWER-UP/////
                    a = new Shield_addon();
                    a->make_addon("img/PNG/Power-ups/shield_gold.png", "Shield");
                    break;
                }
                case 6:
                { ////////POWER-UP/////
                    a = new Speed_addon();
                    a->make_addon("img/PNG/Power-ups/powerupBlue_bolt.png", "Speed");
                    break;
                }
                }
            }
            //////////////////////////////////////////////////////////////////////WINDOW THINGYYSSS////////////////////////////////////////////
            window.clear(Color::Cyan); // clears the screen
            window.draw(background);   // setting background
            window.draw(p->sprite);    // setting player on screen
                                       ////////////////////////////////////////ADDONS DISPLAY////////////////////////////////////////////
            if (a != nullptr)
                window.draw(a->sprite);
            ////////////////////////////////////////LIVES DISPLAY////////////////////////////////////////////
            for (int i = 0; i < lives; i++) // display total lives
            {
                window.draw(livess);
                livess.setPosition(10 + (i * 50), 680);
            }
            ////////////////////////////////////////BULLETS DISPLAY////////////////////////////////////////////
            for (int i = 0; i < p->b1_size; i++)
            {
                window.draw(p->b1[i].sprite);
                p->b1[i].move();
                bullet_collide_enemy = collision6(i);
                if ((p->b1[i].check_boundary() || bullet_collide_enemy) && p->b1->type != "fire")
                {
                    p->delete_chain(i);
                }
            }

            for (int i = 0; i < p->b2_size; i++)
            {
                window.draw(p->b2[i].sprite);
                p->b2[i].move(-1);
                bullet_collide_enemy = collision6(i);
                //  if((p->b2[i].check_boundary() || bullet_collide_enemy) && p->b2->type!= "fire")
                //   { p->delete_chain(i); }
            }

            for (int i = 0; i < p->b3_size; i++)
            {
                window.draw(p->b3[i].sprite);
                p->b3[i].move(1);
                bullet_collide_enemy = collision6(i);
                //   if((p->b3[i].check_boundary() || bullet_collide_enemy) && p->b3->type!= "fire")
                //    { p->delete_chain(i); }
            }

            for (int i = 0; i < p->b4_size; i++)
            {
                window.draw(p->b4[i].sprite);
                p->b4[i].move(-0.5);
                bullet_collide_enemy = collision6(i);
                //  if((p->b2[i].check_boundary() || bullet_collide_enemy) && p->b2->type!= "fire")
                //   { p->delete_chain(i); }
            }

            for (int i = 0; i < p->b5_size; i++)
            {
                window.draw(p->b5[i].sprite);
                p->b5[i].move(0.5);
                bullet_collide_enemy = collision6(i);
                //   if((p->b3[i].check_boundary() || bullet_collide_enemy) && p->b3->type!= "fire")
                //    { p->delete_chain(i); }
            }

            for (int i = 0; i < p->b6_size; i++)
            {
                window.draw(p->b6[i].sprite);
                p->b6[i].move(-1.5);
                bullet_collide_enemy = collision6(i);
                //  if((p->b2[i].check_boundary() || bullet_collide_enemy) && p->b2->type!= "fire")
                //   { p->delete_chain(i); }
            }

            for (int i = 0; i < p->b7_size; i++)
            {
                window.draw(p->b7[i].sprite);
                p->b7[i].move(1.5);
                bullet_collide_enemy = collision6(i);
                //   if((p->b3[i].check_boundary() || bullet_collide_enemy) && p->b3->type!= "fire")
                //    { p->delete_chain(i); }
            }
            ////////////////////////////////////////display GAME OVER////////////////////////////////////////////
            if (lives == 0)
            {
                lives = 3;
                play = display_game_over();
                window.close();
            }
            //////////////////  IIIIIINNNNNVADERSSSSSSSSS    alpha beta gamma

            if (abc != nullptr && enemy_arrive ==0)
            {
                abc->speeds(level);
                if (bomb_Delay.getElapsedTime().asMilliseconds() >= 200)
                {
                    int n = rand() % abc->size_of_enemies;
                    abc->ptr[n].fire(timer);
                    bomb_Delay.restart();
                }
                abc->move();
                for (int i = 0; i < abc->size_of_enemies; i++)
                {
                    if (abc->ptr[i].check)
                    {
                        window.draw(abc->ptr[i].sprite);
                        enemy_collide = collision5(i);
                        if (enemy_collide)
                        {
                            if (shield != true)
                            {
                                p->destroy_ship(&window);
                                lives--;
                                p->x = 520;
                                p->y = 680;
                                shield = 1;
                                addone_timer = timer;
                                p->sprite.setPosition(520, 680);
                            }
                            enemy_collide = 0;
                            bomb_collide = 0;
                        }
                        if (abc->ptr[i].b1 != nullptr)
                        {
                            if (abc->ptr[i].b1->check_boundary())
                            {
                                window.draw(abc->ptr[i].b1->sprite);
                                abc->ptr[i].b1->move(level);
                                bomb_collide = collision4(i);
                                if (bomb_collide)
                                {
                                    delete abc->ptr[i].b1;
                                    abc->ptr[i].b1 = nullptr;
                                }
                            }
                            else
                            {
                                delete abc->ptr[i].b1;
                                abc->ptr[i].b1 = nullptr;
                            }
                        }
                        if (abc != nullptr)
                        {
                            for (int j = 0; j < p->b1_size; j++)
                            {
                                invaders_bullet_collide = collision1_1(i, j);
                                if (invaders_bullet_collide)
                                {
                                    abc->ptr[i].check = 0;
                                    if (abc->ptr[i].type == "alpha")
                                    {
                                        Scores += (10 * level);
                                    }
                                    if (abc->ptr[i].type == "beta")
                                    {
                                        Scores += (20 * level);
                                    }
                                    if (abc->ptr[i].type == "gamma")
                                    {
                                        Scores += (30 * level);
                                    }
                                }
                                if (invaders_bullet_collide && p->b1->type != "fire")
                                {
                                    p->delete_chain(j);
                                    invaders_bullet_collide = 0;
                                }
                            }
                        }
                        if (abc != nullptr && p->b2 != nullptr)
                        {
                            for (int j = 0; j < p->b2_size; j++)
                            {
                                invaders_bullet_collide = collision1_2(i, j);
                                if (invaders_bullet_collide)
                                {
                                    abc->ptr[i].check = 0;
                                    if (abc->ptr[i].type == "alpha")
                                    {
                                        Scores += (10 * level);
                                    }
                                    if (abc->ptr[i].type == "beta")
                                    {
                                        Scores += (20 * level);
                                    }
                                    if (abc->ptr[i].type == "gamma")
                                    {
                                        Scores += (30 * level);
                                    }
                                }
                                if (invaders_bullet_collide && p->b2->type != "fire")
                                {
                                    //  p->delete_chain(j);
                                    invaders_bullet_collide = 0;
                                }
                            }
                        }
                        if (abc != nullptr && p->b3 != nullptr)
                        {
                            for (int j = 0; j < p->b3_size; j++)
                            {
                                invaders_bullet_collide = collision1_3(i, j);
                                if (invaders_bullet_collide)
                                {
                                    abc->ptr[i].check = 0;
                                    if (abc->ptr[i].type == "alpha")
                                    {
                                        Scores += (10 * level);
                                    }
                                    if (abc->ptr[i].type == "beta")
                                    {
                                        Scores += (20 * level);
                                    }
                                    if (abc->ptr[i].type == "gamma")
                                    {
                                        Scores += (30 * level);
                                    }
                                }
                                if (invaders_bullet_collide && p->b3->type != "fire")
                                { // p->delete_chain(j);
                                    invaders_bullet_collide = 0;
                                }
                            }
                        }
                        if (abc != nullptr && p->b4 != nullptr)
                        {
                            for (int j = 0; j < p->b4_size; j++)
                            {
                                invaders_bullet_collide = collision1_4(i, j);
                                if (invaders_bullet_collide)
                                {
                                    abc->ptr[i].check = 0;
                                    if (abc->ptr[i].type == "alpha")
                                    {
                                        Scores += (10 * level);
                                    }
                                    if (abc->ptr[i].type == "beta")
                                    {
                                        Scores += (20 * level);
                                    }
                                    if (abc->ptr[i].type == "gamma")
                                    {
                                        Scores += (30 * level);
                                    }
                                }
                                if (invaders_bullet_collide && p->b4->type != "fire")
                                { // p->delete_chain(j);
                                    invaders_bullet_collide = 0;
                                }
                            }
                        }
                        if (abc != nullptr && p->b5 != nullptr)
                        {
                            for (int j = 0; j < p->b5_size; j++)
                            {
                                invaders_bullet_collide = collision1_5(i, j);
                                if (invaders_bullet_collide)
                                {
                                    abc->ptr[i].check = 0;
                                    if (abc->ptr[i].type == "alpha")
                                    {
                                        Scores += (10 * level);
                                    }
                                    if (abc->ptr[i].type == "beta")
                                    {
                                        Scores += (20 * level);
                                    }
                                    if (abc->ptr[i].type == "gamma")
                                    {
                                        Scores += (30 * level);
                                    }
                                }
                                if (invaders_bullet_collide && p->b5->type != "fire")
                                { // p->delete_chain(j);
                                    invaders_bullet_collide = 0;
                                }
                            }
                        }
                        if (abc != nullptr && p->b6 != nullptr)
                        {
                            for (int j = 0; j < p->b6_size; j++)
                            {
                                invaders_bullet_collide = collision1_6(i, j);
                                if (invaders_bullet_collide)
                                {
                                    abc->ptr[i].check = 0;
                                    if (abc->ptr[i].type == "alpha")
                                    {
                                        Scores += (10 * level);
                                    }
                                    if (abc->ptr[i].type == "beta")
                                    {
                                        Scores += (20 * level);
                                    }
                                    if (abc->ptr[i].type == "gamma")
                                    {
                                        Scores += (30 * level);
                                    }
                                }
                                if (invaders_bullet_collide && p->b6->type != "fire")
                                { // p->delete_chain(j);
                                    invaders_bullet_collide = 0;
                                }
                            }
                        }
                        if (abc != nullptr && p->b7 != nullptr)
                        {
                            for (int j = 0; j < p->b7_size; j++)
                            {
                                invaders_bullet_collide = collision1_7(i, j);
                                if (invaders_bullet_collide)
                                {
                                    abc->ptr[i].check = 0;
                                    if (abc->ptr[i].type == "alpha")
                                    {
                                        Scores += (10 * level);
                                    }
                                    if (abc->ptr[i].type == "beta")
                                    {
                                        Scores += (20 * level);
                                    }
                                    if (abc->ptr[i].type == "gamma")
                                    {
                                        Scores += (30 * level);
                                    }
                                }
                                if (invaders_bullet_collide && p->b7->type != "fire")
                                { // p->delete_chain(j);
                                    invaders_bullet_collide = 0;
                                }
                            }
                        }
                    }
                }
                int just_kidding = 0;
                for (int i = 0; i < abc->size_of_enemies; i++)
                {
                    if (abc->ptr[i].check == 0)
                    {
                        just_kidding++;
                    }
                }
                if (just_kidding == abc->size_of_enemies)
                {
                    if (abc->b1 != nullptr)
                        for (int i = 0; i < abc->size_of_enemies; i++)
                        {
                            delete abc->ptr[i].b1;
                        }
                    if (abc->size_of_enemies > 1)
                        delete[] abc->ptr;
                    abc->ptr = nullptr;
                    delete abc;
                    abc = nullptr;
                    abc = random_constructor(10);
                    abc->display(level);
                    alp++;
                }
            }
            bool zzzz = 0;
            ////////////////////////////////////////MONSTER     display////////////////////////////////////////////
            if (en != nullptr)
            {
                en->speeds(level);
                if ((en->type_of_enemy == "monster"))
                {
                    bomb_collide = collision3();
                    if ((timer - time_check_monster) <= 10)
                    {
                        window.draw(en->sprite);
                        en->move();

                        if (ver) // fire....
                        {
                            if (bomb_Delay.getElapsedTime().asMilliseconds() >= 100)
                            {
                                en->fire();
                                bomb_Delay.restart();
                            }
                        }
                        if (en->light != nullptr)
                        {
                            for (int i = 0; i < en->lsize; i++)
                            {
                                window.draw(en->light[i].sprite);
                                en->light[i].move(level);
                            }
                            if (en->light[en->lsize - 1].top() > 800)
                            {
                                if ((en->lsize) > 1)
                                {
                                    delete[] en->light;
                                    en->lsize = 0;
                                    en->light = nullptr;
                                } // en->lsize=0;
                            }
                        }
                    }
                    else // destructor
                    {
                        en->type_of_enemy = " ";
                        delete en;
                        en = nullptr;
                        time_randomizer = timer;
                        Scores += 40;
                        enemy_arrive=0;
                    }
                }
            }
            //////////////////////////////        DRAGON  display ////////////////
            if (en != nullptr)
            {
                en->speeds(level);
                if ((en->type_of_enemy == "dragon"))
                {
                    
                    if ((timer - time_check_monster) <= 5)
                    {
                        window.draw(en->sprite);
                        // bombs
                        if (ver) // fire
                        {
                            if (bomb_Delay.getElapsedTime().asMilliseconds() >= 150)
                            {
                                if (bomb_direction)
                                {
                                    if (p->x > 810)
                                        dragon_bomb_check = 1;
                                    else if (p->sprite.getPosition().x < 510)
                                        dragon_bomb_check = -1;
                                else
                                    dragon_bomb_check = 0;
                                    bomb_direction = 0;
                                }
                                en->fire(dragon_bomb_check);
                                bomb_Delay.restart();
                            }
                        }
                        else
                        {
                            bomb_direction = 1;
                        }
                        if (dragon_bomb_check == 0)
                        {   bomb_collide = collision3();
                            if (en->light != nullptr)
                            {
                                for (int i = 0; i < en->lsize; i++)
                                {
                                    window.draw(en->light[i].sprite);
                                    en->light[i].move_dragon(level, dragon_bomb_check);
                                }
                                if (en->light[en->lsize - 1].bottom() > 800)
                                {
                                    if (en->lsize > 1)
                                    {
                                        delete[] en->light;
                                        en->lsize = 0;
                                        en->light = nullptr;
                                    }
                                    else
                                        free(en->light);
                                }
                            }
                        }
                        else if (dragon_bomb_check == 1) // right
                        {     bomb_collide = collision3_right();
                            if (en->light_right != nullptr)
                            {
                                for (int i = 0; i < en->right_size; i++)
                                {
                                    window.draw(en->light_right[i].sprite);
                                    en->light_right[i].move_dragon(level, dragon_bomb_check);
                                }
                                if (en->light_right[en->right_size - 1].bottom() > 800)
                                {
                                    if (en->right_size > 1)
                                    {
                                        delete[] en->light_right;
                                        en->right_size = 0;
                                        en->light_right = nullptr;
                                    }
                                    else
                                        free(en->light_right);
                                }
                            }
                        }
                        else if (dragon_bomb_check == -1) // left
                        {   bomb_collide = collision3_left();
                            if (en->light_left != nullptr)
                            {
                                for (int i = 0; i < en->left_size; i++)
                                {
                                    window.draw(en->light_left[i].sprite);
                                    en->light_left[i].move_dragon(level, dragon_bomb_check);
                                }
                                if (en->light_left[en->left_size - 1].bottom() > 800)
                                {
                                    if (en->left_size > 1)
                                    {
                                        delete[] en->light_left;
                                        en->left_size = 0;
                                        en->light_left = nullptr;
                                    }
                                    else
                                        free(en->light_left);
                                }
                            }
                        }
                    }
                    else // destructor
                    {
                        if (en->light != nullptr && en->lsize > 1)
                        {
                            delete[] en->light;
                            en->light = nullptr;
                        }
                        en->light = nullptr;
                        if (en->light_left != nullptr && en->left_size > 1)
                        {
                            delete[] en->light_left;
                            en->light_left = nullptr;
                        }
                        en->light_left = nullptr;
                        if (en->light_right != nullptr && en->right_size > 1)
                        {
                            delete[] en->light_right;
                            en->light_right = nullptr;
                        }
                        en->light_right = nullptr;

                        en->type_of_enemy = " ";
                        delete en;
                        en = nullptr;
                        time_randomizer = timer;
                        Scores += 50;
                        allow_dragon = 0;
                        enemy_arrive=0;
                    }
                }
            }
            std::string myString = std::to_string(Scores);
            std::string myString2 = std::to_string(level);
            ////////////////////////////////////////COLLISION WITH ENEMIES////////////////////////////////////////////
                if (enemy_collide || bomb_collide)
                {
                    // destroy spaceship;  //shield effect needs to be added here..
                    if (shield != true)
                    {
                        p->destroy_ship(&window);
                        lives--;
                        p->x = 520;
                        p->y = 680;
                        shield = 1;
                        addone_timer = timer;
                        p->sprite.setPosition(520, 680);
                    }
                    enemy_collide = 0;
                    bomb_collide = 0;
                }

{ if(bonus[0].right()<=bonus[1].sprite.getPosition().x)
{
    bonus[0].sprite.move(1,0);
    bonus[1].sprite.move(-1,0);
    window.draw(bonus[0].sprite);
    window.draw(bonus[1].sprite);
}}
            if (shield)
            window.draw(shields_image);
            texts.setString(myString);
            lvls.setString(myString2);
            window.draw(text);
            window.draw(texts);
            window.draw(lvl);
            window.draw(lvls);
            window.display(); // Displying all the sprites
        }
    }
    ~Game()
    {
        if (en != nullptr)
            delete en;
            delete p;
        if (abc != nullptr)
        {
            if (abc->b1 != nullptr)
                for (int i = 0; i < abc->size_of_enemies; i++)
                {
                    delete abc->ptr[i].b1;
                }
            if (abc->size_of_enemies > 1)
                delete[] abc->ptr;
            abc->ptr = nullptr;
            delete abc;
            abc = nullptr;
        }
        if (a != nullptr)
            delete a;
    }
};
