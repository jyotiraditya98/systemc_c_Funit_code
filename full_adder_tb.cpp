#include <systemc.h>
#include "full_adder.cpp"

int sc_main(int argc, char *argv[]) {
  sc_signal<bool> a, b, cin, sum, cout;

  full_adder fa("fa");
  fa.a(a);
  fa.b(b);
  fa.cin(cin);
  fa.sum(sum);
  fa.cout(cout);

  // Initialize the inputs
  a = true;
  b = false;
  cin = true;

  sc_start();

  // Print the results
  cout << "sum: " << sum << endl;
  cout << "cout: " << cout << endl;

  return 0;
}
