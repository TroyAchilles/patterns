#include <iostream>
#include <memory>

class Template {
private:
    virtual void primitiveA() = 0;
    virtual void primitiveB() = 0;
public:
    void TemplateMethod() {
        primitiveA();
        primitiveB();
    }
};

class ConcreteTempalteA : public Template {
public:
    virtual void primitiveA() override {
        std::cout << "TemplateA primitiveA" << std::endl;
    }

    virtual void primitiveB() override {
        std::cout << "TemplateA primitiveB" << std::endl;
    }
};

class ConcreteTempalteB : public Template {
public:
    virtual void primitiveA() override {
        std::cout << "TemplateB primitiveA" << std::endl;
    }

    virtual void primitiveB() override {
        std::cout << "TemplateB primitiveB" << std::endl;
    }
};

int main() {
    std::shared_ptr<Template> a = std::make_shared<ConcreteTempalteA>();
    std::shared_ptr<Template> b = std::make_shared<ConcreteTempalteB>();
    a->TemplateMethod();
    b->TemplateMethod();
}
