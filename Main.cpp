#include <iostream>
#include <chrono>
#include <thread>
#include "RandomFwoof/Include/RandomFwoof.h"

int main()
{
      RandomFwoof::setRandomNumberSeed(time(NULL), 0);
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
      std::cout << RandomFwoof::getFlag("rerollrandomseed") << std::endl;
      std::cout << RandomFwoof::generateRandomNumber() << std::endl;
      return 0;
}