#pragma once
#include"ClassVector.h"

template <class Type>
class Conclusion
{
protected:
	Type qwerty = 0;

	char console[61][121];
public:
	Conclusion();
	void PastePoint(const classVector<Type>& _vec1);
	void PastePoint(float x, float y);
	void drawLine(Type x1, Type y1, Type x2, Type y2);
	void PasteRound(Type x0, Type y0, Type rad);
	/*void PasteLine(float x1, float y1, float x2, float y2);*/
	void Print();
	void clear();
};

template <class Type>
inline Conclusion<Type>::Conclusion()
{
	clear();
}

template<class Type>
inline void Conclusion<Type>::PastePoint(const classVector<Type>& _vec1)
{
	classVector<Type> temporary = _vec1;
	console[(int)temporary[0]][(int)temporary[1]] = '.';
}

template<class Type>
inline void Conclusion<Type>::PastePoint(float x, float y)
{
	console[(int)x][(int)y] = '.';
}

template<class Type>
inline void Conclusion<Type>::PasteRound(Type x, Type y, Type _rad)
{
	for (float m = (float)(x - _rad); m < (float)(x + _rad); m += 0.01)
	{
		for (float p = (float)(y - _rad); p < (float)(y + _rad); p += 0.01)
		{
			if (round((m - x) * (m - x) + (p - y) * (p - y)) == round(_rad * _rad))
				PastePoint(round(m), round(p));
		}
	}
}

template<class Type>
inline void Conclusion<Type>::Print()
{
	int i = 0;
	std::cout << "  ";
	for (int q = 0; q < 121; q++)
	{
		std::cout << i;
		i++;
		if (i > 9) i = 0;
	}
	i = 0;
	std::cout << std::endl;

	for (int q = 0; q < 121; q++)
		std::cout << '-';
	std::cout << std::endl;

	for (int q = 0; q < 61; q++)
	{
		std::cout << i << '|';
		i++;
		if (i > 9) i = 0;

		for (int w = 0; w < 121; w++)
			std::cout << console[q][w];
		std::cout << std::endl;
	}
}

template<class Type>
inline void Conclusion<Type>::clear()
{
	for (int q = 0; q < 61; q++)
	{
		for (int w = 0; w < 121; w++)
			console[q][w] = ' ';
	}
}

template<class Type>
inline void Conclusion<Type>::drawLine(Type x1, Type y1, Type x2, Type y2) //algoritm Brezethema
{
	const int deltaX = (int)abs(x2 - x1);
	const int deltaY = (int)abs(y2 - y1);
	const int signX = x1 < x2 ? 1 : -1;
	const int signY = y1 < y2 ? 1 : -1;
	int error = deltaX - deltaY;
	PastePoint(x2, y2);
	while (x1 != x2 || y1 != y2)
	{
		PastePoint(x1, y1);
		int error2 = error * 2;
		if (error2 > -deltaY)
		{
			error -= deltaY;
			x1 += signX;
		}
		if (error2 < deltaX)
		{
			error += deltaX;
			y1 += signY;
		}
	}
}

