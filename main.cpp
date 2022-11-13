#include <iostream>
#include <string>
#include <random>
#include <vector>
#include <SFML/Graphics.hpp>

int tileWidth = 32;
int tileHeight = 32;
int windowWidth = (tileWidth * 15);
int windowHeight = (tileHeight * 15);

class RainDrop
{
private:
    sf::RectangleShape shape;
    float x = 0, y = 0, z = rand() % 20 * -1;
    float velX = 0, velY = 0;
public:
    void init(float x, float y)
    {
        this->x = x;
        this->y = y;
        velX = 0.0f;
        velY = rand() % 10 + 11;
        if(z >= -19)
        {
            shape.setFillColor(sf::Color(100.f, 42.f, 141.f, 205.f));
            shape.setSize(sf::Vector2f(2, 10));
        }
        else if (z >= -16)
        {
            shape.setFillColor(sf::Color(115.f, 81.f, 181.f, 215.f));
            shape.setSize(sf::Vector2f(2, 13));
        }
        else if (z >= -12)
        {
            shape.setFillColor(sf::Color(112.f, 81.f, 185.f, 235.f));
            shape.setSize(sf::Vector2f(2, 19));
        }
        else if (z >= -8)
        {
            shape.setFillColor(sf::Color(112.f, 85.f, 203.f, 245.f));
            shape.setSize(sf::Vector2f(2, 21));
        }
        else if (z >= -4)
        {
            shape.setFillColor(sf::Color(104.f, 97.f, 255.f, 250.f));
            shape.setSize(sf::Vector2f(2, 23));
        }
        else if (z >= 0)
        {
            shape.setFillColor(sf::Color(104.f, 113.f, 255.f, 255.f));
            shape.setSize(sf::Vector2f(2, 26));
        }
    }

    void render(sf::RenderTarget& target)
    {
        target.draw(shape);
    }

    void update()
    {
        x += velX;
        y += velY;
        if (y >= windowHeight)
        {
            y = rand() % 92 * -1;
        }
        shape.setPosition(x, y);
    }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "SFML Rain");
    window.setFramerateLimit(60);

    std::vector<RainDrop> drops;
    for (int i = 0; i < 300; i++)
    {
        RainDrop rd;
        rd.init(rand() % windowWidth, rand() % 272 * -1) ;
        drops.push_back(rd);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        for (auto& d : drops)
        {
            d.update();
        }

        window.clear(sf::Color(121, 121, 121));
        for (auto& d : drops)
        {
            d.render(window);
        }
        window.display();
    }

    return 0;
}
