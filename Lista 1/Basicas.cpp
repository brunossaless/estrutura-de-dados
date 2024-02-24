#include <iostream>
#include <sstream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// using std::string;
// using std::cout;
// using std::cin;
void printar(vector<int> vet)
{
  cout << vet.at(0) << " ";
  if (vet.size() == 1)
    return;
  vet.erase(vet.begin());
  printar(vet);
};
void printarAoInverso(vector<int> vet)
{
  cout << vet.at(vet.size() - 1) << " ";
  if (vet.size() == 1)
    return;
  vet.pop_back();
  printarAoInverso(vet);
};

int soma(vector<int> vet, int start, int end)
{
  if (start == end)
    return vet.at(start);
  else
    return vet.at(start) + soma(vet, start + 1, end);
};

int multiplica(vector<int> vet, int start, int end)
{
  if (start == end)
    return vet.at(start);
  else
    return vet.at(start) * multiplica(vet, start + 1, end);
};
// int multiplica(vector<int> vet)
// {
//   if (vet.size() == 1)
//     return vet.at(vet.size() - 1);
//   else
//   {
//     int x = vet.at(vet.size() - 1) * multiplica(vet);
//     vet.pop_back();
//     return x;
//   }
// }
// ;
int menor(vector<int> vet, int index, int value)
{
  if (index < 0)
    return value;
  else if (vet.at(index) < value)
    value = vet.at(index);
  return menor(vet, index - 1, value);
};
int pos = 0;
void inversoVet(vector<int> &vet)
{
  copy(vet.begin(), vet.end(),
       ostream_iterator<int>(cout, " "));
  cout << endl;
};
int x = 0;
void invertee(vector<int> vet, int len, int x = 0)
{
  if (x >= len / 2)
  {
    cout << "inv : [ ";
    for (int i = 0; i < vet.size(); i++)
      cout << vet.at(i) << " ";
    cout << "]";
    return;
  }

  int aux = vet[x];
  vet[x] = vet[len - x - 1];
  vet[len - x - 1] = aux;
  invertee(vet, len, ++x);
};
int main()
{
  string line;
  getline(cin, line);
  stringstream ss(line);
  vector<int> vet;
  int valores;
  while (ss >> valores)
    vet.push_back(valores);
  cout << "vet : [ ";
  printar(vet);
  cout << "]";
  cout << endl;
  cout << "rvet: [ ";
  printarAoInverso(vet);
  cout << "]";
  cout << endl;
  cout << "sum : " << soma(vet, 0, vet.size() - 1) << endl;
  cout << "mult: " << multiplica(vet, 0, vet.size() - 1) << endl;
  cout << "min : " << menor(vet, vet.size() - 1, vet.at(0)) << endl;
  // vector<int> arr(vet.rbegin(), vet.rend());
  // inversoVet(arr);
  invertee(vet, vet.size(), 0);
}