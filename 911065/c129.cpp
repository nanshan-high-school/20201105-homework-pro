#include <iostream>
using namespace std;

int m,n;
int map[100][100];
void check(int i,int j) {
	if (i >= 0 && i < m && j >= 0 && j < n&& map[i][j] == 1) {
		map[i][j] = 2;
	} else {
		return;
	}

	check(i,j + 1);
	check(i,j - 1);
	check(i + 1,j);
	check(i - 1,j);
	check(i - 1,j - 1);
	check(i + 1,j - 1);
	check(i - 1,j + 1);
	check(i + 1,j + 1);
}

int main() {
	while (cin >> m >> n && m > 0 && n > 0) {
		for (int i = 0; i < m; i++) {
			string temp;
			cin >> temp;
			for (int j = 0; j < n; j++) {
				if (temp[j] == '*') {
					map[i][j] = 0;
				} else if (temp[j] == '@') {
					map[i][j] = 1;
				}
			}
		}
		int count = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 1) {
					check(i,j);
					count++;
				}
			}
		}
		// for (int i = 0; i < m; i++) {
		// 	for (int j = 0; j < n; j++) {
		// 		cout << map[i][j];
		// 	}
		// 	cout << "\n";
		// }
		cout << count << "\n";
	}
}