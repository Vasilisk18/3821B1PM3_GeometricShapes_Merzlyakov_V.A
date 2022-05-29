#pragma once
#include"Object.h"
#include"Point.h"
#include"ClassVector.h"

template <class Type>
class classSquare : public classObject<Type>
{
protected:
	int dim;
	classVector<Type> FirstPoint, SecondPoint;
	classString name;

public:
	Conclusion<Type> printer;
	classSquare();
	classSquare(const classSquare<Type>& square);
	virtual void Print();
	virtual void Plot();
	virtual int GetDim();
	virtual void SetName(const classString& _name);
	virtual classString& GetName();
	virtual classVector<Type>& operator [] (int i);
};

template<class Type>
inline classSquare<Type>::classSquare()
{
	std::cout << "input dim of first point" << std::endl;
	std::cin >> FirstPoint;

	std::cout << std::endl;

	std::cout << "input dim of second point" << std::endl;
	std::cin >> SecondPoint;

	dim = FirstPoint.GetLen();
	name.SetConstStr("Square");
	if (FirstPoint.GetLen() != SecondPoint.GetLen()) throw "dim of 1-st point != dim of 2-d point !!!";

	printer.clear();
}

template<class Type>
inline classSquare<Type>::classSquare(const classSquare<Type>& square)
{
	FirstPoint = square.FirstPoint;
	SecondPoint = square.SecondPoint;
	dim = square.dim;
	name = square.name;
}

template<class Type>
inline void classSquare<Type>::Print()
{
	std::cout << "name = " << name;
	std::cout << "dim =" << dim << std::endl;
	std::cout << "FirstPointOfSquare = " << FirstPoint << std::endl;
	std::cout << "SecondPointOfSquare = " << SecondPoint << std::endl;
}

template<class Type>
inline void classSquare<Type>::Plot()
{
	printer.drawLine(FirstPoint[1], FirstPoint[0], FirstPoint[1], SecondPoint[0]);
	printer.drawLine(FirstPoint[1], FirstPoint[0], SecondPoint[1], FirstPoint[0]);
	printer.drawLine(FirstPoint[1], SecondPoint[0], SecondPoint[1], SecondPoint[0]);
	printer.drawLine(SecondPoint[1], FirstPoint[0], SecondPoint[1], SecondPoint[0]);
	printer.Print();
}

template<class Type>
inline int classSquare<Type>::GetDim()
{
	return 0;
}

template<class Type>
inline void classSquare<Type>::SetName(const classString& _name)
{
	name = _name;
}

template<class Type>
inline classString& classSquare<Type>::GetName()
{
	return name;
}

template<class Type>
inline classVector<Type>& classSquare<Type>::operator[](int i)
{
	switch (i)
	{
	case 0:
		return FirstPoint;
	case 1:
		return SecondPoint;
		break;

	default:
		throw "Oops. You`re trying to get a non-exist array cell";
	}
}