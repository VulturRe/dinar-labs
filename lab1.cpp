#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*
 * Функция для проверки скобок.
 * Если при проходу по строке мы натыкаемся на открывающую скобку, то
 * добавляем её в стек открывающих скобок. Если мы натыкаемся на закрывающую
 * скобку, то пытаемся удалить из стека последнюю открывающую скобку.
 * Пытаемся потому, что стек может оказаться пустым, и если такое произойдёт,
 * то возвращаем false. Если же стек не пустой, то берём последнюю
 * открывающую скобку из стека, и проверяем является ли она парой для текущей
 * закрывающей скобки. Если нет, то возвращаем false.
 */
bool check(string str) {
    stack<char> buffer;

    /*
     * Цикл for (auto s : str) - это по сути foreach. Т.е. цикл проходится по
     * всем элементам стека, помещая текущий в переменную s.
     */
    for (auto s : str) {
        /*
         * Если наткнулись на добавляющую скобку
         */
        if (s == '(' || s == '[' || s == '{')
            buffer.push(s); // Добавляем её в стек

        /*
         * Если наткнулись на закрывающую скобку, но в стеке открывающих
         * скобок нет ни одного элемента, то возвращаем false.
         */
        if ((s == ')' || s == ']' || s == '}') && !buffer.size())
            return false;

        if (s == ')') {
            if (buffer.top() != '(')
                return false;
            buffer.pop(); // Удаляем последний элемент из стека
        }

        if (s == ']') {
            if (buffer.top() != '[')
                return false;
            buffer.pop();
        }

        if (s == '}') {
            if (buffer.top() != '}')
                return false;
            buffer.pop();
        }
    }

    return true;
}

int main() {
    setlocale(LC_ALL, "rus");

    string str;
    cout << "Введите строку.\n";
    cin >> str;
    check(str) ? cout << "\nСтрока составлена правильно.\n" :
        cerr << "\nНепарная закрывающая скобка.\n";

    return 0;
}