#include "pch.h"
#include "CppUnitTest.h"
#include <math.h>

extern "C" char* analyzeTriangle(int side1, int side2, int side3);
extern "C" int checkForTriangle(int side1, int side2, int side3);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestRectangle
{
	TEST_CLASS(UnitTestRectangle)
	{
	public:

		TEST_METHOD(Check_Triangle)
		{
			int s1 = 8, s2 = 9, s3 = 5;

			bool expected = true;
			bool actual = analyzeTriangle(s1, s2, s3); // Change here

			Assert::AreEqual(expected, actual);
		}
	};
}
