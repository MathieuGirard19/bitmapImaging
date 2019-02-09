#pragma once
#include <iostream>
#include <vector>
#include "Drawing.h"
using namespace std;

class DrawObject {
private:
	COLOUR colour;
protected:
	vector<COORD> coord;
public:
	DrawObject(COLOUR c) : colour(c) {};
	COLOUR getCOLOUR() { return colour; }
	virtual void draw(Drawing &draw) = 0;
};

class Point : public DrawObject {
private:
public:
	Point(COLOUR c, COORD cd) : DrawObject(c) {
		coord.push_back(cd);
	}
	void draw(Drawing &draw) {
		draw.setPixel(coord.at(0), getCOLOUR());
		return;
	}
};

class Line : public DrawObject {
private:

public:
	Line(COLOUR c, COORD cd1, COORD cd2) : DrawObject(c) {
		coord.push_back(cd1);
		coord.push_back(cd2);
	}
	void draw(Drawing &draw) {
		draw.drawLine(coord.at(0), coord.at(1), getCOLOUR());
	}
};

class Shape : public DrawObject {
private:
	static int ShapeCounter;
public:
	Shape(COLOUR c) : DrawObject(c) { ShapeCounter++; }
	void draw(Drawing &draw) {
		for (int i = 0; (i+1)< coord.size(); i++) {
			draw.drawLine(coord.at(i), coord.at(i + 1), getCOLOUR());
		}
		draw.drawLine(coord.at(0), coord.at(coord.size() - 1), getCOLOUR());
	}

	void addCOORD(COORD cd) {
		coord.push_back(cd);
	}

	static int getCounter(){
		return ShapeCounter;
	}

	~Shape(){ShapeCounter--;}
};

int Shape::ShapeCounter = 0;