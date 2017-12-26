#include <iostream>
#include <memory>

class Observed {
public:
  Observed() { std::cout << "Observed::Constructor\n"; }
  ~Observed() {
    // vlog
    std::cout << "Observed::Deconstructor\n";
  }
  Observed(const Observed &) { std::cout << "Observed::CopyConstructor\n"; };

  Observed &operator=(const Observed &) {
    std::cout << "Observed::CopyAssignment\n";
  };
};

void tete(Observed & arg) {
    std::cout << "xd" << (long) &arg << "\n";
}

int main() {
  std::cout << "Starting\n";
  Observed ob;
  tete(ob);
  return 0;
}
