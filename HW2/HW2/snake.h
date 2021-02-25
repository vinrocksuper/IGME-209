#pragma once
#include <iostream>
#include "Box2D.h";
#include <conio.h>
using namespace std;

void update();

void display();


void applyForces();

void moveTarget(float& xpos, float& ypos);

int main();
