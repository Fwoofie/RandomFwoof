#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <stdlib.h>

std::string randomNumberSeed = "0";
std::unordered_map<std::string, bool> flags = {
    {"rerollrandomseed", true}
};

int currentRandomIndex = 1;
int savedApplicationRandomSeed = 0;

std::string fixRandomSeed(std::string givenRandomSeed)
{
    std::string fixedRandomSeed = "";

    for (int i = 0; i < givenRandomSeed.length(); i++)
    {
        char currentChar = givenRandomSeed[i];
        if (currentChar != '-')
        {
            fixedRandomSeed += currentChar; 
        }
    }

    return fixedRandomSeed;
}

namespace RandomFwoof {
    
    int powerOf(int originalBase, int exponent) 
    {
        int base = originalBase;
        
        if (exponent == 0)
        {
            return 1;
        }
        
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
        if (flags.find(flag) != flags.end()) {
            return flags[flag];
        }

        return false;
    }

    void clearRandomSeed()
    {
        randomNumberSeed = "012";
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
        
        // printf("\nstringTick: %s\n", stringTick.c_str());
        
        if (ARS == 0) 
        {
            ARS = time(NULL) * 0.5;
        }

        //printf("\nARS: %d\n", ARS);

        savedApplicationRandomSeed = ARS;
            
        int tempOperationHolder = time(0) * 0.25;
        
        for (int i = 0; i < stringTick.length(); i++) {
            int previousIndex;
            int secondPreviousIndex;

            if (i == 0) 
            {
                previousIndex = stringTick.length() - 1;
                secondPreviousIndex = previousIndex - 1;
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
            currentChar = powerOf(currentChar + 1, stringTick[previousIndex] + 1);
            //printf("\ndebug 1: %d\n", currentChar);
            currentChar = (unsigned int) currentChar * secondPreviousIndex + 1 * ( stringTick[secondPreviousIndex] * (previousIndex * 0.5)) + 1 * ARS;
            currentChar += tempOperationHolder;
            //printf("\ndebug 2: %d\n", currentChar); 
            std::string localFinishedString = std::to_string(currentChar * tick);
            finishedNumber.append(localFinishedString.substr(1, localFinishedString.length() - 1));

        }

        randomNumberSeed = fixRandomSeed(finishedNumber);
        //printf("\nrandomNumberSeed: %s\n", randomNumberSeed.c_str());
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

            currentRandomIndex = 2;
            return randomNumberSeed[1] - 48;
        }
        
    }

    int generateRandomNumberRange(int min, int max)
    {
        
        int range = max - min;
        
        int currentRoll = 0;
        for (int i = 0; i < range; i++)
        {
            if (generateRandomNumber() > 4)
            {
                currentRoll++;
            }
        }
        
        return currentRoll + min;

        /*
        int range = max - min;

        int randomNumber = 0;

        int maxRolls = range * 10;
        int currentRolls = 0;
        for (int i = 0; i < range; i++)
        {
            currentRolls += generateRandomNumber();
            if (generateRandomNumber() > 4)
            {
                currentRolls += 1;   
            }
        }
        
        randomNumber = (currentRolls * 0.1);

        return randomNumber + min;
        */
    }

}
