#include <iostream>
#include <memory>
#include <unordered_set>
#include <string>

class Component {
protected:
    std::unordered_set<std::shared_ptr<Component>> childs;
public:
    void AddComponent(std::shared_ptr<Component> child) {
        childs.insert(child);
    }

    void RemoveComponent(std::shared_ptr<Component> child) {
        childs.erase(child);
    }

    virtual void Operation() = 0;
};

class Leaf : public Component {
    std::string name;
public:
    Leaf(std::string name) {
        this->name = std::move(name);
    }

    virtual void Operation() override {
        std::cout << "Self: " << name << std::endl;
        for (auto &iter : childs) {
            iter->Operation();
        }
    }
};

int main() {
    std::shared_ptr<Component> leaf1 = std::make_shared<Leaf>("leaf1");
    std::shared_ptr<Component> leaf2 = std::make_shared<Leaf>("leaf2");
    std::shared_ptr<Component> leaf3 = std::make_shared<Leaf>("leaf3");
    std::shared_ptr<Component> leaf4 = std::make_shared<Leaf>("leaf4");
    std::shared_ptr<Component> leaf5 = std::make_shared<Leaf>("leaf5");
    leaf3->AddComponent(leaf2);
    leaf3->AddComponent(leaf1);
    leaf5->AddComponent(leaf4);
    leaf5->AddComponent(leaf3);
    leaf5->Operation();
}
