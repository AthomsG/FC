#ifndef FCRAND_HPP
#define FCRAND_HPP
#include <ctime>

class FCrand {
  public:
    //seed number (prototype incompleto)
    FCrand(int seed = time(NULL));
    //generate one random between [0,1]
    float GetRandom();
    //generate one random between [min,max]
    float GetRandom(float min, float max);
    //generate N randoms between [0,1]
    float* GetRandom(int N);
    //generate N randoms between [min,max]
    float* GetRandom(int N, float min, float max);
    void SetSeed(int seed = time(NULL));
  private:
    int multiplier = 65;
    int seed;
    int increment = 319;
    int modulus = 65537;
};

#endif
