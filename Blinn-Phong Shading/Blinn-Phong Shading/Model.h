#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include "glut.h"

#define INF	0x7f7f7f7f

#pragma warning(disable:4996) 

using namespace std;

class Vector {
public:
	double x;
	double y;
	double z;

	Vector() : x(0), y(0), z(0) {}
	Vector(double _x, double _y, double  _z) : x(_x), y(_y), z(_z) {}

	Vector operator+(const Vector& v) {
		return Vector(x + v.x, y + v.y, z + v.z);
	}
	Vector operator-(const Vector& v) {
		return Vector(x - v.x, y - v.y, z - v.z);
	}
	Vector operator*(const double scalar) {
		return Vector(x * scalar, y * scalar, z * scalar);
	}
	Vector operator/(const double scalar) {
		return Vector(x / scalar, y / scalar, z / scalar);
	}

	double GetSize() {
		return sqrt(x * x + y * y + z * z);
	}

	Vector GetNormalizedVector() {
		return *this / GetSize();
	}

	Vector Cross(const Vector& v) {
		return Vector(y * v.z - z * v.y,
			z * v.x - x * v.z,
			x * v.y - y * v.x);
	}
};

class Vertex {
public:
	Vector pos;
	int index;

	Vertex(const Vector& _pos, int _index) : pos(_pos), index(_index) {}

};

class Face {
public:
	Vertex* vertex[3];

	Face(Vertex* v1, Vertex* v2, Vertex* v3) {
		vertex[0] = v1;
		vertex[1] = v2;
		vertex[2] = v3;
	}

};

class Model {
public:
	vector<Face> faces;
	vector<Vertex*> vertices;
	vector<Vector*> normalVector;

	Vector max;
	Vector min;

	Model(const char* obj_path);
	void DrawPoint();
	void DrawModel();
	void ComputeNormal();

	vector<Vertex*>& GetVertices() {
		return vertices;
	}

};