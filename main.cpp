#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Product{
    std::string name;
    std::string dateDue;
    std::string weight;
};

class Water: public Product{};
class Eggs: public Product{
    int number;
};
class Bread: public Product{};
class Milk: public Product{};
class Soap: public Product{};

class Container{
    std::vector<Product>;
};

class Refregirator: public Container{};
class Frezer: public Container{};
class Shelve: public Container{};

class Pudge{
public:
    std::vector<Product> jopa;
};

int main() {
    Pudge* pudge = new Pudge();
    Soap* soap = new Soap();
    Milk* milk = new Milk();
    pudge->jopa.push_back(*milk);
    pudge->jopa.push_back(*soap);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
