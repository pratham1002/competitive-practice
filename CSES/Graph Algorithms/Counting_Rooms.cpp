/*
 * You are given a map of a building, and your task is to count the number of its rooms. 
 * The size of the map is n×m squares, and each square is either floor or wall. 
 * You can walk left, right, up, and down through the floor squares.
 * 
 * Algorithm used: DFS (counting connected components)
 */

#include <bits/stdc++.h>

using namespace std;

void DFS(const int n, const int m, const int i, const int j, vector<vector<bool>> &visited, const vector<vector<char>> &building) {
    visited[i][j] = true;
    // cout << i << " " << j << " " << count << endl;

    // We can move if there is a floor 
    // and it has already not been visited

    // up
    if (i > 0 && building[i - 1][j] == '.'  && !visited[i-1][j]) {
        DFS(n, m, i-1, j, visited, building);
    }

    // down
    if (i < n - 1 && building[i + 1][j] == '.' && !visited[i + 1][j]) {
        DFS(n, m, i + 1, j, visited, building);
    }

    // left
    if (j > 0 && building[i ][j - 1] == '.'  && !visited[i][j - 1]) {
        DFS(n, m, i, j - 1, visited, building);
    }

    // right
    if (j < m - 1 && building[i][j + 1] == '.' && !visited[i][j + 1]) {
        DFS(n, m, i, j + 1, visited, building);
    }
}

int findRooms(const int n, const int m, const vector<vector<char>> &building) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (building[i ][j] == '.' && !visited[i][j]) {
                count++;
                DFS(n, m, i, j, visited, building);
            }
        }
    }

    return count;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> building(n, vector<char>(m));

    // Input
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> building[i][j];
        }
    }

    int num_rooms = findRooms(n, m, building);

    cout << num_rooms << endl;

    return 0;
}