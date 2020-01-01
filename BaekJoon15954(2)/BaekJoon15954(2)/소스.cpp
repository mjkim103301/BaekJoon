#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

void fun_deviation(double* dev, int num) {//ǥ������ �ּ� ���
	double min = dev[0];
	for (int i = 1; i < num; i++) {
		if (min > dev[i])
		{
			min = dev[i];
		}

	}
	cout << fixed << setprecision(11) << min;
}
void fun_average(double* like, int N, int K) {

	int num = N - (K - 1);
	num = (num*(num + 1)) / 2;
	double* avg = new double[num];// ���
	double* dev = new double[num];//ǥ������

	int i = 0, j = 0, k = K;
	do
	{
		do
		{
			double average = 0.0;
			double deviation = 0.0;
			for (int z = j; z < k; z++) {//��� ���ϱ�
				average += like[z];
			}

			average /= (double)(k-j);
			avg[i] = average;

			for (int l = j; l < k; l++) {//ǥ������ ���ϱ�
				deviation += pow(like[l] - avg[i], 2);
			}
			deviation /= (double)(k - j);
			dev[i] = sqrt(deviation);

			k++;
			i++;
		} while (k != N+1);
		j++;
		k = K+j;
	} while (i != num);

	fun_deviation(dev, num);

}
int main() {
	int N, K;

	cin >> N >> K;

	double* like = new  double[N];

	for (int i = 0; i < N; i++) {
		cin >> like[i];
	}
	fun_average(like, N, K);

}