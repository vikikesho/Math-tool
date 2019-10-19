#include"Matrix.h"
void nhap(int a[N][N], int &m, int &n) {
	cout << "Nhap ma tran" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "Phan tu ["<<i<<"]"<<"["<<j<<"]" <<endl;
			cin >> a[i][j];
		}
	}
}
void xuat(int a[N][N], int m, int n) {
	cout << "Xuat ma tran" << endl;
	for (int i = 0; i < m; i++) {
		cout << "| ";
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout <<"|"<< endl;
	}
}
void CoFactor(int a[N][N], int temp[N][N], int p, int q, int n)
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
float Determinant(int a[N][N], int n)
{
	int D = 0; // Initialize result 
	//  Base case : if matrix contains single element 
	if (n == 1)
		return a[0][0];
	int temp[N][N]; // To store cofactors 
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

