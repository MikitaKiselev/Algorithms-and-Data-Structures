#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    ofstream file2("bst.out");
    ifstream file("bst.in");

    int n;
    file >> n;
    vector<vector<long long int>> matrix(n, vector<long long int>(3, 0));
    matrix[0][1] = numeric_limits<long long int>::min();
    matrix[0][2] = numeric_limits<long long int>::max();
    file >> matrix[0][0];

    for (int i = 1; i < n; i++) {

        long long int a, position;
        char letter;
        file >> a >> position >> letter;
        matrix[i][0] = a;
        if (letter == 'L') {
            matrix[i][1] = matrix[position - 1][1];
            matrix[i][2] = matrix[position - 1][0];
        }
        else {
            matrix[i][1] = matrix[position - 1][0];
            matrix[i][2] = matrix[position - 1][2];
        }
        if (matrix[i][0] < matrix[i][1] || matrix[i][0] >= matrix[i][2]) {
            file2 << "NO";
            return 0;
        }
    }
    file2 << "YES";
    return 0;
}