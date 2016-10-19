#include <iostream>
#include <memory>

class Product {
public:
    void Init1() {
        std::cout << "init1" << std::endl;
    }
    void Init2() {
        std::cout << "init2" << std::endl;
    }
    void Init3() {
        std::cout << "init3" << std::endl;
    }
    void Operation() {
        std::cout << "do operation" << std::endl;
    }
};

class Builder {
public:
    virtual void BuildPartA() = 0;
    virtual void BuildPartB() = 0;
    virtual Product GetProduct() = 0;
};

class ConcreteBuilder : public Builder {
    Product product;
public:
    virtual void BuildPartA() override {
        product.Init1();
        product.Init3();
    }

    virtual void BuildPartB() override {
        product.Init2();
    }

    virtual Product GetProduct() override {
        return product;
    }
};

class Director {
    std::shared_ptr<Builder> builder = std::make_shared<ConcreteBuilder>();
public:
    Product ConstructA() {
        builder->BuildPartB();
        return builder->GetProduct();
    }

    Product ConstructB() {
        builder->BuildPartA();
        builder->BuildPartB();
        return builder->GetProduct();
    }
};

int main() {
    auto director = std::make_shared<Director>();
    auto producta = director->ConstructA();
    auto productb = director->ConstructB();
    producta.Operation();
    productb.Operation();
}
