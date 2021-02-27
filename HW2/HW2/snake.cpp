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
	if (snakeBody->GetPosition().x > targetBody->GetPosition().x - BOUNDS-2 && snakeBody->GetPosition().x < targetBody->GetPosition().x + BOUNDS +2)
	{
		if (snakeBody->GetPosition().y > targetBody->GetPosition().y - BOUNDS -2&& snakeBody->GetPosition().y < targetBody->GetPosition().y + BOUNDS+2)
		{
			moveTarget(target.position.x, target.position.y);
			targetsHit++;
		}
	}
}

//displays position of target/player
void display()
{
	cout << "Player is at X:" << snakeBody->GetPosition().x << " Y: " << snakeBody->GetPosition().y-1 << "  |  ";
	cout << "Target is at X:" << targetBody-> GetPosition().x << " Y: " << targetBody->GetPosition().y << endl;
}

//reads key presses and applies forces onto player
//use ApplyForceToCenter to add force to snake
//you will not be moving snake directly
void applyForces()
{
	if (key == 119)
	{
		snakeBody->ApplyForceToCenter(b2Vec2(0,20000.0f),false);
	}
	if (key == 97)
	{
		snakeBody->ApplyForceToCenter(b2Vec2(-2000.0f, 0.0f), false);
	}
	if (key == 115)
	{
		snakeBody->ApplyForceToCenter(b2Vec2(0, -100.0f), false);
	}
	if (key == 100)
	{
		snakeBody->ApplyForceToCenter(b2Vec2(2000.0f, 0.0f), false);
	}
	
}

//moves target to new pos
//x/y range within +/- 5.0
void moveTarget(float& xpos, float& ypos)
{
	cout << "Target hit!" << endl;
	world.DestroyBody(targetBody);
	targetBody = nullptr;
	xpos = (rand() / (RAND_MAX / 10.0f)) - 5.0f;
	ypos = (rand() / (RAND_MAX / 10.0f)); // Can't have targets underneath floor!
	target.position.Set(xpos, ypos);
	targetBody = world.CreateBody(&target);
	b2PolygonShape targetShape;
	targetShape.SetAsBox(1.0f, 1.0f);
	targetBody->CreateFixture(&targetShape, 0.0f);

}


