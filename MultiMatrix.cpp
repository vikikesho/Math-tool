#include"MultiMatrix.h"
void nhap(vector<vector<float>> a, int &m, int &n) {
	a.resize(m);
	for (int i = 0; i < m; i++)
		a[i].resize(n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "Phan tu thu " << "[" << i << "]" << "[" << j << "]" << endl;
			cin >> a[i][j];
		}
	}
}
void xuat(vector<vector<float>> a, int m, int n)
{
	for (int i = 0; i < m; i++) {
		cout << "| ";
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << "|" << endl;
	}
}
void multiply(int m1, int m2, vector<vector<float>> data1, int n1, int n2, vector<vector<float>> data2)
{
	int  i, j;
	vector<vector<float>> res;
	res.resize(data1.size());
	for (int i = 0; i < m1; i++)
		res[i].resize(data2.size());

	for (i = 0; i < m1; i++)
	{
		for (j = 0; j < n2; j++)
		{
			res[i][j] = 0;
			for (int x = 0; x < m2; x++)
			{
				res[i][j] = data1[i][x] + data2[x][j];
			}
		}
	}
	for (i = 0; i < m1; i++)
	{
		for (j = 0; j < n2; j++)
		{
			cout << res[i][j];
		}
		cout << "\n";
	}
}
