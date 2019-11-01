#include "Matrix.h"
#include "LinearVector.h"
#include "SubFunctions.h"
#include <iostream>
using namespace std;

void main(){
	int index;
	cout << "***----Ho Tro Hoc Tap Toan Cao Cap----***" << endl;
	cout << "1: Phep toan tren vector" << endl;
	cout << "2: Phep toan tren ma tran" << endl;

	cout << "Nhap vao so thu tu cua phep tinh toan" << endl;
	cin >> index;//Nhận lệnh từ người dùng
	
	if (index == 1) {
		do {
			cout << "1: Cong 2 vector" << endl;
			cout << "2: Nhan vector voi 1 so" << endl;
			cout << "0: Thoat" << endl;
			cout << "Nhap vao so thu tu de lua chon tinh toan voi vector" << endl;
			cin >> index;//Nhận lệnh từ người dùng

			int element;
			vector<float> data1;//Vector sử dụng chung cho tính toán

			if (index == 1) {
				cout << "Cong 2 vector" << endl;
				cout << "So phan tu: ";
				cin >> element;//Nhập vào số phần tử
				cout << "Vector thu 1" << endl;
				TaoVector(data1, element);//Nhập vector thứ 1
				XuatVector(data1);//Xuất vector thứ 1
				cout << "Vector thu 2" << endl;
				vector<float> data2;//Vector thứ 2
				TaoVector(data2, element);//Nhập vector thứ 2
				XuatVector(data2);//Xuất vector thứ 2
				CongVector(data1, data2);//Cộng 2 vector
			}
			if (index == 2) {
				cout << "Nhan vector voi 1 so" << endl;
				cout << "So phan tu: ";
				cin >> element;//Nhập số phần tử
				cout << "Vector" << endl;
				TaoVector(data1, element);//Nhập vào vector 1
				XuatVector(data1);//Xuất vector 1
				NhanVector(data1);//Nhân vector 1 với 1 số
			}
		} while (index != 0);//Tiếp tục chương trình nếu lệnh khác 0
	}
	
	if (index == 2) {
		vector<Matrix> matArr;
		matArr.resize(4);//Tạo 4 ma trận để sử dụng tính toán

		cout << "Ma tran A:" << endl;
		matArr[0].NhapMatrix();//Nhập ma trận A

		cout << "Ma tran B:" << endl;
		matArr[1].NhapMatrix();//Nhập ma trận B

		cout << "Ma tran C:" << endl;
		matArr[2].NhapMatrix();//Nhập ma trận C

		//Ma trận thứ 4 để làm bộ nhớ lưu lại ma trận kết quả gần nhất
		do {
			cout << "1: Xem va nhap lai ma tran" << endl;
			cout << "2: Dinh thuc cua ma tran" << endl;
			cout << "3: Nghich dao cua ma tran" << endl;
			cout << "4: Tich 2 ma tran" << endl;
			cout << "5: Hang cua ma tran" << endl;
			cout << "0: Thoat" << endl;

			cout << "Nhap vao so thu tu de lua chon tinh toan voi ma tran" << endl;
			cin >> index;//Nhận lệnh từ người dùng

			if (index == 1) {
				do {
					cout << "1: Ma tran A" << endl;
					cout << "2: Ma tran B" << endl;
					cout << "3: Ma tran C" << endl;
					cout << "0: Quay lai" << endl;
					cin >> index;//Nhận lệnh từ người dùng

					if (index >= 1 && index <= 3) { //Tránh việc index nằm ngoài lựa chọn được cho phép
						matArr[index - 1].XuatMatrix();//Xem lại ma trận
						matArr[index - 1].NhapMatrix();//Sửa lại ma trận
					}
				} while (index != 0);//Tiếp tục chương trình nếu lệnh khác 0

				index = 1;
			}

			if (index == 2) {
				cout << "1: Ma tran A" << endl;
				cout << "2: Ma tran B" << endl;
				cout << "3: Ma tran C" << endl;
				cout << "4: Ma tran Ans" << endl;
				cin >> index;//Nhận lệnh từ người dùng

				if (index >= 1 && index <= 3) {//Tránh việc index nằm ngoài lựa chọn được cho phép
					if (matArr[index - 1].IsSquare()) //Nếu ma trận vuông thì mới thực hiên tính toán định thức
						cout << "Dinh thuc ma tran: " << matArr[index - 1].Determinant() << endl;
					else cout << "Ma tran khong vuong." << endl;
				}

				index = 2;
			}
			
			if (index == 3) {
				cout << "1: Ma tran A" << endl;
				cout << "2: Ma tran B" << endl;
				cout << "3: Ma tran C" << endl;
				cout << "4: Ma tran Ans" << endl;
				cin >> index;//Nhận lệnh từ người dùng

				if (index >= 1 && index <= 3) {//Tránh việc index nằm ngoài lựa chọn được cho phép
					if (matArr[index - 1].IsSquare() && matArr[index-1].Determinant() != 0) {
						//Ma trận vuông có định thức khác không mới thực hiện tính toán
						cout << "Ma tran nghich dao: " << endl;
						matArr[3] = matArr[index - 1].Inverse();//Tìm ma trận nghịch đảo
						matArr[3].XuatMatrix();//In ra ma trận
					}
					else cout << "Ma tran khong kha nghich." << endl;
				}

				index = 3;
			}

			if (index == 4) {
				cout << "1: Ma tran A" << endl;
				cout << "2: Ma tran B" << endl;
				cout << "3: Ma tran C" << endl;
				cout << "4: Ma tran Ans" << endl;
				cin >> index;//Nhận lệnh từ người dùng
				
				int temp = 4;
				cout << "1: Ma tran A" << endl;
				cout << "2: Ma tran B" << endl;
				cout << "3: Ma tran C" << endl;
				cout << "4: Ma tran Ans" << endl;
				cin >> temp;//Nhận lệnh từ người dùng

				if (index >= 1 && index <= 3) {//Tránh việc index nằm ngoài lựa chọn được cho phép
					if (matArr[index - 1].data[0].size() != matArr[temp - 1].data.size())
						//Nếu 2 ma trận không hợp lệ sẽ không thực hiện tính toán
						cout << "2 ma tran khong thich hop" << endl;
					else {
						matArr[3] = matArr[index - 1].Multiply(matArr[temp - 1]);
						//Nhân 2 ma trận
						matArr[3].XuatMatrix();
					}
				}

				index = 4;
			}
			if (index == 5) {
				cout << "1: Ma tran A" << endl;
				cout << "2: Ma tran B" << endl;
				cout << "3: Ma tran C" << endl;
				cout << "4: Ma tran Ans" << endl;
				cin >> index;//Nhận lệnh từ người dùng
				
				if (index >= 1 && index <= 3) {//Tránh việc index nằm ngoài lựa chọn được cho phép
					cout << "Hang cua ma tran: " << matArr[index - 1].Rank() << endl;
					//Tìm hạng ma trận
				}

				index = 5;
			}
		} while (index != 0);//Tiếp tục chương trình nếu lệnh khác 0
	}
}
