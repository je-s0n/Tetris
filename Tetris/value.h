#pragma once

#include <iostream>
#include <time.h> // 테트리스 게임이 블럭을 쌓아서 한 줄 채우면 터지는 게임인데, 블럭은 랜덤으로 나오기 때문에 포함시킴

using namespace std;

#include "Macro.h"

#define STAGE_WIDTH 10 // 가로 길이
#define STAGE_HEIGHT 15 // 세로 길이

typedef struct _tagPosition
{
	int x;
	int y;
	_tagPosition() : x(0), y(0)
	{
	}

	_tagPosition(const _tagPosition& pos)
	{
		*this = pos;
	}

	_tagPosition(int _x, int _y) : x(_x), y(_y)
	{
	}

	// 구조체끼리 연산하기 위해 간단히 만들어두자
	/***** plus *****/
	_tagPosition operator +(const _tagPosition& pos)
	{
		_tagPosition p;
		p.x = x + pos.x;
		p.y = y + pos.y;
		return p;
	}

	_tagPosition operator +(int i)
	{
		_tagPosition p;
		p.x = x + i;
		p.y = y + i;
		return p;
	}

	void operator +=(const _tagPosition& pos) 
	{
		x += pos.x;
		y += pos.y;
	}

	void operator +=(int i)
	{
		x += i;
		y += i;
	}


	/***** minus *****/
	_tagPosition operator -(const _tagPosition& pos)
	{
		_tagPosition p;
		p.x = x - pos.x;
		p.y = y - pos.y;
		return p;
	}

	_tagPosition operator -(int i)
	{
		_tagPosition p;
		p.x = x - i;
		p.y = y - i;
		return p;
	}

	void operator -=(const _tagPosition& pos)
	{
		x -= pos.x;
		y -= pos.y;
	}

	void operator -=(int i)
	{
		x -= i;
		y -= i;
	}


	/***** equal *****/
	void operator =(const _tagPosition& pos)
	{
		x = pos.x;
		y = pos.y;
	}
} POSITION, *PPOSITION;