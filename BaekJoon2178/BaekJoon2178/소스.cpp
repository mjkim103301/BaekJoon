#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
queue<pair<int, int>> q;

void checkDuplicate(pair<int, int> p, int **array) {
	array[p.first][p.second] = 0;//0이면 이미 지나간 곳.
}
int findNext(pair<int, int> out, int**array) {
	int x = 0, y = 0;
	int add_count = 0;
	x = out.first;
	y = out.second;
	if (array[x][y - 1] == 1)
	{
		pair<int, int>p = make_pair(x, y-1);
		checkDuplicate(p, array);
		q.push(p);
		add_count++;
	}
	
	if (array[x + 1][y] == 1)
	{
		pair<int, int>p = make_pair(x+1, y);
		checkDuplicate(p, array);
		q.push(p);
		add_count++;
	}
	
	if (array[x][y + 1] == 1)
	{
		pair<int, int>p = make_pair(x, y + 1);
		checkDuplicate(p, array);
		q.push(p);
		add_count++;
	}
	if (array[x - 1][y] == 1)
	{
		pair<int, int>p = make_pair(x-1, y );
		checkDuplicate(p, array);
		q.push(p);
		add_count++;
	}

	return add_count;
	

}
void findAnswer(int **array, int row, int column) {
	
	int count = 0;
	vector<int> v;
	v.reserve(10);
	int add_count = 0;
	int delete_count = 0;
	int x = 1, y = 1;
	int k = 0;
	pair<int, int>p = make_pair(x, y);
	
	checkDuplicate(p, array);//지나간 곳이라고 체크하기//지나갔으면 0, 안지나갔으면 1

	q.push(p);
	
	add_count ++;
	v.push_back(add_count);
	while (!q.empty()) {
		
		pair<int, int> out = q.front();
		q.pop();
		delete_count++;
		
		if (out.first== row && out.second == column) {
			count++;
			cout << count<<endl;
			
			break;
		}
	
		add_count+=findNext(out, array);
		
		if (delete_count ==v.at(k) ) {
			v.push_back(add_count);
			count++;
			k++;
		}
	}
}
int main() {
	int row, column;
	cin >> row >> column;

	int** array = new int*[row+2];//array[열 개수][행 개수] 테두리를 0으로 둘러쌓이게 함
	for (int i = 0; i < row+2; i++) {
		array[i] = new int[column+2];
		memset(array[i], 0, sizeof(int) * (column + 2));
	}

	for (int i = 1; i <= row; i++) {//데이터 입력
		for (int j = 1; j <= column; j++) {
			scanf_s("%1d", &array[i][j]);
		}
	}
	findAnswer(array, row, column);

	return 0;
}