#include <iostream>
#include <vector>
using namespace std;

unsigned keyUsageCount(vector<int> list, int key) {
    unsigned count = 0;
    for (auto v : list)
        if (v == key) count++;
    return count;
}

int main() {
    setlocale(LC_ALL, "rus");

    vector<int> list;
    unsigned count;
    int key;

    cout << "Введите количество элементов списка.\n";
    cin >> count;
    cout << "\nВведите элементы списка.\n";
    for (unsigned i = 0; i < count; i++) {
        int temp;
        cin >> temp;
        list.push_back(temp);
    }

    cout << "\nВведите ключ для поиска.\n";
    cin >> key;
    cout << "\nКоличество вхождений ключа в список = " <<
         keyUsageCount(list, key) << endl;

    return 0;
}