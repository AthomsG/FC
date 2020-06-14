#ifndef FCmatrix_hpp
#define FCmatrix_hpp

class FCmatrix {
public:
    //constructors
    FCmatrix();
    FCmatrix(int fm, int fn, double = 0, string = "EMPTY"); //matrix fm x fn filled with one number, whose def value is 0
    FCmatrix(double** fM, int fm, int fn,string = "EMPTY"); //matrix fm x fn given from pointer of pointers
    FCmatrix( double* fM, int fm, int fn,string = "EMPTY" ); //matrix fm x fn given as single pointer (what length ?!)
    FCmatrix( const vector<Vec>&,string = "EMPTY"); //matrix fm x fn given as vector of Vec
    // operators
    virtual Vec& operator[](int) = 0; //get a row by giving índex inside []
    virtual Vec operator[](int) const = 0; //get a row by giving índex inside []
    // // methods
    virtual void SetEntries(const vector<Vec>&) = 0;
    virtual int Get_nRows() const = 0; //number of rows of M
    virtual int Get_nCols() const = 0; //number of columns of M
    virtual Vec GetRow(int i) const = 0; // retrieve row i
    virtual Vec GetCol(int i) const = 0; // retrieve column i
    //
    virtual double Determinant() const = 0;
    // // in row-i, return column-index of max element (in absolute value)
    virtual int GetRowMax(int i=0) const = 0;
    // // in column-j, return row-index (>=j) for which relative amplitude of Mij on the row is highest.
    virtual int GetColMax(int j=0) const = 0; //
    virtual void Print() const; //print e.g. row by row (GetRow to the rescue...)
    virtual vector<Vec> GetM() const {return M;}
    virtual string GetName() const {return classname;}
    virtual ~FCmatrix() {;}
protected:
    vector<Vec> M; //the matrix is a vector of Vec objects...
    string classname; //give the class a name...
};

#endif
