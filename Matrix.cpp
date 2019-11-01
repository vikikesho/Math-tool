#include"Matrix.h"

Matrix::Matrix()
{
	data.resize(1);
	data[0].resize(1);
	data[0][0] = 1;
	determinant = 1;
}

Matrix::Matrix(int row, int col)
{
	data.resize(row);
	for (int i = 0; i < data.size(); i++) {
			data[i].resize(col);
	}

	for (int i = 0; i < data.size(); i++) {
		for (int j = 0; j < data[i].size(); j++) {
			data[i][j] = 0;
		}
	}

	determinant = 0;
}

Matrix::~Matrix()
{
	for (int i = 0; i < data.size(); i++)
		data[i].clear();
	data.clear();

	determinant = 0;
}

void Matrix::NhapMatrix() 
{
	int temp;
	cout << "Nhap so hang: ";
	cin >> temp;
	if (temp == 0)
		return;
	data.resize(temp);
	cout << "Nhap so cot: ";
	cin >> temp;
	for (int i = 0; i < data.size(); i++)
		data[i].resize(temp);

	cout << "Nhap ma tran" << endl;
	for (int i = 0; i < data.size(); i++) {
		cout << "Row " << i + 1 << endl;
		for (int j = 0; j < data[i].size(); j++) {
			cin >> data[i][j];
		}
	}

	FindDeterminant();
}

void Matrix::CopyMatrix(Matrix other)
{
	for (int i = 0; i < data.size(); i++)
		data[i].clear();
	data.clear();

	data.resize(other.data.size());
	for (int i = 0; i < data.size(); i++) {
		data[i] = other.data[i];
	}
}
void Matrix::XuatMatrix() 
{
	cout << "Xuat ma tran" << endl;
	for (int i = 0; i < data.size(); i++) {
		cout << "| ";
		for (int j = 0; j < data[i].size(); j++) {
			cout << data[i][j] << " ";
		}
		cout <<"|"<< endl;
	}
}

bool Matrix::IsSquare()
{
	if (data.size() == data[0].size())
		return true;
	else return false;
}

bool Matrix::IsDiag()
{
	if (!IsSquare())
		return false;
	for (int i = 0; i < data.size(); i++) {
		for (int j = 0; j < data[i].size(); j++) {
			if (i != j && data[i][j] != 0)
				return false;
		}
	}
	return true;
}

float Matrix::Determinant()
{
	if (IsSquare())
		return determinant;
}

void Matrix::Minor(vector<vector<float>> temp, int p, int q)
{
	int i = 0, j = 0;
	// Looping for each element of the matrix 
	for (int row = 0; row < temp.size(); row++)
	{
		for (int col = 0; col < temp.size(); col++)
		{
			//  Copying into temporary matrix only those element 
			//  which are not in given row and column 
			if (row != p && col != q)
			{
				data[i][j] = temp[row][col];
				j++;
				// Row is filled, so increase row index and 
				// reset col index 
				if (j == temp.size() - 1)
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
void Matrix::FindDeterminant()
{
	if (!IsSquare())
		determinant = 0;
	else if(IsDiag()) {
		determinant = 1;
		for (int i = 0; i < data.size(); i++)
			determinant = determinant * data[i][i];
	}
	else {
		float D = 0;
		//  Base case : if matrix contains single element 
		if (data.size() == 1)
			D = data[0][0];
		else {
			Matrix temp(data.size() - 1, data.size() - 1); 
			// Iterate for each element of first row 
			for (int f = 0; f < data.size(); f++)
			{
				// Getting Cofactor of mat[0][f] 
				temp.Minor(data, 0, f);
				temp.FindDeterminant();
				D += pow(-1,f) * data[0][f] * temp.Determinant();
				// terms are to be added with alternate sign 
			}
		}
		determinant = D;
	}
}

void Matrix::Transpose()
{
	if (IsSquare())
	{
		for (int i = 0; i < data.size(); i++)
			for (int j = 0; j <= i; j++) {
				float temp = data[i][j];
				data[i][j] = data[j][i];
			}
	}
	else {
		Matrix tempMat(data[0].size(), data.size());

		for (int i = 0; i < tempMat.data.size(); i++)
			for (int j = 0; j < data.size(); j++) {
				tempMat.data[i][j] = data[j][i];
			}
		CopyMatrix(tempMat);
	}
}

void Matrix::SetDeterminant(float det)
{
	determinant = det;
}

Matrix Matrix::Adjoint()
{
	Matrix adj(data.size(), data.size());
	adj.SetDeterminant(pow(determinant, data.size() - 1));

	if (data.size() == 1)
	{
		adj.data[0][0] = 1;
		return adj;
	}
	else {
		// temp is used to store cofactors of A[][] 
		Matrix temp(data.size() - 1, data.size() - 1);

		for (int i = 0; i < data.size(); i++)
		{
			for (int j = 0; j < data.size(); j++)
			{
				// Get cofactor of A[i][j] 
				temp.Minor(data, i, j);
				temp.FindDeterminant();

				// Interchanging rows and columns to get the 
				// transpose of the cofactor matrix 
				adj.data[j][i] = pow(-1, i + j) * (temp.Determinant());
			}
		}

		return adj;
	}
}

Matrix Matrix::Inverse()
{
	Matrix inv(data.size(), data.size());
	inv.SetDeterminant(1 / determinant);

	Matrix adj(data.size(), data.size());
	adj.CopyMatrix(Adjoint());

	for (int i = 0; i < data.size(); i++)
		for (int j = 0; j < data.size(); j++)
			inv.data[i][j] = adj.data[i][j] / determinant;

	return inv;
}

float Matrix::RowColMultiply(vector<float> col, int row)
{
	float S = 0;
	for (int i = 0; i < data[row].size(); i++)
		S += data[row][i] * col[i];
	return S;
}

Matrix Matrix::Multiply(Matrix other)
{
	Matrix product(data.size(), other.data[0].size());
	product.SetDeterminant(determinant * other.Determinant());

	vector<float> temp;
	temp.resize(other.data[0].size());

	for (int i = 0; i < product.data.size(); i++)
		for (int j = 0; j < product.data[0].size(); j++) {
			for (int k = 0; k < other.data[0].size(); k++)
				temp[k] = other.data[k][j];
			product.data[i][j] = RoundFloat(RowColMultiply(temp, i));
		}

	return product;
}

void Matrix::SwapRow(int r1, int r2)
{
	for (int i = 0; i < data[0].size(); i++)
	{
		int temp = data[r1][i];
		data[r1][i] = data[r2][i];
		data[r2][i] = temp;
	}

	SetDeterminant(-determinant);
}

int Matrix::Rank() //This fucntion also reduces the matrix into echelon form
{
	int rank = data.size();

	for (int row = 0; row < rank; row++)
	{
		// Before we visit current row 'row', we make 
		// sure that mat[row][0],....mat[row][row-1] 
		// are 0. 

		// Diagonal element is not zero 
		if (data[row][row])
		{
			for (int col = 0; col < data.size(); col++)
			{
				if (col != row)
				{
					// This makes all entries of current 
					// column as 0 except entry 'mat[row][row]' 
					float mult = data[col][row] / data[row][row];
					for (int i = 0; i < rank; i++)
						data[col][i] -= mult * data[row][i];
				}
			}
		}

		// Diagonal element is already zero. Two cases 
		// arise: 
		// 1) If there is a row below it with non-zero 
		//    entry, then swap this row with that row 
		//    and process that row 
		// 2) If all elements in current column below 
		//    mat[r][row] are 0, then remvoe this column 
		//    by swapping it with last column and 
		//    reducing number of columns by 1. 
		else
		{
			bool reduce = true;

			/* Find the non-zero element in current
				column  */
			for (int i = row + 1; i < data.size(); i++)
			{
				// Swap the row with non-zero element 
				// with this row. 
				if (data[i][row])
				{
					SwapRow(row, i);
					reduce = false;
					break;
				}
			}

			// If we did not find any row with non-zero 
			// element in current columnm, then all 
			// values in this column are 0. 
			if (reduce)
			{
				// Reduce number of columns 
				rank--;

				// Copy the last column here 
				for (int i = 0; i < data.size(); i++)
					data[i][row] = data[i][rank];
			}

			// Process this row again 
			row--;
		}

		// Uncomment these lines to see intermediate results 
		// display(mat, R, C); 
		// printf("\n"); 
	}
	return rank;
}

