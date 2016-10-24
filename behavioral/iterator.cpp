#include <iostream>
#include <memory>
#include <vector>

class Aggregate;

class Iterator {
public:
    virtual bool HasNext() = 0;
    virtual std::shared_ptr<Iterator> Next() = 0;
    virtual int Get() = 0;
};

class Aggregate {
public:
    virtual std::shared_ptr<Iterator> CreateIterator() = 0;
};

class ConcreteIterator : public Iterator{
private:
    std::vector<int> &vec;
    std::size_t cur = 0;

public:
    ConcreteIterator(std::vector<int> &vec, std::size_t cur = 0)
        : vec(vec), cur(cur)
    {}

    virtual bool HasNext() override {
        return cur != vec.size();
    }

    virtual std::shared_ptr<Iterator> Next() override {
        return std::make_shared<ConcreteIterator>(vec, cur+1);
    }

    virtual int Get() override {
        return vec[cur];
    }
};

class ConcreteAggregate : public Aggregate {
private:
    std::vector<int> vec;

public:
    ConcreteAggregate(std::vector<int> vec) {
        this->vec.swap(vec);
    }

    std::shared_ptr<Iterator> CreateIterator() override {
        return std::make_shared<ConcreteIterator>(vec);
    }
};

int main() {
    std::vector<int> a = {1,2,3,4,5,6};
    std::shared_ptr<Aggregate> ag = std::make_shared<ConcreteAggregate>(std::move(a));
    std::shared_ptr<Iterator> it = ag->CreateIterator();
    while (it->HasNext()) {
        std::cout << it->Get() << std::endl;
        it = it->Next();
    }
}
