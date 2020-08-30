#ifndef _AMOOBJECT_H_
#define _AMOOBJECT_H_

#define WIDTH_LASER 38
#define HEIGHT_LASER 7

#define WIDTH_SPHERE 10
#define HEIGHT_SPHERE 10

#define WIDTH_RED_SLASH 94
#define HEIGHT_RED_SLASH 44

#define WIDTH_BLUE_SLASH 61
#define HEIGHT_BLUE_SLASH 66

#define WIDTH_ROCKET 104
#define HEIGHT_ROCKET 46

#define WIDTH_BOMB_ATOM 83
#define HEIGHT_BOMB_ATOM 28

#define AMO_THREAT_SPEED 10
#define AMO_MAIN_SPEED 30

#include"BaseObject.h"
#include"CommonFunction.h"

class AmoObject : public BaseObject {
private:
	int _xVal, _yVal;
	unsigned int _amoType;
	bool _isMove;
public:
	enum amoType {
		NONE, LAZER, SPHERE, RED_SLASH, BLUE_SLASH, ROCKET, BOMB_ATOM
	};

	AmoObject();
	~AmoObject();

	bool getIsMove() const;
	void handleMove(const int&, const int&);
	void handleMoveRToL();

	int getType() const;
	void handleInput(SDL_Event);

	void setIsMove(bool);
	void setType(const int&);

	void setWidthHeight(const int&, const int&);
	static void freeAmo(AmoObject*);

	void setX_Val(const int& val) { _xVal = val; }
	void setY_Val(const int& val) { _yVal = val; }

	int x_Val() { return _xVal; }
	int y_Val() { return _yVal; }
};

#endif // !
#pragma once