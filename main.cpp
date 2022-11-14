#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

int windowWidth = (64 * 15);
int windowHeight = (64 * 15);

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
            velY = rand() % 3 + 5;
        }
        else if (z >= -16)
        {
            shape.setFillColor(sf::Color(115.f, 81.f, 181.f, 215.f));
            shape.setSize(sf::Vector2f(2, 13));
            velY = rand() % 5 + 5;
        }
        else if (z >= -12)
        {
            shape.setFillColor(sf::Color(112.f, 81.f, 185.f, 235.f));
            shape.setSize(sf::Vector2f(3, 19));
            velY = rand() % 9 + 9;
        }
        else if (z >= -8)
        {
            shape.setFillColor(sf::Color(112.f, 85.f, 203.f, 245.f));
            shape.setSize(sf::Vector2f(4, 21));
            velY = rand() % 8 + 11;
        }
        else if (z >= -4)
        {
            shape.setFillColor(sf::Color(104.f, 97.f, 255.f, 250.f));
            shape.setSize(sf::Vector2f(5, 23));
            velY = rand() % 9 + 11;
        }
        else if (z >= 0)
        {
            shape.setFillColor(sf::Color(104.f, 113.f, 255.f, 255.f));
            shape.setSize(sf::Vector2f(6, 26));
            velY = rand() % 10 + 11;
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
        if (x < 0)
        {
            x = rand() % windowWidth;
        }
        shape.setPosition(x, y);
    }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "SFML Rain", sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(55);

    std::vector<RainDrop> drops;
    for (int i = 0; i < 600; i++)
    {
        RainDrop rd;
        rd.init(rand() % windowWidth, rand() % 762 * -1) ;
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
