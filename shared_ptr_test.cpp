#include "shared_ptr.h"
#include <iostream>

using namespace re;

class Dog
{
public:
    explicit Dog()
    {
        std::cout << "Dog created" << std::endl;
        printf("this dog 1\n");
    }

    void say()
    {
        std::cout << "Woof~Woof~Woof~" << std::endl;
    }

    ~Dog()
    {
        std::cout << "Dog destroyed" << std::endl; 
        printf("this dog 1\n");   
    }
};

int main()
{
    shared_ptr<Dog> dog(new Dog());
    dog->say();

    auto dog2(dog);
    shared_ptr<Dog> dog3 = dog;
    dog2->say();
    dog3->say();

    if(dog)
    {
        std::cout << "dog is not nullptr" << std::endl;
    }

    return 0;
}