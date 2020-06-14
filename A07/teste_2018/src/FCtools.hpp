#ifndef FC_TOOLS_HPP
#define FC_TOOLS_HPP
#include <vector>
#include <string>

using namespace std;

class FCtools{
  public:
    FCtools() {;}
    vector<string> ReadFile2String(string); // file name, returns lines
    vector<Vec> ReadFile2Vec(string);// file name, returns vector of vecs
    Vec* ReadFile(string,int*); //file name, returns pointer to array of vecs
    ~FCtools() {;}
};

#endif
