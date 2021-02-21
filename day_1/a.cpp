#include <iostream>
#include <thread>

using namespace std;

/* output 
 * thread1 and thread2 are sometimes
 * displayed on the same line.
  */
void loop()
{ while(true)
	cout << "thread 1" << endl;
}
void loop1()
{ while(true)
	cout << "thread 2" << endl;
}
void example()
{ thread t(loop);
  thread t1(loop1);
  t.join();
  t1.join();
}
/***/
/* output 
 * thread 1 and thread 2 are no longer 
 * displayed on the same line.
 */
void loop2()
{ while(true) cout << "thread 1 \n";
}
void loop3()
{ while(true) cout << "thread 2 \n";
}
void example1()
{ thread t(loop2);
  thread t1(loop3);
  t.join();
  t1.join();
} 
/**********************************/
/* does not let me enter any value. thread t
 * is the only one being executed.
 */
void example2()
{ thread t(loop2);
  t.join();
  int x;
  while(true) cin >> x;
} 
/***/
/* same as before only loop2 is executed.
 */
void example3()
{ thread t(loop2);
  t.detach();
  int x;
  while(true) cin >> x;
}
/***/
/* MISTAKE: SINCE THE FIRST EXAMPLE IT WAS POSSIBLE TO 
 * ENTER THE VALUE. AS BOTH THREADS ARE BEING EXECUTED
 * THERE WON'T BE A BREAK IN THE DISPLAY OF THREAD 1.
 */
void read()
{ string x;
  while(true) cin >> x;
}
void example4()
{ thread t(loop2);
  thread t1(read);
  t.join();
  t1.join();
}
/**************************************/
/* the execution of thread read stops after the 
 * display of the message.*/
void example5()
{ thread t(read);
  t.detach();
  cout << "Bye!\n";
}
/***/
void example6()
{ thread t(read);
  t.join();
  cout << "Bye!\n";
}
/***/
/* the detached thread still lives as the main thread
 * is still alive
 */
void example7()
{ example5();
  while(true);
}
int main()
{ example7();
}
