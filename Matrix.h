#ifndef _Matrix_H
#define _Matrix_H
#include<iostream>
#include<vector>
using namespace std;
struct Matrix {
	vector<vector<float>>data;
	float m, n;
};
void nhap(vector<vector<float>>& data, int& m, int& n);
void xuat(vector<vector<float>> data, int m, int n);
//float dinhthuc(vector<vector<float>>data, int m, int n);
void CoFactor(vector<vector<float>>a, vector<vector<float>>temp, int p, int q, int n);
float Determinant(vector<vector<float>>a, int n);
#endif
