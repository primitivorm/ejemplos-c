#include <memory>
#include <iostream>
using namespace std;

struct S {
  S() { cout << "make an S\n"; }
  ~S() { cout << "destroy an S\n"; }
  S(const S&) { cout << "copy initialize an S\n"; }
  S& operator=(const S&) { cout << "copy assign an S\n"; }
};

S* f()
{
  return new S; // who is responsible for deleting this S?
};

auto_ptr<S> g()
{
  return auto_ptr<S>(
      new S); // explicitly transfer responsibility for deleting this S
}

int main()
{
  cout << "start main\n";
  S* p = f();
  cout << "after f() before g()\n";
  //	S* q = g();	// this error would be caught by the compiler
  auto_ptr<S> q = g();
  cout << "exit main\n";
  // leaks *p
  // implicitly deletes *q
}
