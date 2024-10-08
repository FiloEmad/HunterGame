#include "operations.h"
#include "game.h"
#include "CompositeShapes.h"
#include "shape.h"
#include <cstdlib>
#include <time.h>
#include <iostream>
#include<fstream>
#include<vector>
#include <sstream>
using namespace std;
/////////////////////////////////// class operation  //////////////////
operation::operation(game* r_pGame)
{
	pGame = r_pGame;
}


/////////////////////////////////// class operAddSign  //////////////////

operAddSign::operAddSign(game* r_pGame) :operation(r_pGame)
{
}
void operAddSign::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new Sign(pGame, signShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);
	pGrid->draw();
}

/////////////////////////////////// class operAddHome  //////////////////

operAddHome::operAddHome(game* r_pGame) : operation(r_pGame)
{
}
void operAddHome::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new Home(pGame, signShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);
	pGrid->draw();
}

/////////////////////////////////// class operAddHat  //////////////////

operAddHat::operAddHat(game* r_pGame) : operation(r_pGame)
{
}
void operAddHat::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new Hat(pGame, signShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);
	pGrid->draw();
}

/////////////////////////////////// class operAddFlag  //////////////////

operAddFlag::operAddFlag(game* r_pGame) : operation(r_pGame)
{
}
void operAddFlag::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new Flag(pGame, signShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);
	pGrid->draw();
}

/////////////////////////////////// class operAddLolypop  //////////////////

operAddLolypop::operAddLolypop(game* r_pGame) : operation(r_pGame)
{
}
void operAddLolypop::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new lolypop(pGame, signShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);
	pGrid->draw();
}
operAddtree::operAddtree(game* r_pGame) : operation(r_pGame)
{
}
void operAddtree::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new ChristmasTree(pGame, signShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);
	pGrid->draw();
}
operAddbullet::operAddbullet(game* r_pGame) : operation(r_pGame)
{
}
void operAddbullet::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new Bullet(pGame, signShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);
	pGrid->draw();
}
////////////////////////////////////////////////Buttoms///////////////////////////////////////////////
operhint::operhint(game* r_pGame) : operation(r_pGame)
{
}
void operhint::Act()
{
	int level = pGame->getLevel();
	if (level>2)
	{
		grid* pGrid = pGame->getGrid();
		int a =pGrid->hint();
		cout << "hint" << endl;
		pGrid->hintchange(a,RED);
		cout << "hintchange" << endl;
		pGrid->hinttime();
		cout << "hinttime" << endl;
	}
	int score = pGame->getScore();
	score--;
	pGame->setScore(score);
}
operrefresh::operrefresh(game* r_pGame) : operation(r_pGame)
{
}
void operrefresh::Act()
{
	grid* pGrid = pGame->getGrid();
	pGrid->RefreshGrid();
	operation* f = nullptr;
	f = new operDrawLevel(pGame);
	f->Act();
	pGrid->draw();
}
opersave::opersave(game* r_pGame) : operation(r_pGame)
{
}
void opersave::Act()
{
	ofstream frogress;
	frogress.open("prog.txt");
	int c = pGame->getLives();
	int s = pGame->getScore();
	int l = pGame->getLevel();

	frogress << c << " " << s << " " << l << endl;

	pGame->getGrid()->createA();

	shape* kk = pGame->getGrid()->getactiveshape();
	kk->save();
	frogress.close();

}

/////////////////////////////////// class operDelShape  //////////////////

operDelShape::operDelShape(game* r_pGame) :operation(r_pGame)
{
}
void operDelShape::Act()
{
	grid* pGrid = pGame->getGrid();
	pGrid->DelActiveShape();
}

/////////////////////////////////// class operIncShape  //////////////////

operIncShape::operIncShape(game* r_pGame) :operation(r_pGame)
{
}
void operIncShape::Act()
{
	grid* pGrid = pGame->getGrid();
	pGrid->IncActiveShape();
}

/////////////////////////////////// class operDecShape  //////////////////

operDecShape::operDecShape(game* r_pGame) :operation(r_pGame)
{
}
void operDecShape::Act()
{
	grid* pGrid = pGame->getGrid();
	pGrid->DecActiveShape();
}

/////////////////////////////////// class rotater  //////////////////

rotater::rotater(game* r_pGame) : operation(r_pGame)
{
}
void rotater::Act()
{
	grid* pGrid = pGame->getGrid();
	pGrid->RotateActiveShapeR();
}

/////////////////////////////////// class rotatel  //////////////////

rotatel::rotatel(game* r_pGame) : operation(r_pGame)
{
}
void rotatel::Act()
{
	grid* pGrid = pGame->getGrid();
	pGrid->RotateActiveShapeL();

}


operDrawLevel::operDrawLevel(game* r_pGame) : operation(r_pGame)
{
}

void operDrawLevel::Act()
{
	grid* pGrid = pGame->getGrid();
	pGrid->RefreshGrid();
	int l = pGame->getLevel();
	int level = 2 * l - 1;
	srand(time(NULL));
	double theta = 22.0 / 56.0;
	shape* p_shape = nullptr;
	int red, blue, yello;
	for (int i = 0; i < level; i++)
	{
		red = rand() % 255; blue = rand() % 255; yello = rand() % 255;
		int k, s; point ref;
		k = rand() % 20 - 10;
		double c = rand() % 8;
		int rows = (config.windHeight - config.toolBarHeight - config.statusBarHeight) / config.gridSpacing;
		int cols = (config.windWidth / config.gridSpacing) / 2;
		s = rand() % 7;
		ref.x = (rand() % cols + 1) * 30;
		ref.y = (rand() % (rows) + 1) * 30 + config.toolBarHeight;
		if (s == 0)
		{
			p_shape = new Sign(pGame, ref);
		}
		if (s == 1)
		{
			p_shape = new Home(pGame, ref);
		}
		if (s == 2)
		{
			p_shape = new Bullet(pGame, ref);
		}
		if (s == 3)
		{
			p_shape = new ChristmasTree(pGame, ref);
		}
		if (s == 4)
		{
			p_shape = new Hat(pGame, ref);
		}
		if (s == 5)
		{
			p_shape = new Flag(pGame, ref);
		}
		if (s == 6)
		{
			p_shape = new lolypop(pGame, ref);
		}
		color r_color(red, blue, yello);
		if (l > 3) { p_shape->setColor(BLACK); }
		else { p_shape->setColor(r_color); }
		p_shape->setparamaters(k, theta * c);
		bool check = pGrid->addShape(p_shape);
		if (check == false)
		{
			i--;
		}
	}
	pGrid->draw();
}


operSelectLevel::operSelectLevel(game* r_pGame) : operation(r_pGame)
{
}
void operSelectLevel::Act()
{
	keytype inpt;
	operation* f = nullptr;
	char cKeyData;
	inpt = pGame->getWind()->WaitKeyPress(cKeyData);
	if (inpt == ASCII) {
		if (isdigit(cKeyData))
			pGame->setLevel(cKeyData-48);
	}
	f = new operDrawLevel(pGame);
	f->Act();
}
 opertimer::opertimer(game* r_pGame) : operation(r_pGame)
{
}
void opertimer::Act()
{
	pGame->Timer();
	
}
operxytimer::operxytimer(game* r_pGame) : operation(r_pGame)
{
}
void operxytimer::Act()
{
	pGame->XYtimer();

}

operload::operload(game* r_pGame): operation(r_pGame)
{
}

void operload::Act()
{
	string test;
	int countt = 0;
	ifstream frogress;
	frogress.open("prog.txt");
	if (!frogress) {
	}
	else {
		string f;
		int s; int h; int g;
		frogress >> s >> h >> g;
		pGame->setlives(s);
		pGame->setScore(h);
		pGame->setLevel(g);

		while (frogress >> test) {
			cout << test << endl;
			countt++;
		}

		cout << countt;

		//shape* dd[1000];
		for (int i = 0; i < countt / 5; i++) {
			shape* sh = nullptr;
			//int f;
			int g = 2 + i;

			vector <double> integers;

			//read(g, integers);
			integers.clear();
			ifstream frogress("prog.txt");

			if (!frogress.is_open()) {
			}
			string line;
			int lineNumber = 0;
			int p = (i + 2) - 1;

			while (getline(frogress, line) && lineNumber < p) {
				lineNumber++;
			}
			if (lineNumber < p) {
			}

			istringstream iss(line);
			double number;

			while (iss >> number) {
				integers.push_back(number);
			}

			cout << "Numbers from the third line:" << endl;
			for (double num : integers) {
				cout << num << endl;
			}
			cout << endl;

			frogress.close();
			int s = integers[0];
			double h = integers[1];
			int x = integers[2];
			int y = integers[3];
			int e = integers[4];
			cout << s << " " << h << " " << e << endl;

			point Refnew;
			Refnew.x = x;
			Refnew.y = y;

			switch (e) {
			case 3:
				sh = new Sign(pGame, Refnew);
				break;
			case 4:
				sh = new Home(pGame, Refnew);
				break;
			case 5:
				sh = new Bullet(pGame, Refnew);
				break;
			case 6:
				sh = new ChristmasTree(pGame, Refnew);
				break;
			case 7:
				sh = new Hat(pGame, Refnew);
				break;
			case 8:
				sh = new lolypop(pGame, Refnew);
				break;
			case 9:
				sh = new Flag(pGame, Refnew);
				break;
			}
			sh->setRefPoint(Refnew);
			sh->setparamaters(s, h);
			sh->setColor(BLACK);
			if (i != countt / 5 - 1) {
				bool checkit = pGame->getGrid()->addShape(sh);
				if (checkit) {
				}
				//dd[i] = sh;
			}
			//pGame->getGrid()->setshapelist(dd, countt);
			else {
				sh->setColor(RED);
				pGame->getGrid()->setActiveShape(sh);
			}
		}

	}
	frogress.close();
	pGame->getGrid()->draw();

}

exitt::exitt(game* r_pGame): operation(r_pGame)
{
}

void exitt::Act()
{
	opersave(pGame).Act();
	pGame->~game();
	pGame->getGrid()->~grid();
}
