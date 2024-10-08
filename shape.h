#pragma once
#include <string>
using namespace std;
#include "CMUgraphicsLib\CMUgraphics.h"

class game;     //forward declaration

struct point
{
	double x, y;
};

enum ShapeType
{
	//Basic shapes
	RCT,	//rectangle
	CRC,	//circle
	TRI,	//triangle

	//Composite shapes
	SIGN,	//a street sign
	HOME,
	BULLET,
	TREE,
	HAT,
	LOLYPOP,
	FLAG
	//TODO: Add more types
};

//Base class for all shapes including Basic shapes, Composite shapes
class shape
{
protected:
	point RefPoint;		//Each shape must have a reference point
    game* pGame;        //pointer to game object
	color fillColor;	//shape fill color
	color borderColor;	//shape border color
	int k = 0;
	double theta = 0;
	ShapeType type;
public:
    shape(game* r_pGame, point ref);
    virtual bool draw() const=0;//for a shape to draw itself on the screen
	void setRefPoint(point p);
	point getRefPoint() const;
	void setparamaters(int n_k, double n_th);
	void Getters(int& s, int& t, point& p);
	virtual void setColor(color c) = 0;
								  
							  
	//-- The following functions should be supported by the shape class
	//-- It should be overridden by each inherited shape
	//-- Decide the parameters that you should pass to each function	

	virtual void rotate(int c) = 0;	//Rotate the shape
	virtual void resize(int c) = 0;	//Resize the shape
	virtual void move(int c) = 0;		//Move the shape
	//virtual void save(ofstream &OutFile) = 0;	//Save the shape parameters to the file
	//virtual void load(ifstream &Infile) = 0;	//Load the shape parameters to the file
	virtual bool checkbound() = 0;
	void save();
	ShapeType getType();
	bool operator==(const shape& other) const;
};




