#include <iostream>
#include <thread>
#include <chrono>
#include <vector> 
using namespace std;

int Tm=0;

struct A
{ int i=0;
  void operator()()
  { i++;
    cout << i << " ";
  }
};

void increment_by_value()
{ vector<thread> T;
  A as;
  Tm = 10;
  while(Tm--)
  { T.push_back(thread(as));
    T[T.size()-1].join();
  }
}


void increment_by_reference()
{ vector<thread> T;
  A as;
  Tm = 10;
  while(Tm--)
  { T.push_back(thread(ref(as)));
    T[T.size()-1].join();
  }
}
/*
void increment_by_reference_1()
{ vector<thread> T;
  A as;
  Tm = 10;
  while(Tm--)
  { T.push_back(thread(&as)); error &as
    T[T.size()-1].join();
  }
}
*/

int main()
{ int i=1;
  cout << "Create a thread with variable passed by value and reference.";
  while(i)
  { cout << "\nChoose program [1,2]:";
    cin >> i; 
    if(i==1) increment_by_value();
    else if(i==2) increment_by_reference();
  }
}
