#include "Inverse.h"
void nhap1(int A[M][M], int& m, int& n) {
	cout << "Nhap ma tran" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "Phan tu [" << i << "]" << "[" << j << "]" << endl;
			cin >> A[i][j];
		}
	}
}
void xuat1(int A[M][M], int m, int n) {
	cout << "Xuat ma tran" << endl;
	for (int i = 0; i < m; i++) {
		cout << "| ";
		for (int j = 0; j < n; j++) {
			cout << A[i][j] << " ";
		}
		cout << "|" << endl;
	}
}
void getCofactor(int A[M][M], int temp[M][M], int p, int q, int n)
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
				temp[i][j++] = A[row][col];

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
   n is current dimension of A[][]. */
int determinant(int A[M][M], int n)
{
	int D = 0; // Initialize result 

	//  Base case : if matrix contains single element 
	if (n == 1)
		return A[0][0];

	int temp[M][M]; // To store cofactors 

	int sign = 1;  // To store sign multiplier 

	 // Iterate for each element of first row 
	for (int f = 0; f < n; f++)
	{
		// Getting Cofactor of A[0][f] 
		getCofactor(A, temp, 0, f, n);
		D += sign * A[0][f] * determinant(temp, n - 1);

		// terms are to be added with alternate sign 
		sign = -sign;
	}

	return D;
}

// Function to get adjoint of A[N][N] in adj[N][N]. 
void adjoint(int A[M][M], int adj[M][M])
{
	if (M == 1)
	{
		adj[0][0] = 1;
		return;
	}

	// temp is used to store cofactors of A[][] 
	int sign = 1, temp[M][M];

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			// Get cofactor of A[i][j] 
			getCofactor(A, temp, i, j, M);

			// sign of adj[j][i] positive if sum of row 
			// and column indexes is even. 
			sign = ((i + j) % 2 == 0) ? 1 : -1;

			// Interchanging rows and columns to get the 
			// transpose of the cofactor matrix 
			adj[j][i] = (sign) * (determinant(temp, M - 1));
		}
	}
}

// Function to calculate and store inverse, returns false if 
// matrix is singular 
bool inverse(int A[M][M], float inverse[M][M])
{
	// Find determinant of A[][] 
	int det = determinant(A, M);
	if (det == 0)
	{
		cout << "Singular matrix, can't find its inverse";
		return false;
	}

	// Find adjoint 
	int adj[M][M];
	adjoint(A, adj);

	// Find Inverse using formula "inverse(A) = adj(A)/det(A)" 
	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++)
			inverse[i][j] = adj[i][j] / float(det);

	return true;
}

