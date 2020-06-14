#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include "array2vec.hpp"

vector<int> array2vec(int size, int* arr)
{
  vector<int> v;

  for(int i=0; i<size; i++)
  {
    v.push_back(arr[i]);
  }
  return v;
}

// order = +/- 1 -> ordem crescente (+) ou descrescente (-)
vector<int> array2vecs(int size, int* arr, int order)
{
  vector<int> vsort = array2vec(size,arr);
  if(order>0)
  {
    sort(vsort.begin(),vsort.end());
  } else{
    sort(vsort.begin(),vsort.end(),greater<int>());
  }

  return vsort;
}

void print_vec(vector<int> vec, int size)
{
  for(int i=0; i<size; i++)
  {
    cout << vec[i] << " ";
  }
  cout << endl;
}

int array2vecmax(int size,int* arr)
{
  vector<int> vec = array2vec(size,arr);
  int max = *max_element(vec.begin(),vec.end());
  return max;
}

int array2vecfind(int size,int* arr,int value)
{
  vector<int> vec = array2vec(size,arr);
  vector<int>::iterator itr = find(vec.begin(),vec.end(),value);
  int index = distance(vec.begin(),itr);
  return index;
}
