#include "Matrix.h"
#include "LinearVector.h"
#include "SubFunctions.h"
#include <iostream>
using namespace std;

void main(){
	int index;
	cout << "***----Ho Tro Hoc Tap Toan Cao Cap----***" << endl;
	cout << "1: Tim cong thuc da thuc toi tieu cua ham Bool" << endl;
	cout << "2: Phep toan tren vector" << endl;
	cout << "3: Phep toan tren ma tran" << endl;

	cout << "Nhap vao so thu tu cua phep tinh toan" << endl;
	cin >> index;
	
	//cout << "Tim cong thuc da thuc toi tieu" << endl;
	//exit(0);
	
	if (index == 2) {
		do {
			cout << "1: Cong 2 vector" << endl;
			cout << "2: Nhan vector voi 1 so" << endl;
			cout << "0: Thoat" << endl;
			cout << "Nhap vao so thu tu de lua chon tinh toan voi vector" << endl;
			cin >> index;

			int element;
			vector<float> data1;

			if (index == 1) {
				
				cout << "Cong 2 vector" << endl;
				cout << "So phan tu: ";
				cin >> element;
				cout << "Vector thu 1" << endl;
				TaoVector(data1, element);
				XuatVector(data1);
				cout << "Vector thu 2" << endl;
				vector<float> data2;
				TaoVector(data2, element);
				XuatVector(data2);
				CongVector(data1, data2);
			}
			if (index == 2) {
				cout << "Nhan vector voi 1 so" << endl;
				cout << "So phan tu: ";
				cin >> element;
				cout << "Vector" << endl;
				TaoVector(data1, element);
				XuatVector(data1);
				NhanVector(data1);
			}
		} while (index != 0);
	}
	
	if (index == 3) {
		vector<Matrix> matArr;
		matArr.resize(4);

		cout << "Ma tran A:" << endl;
		matArr[0].NhapMatrix();

		cout << "Ma tran B:" << endl;
		matArr[1].NhapMatrix();

		cout << "Ma tran C:" << endl;
		matArr[2].NhapMatrix();

		do {
			cout << "1: Xem va nhap lai ma tran" << endl;
			cout << "2: Dinh thuc cua ma tran" << endl;
			cout << "3: Nghich dao cua ma tran" << endl;
			cout << "4: Tich 2 ma tran" << endl;
			cout << "5: Hang cua ma tran" << endl;
			cout << "6: He phuong trinh tuyen tinh" << endl;
			cout << "0: Thoat" << endl;

			cout << "Nhap vao so thu tu de lua chon tinh toan voi ma tran" << endl;
			cin >> index;

			if (index == 1) {
				do {
					cout << "1: Ma tran A" << endl;
					cout << "2: Ma tran B" << endl;
					cout << "3: Ma tran C" << endl;
					cout << "0: Quay lai" << endl;
					cin >> index;

					if (index >= 1 && index <= 3) {
						matArr[index - 1].XuatMatrix();
						matArr[index - 1].NhapMatrix();
					}
				} while (index != 0);

				index = 1;
			}

			if (index == 2) {
				cout << "1: Ma tran A" << endl;
				cout << "2: Ma tran B" << endl;
				cout << "3: Ma tran C" << endl;
				cout << "4: Ma tran Ans" << endl;
				cin >> index;

				if (index >= 1 && index <= 3) {
					if (matArr[index - 1].IsSquare())
						cout << "Dinh thuc ma tran: " << matArr[index - 1].Determinant() << endl;
					else cout << "Ma tran khong vuong." << endl;
				}

				index = 2;
			}
			
			if (index == 3) {
				cout << "1: Ma tran A" << endl;
				cout << "2: Ma tran B" << endl;
				cout << "3: Ma tran C" << endl;
				cout << "4: Ma tran Ans" << endl;
				cin >> index;

				if (index >= 1 && index <= 3) {
					if (matArr[index - 1].IsSquare() && matArr[index-1].Determinant() != 0) {
						cout << "Ma tran nghich dao: " << endl;
						matArr[3] = matArr[index - 1].Inverse();
						matArr[3].XuatMatrix();
					}
					else cout << "Ma tran khong kha nghich." << endl;
				}

				index = 3;
			}

			if (index == 4) {
				cout << "1: Ma tran A" << endl;
				cout << "2: Ma tran B" << endl;
				cout << "3: Ma tran C" << endl;
				cout << "4: Ma tran Ans" << endl;
				cin >> index;
				
				int temp = 4;
				cout << "1: Ma tran A" << endl;
				cout << "2: Ma tran B" << endl;
				cout << "3: Ma tran C" << endl;
				cout << "4: Ma tran Ans" << endl;
				cin >> temp;

				if (index >= 1 && index <= 3) {
					if (matArr[index - 1].data[0].size() != matArr[temp - 1].data.size())
						cout << "2 ma tran khong thich hop" << endl;
					else {
						matArr[3] = matArr[index - 1].Multiply(matArr[temp - 1]);
						matArr[3].XuatMatrix();
					}
				}

				index = 4;
			}
			if (index == 5) {
				cout << "1: Ma tran A" << endl;
				cout << "2: Ma tran B" << endl;
				cout << "3: Ma tran C" << endl;
				cout << "4: Ma tran Ans" << endl;
				cin >> index;
				
				if (index >= 1 && index <= 3) {
					cout << "Hang cua ma tran: " << matArr[index - 1].Rank() << endl;
				}

				index = 5;
			}
			/*case 10: {
				cout << "10: He phuong trinh tuyen tinh" << endl;
				exit(0);
			}
			default: {
				exit(0);
			}
			}
		}*/
		} while (index != 0);
	}
}