#pragma once
#include<iostream>
#include"ClassVector.h"
#include"Object.h"

template <class Type>
class classPoint : public classObject<Type>
{
  protected:
    classString name;
    classVector<Type> Vec;
    int dim;

  public:
    classPoint(int _dim);
    Conclusion<Type> printer;
    virtual void Plot();
    virtual void Print();
    virtual classVector<Type>& operator [](int i);
    virtual int GetDim();
    virtual void SetName(const classString& _name);
    virtual classString& GetName();
}; 

template<class Type>
classPoint<Type>::classPoint(int _dim)
{
  dim = _dim;
  Vec.ReSize(_dim);
  
  name.SetConstStr("qwerty");
  
  for (int q = 0; q < _dim; q++)
  {
    Vec[q] = 5;
  }
}

template<class Type>
inline void classPoint<Type>::Plot()
{
  printer.PastePoint(Vec);
  printer.Print();

}

template<class Type>
void classPoint<Type>::Print()
{
  std::cout << Vec << std::endl;
  std::cout << name << std::endl;
}

template<class Type>
inline classVector<Type>& classPoint<Type>::operator[](int i)
{
  return Vec;
}

template<class Type>
inline int classPoint<Type>::GetDim()
{
  return dim;
}

template<class Type>
inline void classPoint<Type>::SetName(const classString& _name)
{
  name = _name;
}

template<class Type>
inline classString& classPoint<Type>::GetName()
{
  return name;
}