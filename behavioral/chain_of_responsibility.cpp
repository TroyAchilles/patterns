#include <iostream>
#include <memory>
#include <string>

class Handler {
protected:
    std::shared_ptr<Handler> handler;

public:
    void SetSuccessor(std::shared_ptr<Handler> handler) {
        this->handler = handler;
    }

    virtual void Handle(std::string const &name) = 0;
};

class ConcreteHandlerA : public Handler {
public:
    virtual void Handle(std::string const &name) override {
        if (name == "A") {
            std::cout << "Handle A" << std::endl;
        } else if (handler) {
            handler->Handle(name);
        }
    }
};

class ConcreteHandlerB : public Handler {
public:
    virtual void Handle(std::string const &name) override {
        if (name == "B") {
            std::cout << "Handle B" << std::endl;
        } else if (handler) {
            handler->Handle(name);
        }
    }
};

int main() {
    std::shared_ptr<Handler> head = std::make_shared<ConcreteHandlerA>();
    head->SetSuccessor(std::make_shared<ConcreteHandlerB>());
    head->Handle("A");
    head->Handle("B");
}
