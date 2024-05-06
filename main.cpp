#include <iostream>
#include <list>
#include <stdexcept>
#include <memory>

using namespace std;

int main() {
    unique_ptr<list<int>> myList = make_unique<list<int>>(initializer_list<int>{1, 11});

    cout << "List:" << endl;
    for (auto i = myList->begin(); i != myList->end(); i++) {
        cout << *i << endl;
    }

    if (find(myList->begin(), myList->end(), 0) != myList->end()) {
        throw runtime_error("Error: List contains element 0.");
    }

   /* cout << "Push Front:" << endl;
    myList->push_front(10);
    myList->push_front(20);

    for (auto i = myList->begin(); i != myList->end(); i++) {
        cout << *i << endl;
    }

    myList->push_back(5);
    myList->push_back(23);

    cout << "Push Back:" << endl;
    for (auto i = myList->begin(); i != myList->end(); i++) {
        cout << *i << endl;
    }

    myList->pop_front();
    myList->pop_front();

    cout << "Pop Front:" << endl;
    for (auto i = myList->begin(); i != myList->end(); i++) {
        cout << *i << endl;
    }

    myList->pop_back();

    cout << "Pop Back:" << endl;
    for (auto i = myList->begin(); i != myList->end(); i++) {
        cout << *i << endl;
    }

    auto it = myList->begin();
    myList->insert(it, 34);

    cout << "Insert:" << endl;
    for (auto i = myList->begin(); i != myList->end(); i++) {
        cout << *i << endl;
    }

    auto it1 = myList->begin();
    it1++;

    myList->erase(it1);

    cout << "Erase:" << endl;
    for (auto i = myList->begin(); i != myList->end(); i++) {
        cout << *i << endl;
    }

    cout << "Size:" << endl;
    cout << myList->size() << endl;

    myList->clear();

    return 0;
}


