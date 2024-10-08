#pragma once
#include "Basicshapes.h"


////////////////////////////////////////////////////  class Sign  ///////////////////////////////////////
//This class reprsents the composite shape "sign"
//The sign is composed of 2 Recatngles
/*				

					 ------------------
					|				   |
					|		 x		   |     x is the reference point of the Sign shape
					|			       |
					 ------------------
						   |   |
						   |   |
						   | . |
						   |   |
						   |   |
							---
*/

//Note: sign reference point is the center point of the top rectangle
class Sign :public shape
{

	Rect* base;
	Rect* top;
public:
	Sign(game* r_pGame, point ref);
	virtual bool draw() const;
	virtual void resize(int c);	//Resize the shape
	virtual void rotate(int c) ;
    virtual void move(int c);
    virtual bool checkbound();
    virtual void setColor(color c);
};

class ChristmasTree : public shape
{
private:

    Triangle* base;
    Triangle* top;
    Triangle* topmost;
    Rect* trunk;
public:
    ChristmasTree(game* r_pGame, point ref);
    virtual bool draw() const;
    virtual void resize(int c);	//Resize the shape
    virtual void rotate(int c) ;
    virtual void move(int c);
    virtual bool checkbound();
    virtual void setColor(color c);

};

class Home : public shape {
private:

    Triangle* roof;
    Rect* baseSquare;
    Rect* chimeny;
    circle* top;
public:
    Home(game* r_pGame, point ref);
    virtual bool draw() const;
    virtual void resize(int c);	//Resize the shape
    virtual void rotate(int c) ;
    virtual void move(int c);
    virtual bool checkbound();
    virtual void setColor(color c);

};


class Hat : public shape {
private:

    Triangle* cone;
    circle* hat;
    Rect* buttom;
public:
    Hat(game* r_pGame, point ref);
    virtual bool draw() const;
    virtual void resize(int c);	//Resize the shape
    virtual void rotate(int c) ;
    virtual void move(int c);
    virtual bool checkbound();
    virtual void setColor(color c);

};

class Bullet : public shape {
private:

    Triangle* topTriangle;
    Rect* middleRect;
    circle* bottomSemiCircle;
public:
    Bullet(game* r_pGame, point ref);
    virtual bool draw() const;
    virtual void resize(int c);	//Resize the shape
    virtual void rotate(int c) ;
    virtual void move(int c);
    virtual bool checkbound();
    virtual void setColor(color c);

};




class lolypop : public shape {
private:

    circle* top;
    Rect* bottom;
public:
    lolypop(game* r_pGame, point ref);
    virtual bool draw() const;
    virtual void resize(int c);	//Resize the shape
    virtual void rotate(int c) ;
    virtual void move(int c);
    virtual bool checkbound();
    virtual void setColor(color c);

};

class Flag : public shape {
private:

    Triangle* top;
    Rect* rod;
public:
    Flag(game* r_pGame, point ref);
    virtual bool draw() const;
    virtual void resize(int c);	//Resize the shape
    virtual void rotate(int c) ;
    virtual void move(int c);
    virtual bool checkbound();
    virtual void setColor(color c);

};

