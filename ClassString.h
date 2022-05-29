#pragma once
#include<iostream>

class classString
{
  protected:
    int len;
    char* str;
  public:
    classString();
    classString(int _len, char s);
    classString(const classString& c);
    ~classString();

    int GetLen();
    void SetLen(int _len);
    void SetStr(char* _str);
    void SetConstStr(const char* _str);

    bool operator < (const classString& c);
    bool operator > (const classString& c);
    bool operator == (const classString& c);
    classString& operator = (const classString& c);
    classString operator + (const classString& c);
    char& operator [](int i);
    friend std::ostream& operator << (std::ostream& stream, const classString& c);
    friend std::istream& operator >> (std::istream& stream, classString& c);

    int FirstSymbol(char symb);
    int FirstWord(char* _str);
    char** split(char symb, int& NoCount);
    classString& doubling(int count);
    
    char* GetStr();

}; 