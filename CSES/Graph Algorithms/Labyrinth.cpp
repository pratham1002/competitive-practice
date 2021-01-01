/*
 * You are given a map of a labyrinth,
 * Find a path from start to end. 
 * You can walk left, right, up and down.
 * 
 * If there is a path, 
 * print the length of the shortest such path,
 * its description as a string consisting of 
 * characters L (left), R (right), U (up), and D (down). 
 * You can print any valid solution.
 * 
 * Algorithm used: BFS (shortest path)
 */

#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> BFS(const int n, const int m, pair<int, int> &s, vector<vector<char>> &building) {
    queue<pair<int, int>> q;
    q.push(s);

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    visited[s.first][s.second] = true;

    vector<vector<pair<int, int>>> prev(n, vector<pair<int, int>>(m, pair<int, int>(INT_MIN, INT_MIN)));

    while (!q.empty()) {
        pair<int, int> node = q.front();

        int i = node.first, j = node.second;

        q.pop();

        // We can move if there is a floor 
        // and it has already not been visited

        // up
        if (i > 0 && (building[i - 1][j] == '.' || building[i - 1][j] == 'B')  && !visited[i-1][j]) {
            pair<int, int> next(i - 1, j);
            q.push(next);

            visited[next.first][next.second] = true;
            prev[next.first][next.second] = node;
        }

        // down
        if (i < n - 1 && (building[i + 1][j] == '.' || building[i + 1][j] == 'B') && !visited[i + 1][j]) {
            pair<int, int> next(i + 1, j);
            q.push(next);

            visited[next.first][next.second] = true;
            prev[next.first][next.second] = node;
        }

        // left
        if (j > 0 && (building[i ][j - 1] == '.' || building[i][j - 1] == 'B')  && !visited[i][j - 1]) {
            pair<int, int> next(i, j - 1);
            q.push(next);

            visited[next.first][next.second] = true;
            prev[next.first][next.second] = node;
        }

        // right
        if (j < m - 1 && (building[i][j + 1] == '.' || building[i][j + 1] == 'B') && !visited[i][j + 1]) {
            pair<int, int> next(i, j + 1);
            q.push(next);

            visited[next.first][next.second] = true;
            prev[next.first][next.second] = node;
        }
    }

    return prev;
}

void reconstructPath(pair<int, int> s, pair<int, int> e, vector<vector<pair<int, int>>> prev) {
    // Reconstruct the path going backwards from e
    vector<pair<int, int>> path;

    for (pair<int, int> at = e; at.first != INT_MIN; at = prev[at.first][at.second]) {
        path.push_back(at);
    }

    reverse(path.begin(), path.end());

    // If s and e are connected, return the path
    if (path[0] == s) {
        cout << "YES" << endl;
        cout << path.size() - 1 << endl;

        for (int i = 1; i < path.size(); i++) {
            pair<int, int> curr_node = path[i];
            pair<int, int> prev_node = path[i-1];

            if (prev_node.first == (curr_node.first - 1)) {
                cout << 'D';
            }
            if (prev_node.first == (curr_node.first + 1)) {
                cout << 'U';
            }
            if (prev_node.second == (curr_node.second - 1)) {
                cout << 'R';
            }
            if (prev_node.second == (curr_node.second + 1)) {
                cout << 'L';
            }
        }
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    pair<int, int> start;
    pair<int, int> end;

    vector<vector<char>> building(n, vector<char>(m));

    // Input
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> building[i][j];

            if (building[i][j] == 'A') {
                start.first = i;
                start.second = j;
            }
            if (building[i][j] == 'B') {
                end.first = i;
                end.second = j;
            }
        }
    }

    vector<vector<pair<int, int>>> prev = BFS(n, m, start, building);

    reconstructPath(start, end, prev);

    return 0;
}