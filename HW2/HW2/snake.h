#pragma once
#define SFML_STATIC

#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
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
extern int maxTargets;
extern bool isRunning;
void processInput();

void ApplyForceUp(b2Body* player);
void ApplyForceDown(b2Body* player);
void ApplyForceRight(b2Body* player);
void ApplyForceLeft(b2Body* player);

void StopMoving(b2Body* player);

void ReverseGravity(b2World& world);

void SetupTargets(int cnt);

bool SelectNextTarget();

void update();

void display();

void applyForces();

void moveTarget(float& xpos, float& ypos);

int main();
