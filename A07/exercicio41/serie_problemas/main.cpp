#include <iostream>
#include <vector>
using namespace std;
#include "Vec.hpp"
#include "FCtools.hpp"
// #include "TH2F.h"
// #include "TH1F.h"
// #include "TCanvas.h"
// #include "TFrame.h"

#define SEPARATOR "\n\n--------------\n"

int main()
{
  /*Vec a(5);
  a.Print();

  cout << SEPARATOR;

  Vec b(5,1.4);
  b.Print();

  cout << SEPARATOR;

  double arr[]= {1.4,5.6,-7.8,1.2,0.0};
  Vec c(5,arr);
  c.Print();

  cout << SEPARATOR;

  Vec d(b);
  d.Print();

  cout << SEPARATOR;

  double CM[][5] = {{1,7,5,3,-3},{5,2,8,-2,4},{1,-5,-4,6,7.6},{0,-5,3,3.2,3.3},{1,7,2,2.1,1.2}};
  Vec cv[5];
  for(int i =0; i<5; i++)
  {
    cv[i].SetEntries(5,CM[i]);
    cv[i].Print();
  }

  cout << SEPARATOR;

  Vec e(5,2);
  e-=b;
  e.Print();

  cout << SEPARATOR;

  cout << "cv[0][3] = " << cv[0][3] << endl;
  cv[0][0]=12; cv[0][1]=3.4; cv[0][2]=67;

  Vec f(5,2);
  f.Print();

  cout << SEPARATOR;

  f=3.5*f*(2/7.0);
  cout << "\n\n\n\n THIS IS IT \n\n\n";
  f.Print();
  cout << "\n\n\n\n THAT WAS IT \n\n\n";

  cout << SEPARATOR;

  cout << "Dot product of (0,.5,3,3.2,3.3) and (2,2,2,2,2)= " << f.Dot(cv[3]);

  cout << SEPARATOR;

  f.Swap(1,2);
  f.Print();

  cout << SEPARATOR;

  f=-f;
  f.Print();

  cout << SEPARATOR;

  Vec g(3);
  g[0]=67; g[1]=12; g[2]=-18;
  cout << g.Norm() << endl;
  cout << g[g.GetMax()]-g[g.GetMin()] << endl;

  cout << SEPARATOR;

  //colocar ficheiro com matriz na directoria do makefile

  FCtools file;
  vector<Vec> from_file = file.ReadFile2Vec("matrix.txt");


  for(int i=0; i<from_file.size();i++) { from_file[i].Print();}

  cout << SEPARATOR;

  g.SetEntries(f);
  g.Print();

  cout << SEPARATOR;
*/
  FCtools file;
  int file_size=0;
  Vec* vequi = file.ReadFile("matrix.txt",&file_size);
  for(int i =0; i<file_size; i++) { vequi[i].Print();}

  cout << SEPARATOR;

  double* get_array=vequi[3].GetArray();
  Vec hooray(file_size,get_array);
  hooray.Print();

  delete[] vequi;
  delete[] get_array;



  // TH2F* h2 = new TH2F("Histograma 2","H2",5,1,5,5,1,5);
  //  for(int i=0; i<5; i++)
  //  {
  //    for(int j =0; j<5; j++)
  //    {
  //      h2->Fill(i,j,vequi[i][j]);
  //    }
  //  }
  //
  // TCanvas * c1 = new TCanvas("c1","c1",200,10,600,400);
  // c1->SetFillColor(0);
  // c1->SetGrid();
  // h2->Draw();
  // c1->Update();
  // c1->GetFrame()->SetFillColor(0);
  // c1->GetFrame()->SetBorderSize(8);
  // c1->Modified();
  // c1->SaveAs("Matrix.eps");

  // delete h2;
  // delete c1;
  return 0;
}
