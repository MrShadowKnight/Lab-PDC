#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> lexicographicCombinations(int n, int r) {
    vector<vector<int>> result;
    vector<int> combination(r);

    for (int i = 0; i < r; ++i) {
        combination[i] = i + 1;
    }
    result.push_back(combination);

    while (true) {
        int i = r - 1;
        while (i >= 0 && combination[i] == n - r + i + 1) {
            --i;
        }

        if (i < 0) {
            break;
        }

        ++combination[i];
        for (int j = i + 1; j < r; ++j) {
            combination[j] = combination[j - 1] + 1;
        }
        result.push_back(combination);
    }

    return result;
}

int main() {
    int n, r;
    cout << "Enter n = ";
    cin >> n;
    cout << "Enter r = ";
    cin >> r;

    vector<vector<int>> combinations = lexicographicCombinations(n, r);
    for (const auto& combination : combinations) {
        cout << "combination = {";
        for (size_t i = 0; i < combination.size(); ++i) {
            cout << combination[i] << (i < combination.size() - 1 ? ", " : "");
        }
        cout << "}" << endl;
    }
    return 0;
}
