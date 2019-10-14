#include"Matrix.h"
void nhap(vector < vector<float>>& data, int &m, int &n) {
	cout << "Nhap vao so dong cua ma tran" << endl;
	cin >> m;
	data.resize(m);
	cout << "Nhap vao so cot cua ma tran" << endl;
	cin >> n;
	for (int i = 0; i < m; i++) {
		data[i].resize(n);
	}
	cout << "Nhap ma tran" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "Phan tu ["<<i<<"]"<<"["<<j<<"]" <<endl;
			cin >> data[i][j];
		}
	}
}
void xuat(vector<vector<float>> data, int m, int n) {
	cout << "Xuat ma tran" << endl;
	for (int i = 0; i < m; i++) {
		cout << "| ";
		for (int j = 0; j < n; j++) {
			cout << data[i][j] << " ";
		}
		cout <<"|"<< endl;
	}
}
//int dinhthuc(vector<vector<float>>data, int m, int n) {
	//if (m != n)
		//cout << "Khong tinh duoc dinh thuc" << endl;
	//else {
		//int p = m;
		//if (p == 1) return data[0][0];
		//if (p == 2) return data[0][0] * data[1][1] - data[0][1] * data[1][0];
		//if (p == 3) return data[0][0] * (data[1][1] * data[2][2] - data[1][2] * data[2][1]) - data[0][1]*(data[1][0]*data[2][2]-data[1][2]*data[2][0])+data[0][2]*(data[1][0]*data[2][1]-data[1][1]*data[2][0]);
			
	//}
//}
void CoFactor(vector<vector<float>>a, vector<vector<float>>temp, int p, int q, int n)
{
	int i = 0, j = 0;
	// Looping for each element of the matrix 
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++)
		{
			//  Copying into temporary matrix only those element 
			//  which are not in given row and column 
			if (row != p && col != q)
			{
				temp[i][j++] = a[row][col];
				// Row is filled, so increase row index and 
				// reset col index 
				if (j == n - 1)
				{
					j = 0;
					i++;
				}
			}
		}
	}
}
/* Recursive function for finding determinant of matrix.
   n is current dimension of mat[][]. */
float Determinant(vector<vector<float>>a, int n)
{
	int D = 0; // Initialize result 
	//  Base case : if matrix contains single element 
	if (n == 1)
		return a[0][0];
	vector<vector<float>>temp; // To store cofactors 
	int sign = 1;  // To store sign multiplier 
	// Iterate for each element of first row 
	for (int f = 0; f < n; f++)
	{
		// Getting Cofactor of mat[0][f] 
		CoFactor(a, temp, 0, f, n);
		D += sign * a[0][f] * Determinant(temp, n - 1);
		// terms are to be added with alternate sign 
		sign = -sign;
	}
	return D;
}

