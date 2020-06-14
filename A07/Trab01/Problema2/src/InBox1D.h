#ifndef H_InBox1D_H
#define H_InBox1D_H

#include <iostream>
#include <vector>
using namespace std;

class InBox1D {

public:
	InBox1D(double* x0, double* v0, double* m, double alpha=0.99);
	InBox1D(const InBox1D &);
	void StepInTime(double dt); //time step both x and v by dt seconds
	double* GetX() const; //Get x value
	double* GetV() const; //Get v value
	double GetALPHA() const; //Get the velocity damping value
	int GetN() {return Ncollisions;}
private:
	double* m; // mass _ M1 AND M2
	double* x; //position - X1 AND X2
	double* v; //velocity with sign - V1 AND V2
	double alpha;  //velocity damping coefficient
	bool hasreflected; //if particle bounced on any of the walls
	bool collision; //if particle bounced on any of the walls
	int Ncollisions = 0; //nr of collisions (including reflections)
	void AdvanceX(double); //time step x
	void AdvanceV(double); //time step v
};
#endif
