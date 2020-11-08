#include <iostream>
using namespace std;

int m, n;
int g[100][100] = {0};
void search(int a, int b);

int main() {
    while (true) {
        cin >> m;
        cin >> n;
        if (m == 0 && n == 0) {
            break;
        }

        string now;
        for (int i = 0; i < m; i++) {
            cin >> now;
            for (int j = 0; j < n; j++) {
                if (now[j] == '@') {
                    g[i][j] = 1;
                }
            }
        }

        int total = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j] == 1) {
                    total++;
                    search(i, j);
                }                  
            }
        }

        cout << total << "\n";
    }
}

void search(int a, int b) {
    if (a >= 0 && a < m && b >= 0 && b < n && g[a][b] == 1) {
        g[a][b] = 0;
        search(a + 1, b);
        search(a, b + 1);
        search(a + 1, b + 1);
        search(a - 1, b);
        search(a, b - 1);
        search(a - 1, b - 1);
        search(a + 1, b - 1);
        search(a - 1, b + 1);
    } else {
        return;
    }
}
