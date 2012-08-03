#include <iostream>
#include <string>
#include <cstring>
#include "utlite.h"

// Here's my test case

class Test1 : public utlite::Suite<Test1>
{
public:
	// first test
	// this is the prototype of test member functions
	void test1()
	{
		UT_ASSERT(1 == 2); // should fail
	}
	
	// second test
	void test2()
	{
		std::string lhello("Hello, world!");
		const char *lcstr = lhello.c_str();
		UT_ASSERT(lhello.length() == strlen(lcstr)); // should pass
	}

	SUITE_BEGIN // add my tests to this suite
		UT(test1, Test1); // test name, suite name (class where test is)
		UT(test2, Test1);
	SUITE_END
};

int main()
{
	Test1 ltest1;
	// Run the tests
	ltest1.run();
	/*
	Output:
.F.
1 test case(s) passed.
Failed: Test1::test1, line: 15, file: testutlite.cc
expr: 1 == 2
	*/
	return 0;
}

