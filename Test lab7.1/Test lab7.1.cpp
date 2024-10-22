#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab7.1/lab7.1.cpp"  // Підключаємо файл, який містить функції

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testlab71
{
	TEST_CLASS(Testlab71)
	{
	public:

		TEST_METHOD(CreateTest)
		{
			
			int rowCount = 7;
			int colCount = 6;
			int Low = 9;
			int High = 61;

			
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];

			
			Create(a, rowCount, colCount, Low, High);

			
			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					Assert::IsTrue(a[i][j] >= Low, L" Low");
					Assert::IsTrue(a[i][j] <= High, L" High");
				}
			}

			
			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}