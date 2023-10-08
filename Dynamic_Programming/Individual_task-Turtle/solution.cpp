#include <iostream>
using namespace std;

int main() {
    int p = 1000000007;
    int n;
    cin >> n;
    int m;
    cin >> m;

    if (m == 0 || n == 0) {
        cout << 0;
        return 0;
    }

    long long int* current_row = new long long int[m];
    long long int* previous_row = new long long int[m];


    for (int i = 0; i < m; i++) {
        current_row[i] = 1;
        previous_row[i] = 1;
    }

    for (int i = 1; i < n; i++) {

        swap(current_row, previous_row);

        for (int j = 1; j < m; j++) {
            current_row[j] = (current_row[j - 1] % p + previous_row[j] % p + previous_row[j - 1] % p) % p;
        }
    }

    cout << current_row[m - 1];

    return 0;
}