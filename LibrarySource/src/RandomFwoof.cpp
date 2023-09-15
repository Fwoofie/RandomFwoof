//#include "RandomFwoof.h"
#include <iostream>
#include <chrono>

namespace RandomFwoof {
    int generateRandomNumber() {
        auto startTime = std::chrono::high_resolution_clock::now();
        long tick = time(NULL);
          //srand(tick);
           int randomNumber = tick //(rand());

            auto endTime = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime-startTime);

            std::string extraInfo = std::to_string(duration.count()) + " < Time took to calculate. " + std::to_string(randomNumber) + " < Result Number. " + std::to_string(tick) + " < Tick when started";

            std::cout << extraInfo << std::endl;
            return randomNumber;
        }
    }
}