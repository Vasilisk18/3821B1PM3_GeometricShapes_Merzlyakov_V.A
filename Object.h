#pragma once
#include"ClassVector.h"
#include"ClassString.h"
#include"Conclusion.h"

template<class Type>
class classObject
{
  public:
    virtual void Print() = 0;
    virtual void Plot() = 0;
    virtual int GetDim() = 0;
    virtual void SetName(const classString& _name) = 0;
    virtual classString& GetName() = 0;
    virtual classVector<Type>& operator [] (int i) = 0;

};
