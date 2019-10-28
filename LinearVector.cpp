#include "LinearVector.h"
void TaoVector(vector<double> &data) {
	int n;
	cout << "Nhap vao so phan tu cua vector " ;
	cin >> n;
	data.resize(n);
	for (int i = 0; i < data.size(); i++) {
		cin >> data[i];
	}
}
void XuatVector(vector<double>& data)
{
	cout << "Xuat vector" << endl;
	cout << "v = <";
	for (int i = 0; i < data.size(); i++) {
		cout << data[i] << ", ";
	}
	cout << ">" << endl;
}
void CongVector(vector<double>& data1, vector<double>& data2) {
	vector<double>kq;
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
void NhanVector(vector<double>&data) {
	int n;
	cout << "Nhap vao 1 so alpha" << endl;
	cin >> n;
	vector<double>kq;
	kq.resize(data.size());
	cout << "v = <";
	for (int i = 0; i < data.size(); i++) {
		kq[i] = data[i] * n;
		cout  << kq[i] << ",";
	}
	cout << ">" << endl;
}