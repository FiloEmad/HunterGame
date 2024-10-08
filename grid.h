#pragma once
#include "CompositeShapes.h"

class game;

class grid
{
	enum { MaxShapeCount = 1000  };	//assuming max shape count = 1000
	
	int rows, cols;	//numner of rows and columns in the grid to draw grid points
	int height, width;
	point uprLeft;	//upper left point of the grid

	//ShapeList should hold the RANDOMLY generated shapes
	shape* shapeList[MaxShapeCount];	//2D array of shape pointers

	shape* activeShape;	//The shape that the user works on to match to the ranom shapes

	int shapeCount;		//current number of shapes in the list
	game* pGame;
public:
	grid(point r_uprleft, int r_width, int r_height, game* r_pGame);
	~grid();
	void draw() const;
	void clearGridArea() const;
	bool addShape(shape* newShape);
	void setActiveShape(shape* actShape);
	void DelActiveShape();
	void IncActiveShape() const;
	void DecActiveShape() const;
	void RotateActiveShapeR() const;
	void RotateActiveShapeL() const;
	void MoveActiveShapeR() const;
	void MoveActiveShapeL() const;
	void MoveActiveShapeUP() const;
	void MoveActiveShapeDOWN() const;
	void RefreshGrid();
	bool check();
	int hint();
	int getshapecount()const;
	shape* getshapelist()const;
	void createA();
	shape* getactiveshape()const;
	void hintchange(int index, color a);
	void hinttime();
	bool checkList() const;
	void deleterandomly();

};

