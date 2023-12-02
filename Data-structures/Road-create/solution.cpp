#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream file("input.txt");
    ofstream file2("output.txt");
    int n, q;
    file >> n >> q;
    vector<int> arr(n + 1, -1);
    for (int i = 0; i < q; i++) {
        int temp_1, temp_2;
        file >> temp_1 >> temp_2;
        while (arr[temp_1] >= 0) {
            temp_1 = arr[temp_1];
        }
        while (arr[temp_2] >= 0) {
            temp_2 = arr[temp_2];
        }
        if (temp_1 != temp_2) {
            if (abs(arr[temp_1]) >= abs(arr[temp_2])) {
                arr[temp_1] += arr[temp_2];
                arr[temp_2] = temp_1;
            }
            else {
                arr[temp_2] += arr[temp_1];
                arr[temp_1] = temp_2;
            }
            n -= 1;
            file2 << n << endl;
        }
        else {
            file2 << n << endl;
        }
    }
    file.close();
    file2.close();
    return 0;
}