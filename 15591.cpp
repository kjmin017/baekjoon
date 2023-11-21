#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Node {
	int vertex;
	int weight;
};

void usado(const vector<vector<Node>>& graph, int N, int k, int start, vector<bool>& visited) {
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		if (visited[v]) continue;
		visited[v] = true;

		for (const auto& node : graph[v]) {
			if (node.weight >= k && !visited[node.vertex]) {
				q.push(node.vertex);
			}
		}
	}
}

int main() {
	int N, Q;
	cin >> N >> Q;

	vector<vector<Node>> graph(N);
	vector<pair<int, int>> queries(Q); 

	for (int i = 0; i < N - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a - 1].push_back({ b - 1, c });
		graph[b - 1].push_back({ a - 1, c });
	}

	for (int i = 0; i < Q; i++) {
		cin >> queries[i].first >> queries[i].second;
		queries[i].second--; 
	}

	for (const auto& q : queries) {
		int k = q.first;
		int v = q.second;
		vector<bool> visited(N, false);

		usado(graph, N, k, v, visited);

		int cnt = count(visited.begin(), visited.end(), true);
		cout << cnt-1 << endl;
	}

	return 0;
}

