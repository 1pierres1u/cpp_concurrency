#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
using namespace std;
int Tm;
void loop()
{ chrono::seconds timespan(2);
  this_thread::sleep_for(timespan);
}

void count()
{ while(Tm--)
  { thread t(loop);
    t.join();
  }
}

void count1()
{ vector<thread> T;
  while(Tm--)
  { T.push_back(thread(loop));
    T[T.size()-1].join();
  }
}
void count2()
{ vector<thread> T;
  while(Tm--)
  { T.push_back(thread(loop));
    T[T.size()-1].detach();
  }
}
void count3()
{ thread t1(loop);
  thread t2(loop);
  thread t3(loop);
  thread t4(loop);
  thread t5(loop);
  thread t6(loop);
  t1.join();
  t2.join();
  t3.join();
  t4.join();
  t5.join();
  t6.join();
}

int main()
{ cout << "Task Manager will let you see how many \nthreads are created.";
  int c=1;
  while(c)
  {cout << "\nChoose wait time: ";
   cin >> Tm;
   cout << "Choose program\nEnter [1,2,3,4]: ";
   cin >> c;
   if(c==1) count();
   else if(c==2) count1();
   else if(c==3) count2();
   else if(c==4) count3();
  }
}
