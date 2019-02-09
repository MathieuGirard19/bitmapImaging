#include<iostream>
#include "Drawable.h"
#include "Drawing.h"
#include<forward_list>
using namespace std;

int main(int argc, char* argv[]) {
	forward_list<DrawObject *> drawing;
	string filename = argv[1];
	COLOUR rgb = { atoi(argv[4]), atoi(argv[5]), atoi(argv[6]) };
	Drawing test(atoi(argv[2]), atoi(argv[3]), rgb);
	
	for (int i = 7; i < argc; i++) {//iterate through the entire list of arguments starting at the first argument for shapes
		switch (*argv[i]) {//only activate the switch statement when argv[] is a letter	
		case 'S': {
			//cout << *argv[i] << endl;
			COLOUR shapeColour = { atoi(argv[i + 1]), atoi(argv[i + 2]), atoi(argv[i + 3]) };//get first 3 argument corodinates for colours
			Shape *newShape = new Shape(shapeColour);
			int numberOfCoord = atoi(argv[i + 4]);//save the number of coordinates from argument passed
			int currentCoord = i + 5;
			for (int j = 0; j < numberOfCoord; j++) { //save coordinates
				COORD coord;
				coord.row = (atoi(argv[currentCoord]));
				coord.col = (atoi(argv[currentCoord + 1]));
				newShape->addCOORD(coord);
				currentCoord += 2;
			}
			drawing.push_front(newShape);//add new shape to list
			break;
		}

		case 'L': {
			COLOUR lineColour = { atoi(argv[i + 1]), atoi(argv[i + 2]), atoi(argv[i + 3]) };//get first 3 argument coordinates for colours
			COORD cord1, cord2;//save 2 coordiantes for a line
			cord1.row = (atoi(argv[i + 4]));
			cord1.col = (atoi(argv[i + 5]));
			cord2.row = (atoi(argv[i + 6]));
			cord2.col = (atoi(argv[i + 7]));
			Line *newLine = new Line(lineColour, cord1, cord2);
			drawing.push_front(newLine);
			break;
		}

		case 'P': {
			COLOUR pointColour = { atoi(argv[i + 1]), atoi(argv[i + 2]), atoi(argv[i + 3]) };//get first 3 argument coordinates for colours
			COORD cord;// save the single coordiante for a point
			cord.row = (atoi(argv[i + 4]));
			cord.col = (atoi(argv[i + 5]));
			Point *newPoint = new Point(pointColour, cord);
			drawing.push_front(newPoint);
			break;
		}
			default:
				break;
		}
	}

	for (int i = 0; !(drawing.empty()); i++) {//iterate through the list drawing the front item and then pooping that item off
		(*drawing.front()).draw(test);
		drawing.pop_front();
	}
	cout << "File created" << endl << "Number of Shapes:" << Shape::getCounter() << endl;
	test.saveBMP(filename);
	char c;
	cin >> c;
}