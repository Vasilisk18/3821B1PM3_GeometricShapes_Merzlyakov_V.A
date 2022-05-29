#include "Complex.h"
#define pi 3.14

classComplex::classComplex(double _Re, double _Im)
{
  Re = _Re;
  Im = _Im;
  corner = 0;
}

classComplex::classComplex(const classComplex& p)
{
  Re = p.Re;
  Im = p.Im;
  corner = p.corner;
}

double classComplex::GetRe()
{
  return Re;
}

double classComplex::GetIm()
{
  return Im;
}

double classComplex::GetCorner()
{
  return corner;
}

double classComplex::GetAbs()
{
  return sqrt(Re * Re + Im * Im);
}

double classComplex::GetAbs(const classComplex& num)
{
	return sqrt(num.Re * num.Re + num.Im * num.Im);
}

classComplex classComplex::PowNZ(int numb)
{
  classComplex temp(*this);
  temp.corner = (atan2(temp.Im, temp.Re) * 180 / pi) * numb;
  double abs = sqrt(Re * Re + Im * Im);
  
  abs = pow(abs,numb);
  
  temp.Re = cos(temp.corner) * abs;
  temp.Im = sin(temp.corner) * abs;

  return temp;
}

void classComplex::GetTrigonomForm()
{
  corner = atan2(Im, Re) * 180 / pi;
  std::cout << GetAbs(*this) << "*(" << " cos(" << corner << ") + i*sin(" << corner << "))" << std::endl;
}

void classComplex::GetTrigonomForm(const classComplex& num)
{
	corner = atan2(num.Im, num.Re) * 180 / pi;
	std::cout << GetAbs(num) << "*(" << " cos(" << corner << ") + i*sin(" << corner << "))" << std::endl;
}

void classComplex::SetRe(double _Re)
{
  Re = _Re;
}

void classComplex::SetIm(double _Im)
{
  Im = _Im;
}

void classComplex::SetCorner(double _corner)
{
  corner = _corner;
}

classComplex classComplex::operator * (const classComplex& num)
{
	classComplex temp(*this);
	temp.Re = Re * num.Re - Im * num.Im;
	temp.Im = Re * num.Im + num.Re * Im;
	return temp;
}

classComplex classComplex::operator + (const classComplex& num)
{
	classComplex temp(*this);
	temp.Re = Re + num.Re;
	temp.Im = Im + num.Im;
	return temp;
}

classComplex classComplex::operator-(const classComplex& num)
{
	classComplex temp(*this);
	temp.Re = Re - num.Re;
	temp.Im = Im - num.Im;
	return temp;
}

classComplex classComplex::operator / (const classComplex& num)
{
	classComplex temp(*this);
	if (num.Im == 0 && num.Re == 0) throw "This problem was called by operator / ";
	temp.Re = (Re * num.Re + Im * num.Im) / (num.Re * num.Re + num.Im * num.Im);
	temp.Im = (num.Re * Im - Re * num.Im) / (num.Re * num.Re + num.Im * num.Im);

	return temp;
}
classComplex& classComplex::operator=(const classComplex& num)
{
	this->Re = num.Re;
	this->Im = num.Im;
	return *this;

}

bool classComplex::operator==(const classComplex& num)
{
	if (this->Re == num.Re && this->Im == num.Im) return true;
	else return false;
}



std::ostream& operator<<(std::ostream& stream, const classComplex& num)
{
	stream << num.Re << ' ' << '+' << ' ' << num.Im << " * i";
	return stream;
}

std::istream& operator>>(std::istream& stream, const classComplex& num)
{
	stream >> num.Re;
	stream >> num.Im;
	return stream;
}