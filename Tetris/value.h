#pragma once

#include <iostream>
#include <time.h> // 테트리스 게임이 블럭을 쌓아서 한 줄 채우면 터지는 게임인데, 블럭은 랜덤으로 나옴

using namespace std;

#include "Macro.h"

#define STAGE_WIDTH 10 // 가로 길이
#define STAGE_HEIGHT 15 // 세로 길이