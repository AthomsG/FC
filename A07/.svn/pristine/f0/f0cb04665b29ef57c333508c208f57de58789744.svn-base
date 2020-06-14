
#include <vector>
#include <string>
#include "TF1.h"
#include "FCrand.hpp"
#include "iostream"
#include "fstream"
#define SEPARATOR  "\n---------------\n"

using namespace std;

int main()
{
    FCrand rand(1);
    ofstream fich;
    fich.open("random.txt");
    float* nums = new float[100];
    nums = rand.GetRandom(100, 0, 1);
    for (int i = 0; i < 100; i++)
    {
        fich << nums[i] << endl;
    }
    fich.close();
    return 0;
}

