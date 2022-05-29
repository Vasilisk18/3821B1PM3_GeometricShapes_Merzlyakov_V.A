#pragma once
#include"Object.h"
#include<iostream>

template<class Type>
class classPyramid : public classObject<Type>
{
protected:
	classVector<Type> FirstPoint, SecondPoint, ThirdPoint, FourthPoint;
	int dim;
	classString name;
public:
	classPyramid();
	classPyramid(const classPyramid<Type>& _pyr);
	~classPyramid();
	Conclusion<Type> printer;
	virtual void Print();
	virtual void Plot();
	virtual int GetDim();
	virtual void SetName(const classString& _name);
	virtual classString& GetName();
	virtual classVector<Type>& operator [] (int i);

};

template<class Type>
inline classPyramid<Type>::classPyramid()
{
	std::cout << "input dim of first point" << std::endl;
	std::cin >> FirstPoint;

	std::cout << std::endl;
	std::cout << "input dim of second point" << std::endl;
	std::cin >> SecondPoint;

	std::cout << std::endl;
	std::cout << "input dim of third point" << std::endl;
	std::cin >> ThirdPoint;

	std::cout << std::endl;
	std::cout << "input dim of fourth point" << std::endl;
	std::cin >> FourthPoint;

	dim = FirstPoint.GetLen();
	name.SetConstStr("Pyramid");
	if (FirstPoint.GetLen() != SecondPoint.GetLen() && ThirdPoint.GetLen() != FourthPoint.GetLen()) throw "dim of points isn't equals!"; 
	else if (FirstPoint.GetLen() != FourthPoint.GetLen()) throw "dim of points isn't equals!";

}

template<class Type>
inline classPyramid<Type>::classPyramid(const classPyramid<Type>& _pyr)
{
	name = _pyr.name;
	FirstPoint = _pyr.FirstPoint;
	SecondPoint = _pyr.SecondPoint;
	ThirdPoint = _pyr.ThirdPoint;
	FourthPoint = _pyr.FourthPoint;
	dim = _pyr.dim;
}

template<class Type>
inline classPyramid<Type>::~classPyramid()
{

}

template<class Type>
inline void classPyramid<Type>::Print()
{
	std::cout << "name = " << name;
	std::cout << "dim =" << dim << std::endl;
	std::cout << "FirstVector = " << FirstPoint << std::endl;
	std::cout << "SecondVector = " << SecondPoint << std::endl;
	std::cout << "ThirdVector = " << ThirdPoint << std::endl;
	std::cout << "FourthVector = " << ThirdPoint << std::endl;
}

template<class Type>
inline void classPyramid<Type>::Plot()
{
	printer.drawLine(FirstPoint[1], FirstPoint[0], SecondPoint[1], SecondPoint[0]);
	printer.drawLine(FirstPoint[1], FirstPoint[0], ThirdPoint[1], ThirdPoint[0]);
	printer.drawLine(SecondPoint[1], SecondPoint[0], ThirdPoint[1], ThirdPoint[0]);
	printer.PastePoint((float)FourthPoint[0], (float)FourthPoint[1]);
	printer.drawLine(FirstPoint[1], FirstPoint[0], FourthPoint[0], FourthPoint[1]);
	printer.drawLine(SecondPoint[1], SecondPoint[0], FourthPoint[0], FourthPoint[1]);
	printer.drawLine(ThirdPoint[1], ThirdPoint[0], FourthPoint[0], FourthPoint[1]);
	printer.Print();
}

template<class Type>
inline int classPyramid<Type>::GetDim()
{
	return dim;
}

template<class Type>
inline void classPyramid<Type>::SetName(const classString& _name)
{
	name = _name;
}

template<class Type>
inline classString& classPyramid<Type>::GetName()
{
	return name;
}

template<class Type>
inline classVector<Type>& classPyramid<Type>::operator[](int i)
{
	switch (i)
	{
	case 0:
		return FirstPoint;
	case 1:
		return SecondPoint;
		break;
	case 2:
		return ThirdPoint;
		break;
	case 3:
		return FourthPoint;
		break;

	default:
		throw "undefined behavior. You trying to get unexist cell of array";
	}
}