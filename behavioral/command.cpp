#include <iostream>
#include <memory>

class Receiver {
public:
    void DoAction() {
        std::cout << "DoAction" << std::endl;
    }
};

class Command {
public:
    virtual void Excute() = 0;
};

class ConcreteCommand : public Command {
private:
    std::shared_ptr<Receiver> receiver = std::make_shared<Receiver>();
public:
    virtual void Excute() {
        receiver->DoAction();
    }
};

class Invoker {
private:
    std::shared_ptr<Command> some_command = std::make_shared<ConcreteCommand>();
public:
    void ExcuteSomeCommane() {
        some_command->Excute();
    }
};

int main() {
    auto invoker = std::make_shared<Invoker>();
    invoker->ExcuteSomeCommane();
}
