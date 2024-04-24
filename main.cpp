#include "bitarr_dir/bitarr.hpp"


int main()
{
    BitArray b(4, 2);
    BitArray a(8, 5);
    std::cout << "b arr\n";
    for (int i = b.size() - 1; i >= 0; i--){
      std::cout << b[i];
    }
    std::cout << "\na arr \n";
    for (int i = a.size() - 1; i >= 0; i--){
      std::cout << a[i];
    }
    a.swap(b);
    std::cout << "\nSWAP\n";
    std::cout << "b arr\n";
    for (int i = b.size() - 1; i >= 0; i--){
      std::cout << b[i];
    }
    std::cout << "\na arr \n";
    for (int i = a.size() - 1; i >= 0; i--){
      std::cout << a[i];
    }
    std::cout << "\n";
    std::string c = a.to_string();
    std::cout << c << "\n";

    
    // bool tr = a.any();
    // std::cout << tr << "\n";

}