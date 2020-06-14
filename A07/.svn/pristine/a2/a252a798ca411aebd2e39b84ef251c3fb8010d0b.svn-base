#include <iostream>
#include <math.h>
#include <fstream>
#define G  -9.8

using namespace std;

int main()
{
    float vel, x, alt;
    int time = 0;
    
    ofstream fich;
    fich.open("trajectory.txt");
    
    cout << "introduza o valor da velocidade inicial: \n";
    cin  >> vel;
    
    cout << "introduza o valor da altura inicial: \n";
    cin  >> x;
    
    for (int i = 0; i < 10; i++)
    {
        fich << time << " ----- " << x << "\n";
        time += 1;
        x     = time * time * (G/2) + vel * time + alt;
    }
    
    fich.close();
}
