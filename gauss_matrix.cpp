#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int n;

    cout << "====================================\n";
    cout << "     МЕТОД ГАУССА - КАЛЬКУЛЯТОР\n";
    cout << "====================================\n";

    cout << "Введите количество неизвестных: ";
    cin >> n;

    double a[10][11];

    cout << "\nВведите коэффициенты матрицы:\n";
    cout << "Для каждой строки введите коэффициенты и свободный член.\n\n";

    for (int i = 0; i < n; i++) {
        cout << "Строка " << i + 1 << ": ";

        for (int j = 0; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    // Прямой ход метода Гаусса
    for (int i = 0; i < n; i++) {

        // Поиск главного элемента
        int maxRow = i;

        for (int k = i + 1; k < n; k++) {
            if (abs(a[k][i]) > abs(a[maxRow][i])) {
                maxRow = k;
            }
        }

        // Меняем строки местами
        for (int j = 0; j <= n; j++) {
            swap(a[i][j], a[maxRow][j]);
        }

        // Проверка на нулевой главный элемент
        if (abs(a[i][i]) < 1e-9) {
            cout << "\nСистема не имеет единственного решения.\n";
            return 0;
        }

        // Обнуляем элементы ниже главного
        for (int k = i + 1; k < n; k++) {
            double coefficient = a[k][i] / a[i][i];

            for (int j = i; j <= n; j++) {
                a[k][j] -= coefficient * a[i][j];
            }
        }
    }

    // Обратный ход
    double x[10];

    for (int i = n - 1; i >= 0; i--) {
        x[i] = a[i][n];

        for (int j = i + 1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }

        x[i] /= a[i][i];
    }

    cout << "\n====================================\n";
    cout << "             РЕШЕНИЕ\n";
    cout << "====================================\n";

    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = "
             << fixed << setprecision(3) << x[i] << endl;
    }

    cout << "====================================\n";

    return 0;
}
