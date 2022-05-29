#pragma once
#include <iostream>

class classComplex
{
  private:
    double Im;
    double Re;
    double corner;
  public:
    classComplex(double _Re = 0, double _Im = 0);
    classComplex(const classComplex &p);
    
    double GetRe();
    double GetIm();
    double GetCorner();
    double GetAbs(const classComplex &num);
    double GetAbs();
  
    classComplex PowNZ(int numb);
  
    void GetTrigonomForm(const classComplex &num);
    void GetTrigonomForm();

    void SetRe(double _Re);
    void SetIm(double _Im);
    void SetCorner(double _corner);

    classComplex operator + (const classComplex& num);
    classComplex operator - (const classComplex& num);
    classComplex& operator = (const classComplex& num);
    classComplex operator * (const classComplex& num);
    classComplex operator / (const classComplex& num);
    bool operator == (const classComplex& num);
    friend std::ostream& operator << (std::ostream& stream, const classComplex& num);
    friend std::istream& operator >> (std::istream& stream, const classComplex& num);
};