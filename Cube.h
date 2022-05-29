#pragma once
#include"Object.h"
#include"Point.h"
#include"ClassVector.h"

template <class Type>
class classCube : public classObject<Type>
{
protected:
	int dim;
	classVector<Type> FirstPoint, SecondPoint, ThirdPoint, FourthPoint;
	classString name;

public:
	Conclusion<Type> printer;
	classCube();
	classCube(const classCube<Type>& cube);
	virtual void Print();
	virtual void Plot();
	virtual int GetDim();
	virtual void SetName(const classString& _name);
	virtual classString& GetName();
	virtual classVector<Type>& operator [] (int i);
};

template<class Type>
inline classCube<Type>::classCube()
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
	name.SetConstStr("Cube");
	if (FirstPoint.GetLen() != SecondPoint.GetLen()) throw "dim of 1-st point != dim of 2-d point";
	if (ThirdPoint.GetLen() != FourthPoint.GetLen()) throw "dim of 3-d point != dim of 4-th point";
	printer.clear();
}

template<class Type>
inline classCube<Type>::classCube(const classCube<Type>& cube)
{
	FirstPoint = cube.FirstPoint;
	SecondPoint = cube.SecondPoint;
	ThirdPoint = cube.ThirdPoint;
	FourthPoint = cube.FourthPoint;
	dim = cube.dim;
	name = cube.name;
}

template<class Type>
inline void classCube<Type>::Print()
{
	std::cout << "name = " << name;
	std::cout << "dim =" << dim << std::endl;
	std::cout << "FirstPointOfCube = " << FirstPoint << std::endl;
	std::cout << "SecondPointOfCube = " << SecondPoint << std::endl;
	std::cout << "ThirdPointOfCube = " << ThirdPoint << std::endl;
	std::cout << "FourthPointOfCube = " << FourthPoint << std::endl;
}

template<class Type>
inline void classCube<Type>::Plot()
{
	printer.drawLine(FirstPoint[1], FirstPoint[0], FirstPoint[1], SecondPoint[0]); //первый квадрат
	printer.drawLine(FirstPoint[1], FirstPoint[0], SecondPoint[1], FirstPoint[0]);
	printer.drawLine(FirstPoint[1], SecondPoint[0], SecondPoint[1], SecondPoint[0]);
	printer.drawLine(SecondPoint[1], FirstPoint[0], SecondPoint[1], SecondPoint[0]);

	printer.drawLine(ThirdPoint[1], ThirdPoint[0], ThirdPoint[1], FourthPoint[0]);	//второй квадрат
	printer.drawLine(ThirdPoint[1], ThirdPoint[0], FourthPoint[1], ThirdPoint[0]);
	printer.drawLine(ThirdPoint[1], FourthPoint[0], FourthPoint[1], FourthPoint[0]);
	printer.drawLine(FourthPoint[1], ThirdPoint[0], FourthPoint[1], FourthPoint[0]);

	printer.drawLine(FirstPoint[1], FirstPoint[0], ThirdPoint[1], ThirdPoint[0]);
	printer.drawLine(FirstPoint[1], FirstPoint[0], ThirdPoint[1], ThirdPoint[0]);
	printer.drawLine(FirstPoint[1], SecondPoint[0], ThirdPoint[1], FourthPoint[0]);
	printer.drawLine(SecondPoint[1], FirstPoint[0], FourthPoint[1], ThirdPoint[0]);

	printer.drawLine(FirstPoint[1], SecondPoint[0], ThirdPoint[1], FourthPoint[0]);
	printer.drawLine(SecondPoint[1], FirstPoint[0], FourthPoint[1], ThirdPoint[0]);
	printer.drawLine(SecondPoint[1], SecondPoint[0], FourthPoint[1], FourthPoint[0]);
	printer.drawLine(SecondPoint[1], SecondPoint[0], FourthPoint[1], FourthPoint[0]);

	printer.Print();
}

template<class Type>
inline int classCube<Type>::GetDim()
{
	return 0;
}

template<class Type>
inline void classCube<Type>::SetName(const classString& _name)
{
	name = _name;
}

template<class Type>
inline classString& classCube<Type>::GetName()
{
	return name;
}

template<class Type>
inline classVector<Type>& classCube<Type>::operator[](int i)
{
	switch (i)
	{
	case 0:
		return FirstPoint;
	case 1:
		return SecondPoint;
	case 2:
		return ThirdPoint;
	case 3:
		return FourthPoint;
		break;

	default:
		throw "Oops. You`re trying to get a non-exist array cell";
	}
}