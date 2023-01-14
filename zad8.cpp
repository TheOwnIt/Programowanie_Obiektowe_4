#include <iostream>
#include <vector>

using namespace std;

// Klasa wyj¹tku, który jest rzucany, gdy stos jest pe³ny
class StackFullException : public exception {
public:
    const char* what() const noexcept override {
        return "Stos jest pe³ny";
    }
};

// Klasa wyj¹tku, który jest rzucany, gdy stos jest pusty
class StackEmptyException : public exception {
public:
    const char* what() const noexcept override {
        return "Stos jest pusty";
    }
};

// Klasa wyj¹tku, który jest rzucany, gdy podano niepoprawny argument
class IllegalArgumentException : public exception {
public:
    const char* what() const noexcept override {
        return "Niepoprawny argument";
    }
};

// Klasa stosu
class Stack {
private:
    vector<int> data; // wektor przechowuj¹cy dane
    int maxSize; // maksymalna liczba elementów w stosie

public:
    Stack(int maxSize) {
        if (maxSize < 0) {
            throw IllegalArgumentException();
        }
        this->maxSize = maxSize;
    }

    // Dodaje wartoœæ na stos
    void push(int value) {
        if (data.size() == maxSize) {
            throw StackFullException();
        }
        data.push_back(value);
    }

    // Usuwa i zwraca ostatni element ze stosu
    int pop() {
        if (data.empty()) {
            throw StackEmptyException();
        }
        int value = data.back();
        data.pop_back();
        return value;
    }

    // Czyœci stos
    void clear() {
        data.clear();
    }

    // Zwraca ostatni element na stosie
    int top() {
        if (data.empty()) {
            throw StackEmptyException();
        }
        return data.back();
    }

    // Zwraca liczbê elementów przechowywanych w stosie
    int size() {
        return data.size();
    }
};

int main() {
    try {
        Stack stack(5);
        stack.push(1);
        stack.push(2);
        stack.push(3);
        cout << stack.top() << endl; // Output: 3
        cout << stack.pop() << endl; // Output: 3
        cout << stack.size() << endl; // Output: 2
        stack.clear();
        cout << stack.size() << endl; // Output: 0
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}

