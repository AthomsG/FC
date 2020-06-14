#ifndef EqSolver_hpp
#define EqSolver_hpp

class EqSolver {
public:
    EqSolver();
    EqSolver(const FCmatrixFull&, const Vec&); // matriz M e vector de coefs
    EqSolver(const FCmatrixBanded&, const Vec&);
    ~EqSolver(){;}
    void SetConstants(const Vec&);
    void SetMatrix(const FCmatrixFull&);
    Vec GaussEliminationSolver();
    Vec LUdecompositionSolver_Doolittle();
    Vec TridiagonalSolver();
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
