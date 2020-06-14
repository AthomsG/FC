#ifndef DATAPOINTS_HPP
#define DATAPOINTS_HPP

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
    virtual void Draw(const char* = "",const char* = "",const char* = "");
    virtual void Print(const char* = "datafile",const char* = "",const char* = "",const char* = "");
  protected:
    int N; //number of data points;
    double *x, *y; // arrays with data
    static int Nplots; // how many plots already done
};

#endif
