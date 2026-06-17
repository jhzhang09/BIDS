#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
using namespace std;

template <typename T>
void print_all(const T& S)
{
  for (const auto& x : S)
    cout << x << ' ';
  cout << endl;
}

int main()
{
  vector<int> A {1, 2, 3};
  vector<int> B {2, 4};
  vector<int> C(A.size() + B.size());
  auto va = A.begin();
  auto vb = B.begin();
  size_t i = 0;
  // 注意所归并的两个元素相等时得优先考虑向量A中的元素.
  while (va != A.end() && vb != B.end())
      C[i++] = *vb < *va ? *vb++ : *va++;
  while (va != A.end())
    C[i++] = *va++;
  while (vb != B.end())
    C[i++] = *vb++;
  print_all(C);
  merge(A.begin(), A.end(), B.begin(), B.end(), C.begin());
  print_all(C);
  auto vc = C.begin();
  for (va = A.begin(); va != A.end(); ++va)
    *vc++ = *va;
  auto vm = vc;
  for (vb = B.begin(); vb != B.end(); ++vb)
    *vc++ = *vb;
  inplace_merge(C.begin(), vm, C.end());
  print_all(C);
  list<string> D {"Kruskal", "Prim"};
  list<string> E {"Dijkstra", "Floyd", "Warshall"};
  auto ld = D.begin();
  auto le = E.begin();
  // 注意所归并的两个元素相等时得优先考虑链表D中的元素.
  while (ld != D.end() && le != E.end())
    if (*le < *ld)
      D.insert(ld, *le++);
    else
      ++ld;
  D.insert(ld, le, E.end());
  print_all(D);
  return 0;
}
