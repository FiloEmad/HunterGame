#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "toolbar.h"
#include "operations.h"
#include "grid.h"
#include <vector>


//Main class that coordinates the game operation
class game
{

	/// Add more members if needed

	toolbar* gameToolbar;
	int counter = 5;
	int level = 0;
	int score = 0;
	int t = 0;
	int t2 = 0;
	window* pWind;	//Pointer to the CMU graphics window
	grid* shapesGrid;
	operation* oper;
	keytype ktInput;
	char cKeyData;

public:
	game();
	~game();

	string getSrting() const;	 //Returns a string entered by the user
	void createWind(int, int, int, int); //creates the game window
	void clearStatusBar() const;	//Clears the status bar
	void printMessage(string msg) const;	//Print a message on Status bar
	void createToolBar();		//creates the toolbar
	void createGrid();		//creates the shapes grid
	void printstatus();
	window* getWind() const;		//returns a pointer to the graphics window
	grid* getGrid() const;		//returns a pointer to the shapes grid
	int getLevel() const;
	void setLevel(int l);
	void setScore(int s);
	void checkplay();
	int getScore() const;
	int getLives() const;
	void levelup();
	void XYtimer() ;
	void setlives(int l);

	//creates an operation according to the toolbar item clicked
	operation* createRequiredOperation(toolbarItem clickedItem);
	void chechMovement();
	void Timer() ;
	int tracktime();
	void hinttime();
	void run();	//start the game
	void powerup();
	vector<int> calculateTime(int &Time) const;

};