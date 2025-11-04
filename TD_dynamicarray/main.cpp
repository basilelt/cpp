#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

#include "dynamicarray.hpp"

#define ASSERT_ON

#include "utils.h"

void testDefaultCtor()
{	
	std::cout << std::endl << "default ctor test";
	DynamicArray a;
	ASSERT(a.size()==a.blockSize());
	
	std::string s = "[0 0 0 0 0 0 0 0 0 0 ]";
	std::ostringstream os;
	a.printOn(os);
	ASSERT(s == (os.str()));
}

void testValueCtor()
{
	std::cout << std::endl << "value ctor test";
	DynamicArray a(2);
	ASSERT(a.size()==2);
	
	std::string s= "[0 0 ]";
	std::ostringstream os;
	a.printOn(os);
	ASSERT(s == (os.str()));	
}

void testGetSet()
{
	std::cout << std::endl << "get set test";
	DynamicArray a(3);

	a.set(0,0);
	a.set(1,1);
	a[2] = 2;
	ASSERT(a.get(0)==0);
	ASSERT(a.get(1)==1);
	ASSERT(a[2] ==2);
	bool ethrown = false;
	try
	{
		a.set(4,3);
	}
	catch (const std::out_of_range& e)
	{
		ethrown = true;
	}
	ASSERT(ethrown);
}

void testCopyCtor()
{
	std::cout << std::endl << "copy ctor test";

	DynamicArray a1(2);
	a1[0] = 1;
	a1[1] = 2;
	
	DynamicArray a2(a1);
	ASSERT(a2.size() == 2);
	ASSERT(a2[0] == 1);
	ASSERT(a2[1] == 2);
	
	DynamicArray a3;
	a3 = a1;
	ASSERT(a3.size() == 2);
	ASSERT(a3[0] == 1);
	ASSERT(a3[1] == 2);
}

void testGrow()
{
	std::cout << std::endl << "grow test";
	DynamicArray a(2);
	ASSERT(a.size() == 2);
	a[0] = 1;
	a[1] = 2;
	
	a.grow();
	ASSERT(a.size() == 2 + a.blockSize());
	std::string s = "[1 2 0 0 0 0 0 0 0 0 0 0 ]";
	std::ostringstream os;
	a.printOn(os);
	ASSERT(s == (os.str()));
	

}

void testDynamicArray()
{
	std::cout << std::endl << "dynamicArray tests" << std::endl;
	testDefaultCtor();
	testValueCtor();
	testGetSet();
	testCopyCtor();
	testGrow();
}


int main (int argc, char * const argv[])
{
	testDynamicArray();
	return 0;
}
