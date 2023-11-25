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

		//tests for checkForTriangle function
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

			Assert::IsFalse(actual);
		}


		//tests for analyzeTriangle functions
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



		// Test Case 1 for angles: Valid Triangle with sides 3, 4, 5
		TEST_METHOD(Test_ValidTriangle_345)
		{
			int sides[] = { 3, 4, 5 };
			float angles[3];
			find_angles_of_triangle(sides, angles);

			// Check if angles sum up to 180 degrees
			Assert::AreEqual(180.0, static_cast<double>(angles[0] + angles[1] + angles[2]));
		}

		// Test Case 2 for angles: Invalid Triangle with sides 1, 1, 10
		TEST_METHOD(Test_InvalidTriangle_11110)
		{
			int sides[] = { 1, 1, 10 };
			float angles[3];
			int result = find_angles_of_triangle(sides, angles);

			// Check if the function returns an error code
			Assert::AreNotEqual(0, result);
		}

		// Test Case 3 for angles: Invalid Triangle with sides 3, 4, 8 (Does not satisfy the triangle inequality)
		TEST_METHOD(Test_InvalidTriangle_348)
		{
			int sides[] = { 3, 4, 8 };
			float angles[3];
			int result = find_angles_of_triangle(sides, angles);

			// Check if the function returns an error code
			Assert::AreNotEqual(0, result);
		}

		// Test Case 4 for angles: Equilateral Triangle with sides 4, 4, 4
		TEST_METHOD(Test_EquilateralTriangle_444)
		{
			int sides[] = { 4, 4, 4 };
			float angles[3];
			find_angles_of_triangle(sides, angles);

			// Check if all angles are equal (60 degrees)
			Assert::AreEqual(static_cast<double>(60.0), static_cast<double>(angles[0]));
			Assert::AreEqual(static_cast<double>(60.0), static_cast<double>(angles[1]));
			Assert::AreEqual(static_cast<double>(60.0), static_cast<double>(angles[2]));
		}
	};
}
