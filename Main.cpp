#include <iostream>
#include <synchapi.h>
#include "LibrarySource/include/RandomFwoof.h"

int main() {
    int randomNumber = RandomFwoof::generateRandomNumber();
    std::cout << randomNumber;
    return 0;
}