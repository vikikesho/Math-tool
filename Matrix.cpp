#include"Matrix.h"

Matrix::Matrix() //Hàm khởi tạo mặc định tạo ma trận đơn vị 1x1
{
	data.resize(1); //Số hàng bằng 1
	data[0].resize(1); //Số cột bằng 1
	data[0][0] = 1; //Thành phần duy nhất
	determinant = 1; //Có định thức bằng 1
}

Matrix::Matrix(int row, int col) //Hàm khởi tạo ma trận row x col
{
	data.resize(row); //Số hàng bằng row
	for (int i = 0; i < data.size(); i++) {
			data[i].resize(col);
	} //Số cột bằng col

	for (int i = 0; i < data.size(); i++) {
		for (int j = 0; j < data[i].size(); j++) {
			data[i][j] = 0;
		}
	} //Các thành phần của ma trận bằng 0

	determinant = 0;//Định thức bằng 0
}

Matrix::~Matrix() //Hàm hủy
{
	for (int i = 0; i < data.size(); i++)
		data[i].clear();
	//Hủy từng hàng
	
	data.clear();//Hủy toàn bộ ma trận

	determinant = 0;//Cho giá trị định thức bằng 0
}

void Matrix::NhapMatrix() //Nhập ma trận
{
	int temp; //Biến tạm thời để nhận giá trị số hàng và cột
	cout << "Nhap so hang: ";
	cin >> temp; //Nhận vào số hàng của ma trận
	if (temp == 0)
		return; //Nếu nhận giá trị 0 thì thoát, không nhận dữ liệu nữa
	data.resize(temp);//Mở rộng ma trận theo số hàng của ma trận
	cout << "Nhap so cot: ";
	cin >> temp;//Nhận vào số cột của ma trận
	for (int i = 0; i < data.size(); i++)
		data[i].resize(temp);//Mở rộng từng hàng của ma trận theo số cột

	cout << "Nhap ma tran" << endl;
	for (int i = 0; i < data.size(); i++) {
		cout << "Row " << i + 1 << endl; //Nhập giá trị theo từng hàng
		for (int j = 0; j < data[i].size(); j++) {
			cin >> data[i][j]; //Nhận giá trị nhập vào vào hàng i cột j
		}
	}

	FindDeterminant();//Tìm định thức và lưu vào biến determinant
}

void Matrix::CopyMatrix(Matrix other) //Sao chép, hay gán ma trận bằng ma trận khác
{
	for (int i = 0; i < data.size(); i++)
		data[i].clear(); 
	data.clear();//Xóa toàn bộ dữ liệu ban đầu của ma trận

	data.resize(other.data.size());//Sửa kích cỡ ma trận theo kích cỡ ma trận other
	for (int i = 0; i < data.size(); i++) {
		data[i] = other.data[i];
	}//Sao chép từng dữ liệu vào ma trận này
}
void Matrix::XuatMatrix() //Xuất ma trận ra màn hình
{
	cout << "Xuat ma tran" << endl;
	for (int i = 0; i < data.size(); i++) {
		cout << "| ";
		for (int j = 0; j < data[i].size(); j++) {
			cout << data[i][j] << " ";
		}
		cout <<"|"<< endl;
	}//Xuất ma trận dưới dạng:
		// | a b c |
		// | d e f |
}

bool Matrix::IsSquare() //Kiểm tra ma trận có vuông không
{
	if (data.size() == data[0].size())
		return true; //Nếu số hàng bằng số cột trả về true
	else return false;// Nếu không trả về false
}

bool Matrix::IsDiag() //Kiểm tra ma trận có chéo hay không
{
	if (!IsSquare())
		return false; //Nếu ma trận không vuông trả về false 
	//Nếu không thì kiểm tra các giá trị khác không
	for (int i = 0; i < data.size(); i++) {
		for (int j = 0; j < data[i].size(); j++) {
			if (i != j && data[i][j] != 0)
				return false; //Nếu giá trị khác không nằm ở vị trí ij mà i khác j thì trả về false
		}
	}
	return true;//Còn không thì trả về true
}

float Matrix::Determinant() //Hàm trả về giá trị của định thức
{
	if (IsSquare())
		return determinant; //Nếu ma trận vuông thì trả về giả trị của định thức
}

void Matrix::Minor(vector<vector<float>> temp, int p, int q) //Hàm tạo ma trận con bằng cách xóa đi hàng p cột q của ma trận gốc
{
	int i = 0, j = 0;//Khai báo 2 biến đếm số hàng và cột
	
	for (int row = 0; row < temp.size(); row++) //Vòng lặp qua các hàng của ma trận con
	{
		for (int col = 0; col < temp.size(); col++)//Vòng lặp qua các cột của ma trận con
		{
			
			if (row != p && col != q) //Nếu phần tử không thuộc hàng p hay cột q thì gán vào ma trận con
			{
				data[i][j] = temp[row][col];
				j++;
				
				if (j == temp.size() - 1)//Biến đếm khi đạt tới cột cuối cùng thì quay lại cột 1 hàng kế tiếp
				{
					j = 0;
					i++;
				}
			}
		}
	}
}

void Matrix::FindDeterminant() //Hàm tính định thức bằng phương pháp đệ quy
{
	if (!IsSquare()) //Nếu ma trận không vuông thì gán định thức bằng 0 (nhưng không mang ý nghĩa gì cả)
		determinant = 0;
	else if(IsDiag()) {
		//Ma trận chéo thì định thức bằng phần tử trên đường chéo chính nhân với nhau
		determinant = 1;
		for (int i = 0; i < data.size(); i++)//Vòng lặp để nhân các phần tử đường chéo với nhau
			determinant = determinant * data[i][i];
	}
	else {
		float D = 0; //Gọi biết D làm định thức tạm thời
		
		//Trường hợp ma trận có 1 hàng 1 cột
		if (data.size() == 1)
			D = data[0][0]; //Định thức bằng chính giá trị duy nhất
		else {
			//Còn không thì tạo ma trận con với kích thước (n-1) x (n-1)
			Matrix temp(data.size() - 1, data.size() - 1);
			
			//Chọn hàng đầu tiên của ma trận, lần lượt xét các cột
			for (int f = 0; f < data.size(); f++)
			{
				temp.Minor(data, 0, f);//Gán giá trị vào ma trận con bằng cách loại bỏ hàng đầu tiên và cột f
				temp.FindDeterminant();//Tìm định thức của ma trận con đó
				D += pow(-1,f) * data[0][f] * temp.Determinant();// Cộng vào D giá trị theo công thức định thức
			}
		}
		determinant = D;//Trả về định thức của ma trận bằng giá trị D
	}
}

void Matrix::Transpose() //Hàm chuyển vị ma trận
{
	if (IsSquare()) // Nếu ma trận vuông thì đổi chỗ phần tử ij với phần tử ji
	{
		for (int i = 0; i < data.size(); i++)
			for (int j = 0; j <= i; j++) {
				float temp = data[i][j];
				data[i][j] = data[j][i];
			} //Đổi chỗ phần tử ij với phần tử ji
	}
	else {
		//Ma trận không vuông thì tạo ma trận tạm thời kích cỡ bằng cột x hàng
		Matrix tempMat(data[0].size(), data.size());

		for (int i = 0; i < tempMat.data.size(); i++)
			for (int j = 0; j < data.size(); j++) {
				tempMat.data[i][j] = data[j][i]; //Gán giá trị ij của ma trận tạm thời với giá trị ji
			}
		CopyMatrix(tempMat);//Gán ma trận tạm thời vào lại ma trận gốc
	}
}

void Matrix::SetDeterminant(float det)
{
	determinant = det;//Trả về giá trị của định thức
}

Matrix Matrix::Adjoint() //Hàm tạo ma trận phụ hợp
{
	Matrix adj(data.size(), data.size());//Ma trận phụ hợp có kích cỡ giống ma trận gốc
	adj.SetDeterminant(pow(determinant, data.size() - 1));//Ma trận phụ hợp có định thức bằng định thức ma trận gốc mũ n-1

	if (data.size() == 1)//Nếu ma trận gốc là 1x1
	{
		adj.data[0][0] = 1;//Thì ma trận phụ hợp bằng | 1 |
		return adj;
	}
	else {
		//Tạo ma trận tạm thời để làm ma trận con
		Matrix temp(data.size() - 1, data.size() - 1);

		for (int i = 0; i < data.size(); i++)
		{
			for (int j = 0; j < data.size(); j++)
			{
				//Tương tự như hàm tính định thức, tính định thức ma trận con 
				temp.Minor(data, i, j);
				temp.FindDeterminant();

				//Ma trận phụ hợp là ma trận chứa định thức ma trận con * (-1)^(i+j) rồi chuyển vị
				adj.data[j][i] = pow(-1, i + j) * (temp.Determinant());
			}
		}

		return adj;//Trả về ma trận phụ hợp
	}
}

Matrix Matrix::Inverse() //Tìm ma trận nghịch đảo bằng ma trận phụ hợp và định thức
{
	Matrix inv(data.size(), data.size());//Tạo ma trận nghịch đảo kích cỡ bằng ma trận gốc
	inv.SetDeterminant(1 / determinant);//Định thức ma trận nghịch đảo bằng 1/det(M)

	Matrix adj(data.size(), data.size());//Tạo ma trận phụ hợp
	adj.CopyMatrix(Adjoint());// Gán giá trị vào ma trận phụ hợp

	for (int i = 0; i < data.size(); i++)
		for (int j = 0; j < data.size(); j++)
			inv.data[i][j] = adj.data[i][j] / determinant;
	//Ma trận nghịch đảo có phần tử bằng phần tử ma trận phụ hợp chia cho định thức

	return inv;//Trả về ma trận nghịch đảo
}

float Matrix::RowColMultiply(vector<float> col, int row) //Hàm nhân hàng với cột của 2 ma trận
{
	float S = 0;//Gọi biến S làm giá trị trả về
	for (int i = 0; i < data[row].size(); i++)
		S += data[row][i] * col[i]; //Phép nhân hàng và cột ma trận bằng tổng của tích các phần tử
	return S;//Trả về S
}

Matrix Matrix::Multiply(Matrix other)
{
	Matrix product(data.size(), other.data[0].size());//Ma trận tích có kích cỡ bằng hàng ma trận 1 nhân cột ma trận 2
	product.SetDeterminant(determinant * other.Determinant());//Có định thức bằng tích định thức 2 ma trận

	vector<float> temp;
	temp.resize(other.data[0].size()); //Gọi vector tạm thời để chứa cột của ma trận 2

	for (int i = 0; i < product.data.size(); i++)
		for (int j = 0; j < product.data[0].size(); j++) {
			//Xét qua các hàng và cột của ma trận tích
			for (int k = 0; k < other.data[0].size(); k++) //Gán giá trị của cột j vào vector temp
				temp[k] = other.data[k][j];
			product.data[i][j] = RoundFloat(RowColMultiply(temp, i));//Thực hiện phép nhân giữa hàng i và cột j
		}

	return product;//Trả về ma trận tích
}

void Matrix::SwapRow(int r1, int r2) //Hoán vị 2 hàng với nhau
{
	for (int i = 0; i < data[0].size(); i++)
	{
		int temp = data[r1][i];
		data[r1][i] = data[r2][i];
		data[r2][i] = temp;
	}//Đổi giá trị 2 phần tử cùng cột khác hàng với nhau

	SetDeterminant(-determinant);//Định thức sau khi hoán vị bị đổi dấu
}

int Matrix::Rank() //Hàm tìm hạng ma trận bằng cách đưa ma trận về dang bậc thang rút gọn
{
	if(data.size() < data[0].size())
		int rank = data.size();//Đặt hạng ma trận bằng số hàng nếu hàng nhỏ hơn cột
	else int rank = data[0].size();//Và ngược lại

	for (int row = 0; row < rank; row++) //Xét từng cột
	{
		if (data[row][row])//Nếu tại vị trí ij (i=j) khác 0
		{
			for (int col = 0; col < data.size(); col++)
			{
				if (col != row)
				{ 
					float mult = data[col][row] / data[row][row];//Tìm hệ số để thực hiện chuẩn hóa 1 cột
					for (int i = 0; i < rank; i++)
						data[col][i] -= mult * data[row][i];
					//Chuẩn hóa 1 cột bằng cách cho toàn bô phần tử dưới phần tử đang xét thành 0
				}
			}
		}
		else
		{
			bool reduce = true;//Gọi biến reduce để xem ma trận có được rút gọn chưa
			
			//Nếu tại ij (i=j) bằng 0
			for (int i = row + 1; i < data.size(); i++)//Thì xét các phần tử dưới nó
			{ 
				if (data[i][row])
				//Nếu khác 0 thì hoán vị 2 hàng với nhau và reduce thành false (ma trận chưa được rút gọn)
				{
					SwapRow(row, i);
					reduce = false;
					break;
				}
			}

			if (reduce)//Nếu đã được thu gọn thì hạng giảm xuống 1 và cột hiện tại thay bằng cột cuối cùng
			{
				rank--;
				for (int i = 0; i < data.size(); i++)
					data[i][row] = data[i][rank];
			}
			row--;
			//Giảm số hàng đang xét xuống 1 để xét lại hàng này 1 lần nữa. Khi đó thực hiện lại vòng lặp sẽ rút gọn được
			//hàng này thành 0
		}
	}
	return rank;//Trả về hạng ma trận
}

