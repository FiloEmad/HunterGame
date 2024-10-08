#pragma once
#include "CMUgraphicsLib/CMUgraphics.h"


//The folowing struct contains all game configurations
// (MAY be loaded from a configuration file later)
__declspec(selectany) //This line to prevent "redefinition error"
struct
{
	int	windWidth = 1200, windHeight = 600,	//Window width and height
		wx = 5, wy = 5,			//Window starting coordinates

		//The window is divded into 3 areas: toolbar, Working area, and statusbar
		toolBarHeight = 60,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		toolbarItemWidth = 45,			//Width of each icon in toolbar
		statusBarHeight = 50;	//Status Bar Height

	int remainingHeight = windHeight - toolBarHeight - statusBarHeight;

	int gridHeight = int(remainingHeight * (2 / 3.0)); 		//The grid is where bricks can be drawn

	//Default colors
	color	penColor = RED,			//color used to draw borders/write messages
		fillColor = RED,			//shapes fill color (Default)
		bkGrndColor = LAVENDER,		//Screen Background color
		statusBarColor = LIGHTSEAGREEN;	//background color of the status
	int penWidth = 3;			//width of the pen that draws shapes


	color gridDotsColor = RED;
	int gridSpacing = 30;	//spacing between grid points

	////// Configuration for the composite shapes //////
	// default Ref Point for any newly created shape 
	int RefX = 27 * 30;
	int RefY = 7 * 30;

	////-----  Sign Shape Confoguration ---------////
	// For the Sign shape, define width and height of both rectangles
	struct {
		int baseWdth = 20, baseHeight = baseWdth * 4;
		int topWdth = baseWdth * 5, topHeight = 5 * baseWdth / 2;
	}sighShape;
	struct
	{

		int w = 14;
		int s = 4 * w;
		int h = 11 * w / 2;
	}treeshape;



	struct
	{
		int s = 65;
	}homeshape;



	struct
	{

		int r = 10;
		int s = r * 6;
	}hatshape;


	struct
	{

		int w = 50;
		int h = w * 2;
	}bulletshape;


	struct
	{

		int w = 14;
		int h = 12 * w;
		int s = 3 * w;
	}Flagshape;



	struct
	{
		int r = 25;
		int h = 4 * r;
	}lolypopshape;

}config;


enum toolbarItem //The items of the  toolbar (you should add more items)
{
	//Note: Items are ordered here as they appear in the toolbar
	//If you want to change the toolbar items order, just change the order here
	ITM_SIGN,		//Sign shape item

	ITM_EXIT,		//Exit item
	//TODO: Add more items names here
		//no. of toolbar items ==> This should be the last line in this enum
	ITM_DEL,
	ITM_INC,
	ITM_DEC,
	ITM_ROTATEr,
	ITM_ROTATEl,
	ITM_HOME,
	ITM_FLAG,
	ITM_HAT,
	ITM_ICECREAM,
	ITM_TREE,
	ITM_BULLET,
	ITM_HINT,
	ITM_REFRESH,
	ITM_SAVE,
	ITM_TIMER,
	ITM_LOAD,
	ITM_SELECT,
	ITM_XYTIMER,
	ITM_CNT,
	ITM_STATUS
};



