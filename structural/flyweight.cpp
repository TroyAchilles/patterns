#include <iostream>
#include <memory>
#include <unordered_map>
#include <string>
#include <cassert>

class Flyweight {
public:
    virtual void Operation() = 0;
};

class ConcreteFlyweight : public Flyweight {
public:
    virtual void Operation() override {
        std::cout << "Operation" << std::endl;
    }
};

class FlyweightFactory {
private:
    std::unordered_map<std::string, std::shared_ptr<Flyweight>> pool;
public:
    std::shared_ptr<Flyweight> GetFlyweight(std::string const &key) {
        auto iter = pool.find(key);
        if (iter != pool.end()) {
            return iter->second;
        } else {
            auto iter = pool.insert(std::make_pair(key, std::make_shared<ConcreteFlyweight>()));
            assert(iter.second);
            return iter.first->second;
        }
    }
};

int main() {
    auto factory = std::make_shared<FlyweightFactory>();
    auto v1 = factory->GetFlyweight("hello");
    auto v2 = factory->GetFlyweight("hello");
    assert(v1.get() == v2.get());
}
