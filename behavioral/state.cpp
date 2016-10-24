#include <iostream>
#include <memory>
#include <unordered_map>
#include <string>

class State;

class Context : public std::enable_shared_from_this<Context> {
public:
    std::shared_ptr<State> state;
    std::unordered_map<std::string, std::shared_ptr<State>> states;
public:
    void Init();

    void DoAction();

    std::shared_ptr<State> GetState(std::string const &name) {
        return states[name];
    }

    void ChangeState(std::shared_ptr<State> state) {
        this->state = state;
    }

    bool Done() {
        return state == nullptr;
    }
};


class State {
protected:
    std::shared_ptr<Context> ctx;

public:
    State(std::shared_ptr<Context> ctx) {
        this->ctx = ctx;
    }

    virtual void DoAction() = 0;
};

class State1 : public State {
public:
    State1(std::shared_ptr<Context> ctx)
        : State(ctx)
    {}

    virtual void DoAction() override {
        std::cout << "State1 - State2" << std::endl;
        ctx->ChangeState(ctx->GetState("State2"));
    }
};

class State2 : public State {
public:
    State2(std::shared_ptr<Context> ctx)
        : State(ctx)
    {}
    virtual void DoAction() override {
        std::cout << "State2 - State3" << std::endl;
        ctx->ChangeState(ctx->GetState("State3"));
    }
};

class State3 : public State {
public:
    State3(std::shared_ptr<Context> ctx)
        : State(ctx)
    {}

    virtual void DoAction() override {
        std::cout << "State3 - done" << std::endl;
        ctx->ChangeState(nullptr);
    }
};

void Context::Init() {
    states.insert(std::make_pair("State1", std::make_shared<State1>(shared_from_this())));
    states.insert(std::make_pair("State2", std::make_shared<State2>(shared_from_this())));
    states.insert(std::make_pair("State3", std::make_shared<State3>(shared_from_this())));
}

void Context::DoAction() {
    state->DoAction();
}

int main() {
    auto context = std::make_shared<Context>();
    context->Init();
    context->ChangeState(context->GetState("State1"));
    while (!context->Done()) {
        context->DoAction();
    }
}
