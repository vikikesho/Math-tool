#include "LinearVector.h"
void TaoVector(vector<float> &data) {
	int n;
	cout << "Nhap vao so phan tu cua vector" << endl;
	cin >> n;
	data.resize(n);
	for (int i = 0; i < data.size(); i++) {
		cin >> data[i];
	}
}
void XuatVector( vector<float> &data)
{
	cout << "Xuat vector" << endl;
	for (int i = 0; i < data.size(); i++) {
		cout << "Thanh phan "<<i+1<<" cua vector: "<< data[i] << endl;
	}
}
vector<float> CongVector(vector<float>& data1, vector<float>& data2) {
	vector<float>kq;
	if (data1.size() != data2.size()) {
		cout << "Khong du so phan tu cua vector co the cong" << endl;
	}
	else {
		for (int i = 0; i < data1.size(); i++) {
			kq[i] = data1[i] + data2[i];
			cout << "Vector tong thanh phan thu " << i + 1 << "la " << kq[i] << endl;
		}
	}
	return kq;
}
vector<float> NhanVector(vector<float>&data) {
	vector<float>kq;
	return kq;
}