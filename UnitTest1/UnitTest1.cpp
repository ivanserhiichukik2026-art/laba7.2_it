#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\qq\source\repos\laba7.2_it\laba7.2_it\laba7.2_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72Iter
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMaxColumn)
        {
            int r0[] = { 1, 4, 3 };
            int r1[] = { 2, 9, 5 };
            int r2[] = { 7, 6, 8 };

            int* a[] = { r0, r1, r2 };

            Assert::AreEqual(9, MaxColumn(a, 3, 1));
        }

        TEST_METHOD(TestSearchMinMax)
        {
            int r0[] = { 0, 1, 0, 2, 0, 3 };
            int r1[] = { 0, 7, 0, 9, 0, 5 };
            int r2[] = { 0, 4, 0, 6, 0, 2 };

            int* a[] = { r0, r1, r2 };

            Assert::AreEqual(5, SearchMinMax(a, 3, 6));
        }
    };
}
