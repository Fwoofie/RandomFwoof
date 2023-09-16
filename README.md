<br>

# **RandomFwoof**

## **Better psuedo-random Number Library for C++.**
<br>

This library was designed to let developers get improved randomized numbers in C++. 

<br>

`RandomFwoof` will give you a way to have **better** psuedo-randomized numbers than `srand()` and `rand()` can ever generate! 

<br>

- RandomFwoof achieves this by giving the developer a lot of customizability when generating numbers, ***and it's easy to use!*** 🎉

- We allow the developer to have a system that generates better psuedo-randomn numbers than other options.

### With this library you can:
- Put in Application Specific Random Seeds.
- Use Automatically Random Seeds

### How do Application Specific Random Seeds (ASRS) work?
- We give the developer an option to have a `string` that is also included in the formula we use to generate random numbers. If course it still uses the epoch time, but it also includes the Application Specific Random Seed (ASRS). The ASRS can be set manually by the developer. It works by having a 26 digit long string (One letter for each letter of the english alphabet) and it is the english alphabet. The developer can manually change the arrangement of the letters to something else. By default, the value is "badcfehgjilknmporqtsvuxwzy" (which is made from the alphabet, but every set of two letters are flipped) but it can be changed to "aydzefbcijklnopghqrstumvwx" to help mix up the random numbers. In this library, we give you the ability to set your ASRS and a RS (Random Seed) whenever and however many you want -> (Keep in mind, don't spam the ability to set these too often, and you should just use it to help stop repeating numbers).

<br>
<br>
<br>

**Pssst. The folder for the compiled library is the RandomFwoof Folder** 