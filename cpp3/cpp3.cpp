#include <iostream>
#include <string.h>
#include <cstddef>
#include "Queue.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    // Пример использования очереди с типом int:

    Queue<int> q_int;
    
    q_int.push(1);
    q_int.push(2);
    q_int.push(3);
    cout << "Первый элемент: " << q_int.front() << endl;
    cout << "Последний элемент: " << q_int.back() << endl;
    cout << "Размер: " << q_int.size() << endl;
    q_int.pop();
    cout << "Новый первый элемент: " << q_int.front() << endl;
    cout << "Размер: " << q_int.size() << endl;

    cout << endl;
    // Пример использования очереди с типом string:

    Queue<string> q_string;
    q_string.push("Hello");
    q_string.push("World");
    q_string.push("!");
    cout << "Первый элемент: " << q_string.front() << endl;
    cout << "Последний элемент: " << q_string.back() << endl;
    cout << "Размер: " << q_string.size() << endl;
    q_string.pop();
    cout << "Новый первый элемент: " << q_string.front() << endl;
    cout << "Размер: " << q_string.size() << endl;

    getchar();
}