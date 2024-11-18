#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_7.1_rec/7.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestRecursiveSort)
        {
            const int rowCount = 3;
            const int colCount = 4;
            int** matrix = new int* [rowCount];
            for (int i = 0; i < rowCount; i++) {
                matrix[i] = new int[colCount] { i, rowCount - i, 0, i + 1 };
            }

            RecursiveSort(matrix, rowCount, colCount);

            Assert::IsTrue(matrix[0][0] <= matrix[1][0]); // Перевірка сортування першого стовпця
            Assert::IsTrue(matrix[1][0] <= matrix[2][0]);

            for (int i = 0; i < rowCount; i++)
                delete[] matrix[i];
            delete[] matrix;
        }
    };
}