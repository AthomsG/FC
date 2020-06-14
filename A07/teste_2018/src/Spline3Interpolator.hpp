#ifndef Spline3_HPP
#define Spline3_HPP

class Spline3Interpolator : public DataPoints{
  public:
    Spline3Interpolator(int N=0, double *x=NULL, double *y=NULL, TF1* fF0=NULL);
    ~Spline3Interpolator() {delete FInterpolator; delete F0; delete[] K;}
    double Interpolate(double x); //retorna o valor da funcao interpoladora na abcissa x
    void Draw(const char* = "",const char* = "",const char* = "", Int_t npx = 500, int = 1); //draw everything (points and interpolation function)
    TF1* GetInterpolationFunction() {return FInterpolator;}
    void SetFunction(TF1* fF) { FInterpolator = fF;}
    void Print(const char* = "",const char* = "",const char* = "",const char* = "", Int_t npx = 500); // print results to file (optional)
  private:
    void SetCurvatureLines();
    double fInterpolator(double *fx, double *par) {return Interpolate(fx[0]);}
    double* K; // segundas derivadas
    TF1* FInterpolator; //interpolation function
    TF1* F0;  //eventual underlying function
};

#endif
