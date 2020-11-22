#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 7.2)/lab 7.2).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72
{
	TEST_CLASS(UnitTest72)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t;
			const int rowCount = 2;
			const int colCount = 2;
			const int i = 5;
			int** a = new int* [colCount];
			a[0][0] = 8;
			a[0][1] = 14;
			a[1][0] = 10;
			a[1][1] = 20;
			t = SearchMinOdd(a, i, colCount);
			Assert::AreEqual(t, 8);
		}
	};
}
