#include "snake.h";

b2BodyDef groundBodyDef;
b2BodyDef playerSnake;
b2BodyDef target;
b2Vec2 gravity(0.0f, -9.8f);
b2World world(gravity);
int targetsHit = 0;
int key;
b2Body* snakeBody;
b2Body* targetBody;
const float BOUNDS = .2;

// updates physics world
// doesnt move snake, updates box2d
void update()
{
	world.Step((1.0 / 60.0), 6, 2);
	if (snakeBody->GetPosition().x > targetBody->GetPosition().x - BOUNDS && snakeBody->GetPosition().x < targetBody->GetPosition().x + BOUNDS)
	{
		if (snakeBody->GetPosition().y > targetBody->GetPosition().y - BOUNDS && snakeBody->GetPosition().y < targetBody->GetPosition().y + BOUNDS)
		{
			moveTarget(target.position.x, target.position.y);
			targetsHit++;
		}
	}
}

//displays position of target/player
void display()
{
	cout << "Player is at X:" << snakeBody->GetPosition().x << " Y: " << snakeBody->GetPosition().y << "  |  ";
	cout << "Target is at X:" << targetBody-> GetPosition().x << " Y: " << targetBody->GetPosition().y << endl;
}

//reads key presses and applies forces onto player
//use ApplyForceToCenter to add force to snake
//you will not be moving snake directly
void applyForces()
{
	if (key == 119)
	{
		snakeBody->ApplyForceToCenter(b2Vec2(0,200.0f),false);
	}
	if (key == 97)
	{
		snakeBody->ApplyForceToCenter(b2Vec2(-200.0f, 0.0f), false);
	}
	if (key == 115)
	{
		snakeBody->ApplyForceToCenter(b2Vec2(0, -100.0f), false);
	}
	if (key == 100)
	{
		snakeBody->ApplyForceToCenter(b2Vec2(200.0f, 0.0f), false);
	}
	
}

//moves target to new pos
//x/y range within +/- 5.0
void moveTarget(float& xpos, float& ypos)
{
	world.DestroyBody(targetBody);
	targetBody = nullptr;

	target.position.Set(0, 3.0);
	xpos = 0;
	ypos = 3.0;

	//xpos = rand() / RAND_MAX * 10.0f - 5.0f;
	//ypos = rand() / RAND_MAX * 10.0f - 5.0f;
}


//introduce game
//create physics world (box2d)
//create snake (physics body b2body)
//create while loop to keep running until user hits ESC or total # of targets
//	inside while loop check if keypress (kbhit)
//	if keypress then applyForces()
//physcis world will auto update snake based on gravity/ other forces
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
	playerSnake.position.Set(0.0f, 10);
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
	//target.position.Set((rand() / (RAND_MAX/10.0f))-5.0f, (rand() / (RAND_MAX / 10.0f)) - 5.0f);
	target.position.Set(0.0f, 5.0f);
	targetBody = world.CreateBody(&target);
	b2PolygonShape targetShape;
	targetShape.SetAsBox(1.0f, 1.0f);
	targetBody->CreateFixture(&targetShape, 0.0f);

	while (targetsHit < 2) {
		// Exits while loop if Esc is hit
		if (_kbhit()) {
			key = _getch();
			if (key == 27) {
				break;
			}
			else
			{
				applyForces();
			}
		}
		update();
		display();
	}
	return 0;

}
