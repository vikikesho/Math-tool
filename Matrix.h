#pragma once
#include <iostream>
#include <vector>
#include <math.h>
#include "SubFunctions.h"
using namespace std;

class Matrix
{
public:
	vector<vector<float>> data; //Vector 2 chiều chứa thành phần của ma trận

private:
	float determinant; //Định thức của ma trận

	float RowColMultiply(vector<float>, int); //Hàm nhân hàng và cột của 2 vector, dùng cho hàm nhân 2 vector

public:
	Matrix(); //Constructor mặc định
	Matrix(int, int); //Constructor nhận hàng và cột làm tham số
	~Matrix();//Destructor

	void FindDeterminant();//Hàm tính định thức và lưu vào biến determinant
	void Minor(vector<vector<float>>, int, int);//Hàm tạo ma trận con dùng để tính định thức
	float Determinant();//Hàm getter của biến determinant
	void SetDeterminant(float);
	//Hàm setter của biến determinant dùng để tính định thức trong các trường hợp đặc biệt

	void NhapMatrix();//Hàm nhập ma trận
	void CopyMatrix(Matrix);//Hàm gán ma trận
	void XuatMatrix();//Hàm xuất ma trận

	bool IsSquare();//Kiểm tra ma trận có vuông không
	bool IsDiag();//Kiểm tra ma trận chéo hay không
	void Transpose();//Hàm chuyển vị ma trận

	Matrix Adjoint();//Hàm tính ma trận phụ hợp
	Matrix Inverse();//Hàm tính ma trận nghịch đảo
	Matrix Multiply(Matrix);//Hàm nhân ma trận với ma trận khác

	void SwapRow(int, int);//Hàm hoán vị 2 hàng
	int Rank();//Hàm tính hạng ma trận
};