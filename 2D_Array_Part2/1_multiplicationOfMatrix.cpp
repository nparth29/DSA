#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Enter the row number of the first matrix: ";
    cin >> m;
    cout << "Enter the column number of the first matrix: ";
    cin >> n;

    int p, q;
    cout << "Enter the row number of the second matrix: ";
    cin >> p;
    cout << "Enter the column number of the second matrix: ";
    cin >> q;

    // Ensure matrices are compatible for multiplication
    if (n != p) {
        cout << "Matrix multiplication is not possible. The number of columns in the first matrix must equal the number of rows in the second matrix." << endl;
        return 0;
    }

    // Declare matrices
    int a[m][n], b[p][q], result[m][q] = {0};

    // Input for the first matrix
    cout << "Enter the elements of the first matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    // Input for the second matrix
    cout << "Enter the elements of the second matrix:" << endl;
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            cin >> b[i][j];
        }
    }

    // Matrix multiplication logic
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Output the resultant matrix
    cout << "Resultant matrix after multiplication:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
