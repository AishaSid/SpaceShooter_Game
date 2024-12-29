#include "game.h"
#include "Score.h"
class Menu
{
public:
    // add menu attributes here
    Sprite background;
    Texture bg_texture;
    Menu()
    {
        bg_texture.loadFromFile("img/menu2.png");
        background.setTexture(bg_texture);
        background.setScale(1, 1);
    }

    void display_menu()
    {   bool restart=0;
        Game g,h;
        Score score_class;
        string st;
        cout << endl;
        cout << endl;
        cout << "             Hi!! Welcome to the Game.....                        " << endl
             << endl;
        cout << "               ENTER YOUR USER NAME !!!!            " << endl;
        cout << "                  ";
        cin >> st;
        cout << "                " << endl
             << endl;

        RenderWindow window(VideoMode(650, 550), "AISHA SIDDIQA");

        while (window.isOpen())
        {
            Event e;
            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed)
                    window.close();
            }
            if (Keyboard::isKeyPressed(Keyboard::RShift))
            {
                window.close();
                cout << "         Game in Progress...       " << endl;
                cout << st << " is playing game right now.              " << endl;
                g.start_game();
                score_class.record_Input(st, g.Scores);
                cout << "                " << endl;
                cout << st << " Game Ended              " << endl;
                cout << endl;
                window.create(VideoMode(650, 550), "AISHA SIDDIQA");
                restart = 1;
            }
            if(g.play==1 && restart)
            { 
                if (Keyboard::isKeyPressed(Keyboard::Enter))
                {  g.play = 0;
                   restart =0;
                    h.start_game(); score_class.record_Input(st, h.Scores);
                window.close();
                cout << st << " Game Ended              " << endl;
                cout << endl;
                window.create(VideoMode(650, 550), title);}
               
            }
            if (Keyboard::isKeyPressed(Keyboard::I))
            {
                bg_texture.loadFromFile("img/inst2.png");
                background.setScale(1.1, 1.1);
            }
            if (Keyboard::isKeyPressed(Keyboard::BackSpace))
            {
                bg_texture.loadFromFile("img/menu2.png");
                background.setScale(1, 1);
            }
            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                window.close();
            }
            if (Keyboard::isKeyPressed(Keyboard::S))
            {
                score_class.storedata();
                score_class.rearrange_data();
                score_class.display(&window);
            }
            window.clear(Color::Black);
            window.draw(background);

            window.display(); // Displying all the sprites
        }
    }
};
