#include <iostream>
#include <string>
#include<fstream>
#include<iomanip>
using namespace std;
class String {
public:
	friend ostream& operator<<(ostream& os, const String& val);
	friend istream& operator>>(istream& os, const String& val);
	String() {
		length = 0;
		str = nullptr;
	}
	//copy1
	String(const char* str) {
		length = strlen(str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}
		this->str[length] = '\0';
	}
	String(const String& str) {
		this->length = str.length;
		this->str = new char[this->length + 1];
		for (int i = 0; i < this->length; i++)
		{
			this->str[i] = str.str[i];
		}
		this->str[length] = '\0';
	}
	//op= 

	String& operator=(const String& str) {
		this->length = str.length;
		if (this->str != nullptr) {
			delete[]this->str;
		}
		this->str = new char[length];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = str.str[i];
		}
		return *this;
	}
	String& operator=(const char* str) {
		this->length = strlen(str);
		if (this->str != nullptr) {
			delete[]this->str;
		}
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}
		this->str[this->length] = '\0';
		return *this;
	}
	//op+
	String operator+(const String& str) {
		char* other = new char[this->length + str.length + 1];
		int i = 0;
		String c;
		for (; i < this->length; i++)
		{
			other[i] = this->str[i];
		}

		c.length = this->length + str.length;
		for (int j = 0; i < c.length; j++, i++)
		{
			other[i] = str.str[j];
		}
		other[i] = '\0';
		c.str = other;
		return c;
	}
	String operator+(const char* str) {
		char* other = new char[this->length + strlen(str) + 1];
		int i = 0;
		for (; i < this->length; i++)
		{
			other[i] = this->str[i];
		}
		if (this->str != nullptr) {
			delete[]this->str;
		}
		this->length += strlen(str);
		for (int j = 0; i < this->length; j++, i++)
		{
			other[i] = str[j];
		}
		//other[i] = '\0';
		this->str = other;
		return *this;
	}

	//methodPrint
	void print() {
		cout << str << endl;
	}
	//getLength
	int Length() {
		return length;
	}
	//destruct
	~String() {
		if (str != nullptr) {
			delete[]str;
		}
	}
private:
	int length;
	char* str;
};

ostream& operator<<(ostream& os, const String& val) {
	os << val.str;
	return os;

}
istream& operator>>(istream& os, const String& val) {
	os >> val.str;
	return os;

}
