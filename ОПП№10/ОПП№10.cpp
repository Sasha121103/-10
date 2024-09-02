/*Задание 1.
Создать программу, обрабатывающую исключения при работе
с вещественными числами с использованием инструкции try,catch, throw.
Проект – консольное приложение.
В задании надо рассчитывать массив f [ x ] = 1 / (x – N) при x =0…k.
Варианты заданий.
N – последняя цифра номера паспорта плюс 5.
Необходимо отслеживать два исключения:
Деление на 0.
Выход за пределы диапазона.
При работе с программой менять k, чтобы получать разные
условия возможного возникновения исключений.
Пример.

Вариант задания: f[x] = 1 / (x-5). N=10*/

#include <iostream>
//
//// Исключение для деления на ноль
//class DivisionByZeroException {
//public:
//    const char* what() const {
//        return "Ошибка: Деление на ноль";
//    }
//};
//
//// Исключение для выхода за пределы диапазона
//class OutOfRangeException {
//public:
//    const char* what() const {
//        return "Ошибка: Индекс вышел за пределы допустимого диапазона";
//    }
//};
//
//int main() {
//    setlocale(LC_ALL, "RU");
//    try {
//        const int N = 10;
//        int k;
//
//        std::cout << "Введите значение k:";
//        std::cin >> k;
//        if (k < 0) {
//            throw OutOfRangeException();
//        }
//
//        // Массив для хранения значений функции
//        double* f = new double[k + 1];
//
//        // Заполнение массива значениями
//        for (int x = 0; x <= k; ++x) {
//            if (x == N) {
//                throw DivisionByZeroException();
//            }
//            f[x] = 1.0 / (x - N);
//        }
//
//        // Вывод значений массива
//        std::cout << "Вычисленные значения:" << std::endl;
//        for (int x = 0; x <= k; ++x) {
//            std::cout << "f[" << x << "] = " << f[x] << std::endl;
//        }
//
//        // Очистка выделенной памяти
//        delete[] f;
//
//    }
//    catch (const DivisionByZeroException& e) {
//        std::cout << e.what() << std::endl;
//    }
//    catch (const OutOfRangeException& e) {
//        std::cout << e.what() << std::endl;
//    }
//    catch (...) {
//        std::cout << "Произошло неожиданное исключение" << std::endl;
//    }
//
//    return 0;
//}


/*Задание 2.

1) Деление на ноль
2) Ввод числа вместо буквы
3) Выход за границы массива(матрицы). Матрица 2х2, мы, к примеру, перемножаем элементы (3;3)
4) Неверный тип входных параметров(вместо Int пишем double)
*/

// Исключение для деления на ноль
class DivisionByZeroException {
public:
    const char* what() const {
        return "Ошибка: Деление на ноль";
    }
};

// Исключение для выхода за границы массива (матрицы)
class OutOfBoundsException {
public:
    const char* what() const {
        return "Ошибка: Выход за пределы массива";
    }
};

// Исключение для неверного типа входных данных
class InvalidInputException {
public:
    const char* what() const {
        return "Ошибка: Неверный тип входных данных";
    }
};

// Исключение для ввода числа вместо буквы
class InputIsNumberException {
public:
    const char* what() const {
        return "Ошибка: Введено число вместо буквы";
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    try {
        // 1) Деление на ноль
        int a = 10;
        int b;
        std::cout << "Введите целое число для деления: ";
        std::cin >> b;

        if (b == 0) {
            throw DivisionByZeroException();
        }
        std::cout << "Результат деления: " << a / b << std::endl;

        // 2) Ввод числа вместо буквы
        char letter;
        std::cout << "Введите букву: ";
        std::cin >> letter;

        if (isdigit(letter)) { // Проверка, является ли введенный символ цифрой
            throw InputIsNumberException();
        }
        std::cout << "Вы ввели букву: " << letter << std::endl;

        // 3) Выход за границы массива (матрицы)
        const int SIZE = 5;  // Размер матрицы 5x5
        int matrix[SIZE][SIZE] = {
            {1, 2, 3, 4, 5},
            {6, 7, 8, 9, 10},
            {11, 12, 13, 14, 15},
            {16, 17, 18, 19, 20},
            {21, 22, 23, 24, 25}
        };

        int row, col;
        std::cout << "Введите строку и столбец для доступа (0-4): ";
        std::cin >> row >> col;

        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
            throw OutOfBoundsException();
        }
        std::cout << "Элемент матрицы [" << row << "][" << col << "] = " << matrix[row][col] << std::endl;

        // 4) Неверный тип входных параметров
        int integerInput;
        std::cout << "Введите целое число: ";
        std::cin >> integerInput;

        if (std::cin.fail()) {
            std::cin.clear(); // Сброс состояния ошибки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка ввода
            throw InvalidInputException();
        }
        std::cout << "Вы ввели целое число: " << integerInput << std::endl;

    }
    catch (const DivisionByZeroException& e) {
        std::cout << e.what() << std::endl;
    }
    catch (const InputIsNumberException& e) {
        std::cout << e.what() << std::endl;
    }
    catch (const OutOfBoundsException& e) {
        std::cout << e.what() << std::endl;
    }
    catch (const InvalidInputException& e) {
        std::cout << e.what() << std::endl;
    }
    catch (...) {
        std::cout << "Произошло неизвестное исключение" << std::endl;
    }

    return 0;
}
