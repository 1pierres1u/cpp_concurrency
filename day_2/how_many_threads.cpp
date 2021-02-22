#include <iostream>
#include <vector>
#include <thread>
using namespace std;
void loop()
{ while(true) int a=0;
}

void count()
{ while(true)
  { thread t(loop);
    t.join();
  }
}

void count1()
{ vector<thread> T;
  while(true)
  { T.push_back(thread(loop));
    T[T.size()-1].join();
  }
}
void count2()
{ vector<thread> T;
  while(true)
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
  cout << "Choose program\nEnter [0,1,2,3]: ";
  int c=0;
  cin >> c;
  if(c==0) count();
  else if(c==1) count1();
  else if(c==2) count2();
  else if(c==3) count3();
}
