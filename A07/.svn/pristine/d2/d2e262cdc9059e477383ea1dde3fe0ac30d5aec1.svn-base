#include "FCrand.hpp"
#include <cstdlib>
#include <cmath>
using namespace std;

FCrand::FCrand(int seed)
{
  this->seed = seed;
}

float FCrand::GetRandom()
{
  return abs((float)((multiplier*seed+increment)%modulus)/modulus);
}

float FCrand::GetRandom(float min, float max)
{
  return min+(max-min)*abs((float)((multiplier*seed+increment)%modulus)/modulus);
}

float* FCrand::GetRandom(int N)
{
  float* values = new float[N];
  values[0]=abs((multiplier*seed+increment)%modulus);
  for(int i =1; i<N ; i++)
  {
    values[i] = abs((multiplier*(int)values[i-1]+increment)%modulus);
  }
  for(int i =0; i<N; i++) {values[i]=(float)values[i]/modulus;}
  return values;
}

float* FCrand::GetRandom(int N, float min, float max)
{
  float* values = GetRandom(N);
  for(int i =0; i<N; i++)
  {
    values[i] = min + (max-min)*values[i];
  }
  return values;
}

void FCrand::SetSeed(int seed)
{
  this->seed = seed;
}
