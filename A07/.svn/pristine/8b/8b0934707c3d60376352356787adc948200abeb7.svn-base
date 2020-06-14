#ifndef LAGRANGE_HPP
#define LAGRANGE_HPP

class LagrangeInterpolator : public DataPoints
{
  public:
    LagrangeInterpolator(int N=0, double *x=NULL, double *y=NULL, TF1* fF0=NULL);
    ~LagrangeInterpolator() {delete FInterpolator; delete F0;}
    double Interpolate(double x); //retorna o valor da funcao interpoladora na abcissa x
    void Draw(const char*,const char*,const char*, Int_t npx = 500); //draw everything (points and interpolation function)
    TF1* GetInterpolationFunction() {return FInterpolator;}
    void SetFunction(TF1* fF) { FInterpolator = fF;}
    void Print(const char* title,const char*,const char*,const char*, Int_t npx = 500); // print results to file (optional)
  private:
    double fInterpolator(double *fx, double *par) {return Interpolate(fx[0]);}
    TF1* FInterpolator; //interpolation function
    TF1* F0;  //eventual underlying function
};

#endif
