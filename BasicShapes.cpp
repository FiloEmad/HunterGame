#include "BasicShapes.h"
#include "gameConfig.h"
#include "game.h"
#include<iostream>
#include<algorithm>
using namespace std;

////////////////////////////////////////////////////  class Rect  ///////////////////////////////////////

Rect::Rect(game* r_pGame, point ref, int r_hght, int r_wdth) :shape(r_pGame, ref)
{
	pGame = r_pGame;
	hght = r_hght;
	wdth = r_wdth;
}

bool Rect::draw() const
{
	window* pW = pGame->getWind();	//get interface window
	pW->SetPen(fillColor, config.penWidth);
	pW->SetBrush(fillColor);
	point upperLeft, lowerBottom, upperRight, lowerLeft;
	upperLeft.x = 0 - (wdth * (1 + k / 10.0)) / 2; upperLeft.y = 0 - (hght * (1 + k / 10.0)) / 2;
	lowerBottom.x = 0 + (wdth * (1 + k / 10.0)) / 2; lowerBottom.y = 0 + (hght * (1 + k / 10.0)) / 2;
	lowerLeft.x = 0 - (wdth * (1 + k / 10.0)) / 2; lowerLeft.y = 0 + (hght * (1 + k / 10.0)) / 2;
	upperRight.x = 0 + (wdth * (1 + k / 10.0)) / 2; upperRight.y = 0 - (hght * (1 + k / 10.0)) / 2;
	point n_upperLeft, n_lowerBottom, n_upperRight, n_lowerLeft;
	n_upperLeft.x = upperLeft.x * cos(theta) - upperLeft.y * sin(theta) + RefPoint.x;
	n_lowerBottom.x = lowerBottom.x * cos(theta) - lowerBottom.y * sin(theta) + RefPoint.x;
	n_upperRight.x = upperRight.x * cos(theta) - upperRight.y * sin(theta) + RefPoint.x;
	n_lowerLeft.x = lowerLeft.x * cos(theta) - lowerLeft.y * sin(theta) + RefPoint.x;
	n_upperLeft.y = upperLeft.y * cos(theta) + upperLeft.x * sin(theta) + RefPoint.y;
	n_lowerBottom.y = lowerBottom.y * cos(theta) + lowerBottom.x * sin(theta) + RefPoint.y;
	n_upperRight.y = upperRight.y * cos(theta) + upperRight.x * sin(theta) + RefPoint.y;
	n_lowerLeft.y = lowerLeft.y * cos(theta) + lowerLeft.x * sin(theta) + RefPoint.y;
	int Arr_x[] = { (int)n_upperLeft.x, (int)n_lowerLeft.x, (int)n_lowerBottom.x, (int)n_upperRight.x, (int)n_upperLeft.x };
	int Arr_y[] = { (int)n_upperLeft.y, (int)n_lowerLeft.y, (int)n_lowerBottom.y, (int)n_upperRight.y, (int)n_upperLeft.y };
	int* max_x = max_element(Arr_x, Arr_x + 4);
	int* min_x = min_element(Arr_x, Arr_x + 4);
	int* max_y = max_element(Arr_y, Arr_y + 4);
	int* min_y = min_element(Arr_y, Arr_y + 4);
	if (*max_x < config.windWidth && *min_x>0 && *max_y < (config.remainingHeight + config.toolBarHeight) && *min_y>config.toolBarHeight)
	{
		pW->DrawPolygon(Arr_x, Arr_y, 5, FILLED);
		return true;
	}
	else
	{
		return false;
	}
}

void Rect::resize(int c)
{
	if (c == 1 && k<10)
	{
		k++;
	}
	if (c == 0 && k > -10)
	{
		k--;
	}
	draw();
}

void Rect::rotate(int c)
{
	if (c == 1)
	{
		theta += (22.0 / 56.0);
	}
	if (c == 0)
	{
		theta -= (22.0 / 56.0);
	}
	draw();
}

void Rect::move(int c) {
	draw();
}

bool Rect::checkbound()
{
	point upperLeft, lowerBottom, upperRight, lowerLeft;
	upperLeft.x = 0 - (wdth * (1 + k / 10.0)) / 2; upperLeft.y = 0 - (hght * (1 + k / 10.0)) / 2;
	lowerBottom.x = 0 + (wdth * (1 + k / 10.0)) / 2; lowerBottom.y = 0 + (hght * (1 + k / 10.0)) / 2;
	lowerLeft.x = 0 - (wdth * (1 + k / 10.0)) / 2; lowerLeft.y = 0 + (hght * (1 + k / 10.0)) / 2;
	upperRight.x = 0 + (wdth * (1 + k / 10.0)) / 2; upperRight.y = 0 - (hght * (1 + k / 10.0)) / 2;
	point n_upperLeft, n_lowerBottom, n_upperRight, n_lowerLeft;
	n_upperLeft.x = upperLeft.x * cos(theta) - upperLeft.y * sin(theta) + RefPoint.x;
	n_lowerBottom.x = lowerBottom.x * cos(theta) - lowerBottom.y * sin(theta) + RefPoint.x;
	n_upperRight.x = upperRight.x * cos(theta) - upperRight.y * sin(theta) + RefPoint.x;
	n_lowerLeft.x = lowerLeft.x * cos(theta) - lowerLeft.y * sin(theta) + RefPoint.x;
	n_upperLeft.y = upperLeft.y * cos(theta) + upperLeft.x * sin(theta) + RefPoint.y;
	n_lowerBottom.y = lowerBottom.y * cos(theta) + lowerBottom.x * sin(theta) + RefPoint.y;
	n_upperRight.y = upperRight.y * cos(theta) + upperRight.x * sin(theta) + RefPoint.y;
	n_lowerLeft.y = lowerLeft.y * cos(theta) + lowerLeft.x * sin(theta) + RefPoint.y;
	int Arr_x[] = { (int)n_upperLeft.x, (int)n_lowerLeft.x, (int)n_lowerBottom.x, (int)n_upperRight.x, (int)n_upperLeft.x };
	int Arr_y[] = { (int)n_upperLeft.y, (int)n_lowerLeft.y, (int)n_lowerBottom.y, (int)n_upperRight.y, (int)n_upperLeft.y };
	int* max_x = max_element(Arr_x, Arr_x + 4);
	int* min_x = min_element(Arr_x, Arr_x + 4);
	int* max_y = max_element(Arr_y, Arr_y + 4);
	int* min_y = min_element(Arr_y, Arr_y + 4);
	if (*max_x < config.windWidth && *min_x>0 && *max_y < (config.remainingHeight + config.toolBarHeight) && *min_y>config.toolBarHeight)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Rect::setColor(color c)
{
	fillColor = c;
}


////////////////////////////////////////////////////  class circle  ///////////////////////////////////////
//TODO: Add implementation for class circle here
circle::circle(game* r_pGame, point ref, int r) :shape(r_pGame, ref)
{
	rad = r;
}

bool circle::draw() const
{
	window* pW = pGame->getWind();	//get interface window
	pW->SetPen(fillColor, config.penWidth);
	pW->SetBrush(fillColor);
	int max_x = RefPoint.x + rad * (1 + k / 10.0);
	int max_y = RefPoint.y + rad * (1 + k / 10.0);
	int min_x = RefPoint.x - rad * (1 + k / 10.0);
	int min_y = RefPoint.y - rad * (1 + k / 10.0);
	pW->DrawCircle(RefPoint.x, RefPoint.y, rad * (1 + k / 10.0), FILLED);
	return true;
}

void circle::resize(int c)
{
	if (c == 1 && k < 10)
	{
		k++;
	}
	if (c == 0 && k > -10)
	{
		k--;
	}
	window* pW = pGame->getWind();	//get interface window
	pW->SetPen(borderColor, config.penWidth);
	pW->SetBrush(fillColor);
	pW->DrawCircle(RefPoint.x, RefPoint.y, rad * (1 + k / 10.0), FILLED);
}

void circle::rotate(int c) 
{
	window* pW = pGame->getWind();	//get interface window
	pW->SetPen(borderColor, config.penWidth);
	pW->SetBrush(fillColor);
	pW->DrawCircle(RefPoint.x, RefPoint.y, rad * (1 + k / 10.0), FILLED);
}

void circle::move(int c) {
	draw();
}

bool circle::checkbound()
{
	int max_x = RefPoint.x + rad * (1 + k / 10.0);
	int max_y = RefPoint.y + rad * (1 + k / 10.0);
	int min_x = RefPoint.x - rad * (1 + k / 10.0);
	int min_y = RefPoint.y - rad * (1 + k / 10.0);
	if (max_x < config.windWidth && min_x>0 && max_y < (config.remainingHeight + config.toolBarHeight) && min_y>config.toolBarHeight)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void circle::setColor(color c)
{
	fillColor = c;
}


////////////////////////////////////////////////////  class triangle  ///////////////////////////////////////
//TODO: Add implementation for class triangle here

////////////////////////////////////////////////////  class triangle  ///////////////////////////////////////

Triangle::Triangle(game* r_pGame, point ref, int s) :shape(r_pGame, ref), side(s) {}

bool Triangle::draw() const {
	window* pW = pGame->getWind();
	pW->SetPen(fillColor, config.penWidth);
	pW->SetBrush(fillColor);
	point v1, v2, v3;
	v1.x = 0; v1.y = 0 - (1.0 / (sqrt(3.0)) * (side * (1 + k / 10.0)));
	v2.x = 0 - (1.0 / 2.0) * (side * (1 + k / 10.0)); v2.y = 0 + ((sqrt(3.0) / 6.0) * (side * (1 + k / 10.0)));
	v3.x = 0 + (1.0 / 2.0) * (side * (1 + k / 10.0)); v3.y = 0 + ((sqrt(3.0) / 6.0) * (side * (1 + k / 10.0)));
	point n_v1, n_v2, n_v3;
	n_v1.x = v1.x * cos(theta) - v1.y * sin(theta) + RefPoint.x;
	n_v1.y = v1.y * cos(theta) + v1.x * sin(theta) + RefPoint.y;
	n_v2.x = v2.x * cos(theta) - v2.y * sin(theta) + RefPoint.x;
	n_v2.y = v2.y * cos(theta) + v2.x * sin(theta) + RefPoint.y;
	n_v3.x = v3.x * cos(theta) - v3.y * sin(theta) + RefPoint.x;
	n_v3.y = v3.y * cos(theta) + v3.x * sin(theta) + RefPoint.y;
	pW->DrawTriangle(n_v1.x, n_v1.y, n_v2.x, n_v2.y, n_v3.x, n_v3.y, FILLED);
	return true;

}

void Triangle::resize(int c)
{
	if (c == 1 && k < 10)
	{
		k++;
	}
	if (c == 0 && k > -10)
	{
		k--;
	}
	draw();
}

void Triangle::rotate(int c) 
{
	if (c == 1)
	{
		theta += (22.0 / 56.0);
	}
	if (c == 0)
	{
		theta -= (22.0 / 56.0);
	}
	draw();
}

void Triangle::move(int c) {
	draw();
}

bool Triangle::checkbound()
{
	point v1, v2, v3;
	v1.x = 0; v1.y = 0 - (1.0 / (sqrt(3.0)) * (side * (1 + k / 10.0)));
	v2.x = 0 - (1.0 / 2.0) * (side * (1 + k / 10.0)); v2.y = 0 + ((sqrt(3.0) / 6.0) * (side * (1 + k / 10.0)));
	v3.x = 0 + (1.0 / 2.0) * (side * (1 + k / 10.0)); v3.y = 0 + ((sqrt(3.0) / 6.0) * (side * (1 + k / 10.0)));
	point n_v1, n_v2, n_v3;
	n_v1.x = v1.x * cos(theta) - v1.y * sin(theta) + RefPoint.x;
	n_v1.y = v1.y * cos(theta) + v1.x * sin(theta) + RefPoint.y;
	n_v2.x = v2.x * cos(theta) - v2.y * sin(theta) + RefPoint.x;
	n_v2.y = v2.y * cos(theta) + v2.x * sin(theta) + RefPoint.y;
	n_v3.x = v3.x * cos(theta) - v3.y * sin(theta) + RefPoint.x;
	n_v3.y = v3.y * cos(theta) + v3.x * sin(theta) + RefPoint.y;
	double arr_x[] = { n_v1.x,n_v2.x,n_v3.x };
	double arr_y[] = { n_v1.y,n_v2.y,n_v3.y };
	double* max_x = max_element(arr_x, arr_x + 2);
	double* min_x = min_element(arr_x, arr_x + 2);
	double* max_y = max_element(arr_y, arr_y + 2);
	double* min_y = min_element(arr_y, arr_y + 2);

	if (*max_x < config.windWidth && *min_x>0 && *max_y < (config.remainingHeight + config.toolBarHeight) && *min_y>config.toolBarHeight)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Triangle::setColor(color c)
{
	fillColor = c;
}
