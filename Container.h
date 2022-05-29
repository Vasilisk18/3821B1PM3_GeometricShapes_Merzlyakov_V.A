#pragma once
#include"ClassVector.h"
#include"Complex.h"
#include"Conclusion.h"
#include"Line.h"
#include"Object.h"
#include"Point.h"
#include"Round.h"
#include"Square.h"
#include"Triangle.h"

template<class Type>
class classCont
{
  public:
    int count;
    classObject<Type>** data;
    classCont();
    ~classCont();
    void SetObject(classObject<Type>* _object);
    void Print();
    void Plotting();
    void Print(int _numb);
    void Plotting(int _numb);
    void DelObj();
    int GetCount();
};

template<class Type>
inline classCont<Type>::classCont()
{
  data = 0;
  count = 0;
}

template<class Type>
inline classCont<Type>::~classCont()
{
  delete[] data;
  data = 0;
}

template<class Type>
inline void classCont<Type>::SetObject(classObject<Type>* _object)
{
  if (data == 0)
  {
    data = new classObject<Type>*[1];
    count++;
    data[0] = _object;
  }
  else
  {
    classObject<Type>** temp = new classObject<Type>*[count + 1];
    for(int q = 0; q<count;q++)
      temp[q] = data[q];
    delete[] data;
    data = 0;
    
    data = new classObject<Type>*[count + 1];
    for(int q = 0; q < count; q++)
      data[q] = temp[q];
    data[count] = _object;
    count++;
    
    delete[] temp;
    temp = 0;
  }
}

template<class Type>
inline void classCont<Type>::Print()
{
  if(count > 0)
    for(int q = 0; q < count; q++)
      data[q]->Print();
}

template<class Type>
inline void classCont<Type>::Plotting()
{
  if (count > 0)
    for (int q = 0; q < count; q++)
      data[q]->Plot();
}

template<class Type>
inline void classCont<Type>::Print(int _numb)
{
  if (_numb < 0 || _numb > (count - 1)) throw "Trying to get access to out of array";
  else
    data[_numb]->Print();
}

template<class Type>
inline void classCont<Type>::Plotting(int _numb)
{
  if (_numb < 0 || _numb >(count - 1)) throw "Trying to get access to out of array";
  else
    data[_numb]->Plot();
}

template<class Type>
inline void classCont<Type>::DelObj()
{
  if(data == 0) throw "array is empty";
  else if (data != 0)
  {
    classObject<Type>** temp = new classObject<Type>*[count - 1];
    for (int q = 0; q < count - 1; q++)
      temp[q] = data[q];
    delete[] data;
    data = 0;

    count--;
    data = new classObject<Type>*[count];
    for (int q = 0; q < count; q++)
      data[q] = temp[q];
  }
}

template<class Type>
inline int classCont<Type>::GetCount()
{
   return count;
}