#ifndef DATAPOINTS_HPP
#define DATAPOINTS_HPP
#include <string>
using namespace std;

class DataPoints {
  public:
    // constructors
    DataPoints();
    DataPoints(int, double*, double*);
    DataPoints(const DataPoints&);
    //destructor
    virtual ~DataPoints();
    //methods
    virtual double Interpolate(double x) {return 0.;}
    virtual void Draw(string title = "",string x_axix = "",string y_axis = "");
    virtual void PrintPlot(string filename = "plot.eps",string = "Data Points",string = "x",string = "y");
    void Print(string FILE = "datapoints.txt");
  protected:
    int N; //number of data points;
    double *x, *y; // arrays with data
    static int Nplots; // how many plots already done
};

#endif
