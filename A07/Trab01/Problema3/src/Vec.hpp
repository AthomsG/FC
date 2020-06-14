#ifndef VEC_H
#define VEC_H

using namespace std;

class Vec{ //aka poor vector
  public:
    // constructors
    Vec() {entries = NULL; N=0;}
    Vec(int,double value=0);
    Vec(int,double*);
    Vec(const Vec&);
    Vec(const vector<double>&);
    // operators
    void operator=(const Vec&);
    //void operator=(const double*);
    Vec operator+(const Vec&) const;
    void operator+=(const Vec&);
    Vec operator-(const Vec&) const;
    void operator-=(const Vec&);
    double operator[](int) const; // retorna o valor da entrada i do vec
    double& operator[] (int); // retorna a referencia para a entrada i
    Vec operator+(); //positivo do vector
    Vec operator-(); //negativo do vector
    Vec operator*(const Vec&) const;
    Vec operator*(const double) const;
    // methods
    int Size() const;
    double Norm() const; // norma-2 do vector
    double Dot(const Vec&) const; //produto interno com outro vector
    void Swap(int,int); //troca dois elementos
    void Print() const;
    int GetMax() const; // retorna o indice do valor maximo
    int GetMin() const; //retorna o indice do valor minimo
    double* GetArray() const;
    //--Memory Methods
    void SetEntries(const Vec&);
    void SetEntries(int, double);
    void SetEntries(int, double*);
    void SetEntries(vector<double>);
    void push_back(double);
    void push_front(double);
    void pop(int);
    // friend functions
    friend Vec operator*(const double, const Vec&);
    friend void Swap(Vec&, Vec&);
    // destructor
    virtual ~Vec() {delete[] entries;}
  private:
    int N; // Number of elements
    double* entries; // Pointer to array of doubles
};

#endif
