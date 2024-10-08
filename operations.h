#pragma once


class game;
/////////////////////////////////// class operation  //////////////////
//Base class of all operations supported by the application
class operation
{
protected:
	game* pGame;	//pointer to the game class
public:
	operation(game* r_pGame);

	//Function Act:
	//Implements the action that should be taken by this operation
	//Should be overriden by derived classes
	virtual void Act() = 0;
};
/////////////////////////////////// class operAddSign  //////////////////
//Responsible for 
//1- collectign data about a new Sign shape to add
//2- Adding the new shape to the list of shapes (throgh the grid class)
class operAddSign :public operation
{
public:
	operAddSign(game* r_pGame);
	virtual void Act();
};

class operAddHome :public operation
{
public:
	operAddHome(game* r_pGame);
	virtual void Act();
};

class operAddHat :public operation
{
public:
	operAddHat(game* r_pGame);
	virtual void Act();
};

class operAddFlag :public operation
{
public:
	operAddFlag(game* r_pGame);
	virtual void Act();
};

class operAddLolypop :public operation
{
public:
	operAddLolypop(game* r_pGame);
	virtual void Act();
};
class operAddtree :public operation
{
public:
	operAddtree(game* r_pGame);
	virtual void Act();
};
class operAddbullet :public operation
{
public:
	operAddbullet(game* r_pGame);
	virtual void Act();
};
class operhint :public operation
{
public:
	operhint(game* r_pGame);
	virtual void Act();
};
class operrefresh :public operation
{
public:
	operrefresh(game* r_pGame);
	virtual void Act();
};
class opersave :public operation
{
public:
	opersave(game* r_pGame);
	virtual void Act();
};

class operload : public operation
{
public:
	operload(game* r_pGame);
	virtual void Act();
};

class operDelShape :public operation
{
public:
	operDelShape(game* r_pGame);
	virtual void Act();
};


class operIncShape :public operation
{
public:
	operIncShape(game* r_pGame);
	virtual void Act();
};


class operDecShape :public operation
{
public:
	operDecShape(game* r_pGame);
	virtual void Act();
};


class rotater : public operation
{
public:
	rotater(game* r_pGame);
	virtual void Act();
};


class rotatel : public operation
{
public:
	rotatel(game* r_pGame);
	virtual void Act();
};

class operDrawLevel : public operation
{
public:
	operDrawLevel(game* r_pGame);
	virtual void Act();
};

class operSelectLevel :public operation
{
public:
	operSelectLevel(game* r_pGame);
	virtual void Act();
};

class opertimer :public operation
{
public:
	opertimer(game* r_pGame);
	virtual void Act();
};
class operxytimer :public operation
{
public:
	operxytimer(game* r_pGame);
	virtual void Act();
};

class exitt : public operation
{
public:
	exitt(game* r_pGame);
	virtual void Act();
};