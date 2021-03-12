// HW2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "snake.h";


// int main <- this is in HW2.cpp not in snake.cpp
// make it call setupTarget()
// Add code from SFML to create window for display
// Add while loop from Windows PE to control display
// Draw snake pos using circle, target using square
// SFML coords different from Box2D, so need conversion.
//
int main()
{


	srand(time(0));
	cout << "Welcome to Gravity Snake!" << endl;
	cout << "Controls are simple, use WASD to apply a force to move your snake" << endl;
	cout << "Gravity will make your snake naturally fall, and your goal is to hit the target twice!" << endl;
	
	//Creates world
	groundBodyDef.position.Set(0.0f, -10.0f);
	b2PolygonShape groundBox;
	groundBox.SetAsBox(50.0f, 10.0f);
	b2Body* groundBody = world.CreateBody(&groundBodyDef);
	groundBody->CreateFixture(&groundBox, 0.0f);


	// Creates dynamic body (snake)
	playerSnake.type = b2_dynamicBody;
	playerSnake.position.Set(0.0f, 100);
	snakeBody = world.CreateBody(&playerSnake);
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1.0f, 1.0f);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	snakeBody->CreateFixture(&fixtureDef);

	// Creates target (static)
	target.type = b2_staticBody;
	//target.position.Set((rand() / (RAND_MAX/10.0f))-5.0f, (rand() / (RAND_MAX / 10.0f)));
	target.position.Set(0, 50);
	targetBody = world.CreateBody(&target);
	b2PolygonShape targetShape;
	targetShape.SetAsBox(1.0f, 1.0f);
	targetBody->CreateFixture(&targetShape, 0.0f);



	SetupTargets(0);
	
	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
	sf::CircleShape snakeCircle(40.f);
	sf::RectangleShape targetRect(sf::Vector2f(100, 125));

	snakeCircle.setPosition(300, 0);
	targetRect.setPosition(300, 500);
	isRunning = true;
	
	while (window.isOpen() && isRunning) {
		processInput();
		update();
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}
		snakeCircle.setPosition(snakeBody->GetPosition().x+300, 5.2*(-snakeBody->GetPosition().y+100));
		
		// clear the window with black color
		window.clear(sf::Color::Black);

		// draw everything here...
		// window.draw(...);
		window.draw(snakeCircle);
		//window.draw(targetRect); UNCOMMENT THIS LINE
		// end the current frame
		window.display();
		

		
		display();
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
