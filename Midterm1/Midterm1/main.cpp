
#include <iostream>
#include<Quagga.h>
#include<Tree.h>
#include <fstream>

using std::cerr;
using std::endl;
using std::cout;

Quagga passobj(){

  Quagga quag2 = Quagga("temp");
  // ptr = &quag2;
  // Quagga *e = new Quagga("this one");
  return quag2;
}

int passbyref(Quagga *p){
  Quagga *s = p;
  cout << s->Name() << endl;
  return 1;
}

int main(int argc, char* argv[]){
  Quagga *q1 = new Quagga("c");
  Quagga *q2 = new Quagga("b");
  Quagga q3 = Quagga("d");
  Quagga q0 = Quagga("a");
  QuaggaTree tree = QuaggaTree(q0);
  tree.push(q1);
  tree.push(q2);
  tree.push(q1);
  Quagga q4 = Quagga();
  tree.push(&q4);

  // std::filebuf fb;
  // fb.open("output.txt", std::ios::out);
  // std::ostream strg(&fb);
  // cout << tree.left << endl;

  cout << tree.print(std::cout) << endl;
  tree.push(&q3);
  // tree.print(str);
  tree.print(std::cout) << endl;


  delete q1;
  delete q2;

  // Quagga *q = new Quagga("jake");
  // cout << "q = " << &q << endl;
  // cout << q->Name() << endl;
  // Quagga *r = new Quagga();
  // cout << r->Name() << endl;
  // cout << "r = " << &r << endl;
  // Quagga *p = new Quagga(*q);
  // cout << "p = " << &p << endl;
  // Quagga *t = new Quagga(*q);
  // cout << "t = " << &t << endl;
  // cout << p->Name() << endl;
  // passbyref(p);
  // cout << passobj().Name() << endl;
  // Quagga quag = Quagga("nto pointer");
  // cout << quag.Name() << endl;
  // Quagga quag1;
  // cout << quag1.Name() << endl;
  // delete p;
  // delete r;
  // delete t;

	return 1;
}
