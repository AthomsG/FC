#include <iostream>
#include "TH1F.h"
#include "TCanvas.h"
#include "TApplication.h"
#include "Vec.hpp"
#include "TRandom3.h"

using namespace std;

double get_average(int N, int* vetor)
{
    double res = 0;
    for (int i = 0; i < N; i++)
    {
        res += vetor[i];
    }
    return res/N;
}

int check_inside(double x, double y)
{
    if (sqrt(pow(x, 2) + pow(y, 2)) <= 1)
    {
        return 1;
    }
    return 0;
}

double get_pi(int TOTAL, int INSIDE)
{
    return double(4*INSIDE)/double(TOTAL);
}

double get_sigma(int n, int* x)
{
    int* x_2 = new int[n];
    for (int i = 0; i < n; i++)
    {
        x_2[i] = x[i]*x[i];
    }
    double res = sqrt(pow(get_average(n, x), 2) + get_average(n, x_2));
    delete[] x_2;
    return res;
}

double get_err(int n, int* x)
{
    double sigma = get_sigma(n, x);
    return sigma/sqrt(n);
}

int main()
{
    int inside;
    Vec inside_values;
    TRandom3 r(0);

    int iter = 1000;
    int* N = new int[3] {1000, 10000, 100000};
    
    int* sample1 = new int[iter];
    int* sample2 = new int[iter];
    int* sample3 = new int[iter];
    
    for (int sample = 0; sample < iter; sample++)
    {
        inside_values.clear();
        for (int j = 0; j < 3; j++)
        {
            inside = 0;
            for (int i = 0; i < N[j]; i++)
            {
                inside += check_inside(r.Uniform(0, 1), r.Uniform(0, 1));
            }
            inside_values.push_back(inside);
        }
        sample1[sample] = inside_values[0];
        sample2[sample] = inside_values[1];
        sample3[sample] = inside_values[2];
        
        cout << "calculating iter = " << sample << endl;
    }
    
    cout << "\n-----AVERAGED OUT-----\n\n";
    
    cout << "N = " << N[0] << " has PI = " << get_pi(N[0], get_average(iter, sample1)) << " has error " << get_err(N[0], sample1) <<endl;
    cout << "N = " << N[1] << " has PI = " << get_pi(N[1], get_average(iter, sample2)) << " has error " << get_err(N[1], sample2) <<endl;
    cout << "N = " << N[2] << " has PI = " << get_pi(N[2], get_average(iter, sample3)) << " has error " << get_err(N[2], sample3) <<endl << endl;
    
    cout << "sigma 1 = " << get_sigma(N[0], sample1)
    return 0;
}
