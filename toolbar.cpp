#include "toolbar.h"
#include "game.h"
//#include "grid.h"


////////////////////////////////////////////////////  class toolbar   //////////////////////////////////////////////
toolbar::toolbar(game* pG)
{
	height = config.toolBarHeight;
	width = config.windWidth;
	this->pGame = pG;
	window* pWind = pGame->getWind();

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each toolbar item
	toolbarItemImages[ITM_SIGN] = "images\\toolbarItems\\toolbar_sign.jpg";
	toolbarItemImages[ITM_EXIT] = "images\\toolbarItems\\toolbar_Exit.jpg";
	toolbarItemImages[ITM_DEL] = "images\\toolbarItems\\delet.jpg";
	toolbarItemImages[ITM_INC] = "images\\toolbarItems\\plus.jpg";
	toolbarItemImages[ITM_DEC] = "images\\toolbarItems\\dec.jpg";
	toolbarItemImages[ITM_ROTATEr] = "images\\toolbarItems\\Rotater.jpg";
	toolbarItemImages[ITM_ROTATEl] = "images\\toolbarItems\\Rotatel.jpg";
	toolbarItemImages[ITM_HOME] = "images\\toolbarItems\\home.jpg";
	toolbarItemImages[ITM_FLAG] = "images\\toolbarItems\\flag.jpg";
	toolbarItemImages[ITM_HAT] = "images\\toolbarItems\\hat.jpg";
	toolbarItemImages[ITM_ICECREAM] = "images\\toolbarItems\\lolypop.jpg";
	toolbarItemImages[ITM_TREE] = "images\\toolbarItems\\tree.jpg";
	toolbarItemImages[ITM_BULLET] = "images\\toolbarItems\\bullet.jpg";
	toolbarItemImages[ITM_HINT] ="images\\toolbarItems\\HINT.jpg" ;
	toolbarItemImages[ITM_REFRESH] = "images\\toolbarItems\\REFRESH.jpg";
	toolbarItemImages[ITM_SAVE] = "images\\toolbarItems\\SAVE.jpg";
	toolbarItemImages[ITM_TIMER] = "images\\toolbarItems\\timer.jpg";
	toolbarItemImages[ITM_SELECT] = "images\\toolbarItems\\\select.jpg";
	toolbarItemImages[ITM_LOAD] = "images\\toolbarItems\\\load.jpg";
	toolbarItemImages[ITM_XYTIMER] = "images\\toolbarItems\\timer.jpg";
	//TODO: Prepare image for each toolbar item and add it to the list

	//Draw toolbar item one image at a time
	for (int i = 0; i < ITM_CNT; i++)
		pWind->DrawImage(toolbarItemImages[i], i * config.toolbarItemWidth, 0, config.toolbarItemWidth, height);


	//Draw a line under the toolbar
	pWind->SetPen(DARKBLUE, 3);
	pWind->DrawLine(0, height, width, height);
	//drawData();

}

void toolbar::drawData()
{
	int score, level, lives;
	score = pGame->getScore(); level = pGame->getLevel(); lives = pGame->getLives();
	window* pWind = pGame->getWind();
	pWind->SetPen(config.bkGrndColor);
	pWind->DrawRectangle(ITM_CNT * config.toolbarItemWidth, 0, (ITM_CNT + 4) * config.toolbarItemWidth, config.toolBarHeight);
	pWind->SetPen(config.penColor, 50);
	pWind->SetFont(16, BOLD, BY_NAME, "times new roman");
	pWind->DrawString(ITM_CNT * config.toolbarItemWidth, 0, "number of lives is");
	pWind->DrawInteger(ITM_CNT * config.toolbarItemWidth + 200, 0, lives);
	pWind->DrawString(ITM_CNT * config.toolbarItemWidth, 20, "number of scores is");
	pWind->DrawInteger(ITM_CNT * config.toolbarItemWidth + 200, 20, score);
	pWind->DrawString(ITM_CNT * config.toolbarItemWidth, 40, "number of levels is");
	pWind->DrawInteger(ITM_CNT * config.toolbarItemWidth + 200, 40, level);
}




//handles clicks on toolbar icons, returns ITM_CNT if the click is not inside the toolbar
toolbarItem toolbar::getItemClicked(int x)
{

	if (x > ITM_CNT * config.toolbarItemWidth)	//click outside toolbar boundaries
		return ITM_CNT;


	//Check whick toolbar item was clicked
	//==> This assumes that toolbar items are lined up horizontally <==
	//Divide x coord of the point clicked by the icon width (int division)
	//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

	return (toolbarItem)(x / config.toolbarItemWidth);

}

