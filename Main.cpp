#include "LinearVector.h"
#include "Matrix.h"
#include "Inverse.h"
#include"MultiMatrix.h"
#include"Rank.h"
void main(){
	int n;
	cout << "***----Ho Tro Hoc Tap Toan Cao Cap----***" << endl;
	cout << "1: Tim cong thuc da thuc toi tieu cua ham Bool" << endl;
	cout << "2: Phep toan tren vector" << endl;
	cout << "3: Phep toan tren ma tran" << endl;
	do {
		cout << "Nhap vao so thu tu cua phep tinh toan" << endl;
		cin >> n;
	} while (n < 1 || n > 3);
	switch (n){
	case 1: {
		cout << "Tim cong thuc da thuc toi tieu" << endl;
		exit(0);
	}
	case 2: {
		int k;
		cout << "4: Cong 2 vector" << endl;
		cout << "5: Nhan vector voi 1 so" << endl;
		do {
			cout << "Nhap vao so thu tu de lua chon tinh toan voi vector" << endl;
			cin >> k;
		} while (k < 4 || k>5);
		switch (k) {
		case 4: {
			vector<double>data1;
			cout << "Cong 2 vector" << endl;
			cout << "Vector thu 1" << endl;
			TaoVector(data1);
			XuatVector(data1);
			cout << "Vector thu 2" << endl;
			vector<double>data2;
			TaoVector(data2);
			XuatVector(data2);
			CongVector(data1, data2);
			exit(0);
		}
		case 5: {
			cout << "Nhan vector voi 1 so" << endl;
			vector<double>data;
			cout << "Vector thu 1" << endl;
			TaoVector(data);
			XuatVector(data);
			NhanVector(data);
			exit(0);
		}
		}
	case 3: {
		int a;
		cout << "6: Dinh thuc cua ma tran" << endl;
		cout << "7: Nghich dao cua ma tran" << endl;
		cout << "8: Tich 2 ma tran" << endl;
		cout << "9: Hang cua ma tran" << endl;
		cout << "10: He phuong trinh tuyen tinh" << endl;
		do {
			cout << "Nhap vao so thu tu de lua chon tinh toan voi ma tran" << endl;
			cin >> a;
		} while (a < 6 || a>10);
		switch (a) {
		case 6: {
			int m, n;
			cout << "6: Dinh thuc cua ma tran" << endl;
			vector<vector<double>>data;
			cout << "Nhap vao so dong cua ma tran" << endl;
			cin >> m;
			cout << "Nhap vao so cot cua ma tran" << endl;
			cin >> n;
			while (m != n) {
				cout << "Nhap lai m" << endl;
				cin >> m;
				cout << "Nhap lai n" << endl;
				cin >> n;
			}
			nhap(data, m, n);
			xuat(data, m, n);
			cout << "Dinh thuc cua ma tran bang: " << Determinant(data, n) << endl;
			exit(0);
		}
		case 7: {
			cout << "7: Nghich dao cua ma tran" << endl;
			int m, n;
			int b[M][M];
			cout << "Nhap vao so dong cua ma tran" << endl;
			cin >> m;
			cout << "Nhap vao so cot cua ma tran" << endl;
			cin >> n;
			while (m != n) {
				cout << "Nhap lai m" << endl;
				cin >> m;
				cout << "Nhap lai n" << endl;
				cin >> n;
			}
			int adj[M][M];  // To store adjoint of A[][] 
			float inv[M][M]; // To store inverse of A[][]
			nhap1(b, m, n);
			adjoint(b, adj);
			xuat1(b, m, n);
			cout << "The Inverse is : " << endl;
			if (inverse(b, inv))
				xuat1(b, m, n);
			exit(0);
		}
			  case 8: {
				  cout << "8: Tich 2 ma tran" << endl;
				  int data1[100], data2[100];
				  int m1, n1,m2, n2;
				  cout << "Nhap vao so dong cua ma tran" << endl;
				  cin >> m1;
				  cout << "Nhap vao so cot cua ma tran" << endl;
				  cin >> n1;
				  nhap(data1, m1, n1);
				  xuat(data1, m1, n1);
				  cout << "Nhap vao so dong cua ma tran" << endl;
				  cin >> m2;
				  cout << "Nhap vao so cot cua ma tran" << endl;
				  cin >> n2;
				  nhap(data2, m2, n2);
				  xuat(data2, m2, n2);
				  multiply(m1, n1, data1, m2, n2, data2);
				  exit(0);
			  }
			  case 9: {
				  cout << "9: Hang cua ma tran" << endl;
				  int a[100];
				  int m, n;
				  cout << "So dong cua ma tran" << endl;
				  cout << "So cot cua ma tran" << endl;
				  nhap(a, m, n);
				  exit(0);
			  }
		case 10: {
			cout << "10: He phuong trinh tuyen tinh" << endl;
			exit(0);
		}
		default: {
			exit(0);
		}
		}
	}
	}
	}
}