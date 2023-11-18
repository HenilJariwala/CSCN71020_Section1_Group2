#include "pch.h"
#include "CppUnitTest.h"
#include <math.h>


extern "C" float calculateDistance(int x1, int y1, int x2, int y2);
extern "C" void SortingCorners(int* x, int* y);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestRectangle
{
	TEST_CLASS(UnitTestRectangle)
	{
	public:
		
		TEST_METHOD(calculateDistance01)
		{
			int input_x1 = 0;
			int input_y1 = 0;
			int input_x2 = 3;
			int input_y2 = 4;
			
			//Invoking and getting distance and rounding it off
			float distance = calculateDistance(input_x1, input_y1, input_x2, input_y2);
			double multiplier = pow(10.0, 2);  //As we want to round off to 2 decimal places			
			float actual_distance = round(distance * multiplier) / multiplier;

			float expected = 5;
			Assert::AreEqual(expected, actual_distance);
		}
		TEST_METHOD(calculateDistance02)
		{
			int input_x1 = 1;
			int input_y1 = 2;
			int input_x2 = 4;
			int input_y2 = 6;
			
			//Invoking and getting distance and rounding it off
			float distance = calculateDistance(input_x1, input_y1, input_x2, input_y2);
			double multiplier = pow(10.0, 2);  //As we want to round off to 2 decimal places
			float actual_distance = round(distance * multiplier) / multiplier;

			float expected = 5;
			Assert::AreEqual(expected, actual_distance);
		}
		TEST_METHOD(calculateDistance03)
		{
			int input_x1 = 1;
			int input_y1 = 1;
			int input_x2 = 1;
			int input_y2 = 1;
			
			//Invoking and getting distance and rounding it off
			float distance = calculateDistance(input_x1, input_y1, input_x2, input_y2);
			double multiplier = pow(10.0, 2);  //As we want to round off to 2 decimal places			
			float actual_distance = round(distance * multiplier) / multiplier;

			float expected = 0;
			Assert::AreEqual(expected, actual_distance);
		}
		TEST_METHOD(calculateDistance04)
		{
			int input_x1 = -1;
			int input_y1 = -1;
			int input_x2 = -1;
			int input_y2 = -1;

			//Invoking and getting distance and rounding it off
			float distance = calculateDistance(input_x1, input_y1, input_x2, input_y2);
			double multiplier = pow(10.0, 2);  //As we want to round off to 2 decimal places			
			float actual_distance = round(distance * multiplier) / multiplier;

			float expected = 0;
			Assert::AreEqual(expected, actual_distance);
		}
		TEST_METHOD(calculateDistance05)
		{
			int input_x1 = -2;
			int input_y1 = -3;
			int input_x2 = -4;
			int input_y2 = -8;

			float distance = calculateDistance(input_x1, input_y1, input_x2, input_y2);
			double multiplier = pow(10.0, 2);  //As we want to round off to 2 decimal places			
			float actual_distance = round(distance * multiplier) / multiplier;

			float expected = 5.39;
			Assert::AreEqual(expected, actual_distance);
		}

		TEST_METHOD(calculateDistance06)
		{
			int input_x1 = -2;
			int input_y1 = -3;
			int input_x2 = -4;
			int input_y2 = -8;
			
			float distance = calculateDistance(input_x1, input_y1, input_x2, input_y2);
			double multiplier = pow(10.0, 2);  //As we want to round off to 2 decimal places			
			float actual_distance = round(distance * multiplier) / multiplier;

			float expected = 5.39;
			Assert::AreEqual(expected, actual_distance);
		}


		//Testing consecutive corner
		TEST_METHOD(Test_Sort01) 
		{
			int x[] = { -2,3,3,-2 };
			int y[] = { -1,-1,4,4 };

			SortingCorners(x, y);

			int expectedx[] = {-2,3,3,-2};
			int expectedy[] = {4,4,-1,-1,};

			for (int i = 0;i < 4;i++) {
				Assert::AreEqual(x[i], expectedx[i]);
				Assert::AreEqual(y[i], expectedy[i]);
			}
		}

		TEST_METHOD(Test_Sort02)
		{
			int x[] = { 5,10,10,15 };
			int y[] = { 10,5,15,10 };

			SortingCorners(x, y);

			int expectedx[] = { 5,10,15,10 };
			int expectedy[] = { 10,15,10,5 };

			for (int i = 0;i < 4;i++) {
				Assert::AreEqual(x[i], expectedx[i]);
				Assert::AreEqual(y[i], expectedy[i]);
			}
		}

		TEST_METHOD(Test_Sort03)
		{
			int x[] = { -2,3,3,-2 };
			int y[] = { -1,-1,4,4,};

			SortingCorners(x, y);

			int notexpectedx[] = { -2,3,3,-2};
			int notexpectedy[] = { 4,4,-1,-1 };

			for (int i = 0;i < 4;i++) {
				Assert::AreEqual(x[i], notexpectedx[i]);
				Assert::AreEqual(y[i], notexpectedy[i]);
			}
		}

		TEST_METHOD(Test_Sort04)
		{
			int x[] = { -1.5,2.8,-1.5,2.8 };
			int y[] = { 4.7,-2.3,-2.3,4.7 };

			SortingCorners(x, y);

		
			double notexpectedx[] = { -1.5,2.8,2.8,-1.5 };
			double notexpectedy[] = { 4.7,4.7,-2.3,-2.3 };

			for (int i = 0;i < 4;i++) {
				Assert::AreEqual((double)x[i], notexpectedx[i]);
				Assert::AreEqual((double)y[i], notexpectedy[i]);
			}
		}

		TEST_METHOD(Test_Sort05)
		{
			int x[] = { 23,88,23,88 };
			int y[] = { 54,8,8,54 };

			SortingCorners(x, y);


			int notexpectedx[] = { 23,88,88,23 };
			int notexpectedy[] = { 54,54,8,8 };

			for (int i = 0;i < 4;i++) {
				Assert::AreEqual(x[i], notexpectedx[i]);
				Assert::AreEqual(y[i], notexpectedy[i]);
			}
		}

			TEST_METHOD(Test_Sort05)
		{
			int x[] = { -100,500,500,-100 };
			int y[] = { -300,200,-300,200 };

			SortingCorners(x, y);


			int notexpectedx[] = { -100,500,500,-100 };
			int notexpectedy[] = { 200,200,-300,-300 };

			for (int i = 0;i < 4;i++) {
				Assert::AreEqual(x[i], notexpectedx[i]);
				Assert::AreEqual(y[i], notexpectedy[i]);
			}
		}
		



	};
}
