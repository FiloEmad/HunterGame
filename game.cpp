#include "game.h"
#include "gameConfig.h"
#include<iostream>



game::game()
{

	//Create the main window
	createWind(config.windWidth, config.windHeight, config.wx, config.wy);

	//Create and draw the toolbar
	createToolBar();

	//Create and draw the grid
	createGrid();
	shapesGrid->draw();	//draw the grid and all shapes it contains.

	//Create and clear the status bar
	clearStatusBar();
}

game::~game()
{
	delete pWind;
	delete shapesGrid;
}


//////////////////////////////////////////////////////////////////////////////////////////
void game::createWind(int w, int h, int x, int y)
{
	pWind = new window(w, h, x, y);
	pWind->SetBrush(config.bkGrndColor);
	pWind->SetPen(config.bkGrndColor, 1);
	pWind->DrawRectangle(0, 0, w, h);
}
//////////////////////////////////////////////////////////////////////////////////////////
void game::clearStatusBar() const
{
	//Clear Status bar by drawing a filled rectangle
	pWind->SetPen(config.statusBarColor, 1);
	pWind->SetBrush(config.statusBarColor);
	pWind->DrawRectangle(0, config.windHeight - config.statusBarHeight, config.windWidth, config.windHeight);
}


//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the mode
void game::createToolBar()
{
	gameToolbar = new toolbar(this);
}

void game::createGrid()
{
	//calc some grid parameters
	point gridUpperLeftPoint = { 0, config.toolBarHeight };
	int gridHeight = config.windHeight - config.toolBarHeight - config.statusBarHeight;
	//create the grid
	shapesGrid = new grid(gridUpperLeftPoint, config.windWidth, gridHeight, this);
}

operation* game::createRequiredOperation(toolbarItem clickedItem)
{
	//gameToolbar->drawData();
	operation* op = nullptr;
	switch (clickedItem)
	{
	case ITM_SIGN:
		op = new operAddSign(this);
		break;
	case ITM_DEL:
		op = new operDelShape(this);
		break;
	case ITM_INC:
		op = new operIncShape(this);
		break;
	case ITM_DEC:
		op = new operDecShape(this);
		break;
	case ITM_ROTATEr:
		op = new rotater(this);
		break;
	case ITM_ROTATEl:
		op = new rotatel(this);
		break;
	case ITM_FLAG:
		op = new operAddFlag(this);
		break;
	case ITM_HOME:
		op = new operAddHome(this);
		break;
	case ITM_HAT:
		op = new operAddHat(this);
		break;
	case ITM_ICECREAM:
		op = new operAddLolypop(this);
		break;
	case ITM_TREE:
		op = new operAddtree(this);
		break;
	case ITM_BULLET:
		op = new operAddbullet(this);
		break;
		return op;
	case ITM_HINT:
		op = new operhint(this);
		break;
		return op;
	case ITM_REFRESH:
		counter--;
		op = new operrefresh(this);
		break;
		return op;
	case ITM_SAVE:
		op = new opersave(this);
		break;
		return op;
	case ITM_TIMER:
		op = new opertimer(this);
		break;
		return op;
	case ITM_LOAD:
		op = new operload(this);
		break;
		return op;
	case ITM_SELECT:
		op = new operSelectLevel(this);
		break;
		return op;
	case ITM_XYTIMER:
		op = new operxytimer(this);
		break;
		return op;

	case ITM_EXIT:
		op = new exitt(this);
		break;
		return op;
	}
}
void game::chechMovement()
{
	//keytype ktInput;
	//char cKeyData;
	//ktInput = pWind->GetKeyPress(cKeyData);
	if (ktInput == ARROW)
	{
		switch (cKeyData)
		{
		case 2:
			shapesGrid->MoveActiveShapeDOWN();
			break;
		case 4:
			shapesGrid->MoveActiveShapeL();
			break;
		case 6:
			shapesGrid->MoveActiveShapeR();
			break;
		case 8:
			shapesGrid->MoveActiveShapeUP();
			break;
		}
	}
	else if (ktInput == ESCAPE)
	{
		if (shapesGrid->check())
		{
			levelup();
		}
		else
		{
			score--;
		}
		printstatus();
	}
}

void game::checkplay()
{
	keytype ktInput;
	char cKeyData;
	ktInput = pWind->GetKeyPress(cKeyData);
	if (ktInput == ASCII)
	{
		switch (cKeyData)
		{
		case 5:

			break;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////

void game::printMessage(string msg) const	//Prints a message on status bar
{
	clearStatusBar();	//First clear the status bar

	pWind->SetPen(config.penColor, 50);
	pWind->SetFont(16, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, config.windHeight - (int)(0.85 * config.statusBarHeight), msg);
}

void game::printstatus()
{
	static int s = score; static int li = counter; static int le = level;
	pWind->SetPen(config.bkGrndColor);
	pWind->SetBrush(RED);
	pWind->DrawRectangle(ITM_CNT * config.toolbarItemWidth, 0, (ITM_CNT + 7) * config.toolbarItemWidth, config.toolBarHeight);
	pWind->SetPen(BLACK, 50);
	pWind->SetFont(16, BOLD, BY_NAME, "times new roman");
	pWind->DrawString(ITM_CNT * config.toolbarItemWidth, 0, "number of lives is");
	pWind->DrawInteger(ITM_CNT * config.toolbarItemWidth + 200, 0, counter);
	pWind->DrawString(ITM_CNT * config.toolbarItemWidth, 20, "number of scores is");
	pWind->DrawInteger(ITM_CNT * config.toolbarItemWidth + 200, 20, score);
	pWind->DrawString(ITM_CNT * config.toolbarItemWidth, 40, "number of levels is");
	pWind->DrawInteger(ITM_CNT * config.toolbarItemWidth + 200, 40, level);
}

window* game::getWind() const		//returns a pointer to the graphics window
{
	return pWind;
}



string game::getSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if (Label.size() > 0)
				Label.resize(Label.size() - 1);
			else
				Key = '\0';
		else
			Label += Key;
		printMessage(Label);
	}
}

grid* game::getGrid() const
{
	// TODO: Add your implementation code here.
	return shapesGrid;
}


int game::getLevel() const
{
	return level;
}
void game::setLevel(int l) {
	level = l;
}
void game::setScore(int s) {
	score = s;
}

int game::getScore() const
{
	return score;
}

int game::getLives() const
{
	return counter;
}



void game::levelup()
{
	if (shapesGrid->checkList())
	{
		level += 1;
		operation* op = new operDrawLevel(this);
		op->Act();
	}
}

void game::powerup() {
	int x;
	int y;

	if (shapesGrid->getactiveshape() != nullptr) {
		static time_t startTime1 = time(NULL);
		time_t currentTime1 = time(NULL);
		int elapsedSeconds1 = currentTime1 - startTime1;

		if (ktInput == ESCAPE && elapsedSeconds1 < 11) {
			if (shapesGrid->check())
			{
				printstatus();
				levelup();
				pWind->DrawImage("images\\toolbarItems\\\powerup.jpg", 80, 50, 100, 200);
				static time_t startTime2 = time(NULL);
				time_t currentTime2 = time(NULL);
				int elapsedSeconds2 = currentTime2 - startTime2;
				pWind->WaitMouseClick(x, y);
				if (x >= 80 && x <= 180 && y >= 50 && y <= 250 && elapsedSeconds2 < 5)
				{
					shapesGrid->deleterandomly();
					score = +2;
					printstatus();
				}
				if (elapsedSeconds2 > 5) {
					shapesGrid->draw();
				}
			}
		}
	}

}
void game::Timer()  {
	static time_t startTime = time(NULL);

	int timer = (60 * 3 - (level * 5)) * 1000;
	time_t currentTime = time(NULL);
	int elapsedSeconds = currentTime - startTime;

	timer -= elapsedSeconds;

	int minutes = timer / 60000;
	int seconds = (timer) % 60;
	int melli = minutes;

	if (timer <= 0) {
		counter--;
		printstatus();
	}
	if (counter <= 0) {

		clearStatusBar();
		pWind->SetBrush(RED);
		pWind->SetPen(RED, 1);
		pWind->SetFont(45, BOLD, BY_NAME, "Arial");
		pWind->DrawString(((config.windWidth - 300) / 2) + 10, ((config.windHeight - 100) / 2) + 30, "Time out, GAME OVER!!");
		Sleep(2000);
		operation* op = new exitt(this);
		op->Act();

	}

	if (seconds == timer % 60) {
		clearStatusBar();
		pWind->SetPen(config.penColor, 50);
		pWind->SetFont(16, BOLD, BY_NAME, "Arial");
		string timerText = "Time Left: " + to_string(minutes) + ":" + to_string(seconds);
		pWind->DrawString(config.windWidth - 150, config.windHeight - (int)(0.85 * config.statusBarHeight), timerText);
	}
}



void game::XYtimer() 
{

	static time_t startTime = time(NULL);
	int timerY = 40;
	int timerX = 30;
	time_t currentTime = time(NULL);
	int elapsedSeconds = currentTime - startTime;
	
	timerY -= elapsedSeconds;

	int minutesY = timerY / 60000;
	int secondsY = (timerY) % 60;
	int melliY = minutesY;

	timerX -= elapsedSeconds;
	int minutes = timerX / 60000;
	int seconds = (timerX) % 60;
	
	if (shapesGrid->getactiveshape()==nullptr)
	{
		if (seconds == timerX % 60) {
			clearStatusBar();
			pWind->SetPen(config.penColor, 50);
			pWind->SetFont(16, BOLD, BY_NAME, "Arial");
			string timerText = "Time for thinking: " + to_string(minutes) + ":" + to_string(seconds);
			pWind->DrawString(config.windWidth - 170, config.windHeight - (int)(0.85 * config.statusBarHeight), timerText);

		}
	}
	
	if (shapesGrid->getactiveshape() != nullptr) {
		if (seconds == timerX % 60) {
			clearStatusBar();
			pWind->SetPen(config.penColor, 50);
			pWind->SetFont(16, BOLD, BY_NAME, "Arial");
			string timerText = "Time for action: " + to_string(minutesY) + ":" + to_string(secondsY);
			pWind->DrawString(config.windWidth - 150, config.windHeight - (int)(0.85 * config.statusBarHeight), timerText);

		}
		if (timerY == 0 && ktInput == ESCAPE)
		{
			if (!shapesGrid->check())
			{
				score--;
				t = 0;
				printstatus();
			}

		}
		
	}
	if (timerY == 0 || timerY < 0|| timerX==0||timerX<0 || ktInput == ESCAPE)
	{
		if (shapesGrid->check())
		{
			levelup();
			int timerY = 40;
			int timerX = 30;
			printstatus();
		}
	}
}

void game::setlives(int l)
{
	counter = l;
}

////////////////////////////////////////////////////////////////////////
void game::run()
{
	//This function reads the position where the user clicks to determine the desired operation
	int x, y;
	bool isExit = false;

	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - SHAPE HUNT (CIE 101 / CIE202 - project) - - - - - - - - - -");
	toolbarItem clickedItem = ITM_CNT;
	printstatus();
	do
	{
		ktInput = pWind->GetKeyPress(cKeyData);
		//printMessage("Ready...");
		//1- Get user click
		pWind->GetMouseClick(x, y);	//Get the coordinates of the user click
		operation* op = nullptr;

		//2-Explain the user click
		//If user clicks on the Toolbar, ask toolbar which item is clicked
		if (y >= 0 && y < config.toolBarHeight)
		{
			clickedItem = gameToolbar->getItemClicked(x);

			//3-create the approp operation accordin to item clicked by the user
			op = createRequiredOperation(clickedItem);
			if (op)
			{
				op->Act();
				printstatus();
			}

			//4-Redraw the grid after each action
			//shapesGrid->draw();

		}
		if (shapesGrid->getactiveshape())
		{
			powerup();
		}
		//checkplay();
		chechMovement();
		
		if (clickedItem == ITM_TIMER)
		{
			Timer();
			t2++;
		}
		if (t2 > 0)
		{
			Timer();
		}
		if (clickedItem == ITM_XYTIMER)
		{
			t++;
		}
		if (t > 0)
		{
			XYtimer();
		}

	} while (clickedItem != ITM_EXIT);
}