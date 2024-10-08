//Header file for Basic shapes in the game
#pragma once
#include "shape.h"

////////////////////////////////////////////////////  class Rect  ///////////////////////////////////////
//Rectanle class
/*							wdth
					---------------------
					|					|
			hght    |		 x			|     x is the reference point of the rectangle
					|					|
					--------------------
*/


class Rect:public shape
{
	int hght, wdth;	//height and width of the recangle

public:
	Rect(game* r_pGame, point ref, int r_hght, int r_wdth);
	virtual bool draw() const;
	virtual void resize(int c);
	virtual void rotate(int c) ;
	virtual void move(int c);
	virtual bool checkbound();
	virtual void setColor(color c);

};


////////////////////////////////////////////////////  class circle  ///////////////////////////////////////
//Reference point of the circle is its center
class circle :public shape
{
	//Add data memebrs for class circle
	int rad;
public:	
	circle(game* r_pGame, point ref, int r);	//add more parameters for the constructor if needed
	virtual bool draw() const;
	virtual void resize(int c) ;
	virtual void rotate(int c) ;
	virtual void move(int c);
	virtual bool checkbound();
	virtual void setColor(color c);
};

////////////////////////////////////////////////////  class Triangle  ///////////////////////////////////////
// Triangle class
class Triangle : public shape {
private:
	int side;
public:
	Triangle(game* r_pGame, point ref, int s);
	virtual bool draw() const;
	virtual void resize(int c);
	virtual void rotate(int c) ;
	virtual void move(int c);
	virtual bool checkbound();
	virtual void setColor(color c);

};