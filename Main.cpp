#include <iostream>
#include <synchapi.h>
#include "RandomFwoof/include/RandomFwoof.h"

int main() {
    int randomNumber = RandomFwoof::generateRandomNumber();
    std::cout << randomNumber;
    return 0;
}