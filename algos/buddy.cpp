#include <iostream>
#include <string>

int main()
{
    char i;
    std::cout << "Hey, there. What are you doing?";
    std::cout << "a) Doing tickets \nb) Checking email\nc) On your phone\nd) Staring at a wall\n";
    std::cin >> i;
    switch (i)
    {
        case 'a': std::cout << "Good job!" break;
        case 'a': std::cout << "Gotta be up to date." break;
        case 'a': std::cout << "wtf man get back to work" break;
        case 'a': std::cout << "oh jeez, not again" break;
        case 'a': std::cout << "ur bad porgammer" break;
    }
    return 0;
}