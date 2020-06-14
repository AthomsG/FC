#include <iostream>
#include <math.h>
#include <fstream>
#define G  9.8

using namespace std;

int main()
{
    float vel, x, alt;
    int time = 0;
    FILE* fich;
    fich=fopen("trajectory.txt","w");

    cout << "Introduza o valor da velocidade inicial (m/s): ";
    cin  >> vel;

    cout << "introduza o valor da altura inicial (m): ";
    cin >> alt;
    x = alt;
    fprintf(fich,"t(s)    y(m)\n");

    while(x >= 0)
    {
        //fich << time << " ----- " << x << "\n";
        fprintf(fich,"%i ----- %.4f\n",time,x);
        ++time;
        x = time * time * (-G/2) + vel * time + alt;
    }

    fclose (fich);
    return 0;
}
