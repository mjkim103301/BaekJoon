#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int N;//������ ����
	int number=0;//����� ����	
	int distance=0;//�ѰŸ�

	cin >> N>>number;

	int police1[2] = { 1, 1 };
	int police2[2] = { N, N };
	int *x = new int[number];//x��ǥ
	int *y = new int[number];//y��ǥ
	int *car_number = new int[number];
	for (int i = 0; i < number; i++)
	{
		cin >> x[i] >> y[i];


		if (sqrt(pow(x[i] - police1[0], 2) + pow(y[i] - police1[1], 2)) > sqrt(pow(x[i] - police2[0], 2) + pow(y[i] - police2[1], 2)))
		{
			distance += abs(police2[0] - x[i]) +abs( police2[1] - y[i]);
			police2[0] = x[i];
			police2[1] = y[i];
			car_number[i] = 2;

		}
		else
		{
			distance+=abs(police1[0] - x[i]) + abs(police1[1] - y[i]);
			police1[0] = x[i];
			police1[1] = y[i];
			car_number[i] = 1;
		}
	}
	cout << distance<<endl;
	for (int i = 0; i < number; i++)
	{
		cout << car_number[i] << endl;
	}
}