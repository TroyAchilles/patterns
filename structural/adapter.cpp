#include <iostream>
#include <memory>

class Target {
public:
    virtual void Operation() = 0;
};

class Adaptee {
public:
    void AnotherOperation() {
        std::cout << "AnotherOperation" << std::endl;
    }
};

class Adapter : public Target {
private:
    std::shared_ptr<Adaptee> playload;

public:
    void setAdaptee(std::shared_ptr<Adaptee> pl) {
        playload = pl;
    }

    virtual void Operation() override {
        std::cout << "Start adaption" << std::endl;
        playload->AnotherOperation();
    }
};

int main() {
    auto adaptee = std::make_shared<Adaptee>();
    auto adapter = std::make_shared<Adapter>();
    adapter->setAdaptee(adaptee);
    std::shared_ptr<Target> target = adapter;
    target->Operation();
}
