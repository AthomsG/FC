#ifndef FCmatrixBanded_hpp
#define FCmatrixBanded_hpp
#include "FCmatrixFull.hpp"

class FCmatrixBanded : public FCmatrix {
public:
    // constructors
    FCmatrixBanded(); //checked
    FCmatrixBanded(int fm, double = 0, string = "EMPTY"); //checked
    FCmatrixBanded(double** fM, int fm, string = "EMPTY"); //checked
    FCmatrixBanded(double* fM, int fm, string = "EMPTY"); //checked
    FCmatrixBanded(vector<Vec>,string = "EMPTY"); //checked
    FCmatrixBanded(Vec,Vec,Vec,string = "EMPTY"); //checked
    FCmatrixBanded(const FCmatrixBanded&); //checked
    FCmatrixBanded(const FCmatrixFull&, string classname = "EMPTY");
    // operators
    Vec& operator[](int); //checked
    Vec operator[](int) const; //checked
    FCmatrixBanded operator=(const FCmatrix &); //checked
    FCmatrixBanded operator+(const FCmatrix &) const; //checked
    FCmatrixBanded operator-(const FCmatrix &) const; //checked
    FCmatrixBanded operator*(const FCmatrix &) const {;}
    FCmatrixBanded operator*(double lambda) const; //checked
    Vec operator*(const Vec &) const; //checked
    // // methods
    void SetEntries(const vector<Vec>&); //checked
    void SetEntries(int,double = 0); //checked
    // void SetEntries(double**,int,int) {;}
    // void SetEntries(double*,int,int) {;}
    int Get_nRows() const { return GetSize();} //checked
    int Get_nCols() const { return GetSize();} //checked
    Vec GetRow(int i) const {return GetFull().GetRow(i);} //checked
    Vec GetCol(int i) const {return GetFull().GetCol(i);} //checked
    int GetSize() const {return M[1].Size();} //checked
    double Determinant() const; //checked
    int GetRowMax(int i=0) const { return GetFull().GetRowMax(i);}
    int GetColMax(int j=0) const { return GetFull().GetRowMax(j);} //faz sentido aqui?
    FCmatrixFull GetFull() const; //checked
    void Print() const; //checked
    //friend functions
    friend FCmatrixBanded operator*(const double, const FCmatrixBanded&); //checked
    ~FCmatrixBanded() {;}
};



#endif
