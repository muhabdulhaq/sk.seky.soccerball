#pragma once
#include <opencv2/core/core.hpp>
#include "opencv2/opencv.hpp"
#include <queue> 

#define SAFE_DELETE(a) if( (a) != NULL ) delete (a); (a) = NULL;

using namespace cv;
using namespace std;

/*
* Opencv examples
*/
inline ostream& operator<< (ostream& out, Point2f& object) {
	out << "Point2f(x:" << object.x << ", y:" << object.y << ")";
	return out;
}

inline ostream& operator<< (ostream& out, Point3f& object) {
	out << "Point3f(x:" << object.x << ", y:" << object.y << ", z:" << object.z << ")";
	return out;
}

inline ostream& operator<< (ostream& out, RotatedRect& object) {
	out << "RotatedRect(center:" << object.center << ", size:" << object.size << ")";
	return out;
}

/**
* Trieda pre obrazok ako univerzalna entita v ramci Carlos.
*/
class Image {
public:
	double pos_msec; // urcuje poziciu snimky vo video v ms
	Mat data;

	friend ostream& operator<< (ostream& out, Image& object) {
		out << "Image(pos_msec:" << object.pos_msec << ")";
		return out;
	}
};

/**
* Trieda reprezentuje objekt detekovany na obrazovke videa.
* Dany objekt odkazuje na svetovy objekt
*/
class FrameObject {
public:
	RotatedRect boundary;
	int frame;

	friend ostream& operator<< (ostream& out, FrameObject& object) {
		out << "FrameObject(";
		out << "boundary: " << object.boundary << ",";
		out << "frame: " << object.frame << ",";
		out << ")";
		return out;
	}
};

class SoccerObject {
public:
	UINT id; // generovane ID
	queue<FrameObject> positions; // TODO: moze byt obmedzeny na 20snimkov a info budeme ukladat inde
	// int speed; // jeho posledne zachytena rychlost aby smem sledoval ikde asi bude
	bool visible; // objekt s adalej uz enbude zobrazovat
	UINT team;

	int distance() {
		// Vypocitaj vzdialenost, ktoru presiel z historie
	}

	friend ostream& operator<< (ostream& out, SoccerObject& object) {
		out << "SoccerObject(";
		out << "id: " << object.id << ",";
		//out << "speed: " << object.speed << ",";
		out << ")";
		return out;
	}
};