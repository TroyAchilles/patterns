#include <iostream>
#include <memory>

class Colleague;

class Mediator {
public:
    virtual void DoAction(std::shared_ptr<Colleague> c) = 0;
};

class Colleague {
protected:
    std::shared_ptr<Mediator> mediator;
public:
    Colleague(std::shared_ptr<Mediator> m)
        : mediator(m)
    {}

    virtual void Action() = 0;
};

class ConcreteColleagueA : public Colleague, public std::enable_shared_from_this<ConcreteColleagueA> {
public:
    using Colleague::Colleague;

    virtual void Action() override {
        mediator->DoAction(shared_from_this());
    }
};

class ConcreteColleagueB : public Colleague, public std::enable_shared_from_this<ConcreteColleagueB> {
public:
    using Colleague::Colleague;

    virtual void Action() override {
        mediator->DoAction(shared_from_this());
    }
};

class ConcreteMediator : public Mediator {
private:
    std::shared_ptr<ConcreteColleagueA> coa;
    std::shared_ptr<ConcreteColleagueB> cob;

public:
    void SetColleagueA(std::shared_ptr<ConcreteColleagueA> m) {
        coa = m;
    }

    void SetColleagueB(std::shared_ptr<ConcreteColleagueB> m) {
        cob = m;
    }

    virtual void DoAction(std::shared_ptr<Colleague> c) override {
        if (c == coa) {
            std::cout << "ColleagueA" << std::endl;
        }
        if (c == cob) {
            std::cout << "ColleagueB" << std::endl;
        }
    }
};

int main() {
    std::shared_ptr<ConcreteMediator> mediator = std::make_shared<ConcreteMediator>();

    auto a = std::make_shared<ConcreteColleagueA>(mediator);
    auto b = std::make_shared<ConcreteColleagueB>(mediator);

    mediator->SetColleagueA(a);
    mediator->SetColleagueB(b);

    a->Action();
    b->Action();
}
