#include "LinearVector.h"
void TaoVector(vector<float> &data, int n) {
	data.resize(n);
	for (int i = 0; i < data.size(); i++) {
		cin >> data[i];
	}
}
void XuatVector(vector<float>& data)
{
	cout << "v = < ";
	for (int i = 0; i < data.size(); i++) {
		cout << data[i] << " ";
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
		}
	}

	cout << "Vector tong: ";
	XuatVector(kq);
}
void NhanVector(vector<float>& data) {
	float n;
	cout << "Nhap vao 1 so alpha" << endl;
	cin >> n;
	vector<float> kq;
	kq.resize(data.size());
	cout << "w = < ";
	for (int i = 0; i < data.size(); i++) {
		kq[i] = data[i] * n;
		cout  << kq[i] << " ";
	}
	cout << ">" << endl;
}