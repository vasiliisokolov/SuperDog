#include <iostream>
#include <vector>

class Talent
{
public:
    virtual void perfomance() = 0;
};

class Swimming : virtual public Talent
{
public:

    virtual void perfomance()
    {
        std::cout << "It can swim!" << std::endl;
    }
};

class Dancing : virtual public Talent
{
public:

    virtual void perfomance()
    {
        std::cout << "It can dance!" << std::endl;
    }
};

class Counting : virtual public Talent
{
public:

    virtual void perfomance()
    {
        std::cout << "It can count!" << std::endl;
    }
};


class Dog
{
    std::string name;
    int age;

public:

    std::vector<Talent*> talents;

    std::string getName()
    {
        return name;
    }

    int getAge()
    {
        return age;
    }

    void setName(std::string name)
    {
        this->name = name;
    }

    void setAge(int age)
    {
        this->age = age;
    }

    void showTalents()
    {
        for (int i = 0; i < talents.size(); i++)
        {
            talents[i]->perfomance();
        }
    }

    Dog(std::string inName, int inAge)
    {
        setName(inName);
        setAge(inAge);
        bool swimm = false;
        bool dance = false;
        bool count = false;

        for (int i = 0; i < 3; i++)
        {
            int talentType = rand() % 3;
            if (talentType == 0)
            {

            }
            else if (talentType == 1 && !swimm)
            {
                Talent* talent = new Swimming();
                talents.push_back(talent);
                swimm = true;
            }
            else if (talentType == 2 && !dance)
            {
                Talent* talent = new Dancing();
                talents.push_back(talent);
                dance = true;
            }
            else if (talentType == 3 && !count)
            {
                Talent* talent = new Counting();
                talents.push_back(talent);
                count = true;
            }
            
        }
        
    }
    
};

int main()
{
    std::string tempName;
    int tempAge;

    std::cout << "Enter the dog's name: ";
    std::cin >> tempName;
    std::cout << "Enter the dog's age: ";
    std::cin >> tempAge;
    Dog* dog = new Dog(tempName, tempAge);
    dog->showTalents();
    for (int i = 0; i < dog->talents.size(); i++)
    {
        delete dog->talents[i];
    }
    delete dog;
}

