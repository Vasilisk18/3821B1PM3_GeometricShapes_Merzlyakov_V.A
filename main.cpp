#include<iostream>
#include"ClassString.h"
#include"ClassVector.h"
#include"Complex.h"
#include"Conclusion.h"
#include"Line.h"
#include"Object.h"
#include"Point.h"
#include"Round.h"
#include"Square.h"
#include"Triangle.h"
#include"Pyramid.h"
#include"Container.h"
#include"Cube.h"
using namespace std;

int main()
{
  classCont<int> cont;
  classPyramid<int> pyr; 
  classRound<int> round(10);
  classLine<int> line;
  classTriangle<int> triangle;
  classSquare<int> square;
  classCube<int> cube;
  cont.SetObject(&pyr);
  cont.SetObject(&round);
  cont.SetObject(&line);
  cont.SetObject(&triangle);
  cont.SetObject(&square);
  cont.SetObject(&cube);
  cont.Print();
  cont.Plotting();

  return 0;
}