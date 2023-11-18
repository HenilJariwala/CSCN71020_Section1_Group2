#include "pch.h"
#include "CppUnitTest.h"

extern "C" float calculateDistance(int x1, int y1, int x2, int y2);

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
			float actual_distance = calculateDistance(input_x1,input_y1,input_x2,input_y2);
			float expected = 5;
			Assert::AreEqual(expected, actual_distance);
		}
		TEST_METHOD(calculateDistance02)
		{
			int input_x1 = 1;
			int input_y1 = 2;
			int input_x2 = 4;
			int input_y2 = 6;
			float actual_distance = calculateDistance(input_x1, input_y1, input_x2, input_y2);
			float expected = 5;
			Assert::AreEqual(expected, actual_distance);
		}
		TEST_METHOD(calculateDistance03)
		{
			int input_x1 = 1;
			int input_y1 = 1;
			int input_x2 = 1;
			int input_y2 = 1;
			float actual_distance = calculateDistance(input_x1, input_y1, input_x2, input_y2);
			float expected = 0;
			Assert::AreEqual(expected, actual_distance);
		}
		TEST_METHOD(calculateDistance03)
		{
			int input_x1 = -1;
			int input_y1 = -1;
			int input_x2 = -1;
			int input_y2 = -1;
			float actual_distance = calculateDistance(input_x1, input_y1, input_x2, input_y2);
			float expected = 0;
			Assert::AreEqual(expected, actual_distance);
		}
		TEST_METHOD(calculateDistance04)
		{
			int input_x1 = -2;
			int input_y1 = -3;
			int input_x2 = -4;
			int input_y2 = -8;
			float actual_distance = calculateDistance(input_x1, input_y1, input_x2, input_y2);
			float expected = 5.39;
			Assert::AreEqual(expected, actual_distance);
		}
		TEST_METHOD(calculateDistance05)
		{
			int input_x1 = -2;
			int input_y1 = -3;
			int input_x2 = -4;
			int input_y2 = -8;
			float actual_distance = calculateDistance(input_x1, input_y1, input_x2, input_y2);
			float expected = 5.39;
			Assert::AreEqual(expected, actual_distance);
		}
	};
}