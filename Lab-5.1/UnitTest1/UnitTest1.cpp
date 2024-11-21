#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab-5.1/Lab-5.1.cpp"
#include <vector>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

vector<string> generateCartesianProduct(const vector<char>& A, const vector<char>& C) {
    vector<string> cartesianProduct;

    for (char c1 : C) {
        for (char a : A) {
            for (char c2 : C) {
                string element = string(1, c1) + a + c2; // Побудова елементу добутку
                cartesianProduct.push_back(element);
            }
        }
    }

    return cartesianProduct;
}

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:

        TEST_METHOD(TestCartesianProduct)
        {
            // Вхідні дані
            vector<char> A = { 'a', 'b', 'c' };
            vector<char> C = { '0', '1' };

            // Очікуваний результат
            vector<string> expected = {
                "0a0", "0a1", "0b0", "0b1", "0c0", "0c1",
                "1a0", "1a1", "1b0", "1b1", "1c0", "1c1"
            };

            // Генерація результату
            vector<string> result = generateCartesianProduct(A, C);

            // Перевірка розміру
            Assert::AreEqual(expected.size(), result.size(), L"Розмір множини неправильний");

            // Перевірка значень
            for (size_t i = 0; i < expected.size(); i++) {
                Assert::AreEqual(expected[i], result[i], L"Елементи множини не співпадають");
            }
        }
    };
}
