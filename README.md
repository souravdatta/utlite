utlite
======

A lightweight assertion based unit test framework for C++.

This is a header only simple unit test framework that can be used with any C++ project. If a C project is using a C++
compiler, then this framework can be easily incorporated inside it. It has the below features:

1. Fast and lightweight.
2. Uses standard/modern C++.
3. No bloat of infinite classes with peculiar names (ala Java :P).
4. Easy to implement and looks similar to CPPUNIT (but a lot simpler).
5. Header-only, so no linking/building nightmare.
6. Published under LGPL.
7. Future versions will support logging (um, not a feature though).

Here's a small example that explains all the stuffs one needs to do to test:

#include &lt;iostream&gt;
#include &lt;string&gt;
#include &lt;cstring&gt;
#include "utlite.h"

// Here's my test case

class Test1 : public utlite::Suite<Test1> // A test case is basically a CRTP (google it!)
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

