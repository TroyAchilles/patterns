#include <iostream>
#include <cassert>

template <typename T>
class Singleton1 {
public:
    static T & getInstance() {
        static T instance;
        return instance;
    }
};

template <typename T>
class Singleton2 {
    static T t;

public:
    static T & getInstance() {
        return t;
    }
};

template <typename T>
T Singleton2<T>::t;

int main() {
    auto& s11 = Singleton1<int>::getInstance();
    auto& s12 = Singleton1<int>::getInstance();
    assert(&s11 == &s12);

    auto &s21 = Singleton2<int>::getInstance();
    auto &s22 = Singleton2<int>::getInstance();
    assert(&s21 == &s22);
}
