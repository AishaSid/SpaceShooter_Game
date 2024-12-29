#include <iostream>
#include <SFML/Graphics.hpp>
#include <string.h>
using namespace sf;
#include <fstream>
using namespace std;

class Score
{
public:
    struct data
    {
    public:
        string name;
        string badge;
        int score;
        string sco;
        data *link;
    };
    string fileName;
    data *start;
    fstream file;
    Score()
    {
        start = nullptr;
        fileName = "ScoreFile.txt";
    }
    void storedata()
    {
        start = nullptr;
        data *temp = nullptr;
        file.open("ScoreFile.txt", ios::in);
        if (file.is_open())
        {
            std::string line;
            int a = 1;
            while (std::getline(file, line))
            {
                if (a % 3 == 1)
                {
                    data *new_node = new data;
                    new_node->name = line;
                    new_node->badge = "";
                    new_node->sco = "";
                    new_node->link = nullptr;
                    if (start == nullptr)
                    {
                        start = new_node;
                        temp = start;
                    }
                    else
                    {
                        temp->link = new_node;
                        temp = temp->link;
                    }
                }
                else if (a % 3 == 2)
                {
                    temp->badge = line;
                }
                else
                {
                    temp->sco = line;
                    temp->score = stoi(line);
                }
                a++;
            }
            file.close();
            if (temp != nullptr)
            {
                temp->link = nullptr;
            }
        }
        temp = start;
        file.open(fileName, ios::out);
        while (temp != nullptr)
        {
            file << temp->name << endl;
            file << temp->badge << endl;
            file << temp->sco << endl;
            temp = temp->link;
        }
        file.close();
    }
    void record_Input(string a, int ss)
    {
        data *abc = new data;
        abc->score = ss;
        abc->link = NULL;
        data *temp = start;
        abc->name = a;
        file.open(fileName, ios::app);
        file << abc->name << endl;
        file << abc->badge << endl;
        std::string myString = std::to_string(ss);
        abc->sco = myString;
        file << myString << endl;
        file.close();
        if (start == nullptr)
        {
            start = abc;
            return;
        }
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = abc;
    }
    void rearrange_data()
    {
        {
            data *temp1 = start;
            data *temp2 = start->link;
            data temp3[1];
            temp3->link = NULL;
            while (temp1 != NULL)
            {
                temp2 = temp1->link;
                while (temp2 != NULL)
                {
                    if ((temp1->score) < (temp2->score))
                    {
                        temp3->name = temp1->name;
                        temp3->score = temp1->score;
                        temp3->badge = temp1->badge;
                        temp1->name = temp2->name;
                        temp1->score = temp2->score;
                        temp1->badge = temp2->badge;
                        temp2->name = temp3->name;
                        temp2->score = temp3->score;
                        temp2->badge = temp2->badge;
                    }
                    temp2 = temp2->link;
                }
                temp1 = temp1->link;
            }
            if (start != nullptr)
                start->badge = "1";
            if (start->link != nullptr)
                start->link->badge = "2";
            if (start->link->link != nullptr)
                start->link->link->badge = "3";
            temp1 = start;
        }
    }
    void display(RenderWindow *window)
    {
        Sprite background;
        Texture bg_texture;
        bg_texture.loadFromFile("img/badges.png");
        background.setTexture(bg_texture);
        background.setScale(0.805, 0.901);

        data *temp1 = start;
        sf::Text text;
        sf::Font font;
        font.loadFromFile("scorefont.ttf");
        text.setFont(font);
        text.setString("SCORES");
        text.setCharacterSize(33);
        text.setFillColor(sf::Color::Black);
        text.setPosition(270, 30);
        int i = 0;
        while (temp1 != nullptr)
        {
            i++;
            temp1 = temp1->link;
        }
        sf::Text abc[i], def[i], ghi[i];
        temp1 = start;
        for (int j = 0; j < i, j < 3; j++)
        {
            abc[j].setFont(font);
            abc[j].setCharacterSize(26);
            abc[j].setFillColor(sf::Color::Black);
            abc[j].setString(temp1->name);
            abc[j].setPosition(50 + (j * 230), 85);
            def[j].setFont(font);
            def[j].setCharacterSize(31);
            def[j].setString(temp1->badge);
            def[j].setFillColor(sf::Color::Black);
            def[j].setPosition((j * 210) + 100, 257);
            ghi[j].setFont(font);
            ghi[j].setCharacterSize(26);
            ghi[j].setString(temp1->sco);
            ghi[j].setFillColor(sf::Color::Black);
            ghi[j].setPosition(70 + (230 * j), 410);
            temp1 = temp1->link;
        }
        temp1 = start;
        file.open(fileName, ios::out);
        while (temp1 != NULL)
        {
            file << temp1->name << endl;
            file << temp1->badge << endl;
            file << temp1->score << endl;
            temp1 = temp1->link;
        }
        file.close();
        bool press_back = 1;

        while (press_back && (*window).isOpen())
        {
            Event e;
            while ((*window).pollEvent(e))
            {
                if (e.type == Event::Closed)
                    (*window).close();
            }
            if (Keyboard::isKeyPressed(Keyboard::BackSpace))
            {
                press_back = 0;
            }
            (*window).clear(Color::Black);
            (*window).draw(background);
            for (int j = 0; j < i, j < 5; j++)
            {
                (*window).draw(abc[j]);
                (*window).draw(def[j]);
                (*window).draw(ghi[j]);
            }
            (*window).draw(text);
            (*window).display();
        }
    }
    ~Score()
    {
        data *temp1 = start;
        data *temp2;
        while (temp1 != NULL)
        {
            temp2 = temp1->link;
            free(temp1);
            temp1 = temp2;
        }
        start = nullptr;
    }
};
