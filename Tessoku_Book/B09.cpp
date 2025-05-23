#include <iostream>
using namespace std;

int N, maxX, maxY, answer;
int A[100009], B[100009], C[100009], D[100009];
int X[1509][1509];

int main(){
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];

	for (int i = 1; i <= N; i++){
		X[A[i]+1][B[i]+1] += 1;
		X[A[i]+1][D[i]+1] -= 1;
		X[C[i]+1][B[i]+1] -= 1;
		X[C[i]+1][D[i]+1] += 1;
		if (maxX < C[i]) maxX = C[i];
		if (maxY < D[i]) maxY = D[i];
	}

	for (int i = 1; i <= maxX; i++){
		for (int j = 1; j <= maxY; j++) X[i][j] += X[i][j - 1];
	}
	for (int i = 1; i <= maxX; i++){
		for (int j = 1; j <= maxY; j++) X[i][j] += X[i - 1][j];
	}
	for (int i = 1; i <= maxX; i++){
		for (int j = 1; j <= maxY; j++) if(X[i][j] >= 1) answer += 1;
	}
	cout << answer << endl;
	return 0;
}
