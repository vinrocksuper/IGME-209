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
int maxTargets;


b2Vec2* TargetLocations; // ptr array
//b2Vec2 TargetLocationsArr[];
b2Vec2* currentLocation;


typedef void (*inputFunction)(b2Body*);

// Milestone 2 Methods below

//sets function pointer and then at end of func calls those pointer functions
void processInput()
{
	inputFunction inFun = nullptr;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		inFun = ApplyForceUp;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		inFun = ApplyForceLeft;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		inFun = ApplyForceDown;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		inFun = ApplyForceRight;
	}
	inFun(snakeBody);
}


//Applies force to player in cardinal directions using WASD
void ApplyForceUp(b2Body* player)
{
	player->ApplyForceToCenter(b2Vec2(2000.0f, 0.0f), false);
}
void ApplyForceDown(b2Body* player)
{
	player->ApplyForceToCenter(b2Vec2(-1000.0f, 0.0f), false);
}
void ApplyForceLeft(b2Body* player)
{
	player->ApplyForceToCenter(b2Vec2(-2000.0f, 0.0f), false);
}
void ApplyForceRight(b2Body* player)
{
	player->ApplyForceToCenter(b2Vec2(2000.0f, 0.0f), false);
}


//Calls SetVelocity to stop all movement on player
void StopMoving(b2Body* player)
{
	player->SetLinearVelocity(b2Vec2(0,0));
}
// calls b2World SetGravity to reverse the gravity
void ReverseGravity(b2World& world)
{
	world.SetGravity(-gravity);
}

//prompts user for number of targets to use from 1 - 10. (Make sure to check if valid)
// creates arr of b2vec2 positions for target to move to (see global var)
// add one additional target at end of arr at pos (-1000,1000) to end the game
// when target is moved to (-1000,1000) you are done
void SetupTargets(int cnt)
{
	cout << "how many targets should I generate? (From 1-10)" << endl;
	cin >> cnt;
	while(cnt < 1 || cnt > 10)
	{
		cout << "that was an invalid number. Please enter an integer between 1 and 10" << endl;
		cin >> cnt;
	}
	maxTargets = cnt;
	TargetLocations = new b2Vec2[cnt+1];
	//TargetLocationsArr = new b2Vec2[cnt + 1];
	
		for (int i =0;i<cnt;i++)
		{
			TargetLocations[i] = b2Vec2((rand() / (RAND_MAX / 10.0f)) - 5.0f, (rand() / (RAND_MAX / 10.0f)));
		}
		TargetLocations[cnt] = b2Vec2(-1000, 1000);
	
}

// moves currentTarget pointer to next valid target.
// returns true if there are more targets, false otherwise
bool SelectNextTarget()
{
	currentLocation = &TargetLocations[++targetsHit];
	if(currentLocation == nullptr)
	{
		return false;
	}
	return true;
}

//int main <- this is in HW2.cpp not in snake.cpp
// make it call setupTarget()
// Add code from SFML to create window for display
// Add while loop from Windows PE to control display
// Draw snake pos using circle, target using square
// SFML coords different from Box2D, so need conversion.






// Milestone 1 Methods Below

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


