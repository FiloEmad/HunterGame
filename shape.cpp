#include "shape.h"
#include "game.h"
#include "gameConfig.h"
#include<iostream>
#include<fstream>
using namespace std;

shape::shape(game* r_pGame, point ref)
{
	RefPoint = ref;
	pGame = r_pGame;
	fillColor = config.fillColor;
	borderColor = config.penColor;
}

void shape::setRefPoint(point p)
{
	RefPoint = p;
}
point shape::getRefPoint() const
{
	return RefPoint;
}

void shape::setparamaters(int n_k, double n_th)
{
	k = n_k; theta = n_th;
}

void shape::Getters(int& s, int& t, point& p)
{
	s = k; t = theta; p = RefPoint;
}

void shape::save()
{
	fstream frogress("prog.txt", ios::app);

	if (!frogress) {
	}
	else {
		frogress << k << " " << theta << " " << RefPoint.x << " " << RefPoint.y << " " << type << endl;
	}

}

ShapeType shape::getType()
{
	return type;
}

bool shape::operator==(const shape& other) const
{
	//cout << k << " " << theta << " " << RefPoint.x << " " << RefPoint.y << " " << type << endl;
	//cout << other.k << " " << other.theta << " " << other.RefPoint.x << " " << other.RefPoint.y << other.type << endl;
	if (other.k == k && other.theta == theta && other.RefPoint.x == RefPoint.x && other.RefPoint.y == RefPoint.y && other.type == type)
	{
		return true;
	}
	else
	{
		return false;
	}
}



