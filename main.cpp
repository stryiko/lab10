#include <iostream>
#include <cmath>

using namespace std;

// ==========================================
// ЗАВДАННЯ 1: Param66
// ==========================================
struct TPoint {
    double x, y;
};

struct TTriangle {
    TPoint A, B, C;
};

// Допоміжна функція для знаходження довжини сторони (відстані між точками)
double Length(TPoint p1, TPoint p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Функція Area(T) за умовою задачі Param66 (Формула Герона)
double Area(TTriangle T) {
    double a = Length(T.A, T.B);
    double b = Length(T.B, T.C);
    double c = Length(T.A, T.C);
    double p = (a + b + c) / 2.0; // напівпериметр
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

// Структура для збереження даних задачі (Пункт A)
struct Param66Task {
    TPoint A, B, C, D;                // Вхідні дані
    double areaABC, areaABD, areaACD; // Вихідні дані
};

// Функція заповнення даних (Пункт C)
void fill_param66(Param66Task* task) {
    cout << "\n--- Задача Param 66 ---\n";
    cout << "Введіть координати A (x y): "; cin >> task->A.x >> task->A.y;
    cout << "Введіть координати B (x y): "; cin >> task->B.x >> task->B.y;
    cout << "Введіть координати C (x y): "; cin >> task->C.x >> task->C.y;
    cout << "Введіть координати D (x y): "; cin >> task->D.x >> task->D.y;
}

// Функція обробки даних (Пункт B)
void process_param66(Param66Task* task) {
    TTriangle ABC = {task->A, task->B, task->C};
    TTriangle ABD = {task->A, task->B, task->D};
    TTriangle ACD = {task->A, task->C, task->D};

    task->areaABC = Area(ABC);
    task->areaABD = Area(ABD);
    task->areaACD = Area(ACD);
}


// ==========================================
// ЗАВДАННЯ 2: Begin37
// ==========================================
// Структура для збереження даних задачі (Пункт A)
struct Begin37Task {
    double V1, V2, S, T; // Вхідні дані: швидкості, початкова відстань, час
    double distance;     // Вихідні дані: кінцева відстань
};

// Функція заповнення даних (Пункт C)
void fill_begin37(Begin37Task* task) {
    cout << "\n--- Задача Begin 37 ---\n";
    cout << "Введіть швидкість 1-го авто V1 (км/год): "; cin >> task->V1;
    cout << "Введіть швидкість 2-го авто V2 (км/год): "; cin >> task->V2;
    cout << "Введіть початкову відстань між ними S (км): "; cin >> task->S;
    cout << "Введіть час руху T (год): "; cin >> task->T;
}

// Функція обробки даних (Пункт B)
void process_begin37(Begin37Task* task) {
    // Відстань = модуль(початкова відстань - (V1 + V2) * T)
    task->distance = abs(task->S - (task->V1 + task->V2) * task->T);
}


// ==========================================
// ЗАВДАННЯ 3: Boolean4
// ==========================================
// Структура для збереження даних задачі (Пункт A)
struct Boolean4Task {
    int A, B;    // Вхідні дані
    bool result; // Вихідні дані (істинність)
};

// Функція заповнення даних (Пункт C)
void fill_boolean4(Boolean4Task* task) {
    cout << "\n--- Задача Boolean 4 ---\n";
    cout << "Введіть ціле число A: "; cin >> task->A;
    cout << "Введіть ціле число B: "; cin >> task->B;
}

// Функція обробки даних (Пункт B)
void process_boolean4(Boolean4Task* task) {
    // Справедливі нерівності A > 2 і B <= 3
    task->result = (task->A > 2) && (task->B <= 3);
}


// ==========================================
// ГОЛОВНА ФУНКЦІЯ
// ==========================================
int main() {
    setlocale(LC_ALL, "Ukrainian");

    // --- Виклик Param 66 (Пункти D, E) ---
    Param66Task task1;
    fill_param66(&task1);
    process_param66(&task1);
    cout << "Площа трикутника ABC: " << task1.areaABC << endl;
    cout << "Площа трикутника ABD: " << task1.areaABD << endl;
    cout << "Площа трикутника ACD: " << task1.areaACD << endl;

    // --- Виклик Begin 37 (Пункти D, E) ---
    Begin37Task task2;
    fill_begin37(&task2);
    process_begin37(&task2);
    cout << "Відстань між автомобілями через " << task2.T << " год: " 
         << task2.distance << " км" << endl;

    // --- Виклик Boolean 4 (Пункти D, E) ---
    Boolean4Task task3;
    fill_boolean4(&task3);
    process_boolean4(&task3);
    cout << "Істинність висловлювання (A > 2 і B <= 3): " 
         << (task3.result ? "True (Істина)" : "False (Хиба)") << endl;

    return 0;
}