#ifndef FCmatrixFull_hpp
#define FCmatrixFull_hpp
#include "FCmatrix.hpp"

class FCmatrixFull : public FCmatrix {
public:
    // constructors
    FCmatrixFull();
    FCmatrixFull(int fm, int fn, double = 0, string = "EMPTY");
    //inicializa tudo com um valor (default=0)
    FCmatrixFull(double** fM, int fm, int fn, string = "EMPTY");
    FCmatrixFull(double* fM, int fm, int fn,string = "EMPTY");
    FCmatrixFull(vector<Vec>,string = "EMPTY");
    FCmatrixFull(const FCmatrixFull&); // copy constructor
    // operators
    FCmatrixFull operator=(const FCmatrix &);
    FCmatrixFull operator+(const FCmatrix &) const;
    FCmatrixFull operator-(const FCmatrix &) const;
    FCmatrixFull operator*(const FCmatrix &) const;
    FCmatrixFull operator*(double lambda) const;
    Vec operator*(const Vec &) const;
    Vec operator[](int) const; //get a row by giving index inside []
    Vec& operator[] (int); //get a row by giving index inside []
    //methods
    void SetEntries(int,int,double = 0);
    void SetEntries(double**,int,int);
    void SetEntries(double*,int,int);
    void SetEntries(const vector<Vec>&);
    void Transpose();
    double Determinant() const;
    int Get_nRows() const;
    int Get_nCols() const;
    Vec GetRow(int i) const;
    Vec GetCol(int i) const;
    int GetRowMax(int i=0) const;
    int GetColMax(int j=0) const; // verificar eficiencia
    void swapRows(int, int);
    //friend functions
    friend FCmatrixFull operator*(const double, const FCmatrixFull&);
    friend Vec operator*(const Vec&, const FCmatrixFull&);
    ~FCmatrixFull() {;}
};

#endif
