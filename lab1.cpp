#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool check(string str) {
    stack<char> buffer;

    for (auto s : str) {
        if (s == '(' || s == '[' || s == '{')
            buffer.push(s);

        if ((s == ')' || s == ']' || s == '}') && !buffer.size())
            return false;

        if (s == ')' && buffer.size()) {
            if (buffer.top() != '(')
                return false;
            buffer.pop();
        }

        if (s == ']' && buffer.size()) {
            if (buffer.top() != '[')
                return false;
            buffer.pop();
        }

        if (s == '}' && buffer.size()) {
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