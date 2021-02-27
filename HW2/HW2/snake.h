#pragma once
#include <iostream>
#include "Box2D.h";
#include <conio.h>
using namespace std;
extern b2BodyDef groundBodyDef;
extern b2BodyDef playerSnake;
extern b2BodyDef target;
extern b2Vec2 gravity;
extern b2World world;
extern int targetsHit;
extern int key;
extern b2Body* snakeBody;
extern b2Body* targetBody;

void update();

void display();


void applyForces();

void moveTarget(float& xpos, float& ypos);

int main();
