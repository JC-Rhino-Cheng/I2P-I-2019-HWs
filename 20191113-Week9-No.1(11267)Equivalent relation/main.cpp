#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#pragma warning (disable: 4996)
using namespace  std;

void AllLengths(const int n);


int main() {

	int n; cin >> n;
	AllLengths(n);

	system("pause");
}


void AllLengths(const int n) {
	int A[5][5];
	int pi[5][5];

	int inf = 100;

	//initialisation
	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++) {
		cin >> A[i][j];

		pi[i][j] = (A[i][j] == 100 ? -1 : (i == j ? -1 : i));

		A[i][j] = (A[i][j] == 100 ? INT_MAX : A[i][j]);
	}


	for (int k = 0; k < n; k++) {


		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (A[i][k] + A[k][j] < A[i][j] && A[i][k] != INT_MAX && A[k][j] != INT_MAX) {
					A[i][j] = A[i][k] + A[k][j];
					pi[i][j] = k;
				}
			}
		}

		//output this round
		cout << "D" << (k + 1) << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (A[i][j] == inf || A[i][j] == INT_MAX) cout << "inf\t";
				else cout << A[i][j] << "\t";
			}
			cout << endl;
		}
		cout << "Pi" << (k + 1) << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (pi[i][j] == -1) cout << "NIL\t";
				else cout << (pi[i][j] + 1) << "\t";
			}
			cout << endl ;
		}
		cout << endl << "-------------------------------------------" << endl << endl;

	}
}