#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Оголошення множин
    vector<char> A = { 'a', 'b', 'c' };
    vector<char> C = { '0', '1' };

    // Декартовий добуток C x A x C
    vector<string> cartesianProduct;

    for (char c1 : C) {
        for (char a : A) {
            for (char c2 : C) {
                string element = string(1, c1) + a + c2; // Побудова елементу добутку
                cartesianProduct.push_back(element);
            }
        }
    }

    // Виведення результату
    cout << "C x A x C:" << endl;
    int count = 0;
    for (const string& element : cartesianProduct) {
        cout << element << " ";
        count++;

        if (count % 3 == 0) {
            cout << endl;
        }
    }

    if (count % 3 != 0) {
        cout << endl;
    }

    return 0;
}
