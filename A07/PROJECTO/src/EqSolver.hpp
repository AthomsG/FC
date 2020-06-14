#ifndef EqSolver_hpp
#define EqSolver_hpp
#include "FCmatrixBanded.hpp" //inclui todos do ex 41 e 43

class EqSolver {
public:
    EqSolver();
    EqSolver(const FCmatrixFull&, const Vec&); // matriz M e vector de coefs
    EqSolver(const FCmatrixBanded&, const Vec&);
    ~EqSolver(){;}
    void SetConstants(const Vec&);
    void SetMatrix(const FCmatrixFull&);
    // numerical methods
    Vec GaussEliminationSolver();
    Vec LUdecompositionSolver_Doolittle();
    Vec TridiagonalSolver();
    Vec JacobiSolver(double tol = 1.E-6);
    // other methods
    void PrintM() {M.Print();}
    void Printb() {b.Print();}
private:
    FCmatrixFull GaussElimination(FCmatrixFull&, Vec&);
    Vec TridiagonalThomas(FCmatrixBanded &, Vec &);
    FCmatrixFull* LUdecomposition_Doolittle(FCmatrixFull&, Vec& vetor);
    //ELEMENTOS
    FCmatrixFull M; //matriz de coeffs
    Vec b; //vector de constantes
};

#endif
