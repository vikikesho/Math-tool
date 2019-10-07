#ifndef _LinearVector_H
#define _LinearVector_H
#include<iostream>
#include<vector>
using namespace std;
struct LinearVector {
	vector<float> data;
};
void TaoVector(vector<float>& data);
void XuatVector(vector<float> &data);
void CongVector(vector<float>& data1, vector<float>&data2);
void NhanVector(vector<float>& data);
#endif

