#ifndef FILTER_H
#define FILTER_H

#include <fstream>
using namespace std;

// Abstract file filter class
class AbstractFilter
{
public:
	// Define a pure virtual function 
	// for transforming a character.
	virtual char transform(char ch) = 0;
	void doFilter(ifstream &in, ofstream &out);
};

//***************************** Subclasses ***************************************

// Encryption class
class Encrypt:public AbstractFilter
{
private:
	int key;	// Holds encryption key
public:
	// Constructor that takes an integer as an 
	// argument and uses it as the encrytion key
	Encrypt(int key)
	{ this->key = key; }
	virtual char transform(char ch);
};

// Transforms a file to all uppercase class
class Upper:public AbstractFilter
{
public:
	virtual char transform(char ch);
};

// Create an unchanged copy of the original class 
class Copy:public AbstractFilter
{
public:
	virtual char transform(char ch);
};

// Inserts a blank line between any to lines of the file
class DoubleSpaces:public AbstractFilter
{
private:
	int count;	
public:
	DoubleSpaces() { count = 0; }
	void doFilter(ifstream &in, ofstream &out);
	virtual char transform(char ch);
};

#endif