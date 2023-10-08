#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ifstream input("input.txt");
    string arr1, arr2;
    input >> arr1;
    arr2 = arr1;
    reverse(arr2.begin(), arr2.end());
    int n = arr1.length();

    vector<vector<int>> matrix(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr1[i] == arr2[j]) {
                matrix[i + 1][j + 1] = matrix[i][j] + 1;
            }
            else {
                matrix[i + 1][j + 1] = max(matrix[i][j + 1], matrix[i + 1][j]);
            }
        }
    }

    vector<char> answer;

    int i = n, j = n;

    while (i > 0 && j > 0) {
        if (arr1[i - 1] == arr2[j - 1]) {
            answer.push_back(arr1[i - 1]);
            --i;
            --j;
        }
        else if (matrix[i - 1][j] > matrix[i][j - 1]) {
            --i;
        }
        else {
            --j;
        }
    }


    ofstream output("output.txt");
    output << matrix[n][n] << endl;
    for (char c : answer) {
        output << c;
    }
    output << endl;

    return 0;
}