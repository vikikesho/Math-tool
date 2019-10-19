#pragma once
#include<iostream>
using namespace std;
#include<vector>
#define M 10
void nhap1(int A[M][M], int& m, int& n);
void xuat1(int A[M][M], int m, int n);
void getCofactor(int A[M][M], int temp[M][M], int p, int q, int n);
int determinant(int A[M][M], int n);
void adjoint(int A[M][M], int adj[M][M]);
bool inverse(int A[M][M], float inverse[M][M]);
