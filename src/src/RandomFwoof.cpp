#include <iostream>
#include <string>
#include <unordered_map>
#include <stdlib.h>

std::string randomNumberSeed = "0";
std::unordered_map<std::string, bool> flags = {
    {"rerollrandomseed", true}
};

int currentRandomIndex = 0;
int savedApplicationRandomSeed = 0;

namespace RandomFwoof {
    
    int powerOf(int originalBase, int exponent) 
    {
        int base = originalBase;

        for (int i = 1; i < exponent; i++) 
        {
            base = base * originalBase;
        }
        return base;
    }

    void setFlag(std::string flag, bool value)
    {
        flags[flag] = value;
    }

    bool getFlag(std::string flag)
    {
        if (flags[flag]) {
            return flags[flag];
        }

        return false;
    }

    void clearRandomSeed()
    {
        randomNumberSeed = "0";
    }

    std::string getRandomSeed()
    {
        return randomNumberSeed;
    }

    int getRandomSeedIndex()
    {
        return currentRandomIndex;
    }

    void setRandomNumberSeed(int tick, int ARS) 
    {
        //std::vector<int>* randomNumberArray = {0};
        std::string stringTick = std::to_string(tick); //intToArray(tick, *randomNumberArray);
        std::string finishedNumber;

        if (ARS == 0) 
        {
            ARS = time(NULL) * 0.0000004;
        }
        
        savedApplicationRandomSeed = ARS;

        for (int i = 0; i < stringTick.length(); i++) {
            int previousIndex;
            int secondPreviousIndex;

            if (i == 0) 
            {
                previousIndex = stringTick.length() - 1;
                secondPreviousIndex = previousIndex - 2;
            }
            else 
            {
                previousIndex = i - 1;

                if (previousIndex == 0)
                {
                    secondPreviousIndex = stringTick.length() - 1;
                }
                else 
                {
                    secondPreviousIndex = previousIndex - 1;
                }
            }

            int currentChar = stringTick[i];
            currentChar = powerOf(currentChar, stringTick[previousIndex]);
            currentChar = currentChar * secondPreviousIndex * previousIndex * ARS;
            currentChar = abs(currentChar);

            finishedNumber.append(std::to_string(currentChar * tick));

        }

        randomNumberSeed = finishedNumber;

        //std::cout << "The finished product! > " <<  finishedNumber << std::endl;
    }

    int generateRandomNumber() 
    {
        if (currentRandomIndex < randomNumberSeed.size()) {
            currentRandomIndex++;
            return randomNumberSeed[currentRandomIndex-1] - 48;
        } else {
            if (flags["rerollrandomseed"]) 
        {
                setRandomNumberSeed(time(NULL), savedApplicationRandomSeed);
            }

            currentRandomIndex = 1;
            return randomNumberSeed[0] - 48;
        }
        
    }

}
