#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab-4.2/Lab-4.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:

        TEST_METHOD(TestCombinations)
        {
            // Вхідні параметри
            int n = 5;
            int r = 3;

            // Очікуваний результат
            vector<vector<int>> expected = {
                {1, 2, 3}, {1, 2, 4}, {1, 2, 5},
                {1, 3, 4}, {1, 3, 5}, {1, 4, 5},
                {2, 3, 4}, {2, 3, 5}, {2, 4, 5},
                {3, 4, 5}
            };

            // Виклик функції
            vector<vector<int>> result = lexicographicCombinations(n, r);

            // Перевірка розміру
            Assert::AreEqual(expected.size(), result.size(), L"Розмір множини неправильний");

            // Перевірка кожної комбінації
            for (size_t i = 0; i < expected.size(); ++i) {
                Assert::IsTrue(expected[i] == result[i], L"Комбінація не співпадає");
            }
        }
    };
}
