# tetris-game <br/>
♥️ Windows 환경에서 C++ Singleton Pattern으로 구현하는 테트리스 게임 <br/>
♥️ 목표 : 테트리스 게임 개발로 인한 C++ 이해 및 게임 개발 역량 강화 <br/>
<br/>

## 설계
```
Tetris
 ├ Flags.h // 테트리스 도형 종류와 도형 방향의 집합 정의된 헤더파일
 ├ Macro.h // 메모리 해제 함수가 정의된 헤더파일
 ├ main.cpp // main cpp파일
 ├ value.h // 스테이지 가로, 세로 길이 정의 및 스테이지 내 위치 +, -, = 하는 함수 정의
 └ Core
     ├ Core.cpp // 테트리스 게임 동작을 위해 전체적으로 관리하는 cpp파일
     └ Core.h
 └ Stage
     ├ Stage.cpp // 테트리스 도형을 스테이지에 추가/확인/초기화, 스테이지 Render하는 cpp파일 
     ├ Stage.h
     ├ StageManager.cpp // 스테이지 관리 cpp파일
     └ StageManager.h
 └ Shape
     ├ Shape.cpp // 테트리스 도형 cpp파일
     ├ Shape.h
     ├ ShapeManager.cpp // 테트리스 도형 관리 cpp파일
     ├ ShapeManager.h 
     ├ Rectangle.cpp
     ├ Rectangle.h
     ├ ShapeGun.cpp
     ├ ShapeGun.h
     ├ ShapeRGun.cpp
     ├ ShapeRGun.h
     ├ ShapeLine.cpp
     ├ ShapeLine.h
     ├ ShapeS.cpp
     ├ ShapeS.h
     ├ ShapeT.cpp
     ├ ShapeT.h
     ├ ShapeZ.cpp
     └ Shapez.h
```
<br/>


## 동작 결과
![image](https://github.com/je-s0n/tetris-game/assets/152856285/7c8a7e1b-5692-4c6c-b097-0903cf21b096)
<br/><br/>
![image](https://github.com/je-s0n/tetris-game/assets/152856285/cdce2126-a9e1-4366-bac3-27ebbcefce39)



<br/>

## 회고
윤성우 열혈 C++ 프로그래밍 책을 독학한 후 처음으로 개발한 테트리스 게임이다. 지금까지 Java로 개발을 해왔기 때문에 포인터 사용이나 생성자의 얕은 복사 등 헷갈리는 부분들이 많았었고, Java와 다르게 헤더 파일을 사용하여 기존 개발할 때 보다 더 많은 생각을 해야한다는 사실에 어려움을 겪었다. 

이 프로그램을 개발하면서 C++ 사용 시 파일 구성하는 방법을 알 수 있었으며, C++ 독학한 내용들을 실제 개발에 적용해보면서 C++의 심화 개념들을 이해할 수 있었다. 테트리스 개발을 시작으로 실제 게임 TCP 서버를 개발하는 것을 목표로 정했으며, 이를 위해 다양한 프로그램을 만들고, 심화 내용들을 습득하면서 한 단계 더 앞으로 나아가기 위해 노력을 해야겠다는 다짐을 했다. 

<br/>

## 래퍼런스 <br/>
[어소트락 게임아카데미 - Tetris 강의](https://www.youtube.com/watch?v=hozswFmo_iI)
