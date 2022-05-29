#pragma once
#include"Object.h"
#include"ClassVector.h"
#include"Point.h"

template<class Type>
class classLine : public classObject<Type>
{
protected:
	int dim;
	classVector<Type> FirstPoint, SecondPoint;
	classString name;
public:
	Conclusion<Type> printer;
	classLine();
	~classLine();
	classLine(const classLine& _line);
	virtual void Print();
	virtual void Plot();
	virtual int GetDim();
	virtual void SetName(const classString& _name);
	virtual classString& GetName();
	virtual classVector<Type>& operator [] (int i);
};

template<class Type>
inline classLine<Type>::classLine()
{
	std::cout << "input dim of first point" << std::endl;
	std::cin >> FirstPoint;

	std::cout << std::endl;

	std::cout << "input dim of second point" << std::endl;
	std::cin >> SecondPoint;

	dim = FirstPoint.GetLen();
	name.SetConstStr("line");
	if (FirstPoint.GetLen() != SecondPoint.GetLen()) throw "dim of 1-st point != dim of 2-d point !!!";

	printer.clear();
}

template<class Type>
inline classLine<Type>::~classLine()
{

}

template<class Type>
inline classLine<Type>::classLine(const classLine& _line)
{
	FirstPoint = _line.FirstPoint;
	SecondPoint = _line.SecondPoint;
	dim = _line.dim;
	name = _line.name;
}

template<class Type>
inline void classLine<Type>::Print()
{
	std::cout << "name = " << name;
	std::cout << "dim =" << dim << std::endl;
	std::cout << "FirstVector = " << FirstPoint << std::endl;
	std::cout << "SecondVector = " << SecondPoint << std::endl;

}

template<class Type>
inline void classLine<Type>::Plot()
{
	printer.drawLine(FirstPoint[1], FirstPoint[0], SecondPoint[1], SecondPoint[0]);
	printer.Print();
}

template<class Type>
inline int classLine<Type>::GetDim()
{
	return 0;
}

template<class Type>
inline void classLine<Type>::SetName(const classString& _name)
{
	name = _name;
}

template<class Type>
inline classString& classLine<Type>::GetName()
{
	return name;
}

template<class Type>
inline classVector<Type>& classLine<Type>::operator[](int i)//ïðîâåðèòü
{
	switch (i)
	{
	case 0:
		return FirstPoint;
	case 1:
		return SecondPoint;
		break;

	default:
		throw "undefined behavior. You trying to get unexist cell of array";
	}
}