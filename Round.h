#pragma once
#include"Object.h"

template<class Type>
class classRound : public classObject<Type>
{
	protected:
		classVector<Type> point;
		Type rad;
		int dim;
		classString name;
  public:
		Conclusion<Type> printer;
		Type x, y, r;
		classRound(Type _rad);
		classRound(const classRound& _round);
		~classRound();
		virtual void Print();
		virtual void Plot();
		virtual int GetDim();
		void SetRad(Type _rad);
		Type GetRad();
		virtual void SetName(const classString& _name);
		virtual classString& GetName();
		virtual classVector<Type>& operator [] (int i);
};

template<class Type>
inline classRound<Type>::classRound(Type _rad)
{
	std::cout << "input dim of round" << std::endl;
	std::cin >> point;
	dim = point.GetLen();
	name.SetConstStr("Round");
	rad = _rad;
	x = 0;
	y = 0;
	r = 0;
}


template<class Type>
inline classRound<Type>::classRound(const classRound& _round)
{
	point = _round.point;
	dim = _round.dim;
	name = _round.name;
	rad = _round.rad;
}

template<class Type>
inline classRound<Type>::~classRound()
{

}

template<class Type>
inline void classRound<Type>::Print()
{
	std::cout << "dim =" << dim << std::endl;
	std::cout << "Coordinates: " << point << std::endl;
	std::cout << "name = " << name << std::endl;
	std::cout << "rad = " << rad << std::endl;
}

template<class Type>
inline void classRound<Type>::Plot()
{
	x = point[0];
	y = point[1];
	r = rad;
	printer.PasteRound(x, y, r);
	printer.Print();
}

template<class Type>
inline int classRound<Type>::GetDim()
{
	return dim;
}

template<class Type>
inline void classRound<Type>::SetRad(Type _rad)
{
	rad = _rad;
}

template<class Type>
inline Type classRound<Type>::GetRad()
{
	return rad;
}

template<class Type>
inline void classRound<Type>::SetName(const classString& _name)
{
	name = _name;
}

template<class Type>
inline classString& classRound<Type>::GetName()
{
	return name;
}

template<class Type>
inline classVector<Type>& classRound<Type>::operator[](int i)
{
	return point;
}