#include "pch.h"
#include "CppUnitTest.h"
#include <math.h>


extern "C" float calculateDistance(float x1, float y1, float x2, float y2);
extern "C" void SortingCorners(int* x, int* y);
extern "C" bool formsRectangle(int x[], int y[]);
extern "C" float rectanglePerimeter(float length, float width);
extern "C" float rectangleArea(float length, float width);


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestRectangle
{
	TEST_CLASS(UnitTestRectangle)
	{
	public:

		//Testing Distances
		
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
			int x[] = { -750,-400,-400,-750 };
			int y[] = { -600,-600,-200,-200 };

			SortingCorners(x, y);

		
			double notexpectedx[] = { -750,-400,-400,-750 };
			double notexpectedy[] = { -200,-200,-600,-600 };

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


			int expectedx[] = { 23,88,88,23 };
			int expectedy[] = { 54,54,8,8 };

			for (int i = 0;i < 4;i++) {
				Assert::AreEqual(x[i], expectedx[i]);
				Assert::AreEqual(y[i], expectedy[i]);
			}
		}

		TEST_METHOD(Test_Sort06)
		{
			int x[] = { -100,500,500,-100 };
			int y[] = { -300,200,-300,200 };

			SortingCorners(x, y);


			int expectedx[] = { -100,500,500,-100 };
			int expectedy[] = { 200,200,-300,-300 };

			for (int i = 0;i < 4;i++) {
				Assert::AreEqual(x[i], expectedx[i]);
				Assert::AreEqual(y[i], expectedy[i]);
			}
		}

		TEST_METHOD(Test_Sort07)
		{
			int x[] = {0,0,0,0};
			int y[] = { 0,0,0,0 };

			SortingCorners(x, y);


			int expectedx[] = { 0,0,0,0 };
			int expectedy[] = { 0,0,0,0 };

			for (int i = 0; i < 4; i++) {
				Assert::AreEqual(x[i], expectedx[i]);
				Assert::AreEqual(y[i], expectedy[i]);
			}
		}

		TEST_METHOD(Test_FormsRectangle01)
		{
			int x[] = { 0, 0, 3, 3 };
			int y[] = { 0, 4, 4, 0 };

			bool result = formsRectangle(x, y);

			Assert::IsTrue(result);
		}


		TEST_METHOD(Test_FormsRectangle02)
		{
			int x[] = { 0, 0, 1, 1 };
			int y[] = { 0, 4, 5, 0 };

			bool result = formsRectangle(x, y);

			Assert::IsFalse(result); // Expecting an invalid rectangle
		}

		TEST_METHOD(Test_FormsRectangle03)
		{
			int x[] = { 0, 0, 3, 2 };
			int y[] = { 0, 4, 4, 0 };

			bool result = formsRectangle(x, y);

			Assert::IsFalse(result); // Expecting an invalid rectangle (parallelogram)
		}

		TEST_METHOD(Test_FormsRectangle04)
		{
			int x[] = { 0, 0, 4, 4 };
			int y[] = { 0, 8, 4, 0 };

			bool result = formsRectangle(x, y);

			Assert::IsFalse(result); // Expecting an invalid rectangle
		}

		TEST_METHOD(Test_FormsRectangle05)
		{
			int x[] = { -3,-3,2,2 };
			int y[] = { -2,-7,-7,-2 };

			bool result = formsRectangle(x, y);

			Assert::IsTrue(result); // Expecting a valid rectangle
		}

		TEST_METHOD(Test_FormsRectangle06)
		{
			int x[] = { -5, -5, 5, 5 };
			int y[] = { -3, 3, 3, -3 };

			bool result = formsRectangle(x, y);

			Assert::IsTrue(result); // Expecting a valid rectangle with negative coordinates
		}

		//Checking Area and Perimeter
		TEST_METHOD(Test_Area_Perimeter_01)
		{
			int x[] = { 0,0,6,6 };
			int y[] = { 0,4,4,0 };

			float length = calculateDistance(x[0], y[0], x[1], y[1]);
			float width = calculateDistance(x[1], y[1], x[2], y[2]);

			float perimeter = rectanglePerimeter(length, width);
			double multiplier1 = pow(10.0, 2);  //As we want to round off to 2 decimal places			
			float actual_perimeter = round(perimeter * multiplier1) / multiplier1;

			float area = rectangleArea(length, width);
			double multiplier2 = pow(10.0, 2);  //As we want to round off to 2 decimal places			
			float actual_area = round(area * multiplier2) / multiplier2;

			float expectedPerimeter = 20;
			float expectedArea = 24;

			Assert::AreEqual(perimeter, expectedPerimeter);
			Assert::AreEqual(area, expectedArea);

		}

		TEST_METHOD(Test_Area_Perimeter_02)
		{
			int x[] = { 0, 0, 6, 6 };
			int y[] = { 0, 4, 4, 0 };

			float length = calculateDistance(x[0], y[0], x[1], y[1]);
			float width = calculateDistance(x[1], y[1], x[2], y[2]);

			float perimeter = rectanglePerimeter(length, width);
			double multiplier1 = pow(10.0, 2);  //As we want to round off to 2 decimal places			
			float actual_perimeter = round(perimeter * multiplier1) / multiplier1;
			
			float area = rectangleArea(length, width);
			double multiplier2 = pow(10.0, 2);  //As we want to round off to 2 decimal places			
			float actual_area = round(area* multiplier2) / multiplier2;

			float expectedPerimeter = 20;
			float expectedArea = 24;

			Assert::AreEqual(perimeter, expectedPerimeter);
			Assert::AreEqual(area, expectedArea);
		}


		TEST_METHOD(Test_Area_Perimeter_03)
		{
		
			int x[] = { -3,-3,2,2 };
			int y[] = { -2,-7,-7,-2 };

			float length = calculateDistance(x[0], y[0], x[1], y[1]);
			float width = calculateDistance(x[1], y[1], x[2], y[2]);

			float perimeter = rectanglePerimeter(length, width);
			double multiplier1 = pow(10.0, 2);  //As we want to round off to 2 decimal places			
			float actual_perimeter = round(perimeter * multiplier1) / multiplier1;

			float area = rectangleArea(length, width);
			double multiplier2 = pow(10.0, 2);  //As we want to round off to 2 decimal places			
			float actual_area = round(area * multiplier2) / multiplier2;

			float expectedPerimeter = 20;
			float expectedArea = 25;

			Assert::AreEqual(perimeter, expectedPerimeter);
			Assert::AreEqual(area, expectedArea);
		}

		TEST_METHOD(Test_Area_Perimeter_04)
		{

			int x[] = { -3,-3,2,2 };
			int y[] = { -2,-7,-7,-2 };

			float length = calculateDistance(x[0], y[0], x[1], y[1]);
			float width = calculateDistance(x[1], y[1], x[2], y[2]);

			float perimeter = rectanglePerimeter(length, width);
			double multiplier1 = pow(10.0, 2);  //As we want to round off to 2 decimal places			
			float actual_perimeter = round(perimeter * multiplier1) / multiplier1;

			float area = rectangleArea(length, width);
			double multiplier2 = pow(10.0, 2);  //As we want to round off to 2 decimal places			
			float actual_area = round(area * multiplier2) / multiplier2;

			float expectedPerimeter = 20;
			float expectedArea = 25;

			Assert::AreEqual(perimeter, expectedPerimeter);
			Assert::AreEqual(area, expectedArea);
		}
	};
}
