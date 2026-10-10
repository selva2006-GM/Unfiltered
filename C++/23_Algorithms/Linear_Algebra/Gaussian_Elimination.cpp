
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

const double EPS = 1e-10;

void operation(const vector<double>& a,
               vector<double>& b,
               int column) {
    double pivot = a[column];
    double value = b[column];

    if (abs(pivot) < EPS) {
        return;
    }

    double factor = value / pivot;

    for (int i = column; i < (int)a.size(); i++) {
        b[i] -= factor * a[i];
    }

    if (abs(b[column]) < EPS) {
        b[column] = 0.0;
    }
}

void Gaussian_Elimination(vector<vector<double>>& matrix) {
    int rows = matrix.size();

    if (rows == 0) return;

    int totalColumns = matrix[0].size();
    int pivotRow = 0;

    for (int column = 0;
         column < totalColumns - 1 && pivotRow < rows;
         column++) {

        int best = pivotRow;

        for (int r = pivotRow + 1; r < rows; r++) {
            if (abs(matrix[r][column]) >
                abs(matrix[best][column])) {
                best = r;
            }
        }

        if (abs(matrix[best][column]) < EPS) {
            continue;
        }

        swap(matrix[pivotRow], matrix[best]);

        for (int r = pivotRow + 1; r < rows; r++) {
            operation(matrix[pivotRow], matrix[r], column);
        }

        pivotRow++;
    }
}

void printMatrix(const vector<vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (int j = 0; j < (int)row.size(); j++) {
            if (j == (int)row.size() - 1) {
                cout << "| ";
            }

            cout << setw(9) << setprecision(5)
                 << defaultfloat << row[j] << " ";
        }
        cout << '\n';
    }
}


vector<double> Back_Substitution(
    const vector<vector<double>>& matrix
) {
    int rows = matrix.size();
    int totalColumns = matrix[0].size();
    int variables = totalColumns - 1;

    vector<double> solution(variables, 0.0);

    for (int i = rows - 1; i >= 0; i--) {
        // Find the first nonzero coefficient in this row
        int pivot = -1;

        for (int j = 0; j < variables; j++) {
            if (abs(matrix[i][j]) > 1e-10) {
                pivot = j;
                break;
            }
        }

        if (pivot == -1) {
            if (abs(matrix[i][variables]) > 1e-10) {
                cout << "No solution exists.\n";
                return {};
            }
            continue;
        }

        double value = matrix[i][variables];

        for (int j = pivot + 1; j < variables; j++) {
            value -= matrix[i][j] * solution[j];
        }

        solution[pivot] = value / matrix[i][pivot];
    }

    return solution;
}




int main() {
    vector<vector<double>> matrix = {
        { 2,  1, -1,   8},
        {-3, -1,  2, -11},
        {-2,  1,  2,  -3}
    };

    cout << "Original Augmented Matrix:\n";
    printMatrix(matrix);

    Gaussian_Elimination(matrix);

    cout << "\nRow Echelon Form:\n";
    printMatrix(matrix);

    vector<double> solution = Back_Substitution(matrix);

    if (!solution.empty()) {
        cout << "\nSolution:\n";

        for (int i = 0; i < solution.size(); i++) {
            cout << char('x' + i) << " = "
                << solution[i] << '\n';
        }
    }

    return 0;
}
