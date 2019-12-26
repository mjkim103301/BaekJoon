#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int MAX = 100001;
bool visited[MAX];
vector<pair<int, int>> v[MAX];
vector<int> v_length;
int longest=0, farNode;
queue<int> q;

void dfs(int start ,int length) {
	visited[start] = true;
	q.push(start);
	for (int i = 0; i < v[start].size(); i++) {
		int nextNode = v[start][i].first;
		int distance = v[start][i].second;
		if (length > longest) {
			longest = length;
			farNode = start;

		}
		if (!visited[nextNode]) {
			dfs(nextNode, length + distance);
		}
		
	}
	v_length.push_back(length);
	
}
int main() {
	

	int diameter;//트리의 지름
	int node, distance;//입력할 숫자들
	int parent;//부모노드
	cin >> diameter;

	for (int i = 0; i < diameter; i++) {
		cin >> parent;
		while (1) {		
			cin >> node;
			if (node != -1) {
				cin >> distance;
				v[parent].push_back({ node, distance });
			}
			else {
				break;
			}
					
		}
		
	}
	v_length.reserve(10);
	dfs(1, 0);
	while (!q.empty()) {
		visited[q.front()] = false;
		q.pop();
	}
	dfs(farNode, 0);
	cout << longest;
	return 0;
}