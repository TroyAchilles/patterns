#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

class Origonator;

class Memento {
private:
    friend Origonator;

    int state;

    void SetState(int state) {
        this->state = state;
    }

    int GetState() {
        return state;
    }
};

class Origonator {
    int state;
public:
    void SetState(int state) {
        this->state = state;
    }

    int GetState() {
        return state;
    }

    std::shared_ptr<Memento> CreateMemento() {
        auto memento = std::make_shared<Memento>();
        memento->SetState(state);
        return memento;
    }

    void RestoreMemento(std::shared_ptr<Memento> memento) {
        state = memento->GetState();
    }
};

class Caretaker {
private:
    std::unordered_map<std::string, std::shared_ptr<Memento>> mementos;

public:
    std::shared_ptr<Memento> GetMemento(std::string const &name) {
        return mementos[name];
    }

    void SetMemento(std::string const &name, std::shared_ptr<Memento> memento) {
        mementos[name] = memento;
    }
};

int main() {
    auto origonator = std::make_shared<Origonator>();
    origonator->SetState(1111);
    std::cout << origonator->GetState() << std::endl;
    auto caretaker = std::make_shared<Caretaker>();
    caretaker->SetMemento("key", origonator->CreateMemento());
    origonator->SetState(100);
    std::cout << origonator->GetState() << std::endl;
    origonator->RestoreMemento(caretaker->GetMemento("key"));
    std::cout << origonator->GetState() << std::endl;
}
