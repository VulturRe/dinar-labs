#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void merge_sort(int *&array, int start, int end) {

    if (end <= start)
        return;
    int mid = start + (end - start) / 2;
    merge_sort(array, start, mid);
    merge_sort(array, mid + 1, end);

    int *buf = new int[end + 1];

    for (int k = start; k <= end; k++)
        buf[k] = array[k];

    int i = start, j = mid + 1;
    for (int k = start; k <= end; k++) {

        if (i > mid) {
            array[k] = buf[j];
            j++;
        } else if (j > end) {
            array[k] = buf[i];
            i++;
        } else if (buf[j] < buf[i]) {
            array[k] = buf[j];
            j++;
        } else {
            array[k] = buf[i];
            i++;
        }
    }

    delete[] buf;
}

unsigned array_size(string filename) {
    ifstream fin("/home/ilshat/DeeR/Projects/ClionProjects/Dinar/" + filename);
    if (!fin) {
        cerr << "Can't open file!\n";
        return 0;
    }

    unsigned count = 0;
    int number;
    while (fin >> number) {
        count++;
    }
    fin.close();

    return count;
}

int* read_file(string filename, unsigned size) {
    cout << "Считывание из файла.\n";
    ifstream fin("/home/ilshat/DeeR/Projects/ClionProjects/Dinar/" + filename);
    if (!fin) {
        cerr << "Can't open file!\n";
        return nullptr;
    }

    int *array = new int[size];
    for (int i = 0; i < size; i++) {
        fin >> array[i];
    }
    fin.close();

    return array;
}

void write_to_file(string filename, int *array, unsigned size) {
    cout << "Запись в файл.\n";
    ofstream fout("/home/ilshat/DeeR/Projects/ClionProjects/Dinar/" + filename, ios_base::trunc);

    for (int i = 0; i < size; i++) {
        fout << array[i] << endl;
    }
    fout.close();
}

void print_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "rus");

    int size = array_size("lab3.txt");
    int *array = read_file("lab3.txt", size);
    cout << "\nСчитанный массив:\n";
    print_array(array, size);

    merge_sort(array, 0, size);
    cout << "\nОтсортированный массив:\n";
    print_array(array, size);

    cout << endl;
    write_to_file("lab3.txt", array, size);

    delete[] array;

    return 0;
}
