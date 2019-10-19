#include "LinearVector.h"
void TaoVector(vector<float> &data) {
	int n;
	cout << "Nhap vao so phan tu cua vector " ;
	cin >> n;
	data.resize(n);
	for (int i = 0; i < data.size(); i++) {
		cin >> data[i];
	}
}
void XuatVector(vector<float>& data)
{
	cout << "Xuat vector" << endl;
	cout << "v = <";
	for (int i = 0; i < data.size(); i++) {
		cout << data[i] << ", ";
	}
	cout << ">" << endl;
}
void CongVector(vector<float>& data1, vector<float>& data2) {
	vector<float>kq;
	kq.resize(data1.size());
	if (data1.size() != data2.size()) {
		cout << "Khong du so phan tu cua vector co the cong" << endl;
	}
	else {
		for (int i = 0; i < data1.size(); i++) {
			kq[i] = data1[i] + data2[i];
			cout << "Vector tong thanh phan thu " << i + 1 << " = " << kq[i] << endl;
		}
	}
}
void NhanVector(vector<float>&data) {
	int n;
	cout << "Nhap vao 1 so alpha" << endl;
	cin >> n;
	vector<float>kq;
	kq.resize(data.size());
	for (int i = 0; i < data.size(); i++) {
		kq[i] = data[i] * n;
		cout << "Vector tich thanh phan thu " << i + 1 << " = " << kq[i] << endl;
	}
}