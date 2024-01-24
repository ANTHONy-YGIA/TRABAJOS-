#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int secuencia[n];
    for (int i = 0; i < n; ++i) {
        cin >> secuencia[i];
    }

    int k;
    cin >> k;

    for (int i = 0; i < n; ++i) {
        if (secuencia[i] % k != 0) {
            secuencia[i] = -1;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (secuencia[i] == -1) {
            cout << "X ";
        } else {
            cout << secuencia[i] << " ";
        }
    }

    return 0;
}
