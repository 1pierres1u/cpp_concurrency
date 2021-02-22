#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <thread>
#include <algorithm>
using namespace std;

struct SortBatch 
{ vector<vector<int>> * batch;
  int i; //index of next vector to sort
  SortBatch():i(0),batch(nullptr)
  { 
  }
  SortBatch(vector<vector<int>> * b):batch(b),i(0)
  {
  }
  void set_batch(vector<vector<int>>* b)
  { batch = b; 
    i=0;
  }
  void  operator()()
  { if(i<batch->size())
    { cout << "sorting vector " << (i) << endl;
      sort((*batch)[i].begin(),(*batch)[i].end());
    }
  }
  bool stop()
  { return (i==batch->size());
  }
  void next_one()
  { i++;
  }
};

struct Runner
{ SortBatch sb;
  vector<thread> T;
  Runner()
  {
  }
  Runner(vector<vector<int>>* s):sb(SortBatch(s))
  {
  }
  void sort()
  { T.clear();
    while(!sb.stop())
    {  T.push_back(thread(sb));
       T[T.size()-1].detach();
       sb.next_one();
    }
  }
};
void generate(vector<vector<int>> * v, size_t no_vectors, size_t size_vector)
{ v->clear();
  *v = vector<vector<int>>(no_vectors);
  while(no_vectors--)
  { size_t Ma=size_vector;
    (*v)[no_vectors].reserve(size_vector);
    while(Ma--)
    {(*v)[no_vectors].push_back(rand()%size_vector);
    }
  }
}
int main()
{ vector<vector<int>> s{{9,1,3,1,5},{0,1,9,2,8,3},{5,6,1,0,3,8}};
  cout << "Sorting Vectors In Parallel\n";
  cout << "enter number of vectors: ";
  size_t no_vectors,size_vectors;
  cin >> no_vectors;
  cout << "enter size of vectors: ";
  cin >> size_vectors;
  generate(&s,no_vectors,size_vectors);
  Runner r(&s);
  r.sort();  
  for(int i=0; i<s.size(); i++)
  { for(auto& x: s[i])
    { cout << x  << " ";
    }
    cout << endl;
  }
}
