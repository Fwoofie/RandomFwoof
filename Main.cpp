#include <iostream>
#include <chrono>
#include <thread>
#include "RandomFwoof/Include/RandomFwoof.h"

int main()
{
      RandomFwoof::setRandomNumberSeed(time(NULL), 0); // second argument is for ARS! Leave 0 for auto
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
      std::cout << RandomFwoof::getFlag("rerollrandomseed") << std::endl; //automatically true: use setFlag to change! This makes it so when the randomnumbers finish the set sequence, it wil automatically make a new one!
      std::cout << RandomFwoof::generateRandomNumber() << std::endl;
      return 0;
}
