#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void dfs(int** arr, int N, int start, vector<int>& visited) {
    visited[start] = 1;
    cout << start << " ";

    for (int i = 1; i < N+1; ++i) {
        if (arr[start][i] == 1 && visited[i] != 1) {

            dfs(arr, N, i, visited);
        }
    }
}

void bfs(int** arr, int N, int start, vector<int>& visited) {
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int i = 1; i < N+1; ++i) {
            if (arr[current][i] == 1 && visited[i] != 1) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    int N, M, start;
    cin >> N >> M >> start;
    vector<int> visited(N+1, 0);

    int** arr = new int*[N+1];
    for (int i = 0; i < N+1; ++i) {
        arr[i] = new int[N+1]();
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
		arr[b][a] = 1;
    }

    dfs(arr, N, start, visited);
    cout << endl;
    visited.assign(N+1, false); // Reset visited array for BFS
    bfs(arr, N, start, visited);
    cout << endl;

    for (int i = 0; i < N+1; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}

