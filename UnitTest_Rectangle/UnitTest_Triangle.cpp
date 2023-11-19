#include "pch.h"
#include "CppUnitTest.h"
#include <math.h>

extern "C" char* analyzeTriangle(int side1, int side2, int side3);
extern "C" int checkForTriangle(int side1, int side2, int side3);
extern "C" int find_angles_of_triangle(int*, float*);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestRectangle
{
	TEST_CLASS(UnitTestRectangle)
	{
	public:

		TEST_METHOD(Check_Triangle01)
		{
			int s1 = 9, s2 = 9, s3 = 5;

			bool actual = checkForTriangle(s1, s2, s3);

			Assert::IsTrue(actual);
		}

		TEST_METHOD(Check_Triangle02)
		{
			int s1 = 0, s2 = 0, s3 = 0;

			bool actual = checkForTriangle(s1, s2, s3);

			Assert::IsFalse(actual);
		}

		TEST_METHOD(Check_Triangle03)
		{
			int s1 = -25, s2 = 5, s3 = 5;

			bool actual = checkForTriangle(s1, s2, s3);

			Assert::IsTrue(actual);
		}

		TEST_METHOD(Analyze_EquilateralTriangle)
		{
			int s1 = 5, s2 = 5, s3 = 5;

			char* actual = analyzeTriangle(s1, s2, s3);

			Assert::AreEqual("Equilateral triangle", actual);
		}

		TEST_METHOD(Analyze_IsoscelesTriangle)
		{
			int s1 = 5, s2 = 5, s3 = 8;

			char* actual = analyzeTriangle(s1, s2, s3);

			Assert::AreEqual("Isosceles triangle", actual);
		}

		TEST_METHOD(Analyze_ScaleneTriangle)
		{
			int s1 = 3, s2 = 4, s3 = 5;

			char* actual = analyzeTriangle(s1, s2, s3);

			Assert::AreEqual("Scalene triangle", actual);
		}

		TEST_METHOD(Analyze_NotATriangle)
		{
			int s1 = 2, s2 = 2, s3 = 5;

			char* actual = analyzeTriangle(s1, s2, s3);

			Assert::AreEqual("Isosceles triangle", actual);
		}
	};
}
