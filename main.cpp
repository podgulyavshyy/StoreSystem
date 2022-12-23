#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int date = 0;

class Product{
public:
    std::string type;
    std::string name;
    double weight;
    int dateDue;
    Product(std::string type, std::string name, double weight, int dateDue){
        this->type = type;
        this->name = name;
        this->weight = weight;
        this->dateDue = dateDue;
    }

    virtual ~Product(){};

    int getDueDate() {
        return this->dateDue;
    }

    void giveInfo(){
        std::cout << "Type: " << this->type << " Name: " << this->name << " Weight: " << this->weight <<std::endl;
    }
};

class Water: public Product{
public:
    Water(std::string type, std::string name, double weight, int dateDue) : Product(type, name, weight, dateDue) {};
};
class Eggs: public Product{
    int number;
public:
    Eggs(std::string type, std::string name, double weight, int dateDue, int number) : Product(type, name, weight, dateDue) {
        this->number = number;
    };
};
class Bread: public Product{

public:

    Bread(std::string type, std::string name, double weight, int dateDue) : Product(type, name, weight, dateDue) {};
};
class Milk: public Product{

public:
    Milk(std::string type, std::string name, double weight, int dateDue) : Product(type, name, weight, dateDue) {};

};
class Soap: public Product{
public:
    Soap(std::string type, std::string name, double weight, int dateDue) : Product(type, name, weight, dateDue) {
        this->dateDue = NULL;
    };
};

class Fish: public Product{
public:
    Fish(std::string type, std::string name, double weight, int dateDue) : Product(type, name, weight, dateDue) {
        this->dateDue = NULL;
    };
};

class Meat: public Product{
public:
    Meat(std::string type, std::string name, double weight, int dateDue) : Product(type, name, weight, dateDue) {
        this->dateDue = NULL;
    };
};
class Container{
public:
    std::string type;
    std::string name;
    std::vector<Product> shelve;
    int minTemp;
    int maxTemp;
    int currTemp;
    Container(std::string type, std::string name){
        this->type = type;
        this->name = name;
    }
    void showAll(){
        std::cout << this->type << std::endl;
        for (int i = 0; i < shelve.size(); ++i) {
            shelve[i].giveInfo();
        }
    }
    void remove(std::string name){
        for (int i = 0; i < shelve.size(); ++i) {
            if (shelve[i].name == name){
                this->shelve.erase(this->shelve.begin() + i);
            }
        }
    }
    void add(Product prod){
        shelve.push_back(prod);
    }

    void setMinTemp(int minTemp){
        this->minTemp = minTemp;
    }

    void setMaxTemp(int maxTemp){
        this->maxTemp = maxTemp;
    }

    void setTemp(int temp){
        if(this->type == "Freezer" || this->type == "Refrigerator") {
            if (temp > this->minTemp && temp < this->maxTemp) {
                this->currTemp = temp;
                std::cout << "Done" << std::endl;
            } else {
                std::cout << "Choose temperature within limits" << std::endl;
            }
        }
    }
};

class Refrigerator: public Container{
public:
    Refrigerator(std::string type, std::string name) : Container(type, name) {};
};
class Freezer: public Container{
public:
    Freezer(std::string type, std::string name) : Container(type, name) {};
};
class Shelve: public Container{
public:
    Shelve(std::string type, std::string name) : Container(type, name) {};
};

class Shop{
public:
    std::vector<Container> containers;
    void showAll(){
        for (int i = 0; i < containers.size(); ++i) {
            containers[i].showAll();
        }
    }
    void add(std::string itemName, std::string contName){
        Product temp = *new Product("type", "name", 0, 0);
        for (int i = 0; i < containers.size(); ++i) {
            for (int j = 0; j < containers[i].shelve.size(); ++j) {
                if(containers[i].shelve[j].name == itemName){
                    temp = containers[i].shelve[j];
                }
            }
        }
        for (int i = 0; i < containers.size(); ++i) {
            if(containers[i].name == contName){
                containers[i].shelve.push_back(temp);
            }
        }

    }
    void move(std::string itemName, std::string contName){
        Product temp = *new Product("type", "name", 0, 0);
        for (int i = 0; i < containers.size(); ++i) {
            for (int j = 0; j < containers[i].shelve.size(); ++j) {
                if(containers[i].shelve[j].name == itemName){
                    temp = containers[i].shelve[j];
                    containers[i].shelve.erase(containers[i].shelve.begin() + j);
                }
            }
        }
        for (int i = 0; i < containers.size(); ++i) {
            if(containers[i].name == contName){
                containers[i].shelve.push_back(temp);
            }
        }
    }

    void nextDay(){
        date++;
        int deletedElem;
        for (int i = 0; i < containers.size(); ++i) {
            for (int j = 0; j < containers[i].shelve.size() + deletedElem; ++j) {
                if(containers[i].shelve[j].getDueDate() == date){

                    containers[i].shelve.erase(containers[i].shelve.begin() + j - deletedElem);
                    deletedElem++;
                }
            }
            deletedElem = 0;
        }
    }
};

void tokenize(std::string const &str, const char* delim, std::vector<std::string> &out)
{
    char *token = strtok(const_cast<char*>(str.c_str()), delim);
    while (token != nullptr)
    {
        out.push_back(std::string(token));
        token = strtok(nullptr, delim);
    }
}

void UI(Shop shop){
    while(true) {
        std::string input;
        std::cout << std::endl;
        std::vector<std::string> inputVec;
        std::getline(std::cin, input);
        tokenize(input, " ", inputVec);
        int command = std::stoi(inputVec[0]);

        if(command == 1){
            shop.showAll();
        }

        if(command == 2){
            std::string type = inputVec[1];
            for (int i = 0; i < shop.containers.size(); ++i) {
                if (shop.containers[i].type == type){
                    shop.containers[i].showAll();
                }
            }
        }

        if(command == 3){
            shop.nextDay();
        }

        if(command == 4){
            std::string name = inputVec[1];
            for (int i = 0; i < shop.containers.size(); ++i) {
                shop.containers[i].remove(name);
            }
        }

        if(command == 5){
            std::string itemName = inputVec[1];
            std::string contName = inputVec[2];
            shop.add(itemName, contName);
        }

        if(command == 6){
            std::string contName = inputVec[1];
            int newTemp = std::stoi(inputVec[2]);
            for (int i = 0; i < shop.containers.size(); ++i) {
                if(shop.containers[i].name == contName){
                    shop.containers[i].setTemp(newTemp);
                }
            }
        }

        if(command == 7){
            std::string itemName = inputVec[1];
            std::string contName = inputVec[2];
            shop.move(itemName, contName);
        }
    }
}


int main() {


    Product* YaMilk = new Milk("Milk", "Yahotynske", 5, 1);
    Milk* YahMilk = dynamic_cast <Milk*>(YaMilk);
    YahMilk->getDueDate();
    std::cout << YahMilk->getDueDate();
    Milk* YahotynskeMilk = new Milk("Milk", "Yahotynske", 5, 1);
    Eggs* NovusEggs = new Eggs("Eggs", "Novus", 5, 1, 10);

    Fish* Salmon = new Fish("Fish", "Salmon", 2, 0);
    Meat* Pork = new Meat("Meat", "Pork", 3, 0);
    Fish* Salmon1 = new Fish("Fish", "Salmon", 4, 0);

    Bread* Croissant = new Bread("Bread", "Croissant", 0.2, 1);
    Bread* WhiteBread = new Bread("Bread", "WhiteBread", 0.5, 1);

    Soap* Domestos = new Soap("Soap", "Domestos", 1, 0);
    Soap* Gillette = new Soap("Soap", "Gillette", 0.5, 0);
    Soap* Dove = new Soap("Soap", "Dove", 0.25, 0);

    Water* Morshynska = new Water("Water", "Morshynska", 100, 2);
    Water* Buvette = new Water("Water", "Buvette", 50, 1);

    Refrigerator* Ref1 = new Refrigerator("Refrigerator", "Ref1");
    Freezer* Freezer1 = new Freezer("Freezer", "Freezer1");
    Shelve* Shelve1 = new Shelve("Shelve", "Shelve1");
    Shelve* Shelve2 = new Shelve("Shelve", "Shelve2");
    Shelve* Shelve3 = new Shelve("Shelve", "Shelve3");

    Ref1->setMinTemp(20);
    Ref1->setMaxTemp(50);



    Ref1->shelve.push_back(*YahotynskeMilk);
    Ref1->shelve.push_back(*NovusEggs);

    Freezer1->shelve.push_back(*Salmon);
    Freezer1->shelve.push_back(*Pork);
    Freezer1->shelve.push_back(*Salmon1);

    Shelve1->shelve.push_back(*Croissant);
    Shelve1->shelve.push_back(*WhiteBread);

    Shelve2->shelve.push_back(*Domestos);
    Shelve2->shelve.push_back(*Gillette);
    Shelve2->shelve.push_back(*Dove);

    Shelve3->shelve.push_back(*Morshynska);
    Shelve3->shelve.push_back(*Buvette);

    Shop* Shop1 = new Shop;

    Shop1->containers.push_back(*Ref1);
    Shop1->containers.push_back(*Freezer1);
    Shop1->containers.push_back(*Shelve1);
    Shop1->containers.push_back(*Shelve2);
    Shop1->containers.push_back(*Shelve3);

    UI(*Shop1);


    // std::cout << "Hello, World!" << std::endl;
    return 0;
}
