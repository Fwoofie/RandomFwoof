#ifndef RANDOMFWOOF_INCLUDED
#define RANDOMFWOOF_INCLUDED
#include <string>

namespace RandomFwoof { 
    int generateRandomNumber(); 
    void setRandomNumberSeed(int tick, int ARS);
    void clearRandomSeed();
    std::string getRandomSeed();
    int getRandomSeedIndex();
    void setFlag(std::string flag, bool value);
    bool getFlag(std::string flag);
};

#endif 