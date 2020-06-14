#include <iostream>
using namespace std;

class Base {
public:
    Base()
    {
        i = new int;
        cout << "Criaram-me!! (Sou uma Base)\n";
    }
    virtual ~Base() //FIXED
    {
        cout << "Fui destruído!!\n";
        delete i;
    }
private:
    int* i;
};

class Derived : public Base {
public:
    Derived() {
        f = new float;
        cout << "Criaram-me!! (Sou uma classe derivada da Base)\n";
    }
    
    ~Derived() {
        delete f;
        cout << "Destruirem-me!!\n";
    }

private:
    float* f;
};

int main() {
    Base* obj = new Derived;
    
    delete obj;
    return 0;
}

//O seguinte programa não está correto, uma vez que são criados 2 objetos, um de classe Base e outro Derived, sendo que apenas o objeto de classe Base é devidamente libertado.
