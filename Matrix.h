#pragma once
#include<iostream>
using namespace std;
#include<vector>
void nhap(vector<vector<double>>&data, int &m, int &n);
void xuat(vector<vector<double>>data, int m, int n);
void CoFactor(vector<vector<double>>data, vector<vector<double>>temp, int p, int q, int n);
double Determinant(vector<vector<double>>data, int n);