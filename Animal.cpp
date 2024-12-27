#pragma once
#include <iostream>
#include <ostream>
using namespace std;

// Animal header--
class Animal
{
public:
    virtual void makeSound() const = 0;
};

//----------------------------------------------------------------------
// Animal's Children
class Dog : public Animal
{
public:
    string _name = "멍멍이";
    void makeSound() const override
    {
        cout << "멍-멍-멍!!" << endl;
    }
};

class Cat : public Animal
{
public:
    string _name = "야옹이";
    void makeSound() const override
    {
        cout << "냐옹-냐옹-냐옹!!" << endl;
    }
};

class Cow : public Animal
{
public:
    string _name = "송애지";
    void makeSound() const override
    {
        cout << "음머-음머-음머~" << endl;
    }
};

//----------------------------------------------------------------------
// Zoo header--
class Zoo
{
private:
    Animal* _animals[10];
    int _count;
    
public:
    Zoo() : _count(0) {}
    
    void addAnimal(Animal* animal)
    {
        if (_count < 10)
        {
            _animals[_count++] = animal;
        }
        else
        {
            cout << "동물원이 가득 찼어요!" << endl;
        }
    }
    
    void performActions()
    {
        for (int i = 0; i < _count; i++)
        {
            _animals[i]->makeSound();
        }
    }
    ~Zoo()
    {
        for (int i = 0; i < _count; i++)
        {
            delete _animals[i];
        }
    }
};


//----------------------------------------------------------------------
// functions.
Animal* createRandomAnimal()
{
    int randNum = rand() % 3;

    switch (randNum)
    {
        case 0: return new Dog;
        case 1: return new Cat;
        case 2: return new Cow;
        default: return nullptr;
    }
}


//----------------------------------------------------------------------
// main function.
void main()
{
    Zoo zoo_01;

    // 생성할 동물 수
    int animalsCount = 10;

    for (int i = 0; i < animalsCount; i++)
    {
        zoo_01.addAnimal(createRandomAnimal());
    }
    zoo_01.performActions();
}