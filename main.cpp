#include <iostream>
#include <vector>
#include <deque>

using namespace std;
int main() {
    // 1. Об'єднання двох відсортованих контейнерів у один відсортований масив
    vector<int> container1 = {1, 3, 5, 7, 9};
    vector<int> container2 = {2, 4, 6, 8, 10};
    vector<int> mergedContainer;

    auto it1 = container1.begin();
    auto it2 = container2.begin();

    while (it1 != container1.end() && it2 != container2.end()) {
        if (*it1 < *it2) {
            mergedContainer.push_back(*it1);
            ++it1;
        } else {
            mergedContainer.push_back(*it2);
            ++it2;
        }
    }

    // Додамо залишок з першого контейнера, якщо він існує
    while (it1 != container1.end()) {
        mergedContainer.push_back(*it1);
        ++it1;
    }

    // Додамо залишок з другого контейнера, якщо він існує
    while (it2 != container2.end()) {
        mergedContainer.push_back(*it2);
        ++it2;
    }

    // Виведемо результат об'єднання
    cout << "Merged and sorted array: ";
    for (int num : mergedContainer) {
        cout << num << " ";
    }
    cout << endl;

    // 2. Розділення масиву на парні та непарні числа
    vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> evenNumbers;
    vector<int> oddNumbers;

    for (int num : array) {
        if (num % 2 == 0) {
            evenNumbers.push_back(num);
        } else {
            oddNumbers.push_back(num);
        }
    }

    // Виведемо результат розділення
    cout << "Even numbers: ";
    for (int num : evenNumbers) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Odd numbers: ";
    for (int num : oddNumbers) {
        cout << num << " ";
    }
    cout << endl;

   /* // 3. Перевірка чи Dequeue читається однаково вперед і назад
    deque<int> dq = {1, 2, 3, 4, 5};

    // Перевірка вперед
    cout << "Forward traversal: ";
    for (auto it = dq.begin(); it != dq.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Перевірка назад
    cout << "Hello  World: ";
    for (auto rit = dq.rbegin(); rit != dq.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;

    // Перевірка на ідентичність впередніх та зворотних ітераторів
    bool isPalindrome = true;
    auto it = dq.begin();
    auto rit = dq.rbegin();
    while (it != dq.end() && rit != dq.rend()) {
        if (*it != *rit) {
            isPalindrome = false;
            break;
        }
        ++it;
        ++rit;
    }

    if (isPalindrome) {
        cout << "Deque reads the same forwards and backwards." << endl;
    } else {
        cout << "Deque does not read the same forwards and backwards." << endl;
    }

    return 0;
}

