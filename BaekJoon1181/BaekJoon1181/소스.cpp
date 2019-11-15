#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


bool compare(string w1, string w2) {
	if (w1.length() == w2.length())
		return w1 < w2;

	else
		return w1.length() < w2.length();
}
void arrange(vector<string> &v, int N) {

	sort(v.begin(), v.end(), compare);
	string temp;
	for (int i = 0; i < N; i++) {
		if (temp == v[i])
			continue;
		cout << v[i] << endl;
		temp = v[i];
	}


}
int main() {
	int N=0;//단어의 개수
	string words;//단어
	vector<string> v;
	v.reserve(200);
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> words;
		v.push_back(words);	
	}
	arrange(v, N);
	
}