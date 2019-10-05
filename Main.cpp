#include<iostream>
using namespace std;
void main() {
	int n;
	cout << "***----Ho Tro Hoc Tap Toan Cao Cap----***"<<endl;
	cout << "1: Tim cong thuc da thuc toi tieu cua ham Bool" << endl;
	cout << "2: Phep toan tren vector" << endl;
	cout << "3: Phep toan tren ma tran" << endl;
	do {
		cout << "Nhap vao so thu tu cua phep tinh toan" << endl;
		cin >> n;
	} while (n < 1 && n>3);
	switch (n) {
	case 1:{
		cout << "Tim cong thuc da thuc toi tieu" << endl;
		break;
	}
	case 2: {
		int k;
		cout << "4: Cong 2 vector" << endl;
		cout << "5: Nhan vector voi 1 so" << endl;
		do {
			cout << "Nhap vao so thu tu de lua chon tinh toan voi vector" << endl;
			cin >> k;
		} while (k < 4 && k>5);
		switch (k) {
		case 4: {
			cout << "Cong 2 vector" << endl;
			break;
		}
		case 5: {
			cout << "Nhan vector voi 1 so" << endl;
			break;
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
		} while (a < 6 && a>10);
		switch (a) {
		case 6: {
			cout << "6: Dinh thuc cua ma tran" << endl;
			break;
		}
		case 7: {
			cout << "7: Nghich dao cua ma tran" << endl;
			break;
		}
		case 8: {
			cout << "8: Tich 2 ma tran" << endl;
			break;
		}
		case 9: {
			cout << "9: Hang cua ma tran" << endl;
			break;
		}
		case 10: {
			cout <<"10: He phuong trinh tuyen tinh" << endl;
			break;
		}
		}
	}
	}
	}
}