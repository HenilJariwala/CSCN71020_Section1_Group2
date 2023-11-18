#include "pch.h"
#include "CppUnitTest.h"
#include "..//PolygonChecker/main.c"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(UnitTest1)
{
public:

    TEST_METHOD(TestTriangleAnalysis)
    {
        // Arrange
        int side1 = 3;
        int side2 = 4;
        int side3 = 5;

        // Act
        char* result = analyzeTriangle(side1, side2, side3);

        // Assert
        Assert::AreEqual("Scalene triangle", result);
    }

    TEST_METHOD(TestCheckForTriangle)
    {
        // Arrange
        int side1 = 3;
        int side2 = 4;
        int side3 = 5;

        // Act
        bool isValid = checkForTriangle(side1, side2, side3);

        // Assert
        Assert::IsTrue(isValid);
    }

    // Add more tests as needed
};
