#include "CompositeShapes.h"
#include "gameConfig.h"

////////////////////////////////////////////////////  class Sign  ///////////////////////////////////////


Sign::Sign(game* r_pGame, point ref):shape(r_pGame, ref)
{
	//calc the ref point of the Sign base and top rectangles relative to the Sign shape
	point topRef = ref;	//top rect ref is the same as the sign
	point baseRef = { ref.x, ref.y + config.sighShape.topHeight / 2 + config.sighShape.baseHeight / 2 };
	top = new Rect(pGame, topRef, config.sighShape.topHeight, config.sighShape.topWdth);
	base = new Rect(pGame, baseRef, config.sighShape.baseHeight, config.sighShape.baseWdth);
    type = SIGN;
}

bool Sign::draw() const
{

    point p, n_P;
    p.x = 0; p.y = 0 + (config.sighShape.topHeight * (1 + k / 10.0)) / 2 + (config.sighShape.baseHeight * (1 + k / 10.0)) / 2;
    n_P.x = p.x * cos(theta) - p.y * sin(theta) + RefPoint.x;
    n_P.y = p.x * sin(theta) + p.y * cos(theta) + RefPoint.y;
    base->setRefPoint(n_P);
    base->setparamaters(k, theta);
    top->setparamaters(k, theta);
    if (base->checkbound() && top->checkbound())
    {
        base->draw();
        top->draw();
        return true;
    }
}

void Sign::resize(int c)
{
    point p, n_P;
	if (c == 1) { 
		k++;
	}
    if (c == 0 && k > -10) {
        k--;
    }
    p.x = 0; p.y = 0 + (config.sighShape.topHeight * (1 + k / 10.0)) / 2 + (config.sighShape.baseHeight * (1 + k / 10.0)) / 2;
    n_P.x = p.x * cos(theta) - p.y * sin(theta) + RefPoint.x;
    n_P.y = p.x * sin(theta) + p.y * cos(theta) + RefPoint.y;
    base->setRefPoint(n_P);
    if (base->checkbound() && top->checkbound())
    {
        base->resize(c);
        top->resize(c);
    }
}

void Sign::rotate(int c)
{
	if (c == 1)
	{
		theta += (22.0 / 56.0);
	}
	if (c == 0)
	{
        theta -= (22.0 / 56.0);
	}
    point p, n_P;
    base->setRefPoint({ RefPoint.x,RefPoint.y + (config.sighShape.topHeight * (1 + k / 10)) / 2 + (config.sighShape.baseHeight * (1 + k / 10)) / 2 });
    p.x = base->getRefPoint().x - RefPoint.x; p.y = base->getRefPoint().y - RefPoint.y;
    n_P.x = p.x * cos(theta) - p.y * sin(theta) + RefPoint.x;
    n_P.y = p.x * sin(theta) + p.y * cos(theta) + RefPoint.y;
    base->setRefPoint(n_P);
    if (base->checkbound() && top->checkbound())
    {
        base->rotate(c);
        top->rotate(c);
    }

}

void Sign::move(int c) {
    if (c == 0) { RefPoint.x += 30; }
    if (c == 1) { RefPoint.x -= 30; }
    if (c == 2) { RefPoint.y += 30; }
    if (c == 3) { RefPoint.y -= 30; }
    point p, n_P;
    p.x = 0; p.y = 0 + (config.sighShape.topHeight * (1 + k / 10.0)) / 2 + (config.sighShape.baseHeight * (1 + k / 10.0)) / 2;
    n_P.x = p.x * cos(theta) - p.y * sin(theta) + RefPoint.x;
    n_P.y = p.x * sin(theta) + p.y * cos(theta) + RefPoint.y;
    base->setRefPoint(n_P);
    top->setRefPoint(RefPoint);
    if (base->checkbound() && top->checkbound())
    {
        draw();
    }
}

bool Sign::checkbound()
{
    if (top->checkbound() == true && base->checkbound() == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Sign::setColor(color c)
{
    fillColor = c;
    base->setColor(c);
    top->setColor(c);
}


////////////////////////////////////////////////////  class ChristmasTree  ///////////////////////////////////////

ChristmasTree::ChristmasTree(game* r_pGame, point ref) : shape(r_pGame, ref) {
    point RefBase = ref;
    point RefTop = { ref.x, ref.y - (sqrt(3.0) / 3.0) * (config.treeshape.s) };
    point RefTopmost = { ref.x, ref.y - (sqrt(3.0) * 2.0 / 3.0) * (config.treeshape.s) };
    point RefTrunk = { ref.x,ref.y + (sqrt(3.0) / 6.0) * (config.treeshape.s) + config.treeshape.h / 2 };
    base = new Triangle(r_pGame, RefBase, config.treeshape.s);
    top = new Triangle(r_pGame, RefTop, config.treeshape.s);
    trunk = new Rect(r_pGame, RefTrunk, config.treeshape.h, config.treeshape.w);
    topmost = new Triangle(r_pGame, RefTopmost, config.treeshape.s);
    type = TREE;
}

bool ChristmasTree::draw() const {
    point topP, n_topP, trunkP, n_trunkP, topmostP, n_topmostP;
    topP.x = 0; topP.y = 0 - (sqrt(3.0) / 3.0) * (config.treeshape.s * (1 + k / 10.0));
    trunkP.x = 0; trunkP.y = 0 + (sqrt(3.0) / 6.0) * (config.treeshape.s * (1 + k / 10.0)) + (config.treeshape.h * (1 + k / 10.0)) / 2;
    topmostP.x = 0; topmostP.y = -(sqrt(3.0) * 2.0 / 3.0) * (config.treeshape.s * (1 + k / 10.0));
    n_topP.x = topP.x * cos(theta) - topP.y * sin(theta) + RefPoint.x;
    n_topP.y = topP.y * cos(theta) + topP.x * sin(theta) + RefPoint.y;
    n_trunkP.x = trunkP.x * cos(theta) - trunkP.y * sin(theta) + RefPoint.x;
    n_trunkP.y = trunkP.y * cos(theta) + trunkP.x * sin(theta) + RefPoint.y;
    n_topmostP.x = topmostP.x * cos(theta) - topmostP.y * sin(theta) + RefPoint.x;
    n_topmostP.y = topmostP.y * cos(theta) + topmostP.x * sin(theta) + RefPoint.y;
    top->setRefPoint(n_topP);
    trunk->setRefPoint(n_trunkP);
    topmost->setRefPoint(n_topmostP);
    base->setparamaters(k, theta);
    top->setparamaters(k, theta);
    topmost->setparamaters(k, theta);
    trunk->setparamaters(k, theta);
    if (top->checkbound() && base->checkbound() && topmost->checkbound() && trunk->checkbound())
    {
        base->draw();
        top->draw();
        topmost->draw();
        trunk->draw();
        return true;
    }
    else
    {
        return false;
    }
}

void ChristmasTree::resize(int c) {
    if (c == 1 && k < 10) { k++; };
    if (c == 0 && k > -10) { k--; };


    point topP, n_topP, trunkP, n_trunkP, topmostP, n_topmostP;
    topP.x = 0; topP.y = 0 - (sqrt(3.0) / 3.0) * (config.treeshape.s * (1 + k / 10.0));
    trunkP.x = 0; trunkP.y = 0 + (sqrt(3.0) / 6.0) * (config.treeshape.s * (1 + k / 10.0)) + (config.treeshape.h * (1 + k / 10.0)) / 2;
    topmostP.x = 0; topmostP.y = -(sqrt(3.0) * 2.0 / 3.0) * (config.treeshape.s * (1 + k / 10.0));
    n_topP.x = topP.x * cos(theta) - topP.y * sin(theta) + RefPoint.x;
    n_topP.y = topP.y * cos(theta) + topP.x * sin(theta) + RefPoint.y;
    n_trunkP.x = trunkP.x * cos(theta) - trunkP.y * sin(theta) + RefPoint.x;
    n_trunkP.y = trunkP.y * cos(theta) + trunkP.x * sin(theta) + RefPoint.y;
    n_topmostP.x = topmostP.x * cos(theta) - topmostP.y * sin(theta) + RefPoint.x;
    n_topmostP.y = topmostP.y * cos(theta) + topmostP.x * sin(theta) + RefPoint.y;
    top->setRefPoint(n_topP);
    trunk->setRefPoint(n_trunkP);
    topmost->setRefPoint(n_topmostP);
    topmost->resize(c);
    top->resize(c);
    base->resize(c);
    trunk->resize(c);
}

void ChristmasTree::rotate(int c)  {
    if (c == 1)
    {
        theta += (22.0 / 56.0);
    }
    if (c == 0)
    {
        theta -= (22.0 / 56.0);
    }
    point topP, n_topP, trunkP, n_trunkP, topmostP, n_topmostP;
    topP.x = 0; topP.y = 0 - (sqrt(3.0) / 3.0) * (config.treeshape.s * (1 + k / 10.0));
    trunkP.x = 0; trunkP.y = 0 + (sqrt(3.0) / 6.0) * (config.treeshape.s * (1 + k / 10.0)) + (config.treeshape.h * (1 + k / 10.0)) / 2;
    topmostP.x = 0; topmostP.y = -(sqrt(3.0) * 2.0 / 3.0) * (config.treeshape.s * (1 + k / 10.0));
    n_topP.x = topP.x * cos(theta) - topP.y * sin(theta) + RefPoint.x;
    n_topP.y = topP.y * cos(theta) + topP.x * sin(theta) + RefPoint.y;
    n_trunkP.x = trunkP.x * cos(theta) - trunkP.y * sin(theta) + RefPoint.x;
    n_trunkP.y = trunkP.y * cos(theta) + trunkP.x * sin(theta) + RefPoint.y;
    n_topmostP.x = topmostP.x * cos(theta) - topmostP.y * sin(theta) + RefPoint.x;
    n_topmostP.y = topmostP.y * cos(theta) + topmostP.x * sin(theta) + RefPoint.y;
    top->setRefPoint(n_topP);
    trunk->setRefPoint(n_trunkP);
    topmost->setRefPoint(n_topmostP);
    topmost->rotate(c);
    top->rotate(c);
    base->rotate(c);
    trunk->rotate(c);
}

void ChristmasTree::move(int c) {
    if (c == 0) { RefPoint.x += 30; }
    if (c == 1) { RefPoint.x -= 30; }
    if (c == 2) { RefPoint.y += 30; }
    if (c == 3) { RefPoint.y -= 30; }
    point topP, n_topP, trunkP, n_trunkP, topmostP, n_topmostP;
    topP.x = 0; topP.y = 0 - (sqrt(3.0) / 3.0) * (config.treeshape.s * (1 + k / 10.0));
    trunkP.x = 0; trunkP.y = 0 + (sqrt(3.0) / 6.0) * (config.treeshape.s * (1 + k / 10.0)) + (config.treeshape.h * (1 + k / 10.0)) / 2;
    topmostP.x = 0; topmostP.y = -(sqrt(3.0) * 2.0 / 3.0) * (config.treeshape.s * (1 + k / 10.0));
    n_topP.x = topP.x * cos(theta) - topP.y * sin(theta) + RefPoint.x;
    n_topP.y = topP.y * cos(theta) + topP.x * sin(theta) + RefPoint.y;
    n_trunkP.x = trunkP.x * cos(theta) - trunkP.y * sin(theta) + RefPoint.x;
    n_trunkP.y = trunkP.y * cos(theta) + trunkP.x * sin(theta) + RefPoint.y;
    n_topmostP.x = topmostP.x * cos(theta) - topmostP.y * sin(theta) + RefPoint.x;
    n_topmostP.y = topmostP.y * cos(theta) + topmostP.x * sin(theta) + RefPoint.y;
    top->setRefPoint(n_topP);
    trunk->setRefPoint(n_trunkP);
    topmost->setRefPoint(n_topmostP);
    base->setRefPoint(RefPoint);
    draw();
}

bool ChristmasTree::checkbound()
{
    if (top->checkbound() && base->checkbound() && topmost->checkbound() && trunk->checkbound())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void ChristmasTree::setColor(color c)
{
    fillColor = c;
    base->setColor(c);
    top->setColor(c);
    topmost->setColor(c);
    trunk->setColor(c);
}


////////////////////////////////////////////////////  class Home  ///////////////////////////////////////

Home::Home(game* r_pGame, point ref) : shape(r_pGame, ref) {
    point RefBase = ref;
    point RefRoof = { ref.x, ref.y - config.homeshape.s / 2 - (sqrt(3.0) / 6) * (config.homeshape.s) };
    roof = new Triangle(r_pGame, RefRoof, config.homeshape.s);
    baseSquare = new Rect(r_pGame, RefBase, config.homeshape.s, config.homeshape.s);
    point refChimney = { ref.x - config.homeshape.s / 2.5, ref.y - config.homeshape.s / 2 - (sqrt(3.0) / 6) * (config.homeshape.s) };
    chimeny = new Rect(r_pGame, refChimney, config.homeshape.s, config.homeshape.s / 5);
    point toppo = { ref.x,ref.y - config.homeshape.s / 2 - (sqrt(3.0) / 2) * (config.homeshape.s) };
    top = new circle(r_pGame, toppo, config.homeshape.s / 10);
    type = HOME;
}

bool Home::draw() const {
    point roofp, n_roofp, chimenyP, n_chimenyP, topP, n_topP;
    roofp.x = 0; roofp.y = -(config.homeshape.s * (1 + k / 10.0)) / 2 - (sqrt(3.0) / 6) * (config.homeshape.s * (1 + k / 10.0));
    topP.x = 0; topP.y = -config.homeshape.s * (1 + k / 10.0) / 2 - (sqrt(3.0) / 2) * (config.homeshape.s * (1 + k / 10.0));
    chimenyP.x = -config.homeshape.s * (1 + k / 10.0) / 2.5;
    chimenyP.y = -config.homeshape.s * (1 + k / 10.0) / 2 - (sqrt(3.0) / 6) * (config.homeshape.s * (1 + k / 10.0));
    n_roofp.x = roofp.x * cos(theta) - roofp.y * sin(theta) + RefPoint.x;
    n_roofp.y = roofp.y * cos(theta) + roofp.x * sin(theta) + RefPoint.y;
    n_chimenyP.x = chimenyP.x * cos(theta) - chimenyP.y * sin(theta) + RefPoint.x;
    n_chimenyP.y = chimenyP.y * cos(theta) + chimenyP.x * sin(theta) + RefPoint.y;
    n_topP.x = topP.x * cos(theta) - topP.y * sin(theta) + RefPoint.x;
    n_topP.y = topP.y * cos(theta) + topP.x * sin(theta) + RefPoint.y;
    top->setRefPoint(n_topP);
    chimeny->setRefPoint(n_chimenyP);
    roof->setRefPoint(n_roofp);
    roof->setparamaters(k, theta);
    baseSquare->setparamaters(k, theta);
    chimeny->setparamaters(k, theta);
    top->setparamaters(k, theta);
    if (top->checkbound() && chimeny->checkbound() && roof->checkbound() && baseSquare->checkbound())
    {
        roof->draw();
        baseSquare->draw();
        chimeny->draw();
        top->draw();
        return true;
    }
    else
    {
        return false;
    }

}

void Home::resize(int c)
{
    if (c == 1 && k < 10) { k++; };
    if (c == 0 && k > -10) { k--; };


    point roofp, n_roofp, chimenyP, n_chimenyP, topP, n_topP;
    roofp.x = 0; roofp.y = -(config.homeshape.s * (1 + k / 10.0)) / 2 - (sqrt(3.0) / 6) * (config.homeshape.s * (1 + k / 10.0));
    topP.x = 0; topP.y = -config.homeshape.s * (1 + k / 10.0) / 2 - (sqrt(3.0) / 2) * (config.homeshape.s * (1 + k / 10.0));
    chimenyP.x = -config.homeshape.s * (1 + k / 10.0) / 2.5;
    chimenyP.y = -config.homeshape.s * (1 + k / 10.0) / 2 - (sqrt(3.0) / 6) * (config.homeshape.s * (1 + k / 10.0));
    n_roofp.x = roofp.x * cos(theta) - roofp.y * sin(theta) + RefPoint.x;
    n_roofp.y = roofp.y * cos(theta) + roofp.x * sin(theta) + RefPoint.y;
    n_chimenyP.x = chimenyP.x * cos(theta) - chimenyP.y * sin(theta) + RefPoint.x;
    n_chimenyP.y = chimenyP.y * cos(theta) + chimenyP.x * sin(theta) + RefPoint.y;
    n_topP.x = topP.x * cos(theta) - topP.y * sin(theta) + RefPoint.x;
    n_topP.y = topP.y * cos(theta) + topP.x * sin(theta) + RefPoint.y;
    top->setRefPoint(n_topP);
    chimeny->setRefPoint(n_chimenyP);
    roof->setRefPoint(n_roofp);
    roof->resize(c);
    baseSquare->resize(c);
    top->resize(c);
    chimeny->resize(c);
}

void Home::rotate(int c)  {
    if (c == 1)
    {
        theta += (22.0 / 56.0);
    }
    if (c == 0)
    {
        theta -= (22.0 / 56.0);
    }
    point roofp, n_roofp, chimenyP, n_chimenyP, topP, n_topP;
    roofp.x = 0; roofp.y = -(config.homeshape.s * (1 + k / 10.0)) / 2 - (sqrt(3.0) / 6) * (config.homeshape.s * (1 + k / 10.0));
    topP.x = 0; topP.y = -config.homeshape.s * (1 + k / 10.0) / 2 - (sqrt(3.0) / 2) * (config.homeshape.s * (1 + k / 10.0));
    chimenyP.x = -config.homeshape.s * (1 + k / 10.0) / 2.5;
    chimenyP.y = -config.homeshape.s * (1 + k / 10.0) / 2 - (sqrt(3.0) / 6) * (config.homeshape.s * (1 + k / 10.0));
    n_roofp.x = roofp.x * cos(theta) - roofp.y * sin(theta) + RefPoint.x;
    n_roofp.y = roofp.y * cos(theta) + roofp.x * sin(theta) + RefPoint.y;
    n_chimenyP.x = chimenyP.x * cos(theta) - chimenyP.y * sin(theta) + RefPoint.x;
    n_chimenyP.y = chimenyP.y * cos(theta) + chimenyP.x * sin(theta) + RefPoint.y;
    n_topP.x = topP.x * cos(theta) - topP.y * sin(theta) + RefPoint.x;
    n_topP.y = topP.y * cos(theta) + topP.x * sin(theta) + RefPoint.y;
    top->setRefPoint(n_topP);
    chimeny->setRefPoint(n_chimenyP);
    roof->setRefPoint(n_roofp);
    roof->rotate(c);
    baseSquare->rotate(c);
    top->rotate(c);
    chimeny->rotate(c);
}

void Home::move(int c) {
    if (c == 0) { RefPoint.x += 30; }
    if (c == 1) { RefPoint.x -= 30; }
    if (c == 2) { RefPoint.y += 30; }
    if (c == 3) { RefPoint.y -= 30; }
    point roofp, n_roofp, chimenyP, n_chimenyP, topP, n_topP;
    roofp.x = 0; roofp.y = -(config.homeshape.s * (1 + k / 10.0)) / 2 - (sqrt(3.0) / 6) * (config.homeshape.s * (1 + k / 10.0));
    topP.x = 0; topP.y = -config.homeshape.s * (1 + k / 10.0) / 2 - (sqrt(3.0) / 2) * (config.homeshape.s * (1 + k / 10.0));
    chimenyP.x = -config.homeshape.s * (1 + k / 10.0) / 2.5;
    chimenyP.y = -config.homeshape.s * (1 + k / 10.0) / 2 - (sqrt(3.0) / 6) * (config.homeshape.s * (1 + k / 10.0));
    n_roofp.x = roofp.x * cos(theta) - roofp.y * sin(theta) + RefPoint.x;
    n_roofp.y = roofp.y * cos(theta) + roofp.x * sin(theta) + RefPoint.y;
    n_chimenyP.x = chimenyP.x * cos(theta) - chimenyP.y * sin(theta) + RefPoint.x;
    n_chimenyP.y = chimenyP.y * cos(theta) + chimenyP.x * sin(theta) + RefPoint.y;
    n_topP.x = topP.x * cos(theta) - topP.y * sin(theta) + RefPoint.x;
    n_topP.y = topP.y * cos(theta) + topP.x * sin(theta) + RefPoint.y;
    top->setRefPoint(n_topP);
    chimeny->setRefPoint(n_chimenyP);
    roof->setRefPoint(n_roofp);
    baseSquare->setRefPoint(RefPoint);
    draw();
}

bool Home::checkbound()
{
    if (top->checkbound() && chimeny->checkbound() && roof->checkbound() && baseSquare->checkbound())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Home::setColor(color c)
{
    fillColor = c;
    chimeny->setColor(c);
    top->setColor(c);
    roof->setColor(c);
    baseSquare->setColor(c);
}

////////////////////////////////////////////////////  class Hat  ///////////////////////////////////////

Hat::Hat(game* r_pGame, point ref) : shape(r_pGame, ref) {

    cone = new Triangle(r_pGame, ref, config.hatshape.s);
    hat = new circle(r_pGame, point{ ref.x, ref.y - (config.hatshape.s / sqrt(3)) }, config.hatshape.r);
    buttom = new Rect(r_pGame, point{ ref.x, ref.y + (config.hatshape.s / sqrt(6)) }, config.hatshape.s / 5, config.hatshape.s * 1.05);
    type = HAT;
}

bool Hat::draw() const {
    point p, n_p, buttP, n_buttP;
    p.x = 0; p.y = -((config.hatshape.s * (1 + k / 10.0)) / sqrt(3));
    buttP.x = 0; buttP.y = config.hatshape.s * (1 + k / 10.0) / sqrt(6);
    n_p.x = p.x * cos(theta) - p.y * sin(theta) + RefPoint.x;
    n_p.y = p.y * cos(theta) + p.x * sin(theta) + RefPoint.y;
    n_buttP.x = buttP.x * cos(theta) - buttP.y * sin(theta) + RefPoint.x;
    n_buttP.y = buttP.y * cos(theta) + buttP.x * sin(theta) + RefPoint.y;
    hat->setRefPoint(n_p);
    buttom->setRefPoint(n_buttP);
    cone->setparamaters(k, theta);
    hat->setparamaters(k, theta);
    buttom->setparamaters(k, theta);
    if (hat->checkbound() && buttom->checkbound() && cone->checkbound())
    {
        cone->draw();
        hat->draw();
        buttom->draw();
        return true;
    }
    else
    {
        return false;
    }

}

void Hat::resize(int c) {
    if (c == 1 && k < 10) { k++; };
    if (c == 0 && k > -10) { k--; };

    point p, n_p, buttP, n_buttP;
    p.x = 0; p.y = -((config.hatshape.s * (1 + k / 10.0)) / sqrt(3));
    buttP.x = 0; buttP.y = config.hatshape.s * (1 + k / 10.0) / sqrt(6);
    n_p.x = p.x * cos(theta) - p.y * sin(theta) + RefPoint.x;
    n_p.y = p.y * cos(theta) + p.x * sin(theta) + RefPoint.y;
    n_buttP.x = buttP.x * cos(theta) - buttP.y * sin(theta) + RefPoint.x;
    n_buttP.y = buttP.y * cos(theta) + buttP.x * sin(theta) + RefPoint.y;
    hat->setRefPoint(n_p);
    buttom->setRefPoint(n_buttP);
    cone->resize(c);
    hat->resize(c);
    buttom->resize(c);

}

void Hat::rotate(int c)  {
    if (c == 1)
    {
        theta += (22.0 / 56.0);
    }
    if (c == 0)
    {
        theta -= (22.0 / 56.0);
    }
    point p, n_p, buttP, n_buttP;
    p.x = 0; p.y = -((config.hatshape.s * (1 + k / 10.0)) / sqrt(3));
    buttP.x = 0; buttP.y = config.hatshape.s * (1 + k / 10.0) / sqrt(6);
    n_p.x = p.x * cos(theta) - p.y * sin(theta) + RefPoint.x;
    n_p.y = p.y * cos(theta) + p.x * sin(theta) + RefPoint.y;
    n_buttP.x = buttP.x * cos(theta) - buttP.y * sin(theta) + RefPoint.x;
    n_buttP.y = buttP.y * cos(theta) + buttP.x * sin(theta) + RefPoint.y;
    hat->setRefPoint(n_p);
    buttom->setRefPoint(n_buttP);
    cone->rotate(c);
    hat->rotate(c);
    buttom->rotate(c);
}

void Hat::move(int c) {
    if (c == 0) { RefPoint.x += 30; }
    if (c == 1) { RefPoint.x -= 30; }
    if (c == 2) { RefPoint.y += 30; }
    if (c == 3) { RefPoint.y -= 30; }
    point p, n_p, buttP, n_buttP;
    p.x = 0; p.y = -((config.hatshape.s * (1 + k / 10.0)) / sqrt(3));
    buttP.x = 0; buttP.y = config.hatshape.s * (1 + k / 10.0) / sqrt(6);
    n_p.x = p.x * cos(theta) - p.y * sin(theta) + RefPoint.x;
    n_p.y = p.y * cos(theta) + p.x * sin(theta) + RefPoint.y;
    n_buttP.x = buttP.x * cos(theta) - buttP.y * sin(theta) + RefPoint.x;
    n_buttP.y = buttP.y * cos(theta) + buttP.x * sin(theta) + RefPoint.y;
    hat->setRefPoint(n_p);
    buttom->setRefPoint(n_buttP);
    cone->setRefPoint(RefPoint);
    draw();
}

bool Hat::checkbound()
{
    if (hat->checkbound() && buttom->checkbound() && cone->checkbound())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Hat::setColor(color c)
{
    fillColor = c;
    hat->setColor(c);
    buttom->setColor(c);
    cone->setColor(c);
}


////////////////////////////////////////////////////  class Bullet  ///////////////////////////////////////

Bullet::Bullet(game* r_pGame, point ref) : shape(r_pGame, ref) {
    point RefRect = ref;
    point RefTri = { ref.x, ref.y - config.bulletshape.h / 2 - (sqrt(3.0) / 6.0) * config.bulletshape.w };
    point RefCircle = { ref.x, ref.y + config.bulletshape.h / 2 };
    topTriangle = new Triangle(r_pGame, RefTri, config.bulletshape.w);
    middleRect = new Rect(r_pGame, RefRect, config.bulletshape.h, config.bulletshape.w);
    bottomSemiCircle = new circle(r_pGame, RefCircle, config.bulletshape.w / 2);
    type = BULLET;
}

bool Bullet::draw() const {
    point triP, n_triP, semiP, n_semiP;
    triP.x = 0; triP.y = -(config.bulletshape.h * (1 + k / 10.0)) / 2 - (sqrt(3.0) / 6.0) * (config.bulletshape.w * (1 + k / 10.0));
    semiP.x = 0; semiP.y = (config.bulletshape.h * (1 + k / 10.0)) / 2;
    n_triP.x = triP.x * cos(theta) - triP.y * sin(theta) + RefPoint.x;
    n_triP.y = triP.y * cos(theta) + triP.x * sin(theta) + RefPoint.y;
    n_semiP.x = semiP.x * cos(theta) - semiP.y * sin(theta) + RefPoint.x;
    n_semiP.y = semiP.y * cos(theta) + semiP.x * sin(theta) + RefPoint.y;
    topTriangle->setRefPoint(n_triP);
    bottomSemiCircle->setRefPoint(n_semiP);
    topTriangle->setparamaters(k, theta);
    middleRect->setparamaters(k, theta);
    bottomSemiCircle->setparamaters(k, theta);
    if (topTriangle->checkbound() && bottomSemiCircle->checkbound() && middleRect->checkbound())
    {
        topTriangle->draw();
        middleRect->draw();
        bottomSemiCircle->draw();
        return true;
    }
    else
    {
        return false;
    }

}

void Bullet::resize(int c) {
    if (c == 1 &&k<10) { k++; };
    if (c == 0 && k > -10) { k--; };

    point triP, n_triP, semiP, n_semiP;
    triP.x = 0; triP.y = -(config.bulletshape.h * (1 + k / 10.0)) / 2 - (sqrt(3.0) / 6.0) * (config.bulletshape.w * (1 + k / 10.0));
    semiP.x = 0; semiP.y = (config.bulletshape.h * (1 + k / 10.0)) / 2;
    n_triP.x = triP.x * cos(theta) - triP.y * sin(theta) + RefPoint.x;
    n_triP.y = triP.y * cos(theta) + triP.x * sin(theta) + RefPoint.y;
    n_semiP.x = semiP.x * cos(theta) - semiP.y * sin(theta) + RefPoint.x;
    n_semiP.y = semiP.y * cos(theta) + semiP.x * sin(theta) + RefPoint.y;
    topTriangle->setRefPoint(n_triP);
    bottomSemiCircle->setRefPoint(n_semiP);
    topTriangle->resize(c);
    bottomSemiCircle->resize(c);
    middleRect->resize(c);
}


void Bullet::rotate(int c)  {
    if (c == 1)
    {
        theta += (22.0 / 56.0);
    }
    if (c == 0)
    {
        theta -= (22.0 / 56.0);
    }
    point triP, n_triP, semiP, n_semiP;
    triP.x = 0; triP.y = -(config.bulletshape.h * (1 + k / 10.0)) / 2 - (sqrt(3.0) / 6.0) * (config.bulletshape.w * (1 + k / 10.0));
    semiP.x = 0; semiP.y = (config.bulletshape.h * (1 + k / 10.0)) / 2;
    n_triP.x = triP.x * cos(theta) - triP.y * sin(theta) + RefPoint.x;
    n_triP.y = triP.y * cos(theta) + triP.x * sin(theta) + RefPoint.y;
    n_semiP.x = semiP.x * cos(theta) - semiP.y * sin(theta) + RefPoint.x;
    n_semiP.y = semiP.y * cos(theta) + semiP.x * sin(theta) + RefPoint.y;
    topTriangle->setRefPoint(n_triP);
    bottomSemiCircle->setRefPoint(n_semiP);
    topTriangle->rotate(c);
    bottomSemiCircle->rotate(c);
    middleRect->rotate(c);

}

void Bullet::move(int c) {
    if (c == 0) { RefPoint.x += 30; }
    if (c == 1) { RefPoint.x -= 30; }
    if (c == 2) { RefPoint.y += 30; }
    if (c == 3) { RefPoint.y -= 30; }
    point triP, n_triP, semiP, n_semiP;
    triP.x = 0; triP.y = -(config.bulletshape.h * (1 + k / 10.0)) / 2 - (sqrt(3.0) / 6.0) * (config.bulletshape.w * (1 + k / 10.0));
    semiP.x = 0; semiP.y = (config.bulletshape.h * (1 + k / 10.0)) / 2;
    n_triP.x = triP.x * cos(theta) - triP.y * sin(theta) + RefPoint.x;
    n_triP.y = triP.y * cos(theta) + triP.x * sin(theta) + RefPoint.y;
    n_semiP.x = semiP.x * cos(theta) - semiP.y * sin(theta) + RefPoint.x;
    n_semiP.y = semiP.y * cos(theta) + semiP.x * sin(theta) + RefPoint.y;
    topTriangle->setRefPoint(n_triP);
    bottomSemiCircle->setRefPoint(n_semiP);
    middleRect->setRefPoint(RefPoint);
    draw();
}

bool Bullet::checkbound()
{
    if (topTriangle->checkbound() && bottomSemiCircle->checkbound() && middleRect->checkbound())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Bullet::setColor(color c)
{
    fillColor = c;
    topTriangle->setColor(c);
    bottomSemiCircle->setColor(c);
    middleRect->setColor(c);
}



////////////////////////////////////////////////////  class lolypop  ///////////////////////////////////////

lolypop::lolypop(game* r_pGame, point ref) : shape(r_pGame, ref) {
    bottom = new Rect(r_pGame, ref, config.lolypopshape.h, config.lolypopshape.h / 10);
    double x2 = ref.x;
    double y2 = (ref.y - (config.lolypopshape.h / 2) - config.lolypopshape.r);
    top = new circle(r_pGame, point{ x2, y2 }, config.lolypopshape.r);
    type = LOLYPOP;
}

bool lolypop::draw() const {
    point p, n_p;
    p.x = 0; p.y = -((config.lolypopshape.h * (1 + k / 10.0)) / 2) - (config.lolypopshape.r * (1 + k / 10.0));
    n_p.x = p.x * cos(theta) - p.y * sin(theta) + RefPoint.x;
    n_p.y = p.y * cos(theta) + p.x * sin(theta) + RefPoint.y;
    top->setRefPoint(n_p);
    bottom->setparamaters(k, theta);
    top->setparamaters(k, theta);
    if (top->checkbound() && bottom->checkbound())
    {
        bottom->draw();
        top->draw();
        return true;
    }
    else
    {
        return false;
    }

}

void lolypop::resize(int c)
{

    if (c == 1 && k<10) { k++; };
    if (c == 0 && k > -10) { k--; };

    point p, n_p;
    p.x = 0; p.y = -((config.lolypopshape.h * (1 + k / 10.0)) / 2) - (config.lolypopshape.r * (1 + k / 10.0));
    n_p.x = p.x * cos(theta) - p.y * sin(theta) + RefPoint.x;
    n_p.y = p.y * cos(theta) + p.x * sin(theta) + RefPoint.y;
    top->setRefPoint(n_p);
    top->resize(c);
    bottom->resize(c);
}
    

void lolypop::rotate(int c) 
{
    if (c == 1)
    {
        theta += (22.0 / 56.0);
    }
    if (c == 0)
    {
        theta -= (22.0 / 56.0);
    }
    point p, n_p;
    p.x = 0; p.y = -((config.lolypopshape.h * (1 + k / 10.0)) / 2) - (config.lolypopshape.r * (1 + k / 10.0));
    n_p.x = p.x * cos(theta) - p.y * sin(theta) + RefPoint.x;
    n_p.y = p.y * cos(theta) + p.x * sin(theta) + RefPoint.y;
    top->setRefPoint(n_p);
    top->rotate(c);
    bottom->rotate(c);
}

void lolypop::move(int c) {
    if (c == 0) { RefPoint.x += 30; }
    if (c == 1) { RefPoint.x -= 30; }
    if (c == 2) { RefPoint.y += 30; }
    if (c == 3) { RefPoint.y -= 30; }
    point p, n_p;
    p.x = 0; p.y = -((config.lolypopshape.h * (1 + k / 10.0)) / 2) - (config.lolypopshape.r * (1 + k / 10.0));
    n_p.x = p.x * cos(theta) - p.y * sin(theta) + RefPoint.x;
    n_p.y = p.y * cos(theta) + p.x * sin(theta) + RefPoint.y;
    top->setRefPoint(n_p);
    bottom->setRefPoint(RefPoint);
    draw();
}

bool lolypop::checkbound()
{
    if (top->checkbound() && bottom->checkbound())
    {
        return true;
    }
    else
    {
        return false;
    }
}


void lolypop::setColor(color c)
{
    fillColor = c;
    top->setColor(c);
    bottom->setColor(c);
}


////////////////////////////////////////////////////  class Flag  ///////////////////////////////////////

Flag::Flag(game* r_pGame, point ref) : shape(r_pGame, ref)
{
    point RefTop = { ref.x,ref.y };
    point RefRod = { ref.x + ((config.Flagshape.h / 2) - config.Flagshape.s / 2) , ref.y + (sqrt(3.0) / 6.0) * config.Flagshape.s + config.Flagshape.w / 2 };
    rod = new Rect(r_pGame, RefRod, config.Flagshape.w, config.Flagshape.h);
    top = new Triangle(r_pGame, RefTop, config.Flagshape.s);
    type = FLAG;
}

bool Flag::draw() const {
    point p, n_p;
    p.x = ((config.Flagshape.h * (1 + k / 10.0)) / 2) - (config.Flagshape.s * (1 + k / 10.0)) / 2;
    p.y = (sqrt(3.0) / 6.0) * (config.Flagshape.s * (1 + k / 10.0)) + (config.Flagshape.w * (1 + k / 10.0)) / 2;
    n_p.x = p.x * cos(theta) - p.y * sin(theta) + RefPoint.x;
    n_p.y = p.y * cos(theta) + p.x * sin(theta) + RefPoint.y;
    rod->setRefPoint(n_p);
    rod->setparamaters(k, theta);
    top->setparamaters(k, theta);
    if (top->checkbound() && rod->checkbound())
    {
        rod->draw();
        top->draw();
        return true;
    }
    else
    {
        return false;
    }

}

void Flag::resize(int c)
{
    if (c == 1 && k < 10) { k++; };
    if (c == 0 && k > -10) { k--; };
    point p, n_p;
    p.x = ((config.Flagshape.h * (1 + k / 10.0)) / 2) - (config.Flagshape.s * (1 + k / 10.0)) / 2;
    p.y = (sqrt(3.0) / 6.0) * (config.Flagshape.s * (1 + k / 10.0)) + (config.Flagshape.w * (1 + k / 10.0)) / 2;
    n_p.x = p.x * cos(theta) - p.y * sin(theta) + RefPoint.x;
    n_p.y = p.y * cos(theta) + p.x * sin(theta) + RefPoint.y;
    rod->setRefPoint(n_p);
    rod->resize(c);
    top->resize(c);
}

void Flag::rotate(int c) 
{
    if (c == 1)
    {
        theta += (22.0 / 56.0);
    }
    if (c == 0)
    {
        theta -= (22.0 / 56.0);
    }
    point p, n_p;
    p.x = ((config.Flagshape.h * (1 + k / 10.0)) / 2) - (config.Flagshape.s * (1 + k / 10.0)) / 2;
    p.y = (sqrt(3.0) / 6.0) * (config.Flagshape.s * (1 + k / 10.0)) + (config.Flagshape.w * (1 + k / 10.0)) / 2;
    n_p.x = p.x * cos(theta) - p.y * sin(theta) + RefPoint.x;
    n_p.y = p.y * cos(theta) + p.x * sin(theta) + RefPoint.y;
    rod->setRefPoint(n_p);
    rod->rotate(c);
    top->rotate(c);
}

void Flag::move(int c) {
    if (c == 0) { RefPoint.x += 30; }
    if (c == 1) { RefPoint.x -= 30; }
    if (c == 2) { RefPoint.y += 30; }
    if (c == 3) { RefPoint.y -= 30; }
    point p, n_p;
    p.x = ((config.Flagshape.h * (1 + k / 10.0)) / 2) - (config.Flagshape.s * (1 + k / 10.0)) / 2;
    p.y = (sqrt(3.0) / 6.0) * (config.Flagshape.s * (1 + k / 10.0)) + (config.Flagshape.w * (1 + k / 10.0)) / 2;
    n_p.x = p.x * cos(theta) - p.y * sin(theta) + RefPoint.x;
    n_p.y = p.y * cos(theta) + p.x * sin(theta) + RefPoint.y;
    rod->setRefPoint(n_p);
    top->setRefPoint(RefPoint);
    draw();
}

bool Flag::checkbound()
{
    if (top->checkbound() && rod->checkbound())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Flag::setColor(color c)
{
    fillColor = c;
    top->setColor(c);
    rod->setColor(c);
}

