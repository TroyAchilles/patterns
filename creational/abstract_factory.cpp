#include <iostream>
#include <memory>

class AbstractProductA {
public:
    virtual void Opteration() = 0;
};

class ProductA1 : public AbstractProductA {
public:
    virtual void Opteration() override {
        std::cout << "ProductA1" << std::endl;
    }
};

class ProductA2 : public AbstractProductA {
public:
    virtual void Opteration() override {
        std::cout << "ProductA2" << std::endl;
    }
};

class AbstractProductB {
public:
    virtual void Opteration() = 0;
};

class ProductB1 : public AbstractProductB {
public:
    virtual void Opteration() override {
        std::cout << "ProductB1" << std::endl;
    }
};

class ProductB2 : public AbstractProductB {
public:
    virtual void Opteration() override {
        std::cout << "ProductB2" << std::endl;
    }
};


class AbstractFactory {
public:
    virtual std::shared_ptr<AbstractProductA> CreateProductA() = 0;
    virtual std::shared_ptr<AbstractProductB> CreateProductB() = 0;
};

class ConcreteFactoryA : public AbstractFactory {
public:
    virtual std::shared_ptr<AbstractProductA> CreateProductA() override {
        return std::shared_ptr<AbstractProductA>(new ProductA1);
    }

    virtual std::shared_ptr<AbstractProductB> CreateProductB() override {
        return std::shared_ptr<AbstractProductB>(new ProductB2);
    }
};

class ConcreteFactoryB : public AbstractFactory {
public:
    virtual std::shared_ptr<AbstractProductA> CreateProductA() override {
        return std::shared_ptr<AbstractProductA>(new ProductA2);
    }
    virtual std::shared_ptr<AbstractProductB> CreateProductB() override {
        return std::shared_ptr<AbstractProductB>(new ProductB1);
    }
};

int main() {
    auto factory1 = std::shared_ptr<AbstractFactory>(new ConcreteFactoryA);
    auto factory2 = std::shared_ptr<AbstractFactory>(new ConcreteFactoryB);
    factory1->CreateProductA()->Opteration();
    factory1->CreateProductB()->Opteration();
    factory2->CreateProductA()->Opteration();
    factory2->CreateProductB()->Opteration();
}
