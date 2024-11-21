#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printBitVector(const vector<int>& bitVector) {
    for (int bit : bitVector) {
        cout << bit << " ";
    }
    cout << endl;
}

int main() {
    // Вхідні дані
    vector<int> U = { 1, 2, 3, 4, 5 }; // Універсум
    vector<int> A = { 1, 2, 4 };       // Множина A
    vector<int> B = { 2, 3, 5 };       // Множина B

    // Сортування універсуму
    sort(U.begin(), U.end());

    // Бітові рядки
    vector<int> Abit(U.size(), 0);
    vector<int> Bbit(U.size(), 0);

    // Формування бітового рядка множини A
    for (size_t i = 0; i < U.size(); ++i) {
        if (find(A.begin(), A.end(), U[i]) != A.end()) {
            Abit[i] = 1;
        }
    }

    // Формування бітового рядка множини B
    for (size_t i = 0; i < U.size(); ++i) {
        if (find(B.begin(), B.end(), U[i]) != B.end()) {
            Bbit[i] = 1;
        }
    }

    // Операції над множинами
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

    // Виведення результатів
    cout << "Universe: ";
    for (int elem : U) {
        cout << elem << " ";
    }
    cout << endl;

    cout << "Bit vector for set A: ";
    printBitVector(Abit);

    cout << "Bit vector for set B: ";
    printBitVector(Bbit);

    cout << "notA: ";
    printBitVector(notA);

    cout << "AperB: ";
    printBitVector(AperB);

    cout << "AobB: ";
    printBitVector(AobB);

    cout << "ArizB: ";
    printBitVector(ArizB);

    cout << "AxorB: ";
    printBitVector(AxorB);

    return 0;
}
