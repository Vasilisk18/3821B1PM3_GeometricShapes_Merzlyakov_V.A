#include<iostream>
#include"ClassString.h"

classString::classString()
{
	len = 0;
	str = nullptr;
}

classString::classString(int _len, char s)
{
	int q = 0;
	if (str == nullptr)
	{
		delete[] str;
		len = 0;
	}
	if (_len > 0)
	{
		str = new char[_len + 1];
		str[_len] = '\0';
		for (q = 0; q < _len; q++)
			str[q] = s;

	}
	if (str != nullptr) len = (int)strlen(str);
}

classString::classString(const classString& c)
{
	int q = 0;
	if (c.len <= 0) std::cout << "f" << std::endl;
	else if (c.len > 0 && c.str != nullptr)
	{
		len = c.len;
		if (str != nullptr) delete[] str;
		str = new char[len + 1];
		for (q = 0; q < len; q++)
		{
			str[q] = c.str[q];
		}
	}

	str[len] = '\0';
}

int classString::GetLen()
{
	return len;
}

void classString::SetLen(int _len)
{
	len = _len;
}

void classString::SetStr(char* _str)
{
	int TemporaryLength = 0;
	if (_str == nullptr) throw "Error in SetString func. Your str = nullptr";

	if (str != nullptr) delete[] str;
	str = new char[strlen(_str) + 1];
	str[strlen(_str)] = '\0';

	for (int q = 0; q < strlen(_str); q++)
	{
		str[q] = _str[q];
	}
	len = (int)strlen(_str);
}

void classString::SetConstStr(const char* _str)
{
	int TemporaryLength = 0;
	if (_str == nullptr) throw "Error in SetStr func. Your str = 0";

	if (str != nullptr) delete[] str;
	str = new char[strlen(_str) + 1];
	str[strlen(_str)] = '\0';

	for (int q = 0; q < strlen(_str); q++)
	{
		str[q] = _str[q];
	}
	len = (int)strlen(_str);
}

classString::~classString()
{
	if (str != nullptr)
		delete[] str;
}

char* classString::GetStr()
{
	return str;
}

int classString::FirstSymbol(char symb)
{
	if (str == nullptr) return -1;

	for (int q = 0; q < strlen(str); q++)
	{
		if (str[q] == symb) return q;
	}
	return -1;
}

int classString::FirstWord(char* _str)
{
	bool similar;
	if (_str == nullptr) return -1;

	for (int q = 0; q < strlen(str); q++)
	{
		if (_str[0] == str[q])
		{
			similar = true;
			for (int w = 1; w < strlen(_str); w++)
			{
				if (_str[w] != str[q + w]) similar = false;
			}

			if (similar == true) return q;
		}

	}

	return -1;

}
char** classString::split(char symb, int& NoCount)
{
	int CountOfString = 0;
	int index = 0;

	char** Set = nullptr;
	int low = 0;

	for (int q = 0; q < strlen(str); q++)
		if (str[q] == symb) CountOfString++;

	if (CountOfString == 0)
	{
		char** Set = new char* [1];
		Set[0] = str;
		return Set;
	}

	Set = new char* [CountOfString++];

	for (int a = 0; a < strlen(str); a++)
	{
		if (str[a] == symb)
		{
			Set[index] = new char[a - low + 1];
			Set[index][a - low] = '\0';
			for (int i = low; i < a; i++)
			{
				Set[index][i - low] = str[i];
			}
			low = a + 1;
			index++;
		}
	}
	if (CountOfString > 0)
	{
		Set[index] = new char[strlen(str) - low + 1];
		Set[index][strlen(str) - low] = '\0';
		for (int i = low; i < strlen(str); i++)
		{
			Set[index][i - low] = str[i];
		}
	}
	NoCount = CountOfString;
	return Set;
}

classString& classString::doubling(int count)
{
	char* TemporaryString = new char[strlen(str) * count + 1];
	TemporaryString[strlen(str) * count] = '\0';
	for (int q = 0; q < strlen(str) * count; q = q + 3)
	{
		for (int i = 0; i < strlen(str); i++)
		{
			TemporaryString[q + i] = str[i];
		}
	}
	delete[] str;
	str = TemporaryString;
	return *this;
}

char& classString::operator[](int i)
{
	char q = 3;
	if (len > 0 && str != nullptr && (i >= 0 && i < len))
	{
		return str[i];
	}
	else
		return q;
}

bool classString::operator==(const classString& c)
{
	int tmplen = strlen(str);
	int _tmplen = strlen(c.str);

	if (tmplen != _tmplen) return false;
	else
	{
		for (int q = 0; q < tmplen; q++)
		{
			if (str[q] != c.str[q]) return false;
		}
	}
	return true;
}
classString& classString::operator = (const classString& c)
{
	if (c.str != nullptr)
	{
		len = strlen(c.str);

		if (str == nullptr) delete[] str;
		str = new char[len + 1];
		str[len] = '\0';

		for (int q = 0; q < len; q++)
		{
			str[q] = c.str[q];
		}
	}
	return *this;
}

bool classString::operator < (const classString& c)
{
	int tmplen1 = 0;
	int tmplen2 = 0;

	if (c.str == nullptr && str == nullptr) throw "Exception in operator <";
	else
	{
		tmplen1 = strlen(str);
		tmplen2 = strlen(c.str);

		if (tmplen2 < tmplen1) tmplen2 = tmplen1;

		for (int q = 0; q < tmplen1; q++)
		{
			if (str[q] >= c.str[q]) return false;
		}

	}
	return true;
}

bool classString::operator > (const classString& c)
{
	int tmplen1 = 0;
	int tmplen2 = 0;

	if (c.str == nullptr && str == nullptr) throw "Exception in operator <";
	else
	{
		tmplen1 = strlen(str);
		tmplen2 = strlen(c.str);

		if (tmplen2 < tmplen1) tmplen2 = tmplen1;

		for (int q = 0; q < tmplen1; q++)
		{
			if (str[q] <= c.str[q]) return false;
		}

	}
	return true;
}

classString classString::operator + (const classString& c)
{
	int tmplength = 0; int p_tmplength = 0;
	classString result(*this);
	if (str == nullptr) throw "str of first object = nullptr";
	if (c.str == nullptr) throw "str of second object = nullptr";

	if (result.str == nullptr) delete[] result.str;
	result.str = new char[strlen(str) + strlen(c.str) + 1];
	result.str[strlen(str) + strlen(c.str)] = '\0';
	tmplength = strlen(str);
	p_tmplength = strlen(c.str);

	for (int i = 0; i < tmplength; i++)
	{
		result.str[i] = str[i];
	}
	for (int i = 0; i < p_tmplength; i++)
	{
		result.str[tmplength + i] = c.str[i];
	}
	result.len = strlen(result.str);
	return result;


}

std::istream& operator>>(std::istream& stream, classString& c)
{
	int i = 0;
	char tmp = 0;
	if (c.str != nullptr) delete[] c.str;
	char* tmpstr = nullptr;
	tmpstr = new char[255];

	for (int a = 0; a < 255; a++)
	{
		tmpstr[a] = '\0';
	}

	while (tmp != '0')
	{
		stream >> tmp;
		tmpstr[i] = tmp;
		i++;
	}

	c.str = new char[strlen(tmpstr)];
	c.str[strlen(tmpstr) - 1] = '\0';

	for (int q = 0; q < strlen(tmpstr) - 1; q++)
		c.str[q] = tmpstr[q];
	c.len = strlen(c.str);
	delete[] tmpstr;
	tmpstr = nullptr;
	return stream;
}

std::ostream& operator<<(std::ostream& stream, const classString& c)
{
	for (int q = 0; q < strlen(c.str); q++)
	{
		stream << c.str[q];
	}
	stream << '\n';
	return stream;
}