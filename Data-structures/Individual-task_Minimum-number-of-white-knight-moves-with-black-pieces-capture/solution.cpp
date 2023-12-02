#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <tuple>

using namespace std;

int main() {
    ifstream file("in.txt");
    int n, m;
    file >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            file >> matrix[i][j];
        }
    }

    int x1, y1, x2, y2;
    file >> x1 >> y1 >> x2 >> y2;
    x1 -= 1;
    y1 -= 1;
    x2 -= 1;
    y2 -= 1;
    file.close();

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    pq.push(make_tuple(0, x1, y1));

    ofstream file2("out.txt");

    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();
        int distance = get<0>(curr);
        int x = get<1>(curr);
        int y = get<2>(curr);

        if (x == x2 && y == y2) {
            file2 << distance;
            file2.close();
            return 0;
        }

        if (!visited[x][y]) {
            visited[x][y] = true;
            vector<pair<int, int>> moves = { {x + 2, y + 1}, {x + 2, y - 1}, {x - 2, y + 1}, {x - 2, y - 1},
                                            {x + 1, y + 2}, {x + 1, y - 2}, {x - 1, y + 2}, {x - 1, y - 2} };

            for (auto move : moves) {
                int move_x = move.first;
                int move_y = move.second;

                if (0 <= move_x && move_x < n && 0 <= move_y && move_y < m && !visited[move_x][move_y] && matrix[move_x][move_y] != -1) {
                    pq.push(make_tuple(distance + 1 + matrix[move_x][move_y], move_x, move_y));
                }
            }
        }
    }

    file2 << "No";
    file2.close();

    return 0;
}