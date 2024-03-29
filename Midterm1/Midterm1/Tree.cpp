#include<Quagga.h>
#include <Tree.h>

using std::cout;
using std::endl;
QuaggaTree::QuaggaTree()
{
  left = NULL;
  right = NULL;
  value = new Quagga();
}

QuaggaTree::QuaggaTree(const Quagga& q)
{
  left = NULL;
  right = NULL;
  value = new Quagga(q);
}

QuaggaTree::~QuaggaTree()
{
  delete left;
  if (right != NULL) delete right;
}

bool QuaggaTree::push(Quagga* qptr)
{
  if (0 == value->Name().compare("Uninitialized")) {
    value = qptr;
    return true;
  }
  cout << value->Name() <<"    comparison   " << qptr->Name() << endl;
  int lexical_comparison = value->Name().compare(qptr->Name());
  cout << lexical_comparison << endl;

  if (lexical_comparison < 0) {
    if (left) left->push(qptr);
    else left = new QuaggaTree(*qptr);
    cout << "left: "<< value->Name() << endl;
    return true;
  }
  else if (lexical_comparison > 0) {
    if (right) right->push(qptr);
    else right = new QuaggaTree(*qptr);
    cout << "right: "<< value->Name() << endl;
    return true;
  }
  return false;
}

ostream& QuaggaTree::print(ostream& ostr) const
{
  if (left) left->print(ostr);
  ostr << " " << value->Name();
  if (right) right->print(ostr);
  ostr << " ";
  return ostr;
}
