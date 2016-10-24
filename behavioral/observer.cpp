#include <iostream>
#include <memory>
#include <unordered_set>

class Observer {
public:
    virtual void Update() = 0;
};

class Subject {
private:
    std::unordered_set<std::shared_ptr<Observer>> observers;

public:
    void Attach(std::shared_ptr<Observer> observer) {
        observers.insert(observer);
    }

    void Detach(std::shared_ptr<Observer> observer) {
        observers.erase(observer);
    }

    void Notify() {
        for (auto &it : observers) {
            it->Update();
        }
    }
};

class ConcreteSubject : public Subject {};

class ConcreteObserver : public Observer, public std::enable_shared_from_this<ConcreteObserver> {
private:
    std::shared_ptr<Subject> subject;

public:
    void SetSubject(std::shared_ptr<Subject> sub) {
        if (subject != nullptr) {
            subject->Detach(shared_from_this());
        }
        subject = sub;
        subject->Attach(shared_from_this());
    }

    virtual void Update() override {
        std::cout << "ConcreteObserver" << std::endl;
    }
};

int main() {
    std::shared_ptr<Subject> subject = std::make_shared<ConcreteSubject>();
    auto observer = std::make_shared<ConcreteObserver>();
    observer->SetSubject(subject);
    subject->Notify();
}
