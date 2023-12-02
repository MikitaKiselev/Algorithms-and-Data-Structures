#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k = sqrt(n);
    vector<long long int> arr2;

    for (int i = 0; i < n; i += k) {
        long long int bsum = 0;
        for (int j = i; j < min(i + k, n); j++) {
            bsum += arr[j];
        }
        arr2.push_back(bsum);
    }

    vector<long long int> arr3;
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        string operation;
        cin >> operation;

        if (operation == "FindSum") {
            int l, r;
            cin >> l >> r;
            int jl = l / k;
            int jr = r / k;
            long long int result = 0;
            
            if (jl == jr) {
                for (int j = l; j < r; j++) {
                    result += arr[j];
                }
            }
            else {
                for (int j = l; j < (jl + 1) * k; j++) {
                    result += arr[j];
                }

                for (int j = jl + 1; j < jr; j++) {
                    result += arr2[j];
                }

                for (int j = jr * k; j < r; j++) {
                    result += arr[j];
                }
            }

            cout << result << endl;
        }
        else if (operation == "Add") {
            long long int i, x;
            cin >> i >> x;
            arr[i] += x;
            arr2[i / k] += x;
        }
    }

    return 0;
}