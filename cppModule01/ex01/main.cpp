#include "Zombie.hpp"

int main()
{
    int N;
    std::string name;

    std::cout << "Please enter name:";
    std::getline(std::cin, name);

    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Array len:";
    std::cin >> N;

   


    Zombie *array = zombieHorde(N,name);
    for(int x = 0;x < N;x++)
    {
        array[x].announce();
    }

    delete[] array;
    return 0;
}