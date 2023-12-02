#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");
    int n, m, q;
    input >> n >> m >> q;
    vector<int> arr(n + 1, -1);
    vector<vector<int>> arrM(m+1, vector<int>(2));
    vector<int> arrQ(q);
    vector <int> arrE(m + 1, 1);
    for (int i = 1; i < m+1; i++) {
        input >> arrM[i][0] >> arrM[i][1];
    }

    for (int i = q - 1; i >=0; i--) {
        input >> arrQ[i];
        arrE[arrQ[i]] = 0;
    }

    long long int ind = 0;
    if (q != m) {
        for (int i = 1; i <= m; i++) {
            if (arrE[i]) {
                int temp_1 = arrM[i][0];
                int temp_2 = arrM[i][1];

                while (arr[temp_1] >= 0) {
                    temp_1 = arr[temp_1];
                }

                while (arr[temp_2] >= 0) {
                    temp_2 = arr[temp_2];
                }

                if (temp_1 != temp_2) {
                    n -= 1;

                    if (abs(arr[temp_1]) >= abs(arr[temp_2])) {
                        arr[temp_1] += arr[temp_2];
                        arr[temp_2] = temp_1;
                    }
                    else {
                        arr[temp_2] += arr[temp_1];
                        arr[temp_1] = temp_2;
                    }
                }
            }
        }
    }

    for (long long int index = 0; index < q; index++) {
        long long int temp_1 = arrM[arrQ[index]][0];
        long long int temp_2 = arrM[arrQ[index]][1];

        while (arr[temp_1] >= 0) {
            temp_1 = arr[temp_1];
        }

        while (arr[temp_2] >= 0) {
            temp_2 = arr[temp_2];
        }

        if (temp_1 != temp_2) {
            n -= 1;
            if (n == 1) {
                ind = index + 1;
                break;
            }
            if (abs(arr[temp_1]) >= abs(arr[temp_2])) {
                arr[temp_1] += arr[temp_2];
                arr[temp_2] = temp_1;
            }
            else {
                arr[temp_2] += arr[temp_1];
                arr[temp_1] = temp_2;
            }
        }
    }
   
    for (int i = 0; i < q - ind; i++) {
        output << '1';
    }

    for (int i = 0; i < ind; i++) {
        output << '0';
    }

    return 0;
}