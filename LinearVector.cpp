#include "LinearVector.h"
void TaoVector(vector<float> &data, int n) { //Hàm tạo vector với n phần tử
	data.resize(n);//Mở rộng vector chứa n phần tử
	for (int i = 0; i < data.size(); i++) {
		cin >> data[i];//Nhập giá trị cho vector
	}
}
void XuatVector(vector<float>& data)//In vector ra màn hình
{
	cout << "v = < ";//Mở ngoặc của vector
	for (int i = 0; i < data.size(); i++) {
		cout << data[i] << " ";//In từng phần tử
	}
	cout << ">" << endl;//Đóng ngoặc vector
}
void CongVector(vector<float>& data1, vector<float>& data2) {//Cộng 2 vector
	vector<float>kq; //Vector tổng
	kq.resize(data1.size());//Mở rộng vector tổng theo kích thước 2 vector ban đầu 
	if (data1.size() != data2.size()) {
		cout << "Khong du so phan tu cua vector co the cong" << endl;//Báo lỗi nếu 2 vector sai kích thước
	}
	else {
		for (int i = 0; i < data1.size(); i++) {
			kq[i] = data1[i] + data2[i];//Cộng từng phần tử của 2 vector
		}
	}

	cout << "Vector tong: ";
	XuatVector(kq);//Xuất vector tổng ra màn hình
}
void NhanVector(vector<float>& data) {//Nhân vector với số alpha
	float n; //Biến chứa số alpha
	cout << "Nhap vao 1 so alpha" << endl;
	cin >> n;//Nhập vào số alpha
	vector<float> kq;//Vector kết quả
	kq.resize(data.size());
	cout << "w = < ";
	for (int i = 0; i < data.size(); i++) {
		kq[i] = data[i] * n;//Nhân từng phần tử với số alpha
		cout  << kq[i] << " ";//Xuất ra trực tiếp từng phần tử
	}
	cout << ">" << endl;
}
