#include"Matrix.h"
void nhap(vector<vector<double>>&data, int &m, int &n) {
	cout << "Nhap ma tran" << endl;
	data.resize(m);
	for (int i = 0; i < m; i++) {
		
		data[i].resize(n);
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "Phan tu ["<<i<<"]"<<"["<<j<<"]" <<endl;
			cin >> data[i][j];
		}
	}
}
void xuat(vector<vector<double>>data, int m, int n) {
	cout << "Xuat ma tran" << endl;
	for (int i = 0; i < m; i++) {
		cout << "| ";
		for (int j = 0; j < n; j++) {
			cout << data[i][j] << " ";
		}
		cout <<"|"<< endl;
	}
}
void CoFactor(vector<vector<double>>data, vector<vector<double>> temp, int p, int q, int n)
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
				temp[i][j++] = data[row][col];
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
double Determinant(vector<vector<double>>data, int n)
{
	int D = 0; // Initialize result 
	//  Base case : if matrix contains single element 
	if (n == 1)
		return data[0][0];
	vector<vector<double>>temp; // To store cofactors 
	temp.resize(data.size());
	for (int t = 0; t < data.size(); t++) {
		temp[t].resize(data.size());
	}
	int sign = 1;  // To store sign multiplier 
	// Iterate for each element of first row 
	for (int f = 0; f < n; f++)
	{
		// Getting Cofactor of mat[0][f] 
		CoFactor(data, temp, 0, f, n);
		D += sign * data[0][f] * Determinant(temp, n - 1);
		// terms are to be added with alternate sign 
		sign = -sign;
	}
	return D;
}

