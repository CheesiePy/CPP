#ifndef LAB09_ANIMAL_H
#define LAB09_ANIMAL_H
using namespace std;
class Animal {

public:
    virtual void speak() = 0;


protected:
    Animal(): name(string("unnamed")), gender(false){};
    Animal(bool gender, const string& setName): name(string(setName)),gender(gender){};

    string& getName(){return name;}

private:
    string name;
    bool gender; // false = male , true = female

};


#endif //LAB09_ANIMAL_H
