#include <iostream>
#include <memory>

class Strategy {
public:
    virtual void Algorithm() = 0;
};

class Context {
private:
    std::shared_ptr<Strategy> strategy;
public:
    void SetStrategy(std::shared_ptr<Strategy> strategy) {
        this->strategy = strategy;
    }

    void DoAction() {
        std::cout << "DoAction" << std::endl;
        strategy->Algorithm();
    }
};

class ConcreteStrategy : public Strategy{
public:
    virtual void Algorithm() override {
        std::cout << "Algorithm" << std::endl;
    }
};

int main() {
    auto ctx = std::make_shared<Context>();
    ctx->SetStrategy(std::make_shared<ConcreteStrategy>());
    ctx->DoAction();
}
