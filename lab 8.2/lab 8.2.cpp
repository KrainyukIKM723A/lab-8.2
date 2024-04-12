#include <iostream> 

#include <cmath> 



using namespace std;



int main() {

    int n; // Кількість елементів масиву 

    double a[100]; // Масив дійсних чисел 

    double min_abs = 1e9; // Мінімальний за модулем елемент 

    double sum_after_zero = 0; // Сума модулів елементів після першого нуля 

    int min_index, max_index; // Індекси мінімального і максимального елементів 



    cout << "Введіть кількість елементів масиву: ";

    cin >> n;

    for (int i = 0; i < n; i++) {

        cout << "Введіть " << i + 1 << "-й елемент: ";

        cin >> a[i];

    }



    for (int i = 0; i < n; i++) {

        if (abs(a[i]) < min_abs) {

            min_abs = abs(a[i]);

        }

    }



    bool found_zero = false;

    for (int i = 0; i < n; i++) {

        if (a[i] == 0) {

            found_zero = true;

        }

        if (found_zero) {

            sum_after_zero += abs(a[i]);

        }

    }



    min_index = 0;

    max_index = 0;

    for (int i = 1; i < n; i++) {

        if (a[i] < a[min_index]) {

            min_index = i;

        }

        if (a[i] > a[max_index]) {

            max_index = i;

        }

    }



    double sum = 0;

    for (int i = min_index; i <= max_index; i++) {

        sum += a[i];

    }

    double avg = sum / (max_index - min_index + 1);



    cout << "Мінімальний за модулем елемент: " << min_abs << endl;

    cout << "Сума модулів елементів після першого нуля: " << sum_after_zero << endl;

    cout << "Середнє арифметичне елементів між " << min_index + 1 << " та " << max_index + 1 << " елементами: " << avg << endl;



    return 0;

}