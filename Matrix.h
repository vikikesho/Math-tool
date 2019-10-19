#pragma once
#include<iostream>
using namespace std;
#include<vector>
#define N 10
void nhap(int a[N][N], int& m, int& n);
void xuat(int a[N][N], int m, int n);
void CoFactor(int a[N][N], int temp[N][N], int p, int q, int n);
float Determinant(int a[N][N], int n);