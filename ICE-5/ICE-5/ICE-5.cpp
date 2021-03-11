// ICE-5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define SFML_STATIC

#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    sf::CircleShape myCircle(40.f);
    sf::RectangleShape myRect(sf::Vector2f(100,125));
    myRect.setOrigin(50, 163);
    myRect.setPosition(300.f, 200.f);
    sf::ConvexShape weirdShape;
    weirdShape.setPointCount(5);
    weirdShape.setPoint(0, sf::Vector2f(11.f, 30.f));
    weirdShape.setPoint(1, sf::Vector2f(61.f, 39.f));
    weirdShape.setPoint(2, sf::Vector2f(121.f, 310.f));
    weirdShape.setPoint(3, sf::Vector2f(41.f, 130.f));
    weirdShape.setPoint(4, sf::Vector2f(11.f, 0.f));
    weirdShape.setPosition(500.f, 400.f);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);
        window.draw(myCircle);
        window.draw(myRect);
        window.draw(weirdShape);
        // end the current frame
        window.display();
    }

    return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
