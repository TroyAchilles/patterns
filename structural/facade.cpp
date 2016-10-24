#include <iostream>
#include <memory>

class SubsystemA {
public:
    void OperationA() {
        std::cout << "OperationA" << std::endl;
    }
};

class SubsystemB {
public:
    void OperationB() {
        std::cout << "OperationB" << std::endl;
    }
};

class Facade {
private:
    std::shared_ptr<SubsystemA> suba;
    std::shared_ptr<SubsystemB> subb;
public:
    Facade(std::shared_ptr<SubsystemA> suba, std::shared_ptr<SubsystemB> subb) {
        this->suba = suba;
        this->subb = subb;
    }

    void Operation() {
        suba->OperationA();
        subb->OperationB();
    }
};

int main() {
    auto suba = std::make_shared<SubsystemA>();
    auto subb = std::make_shared<SubsystemB>();
    auto facade = std::make_shared<Facade>(suba, subb);
    facade->Operation();
}
