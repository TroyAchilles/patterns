#include <iostream>
#include <memory>

class Subject {
public:
    virtual void Operation() = 0;
};

class RealSubject : public Subject {
public:
    virtual void Operation() override {
        std::cout << "Operation" << std::endl;
    }

    void OtherOperation() {
        std::cout << "OtherOperation" << std::endl;
    }
};

class Proxy : public Subject {
private:
    std::shared_ptr<RealSubject> subject = std::make_shared<RealSubject>();

public:
    virtual void Operation() override {
        subject->OtherOperation();
        subject->Operation();
    }
};

int main() {
    std::shared_ptr<Subject> subject = std::make_shared<Proxy>();
    subject->Operation();
}
