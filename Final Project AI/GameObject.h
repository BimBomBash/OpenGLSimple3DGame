#pragma once
struct Vector3 {
	float x, y, z;
	Vector3(float _x, float _y, float _z) :x(_x), y(_y), z(_z) {};
	static float DistanceXZ(Vector3 *a, Vector3 *b) {
		return sqrt(a->x*a->x + a->z*a->z);
	}
	float DistanceXZto(Vector3 *a) {
		return sqrt((x-a->x)*(x - a->x) + (z - a->z)*(z - a->z));
	}
};

struct Transform {
	Vector3 *position;
	Vector3 *rotation;
	Vector3 *scale;
	Transform() {
		position = new Vector3(0, 0, 0);
		rotation = new Vector3(0, 0, 0);
		scale = new Vector3(0, 0, 0);
	}
};

struct Coordinate {
	float x, y, z;
	Coordinate(float _x, float _y, float _z) { x = _x; y = _y; z = _z; }
};

struct Face {
	int faceNum;
	bool four;
	int faces[4];
	Face(int _faceNum, int f1, int f2, int f3) :faceNum(_faceNum) {
		faces[0] = f1;
		faces[1] = f2;
		faces[2] = f3;
		four = false;
	}
	Face(int _faceNum, int f1, int f2, int f3, int f4) :faceNum(_faceNum) {
		faces[0] = f1;
		faces[1] = f2;
		faces[2] = f3;
		faces[3] = f4;
		four = true;
	}
};

class GameObject
{
protected:
	int object;
	float rTri = 0;
public:
	Transform *transform;
	int LoadObject(const char* _filename);
	virtual void Draw();
	virtual void Update();
	GameObject();
	~GameObject();
};

