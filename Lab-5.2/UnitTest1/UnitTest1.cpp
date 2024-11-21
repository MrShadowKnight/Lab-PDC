#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab-5.2/Lab-5.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestSetOperations
{
    TEST_CLASS(UnitTestSetOperations)
    {
    public:

        // Тест формування бітового рядка
        TEST_METHOD(TestBitVectorFormation)
        {
            vector<int> U = { 1, 2, 3, 4, 5 };
            vector<int> A = { 1, 2, 4 };

            // Очікуваний бітовий рядок для A
            vector<int> expectedAbit = { 1, 1, 0, 1, 0 };

            vector<int> Abit(U.size(), 0);
            for (size_t i = 0; i < U.size(); ++i) {
                if (find(A.begin(), A.end(), U[i]) != A.end()) {
                    Abit[i] = 1;
                }
            }

            Assert::IsTrue(Abit == expectedAbit, L"Бітовий рядок для множини A сформовано неправильно.");
        }

        // Тест операцій над множинами
        TEST_METHOD(TestSetOperations)
        {
            vector<int> U = { 1, 2, 3, 4, 5 };
            vector<int> A = { 1, 2, 4 };
            vector<int> B = { 2, 3, 5 };

            vector<int> Abit(U.size(), 0);
            vector<int> Bbit(U.size(), 0);

            for (size_t i = 0; i < U.size(); ++i) {
                if (find(A.begin(), A.end(), U[i]) != A.end()) {
                    Abit[i] = 1;
                }
                if (find(B.begin(), B.end(), U[i]) != B.end()) {
                    Bbit[i] = 1;
                }
            }

            // Очікувані результати
            vector<int> expectedNotA = { 0, 0, 1, 0, 1 };
            vector<int> expectedAperB = { 0, 1, 0, 0, 0 };
            vector<int> expectedAobB = { 1, 1, 1, 1, 1 };
            vector<int> expectedArizB = { 1, 0, 0, 1, 0 };
            vector<int> expectedAxorB = { 1, 0, 1, 1, 1 };

            vector<int> notA(U.size());
            vector<int> AperB(U.size());
            vector<int> AobB(U.size());
            vector<int> ArizB(U.size());
            vector<int> AxorB(U.size());

            for (size_t i = 0; i < U.size(); ++i) {
                notA[i] = 1 - Abit[i];
                AperB[i] = Abit[i] & Bbit[i];
                AobB[i] = Abit[i] | Bbit[i];
                ArizB[i] = Abit[i] & (1 - Bbit[i]);
                AxorB[i] = Abit[i] ^ Bbit[i];
            }

            // Перевірка операцій
            Assert::IsTrue(notA == expectedNotA, L"Операція notA виконана неправильно.");
            Assert::IsTrue(AperB == expectedAperB, L"Операція AperB виконана неправильно.");
            Assert::IsTrue(AobB == expectedAobB, L"Операція AobB виконана неправильно.");
            Assert::IsTrue(ArizB == expectedArizB, L"Операція ArizB виконана неправильно.");
            Assert::IsTrue(AxorB == expectedAxorB, L"Операція AxorB виконана неправильно.");
        }
    };
}
