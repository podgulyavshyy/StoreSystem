#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Product{
public:
    std::string type;
    std::string name;
    double weight;
    Product(std::string type, std::string name, double weight){
        this->type = type;
        this->name = name;
        this->weight = weight;
    }

    void giveInfo(){
        std::cout << "Type: " << this->type << " Name: " << this->name << " Weight: " << this->weight <<std::endl;
    }
};

class Water: public Product{
    int dateDue;
public:
    Water(std::string type, std::string name, double weight, int dateDue) : Product(type, name, weight) {
        this->dateDue = dateDue;
    };
};
class Eggs: public Product{
    int number;
    int dateDue;
public:
    Eggs(std::string type, std::string name, double weight, int dateDue, int number) : Product(type, name, weight) {
        this->dateDue = dateDue;
        this->number = number;
    };
};
class Bread: public Product{
    int dateDue;
public:
    Bread(std::string type, std::string name, double weight, int dateDue) : Product(type, name, weight) {
        this->dateDue = dateDue;
    };
};
class Milk: public Product{
    int dateDue;
public:
    Milk(std::string type, std::string name, double weight, int dateDue) : Product(type, name, weight) {
        this->dateDue = dateDue;
    };
};
class Soap: public Product{
public:
    Soap(std::string type, std::string name, double weight) : Product(type, name, weight) {};
};

class Fish: public Product{
public:
    Fish(std::string type, std::string name, double weight) : Product(type, name, weight) {};
};

class Meat: public Product{
public:
    Meat(std::string type, std::string name, double weight) : Product(type, name, weight) {};
};
class Container{
public:
    std::string type;
    std::vector<Product> shelve;
    Container(std::string type){
        this->type = type;
    }
    void showAll(){
        std::cout << this->type << std::endl;
        for (int i = 0; i < shelve.size(); ++i) {
            shelve[i].giveInfo();
        }
    }
};

class Refrigerator: public Container{
public:
    Refrigerator(std::string type) : Container(type) {};
};
class Freezer: public Container{
public:
    Freezer(std::string type) : Container(type) {};
};
class Shelve: public Container{
public:
    Shelve(std::string type) : Container(type) {};
};

class Shop{
public:
    std::vector<Container> containers;
    void showAll(){
        for (int i = 0; i < containers.size(); ++i) {
            containers[i].showAll();
        }
    }
};


int main() {
    Milk* YahotynskeMilk = new Milk("Milk", "Yahotynske", 5, 1);
    Eggs* NovusEggs = new Eggs("Eggs", "Novus", 5, 1, 10);

    Fish* Salmon = new Fish("Fish", "Salmon", 2);
    Meat* Pork = new Meat("Meat", "Pork", 3);
    Fish* Salmon1 = new Fish("Fish", "Salmon", 4);

    Bread* Croissant = new Bread("Bread", "Croissant", 1, 0.2);
    Bread* WhiteBread = new Bread("Bread", "WhiteBread", 1, 0.5);

    Soap* Domestos = new Soap("Soap", "Domestos", 1);
    Soap* Gillette = new Soap("Soap", "Gillette", 0.5);
    Soap* Dove = new Soap("Soap", "Dove", 0.25);

    Water* Morshynska = new Water("Water", "Dove", 100, 2);
    Water* Buvette = new Water("Water", "Dove", 50, 1);

    Refrigerator* Ref1 = new Refrigerator("Ref1");
    Freezer* Freezer1 = new Freezer("Freezer1");
    Shelve* Shelve1 = new Shelve("Shelve1");
    Shelve* Shelve2 = new Shelve("Shelve2");
    Shelve* Shelve3 = new Shelve("Shelve3");




    Ref1->shelve.push_back(*YahotynskeMilk);
    Ref1->shelve.push_back(*NovusEggs);

    Freezer1->shelve.push_back(*Salmon);
    Freezer1->shelve.push_back(*Pork);
    Freezer1->shelve.push_back(*Salmon1);

    Shelve1->shelve.push_back(*Croissant);
    Shelve1->shelve.push_back(*WhiteBread);

    Shelve2->shelve.push_back(*Domestos);
    Shelve2->shelve.push_back(*Gillette);
    Shelve2->shelve.push_back(*Domestos);

    Shelve3->shelve.push_back(*Morshynska);
    Shelve3->shelve.push_back(*Buvette);

    Shop* Shop1 = new Shop;

    Shop1->containers.push_back(*Ref1);
    Shop1->containers.push_back(*Freezer1);
    Shop1->containers.push_back(*Shelve1);
    Shop1->containers.push_back(*Shelve2);
    Shop1->containers.push_back(*Shelve3);

    Shop1->showAll();


    // std::cout << "Hello, World!" << std::endl;
    return 0;
}
