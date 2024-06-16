#include ".//bitarr.hpp"


int main()
{
    BitArray b(1, 10);
    BitArray a(2, 15);
    std::cout << "b arr\n";
    for (int i = 8 * b.size() - 1; i >= 0; i--){
      std::cout << b[i];
    }
    std::cout << "\na arr \n";
    for (int i = 8 * a.size() - 1; i >= 0; i--){
      std::cout << a[i];
    }
    a.swap(b);
    std::cout << "\nSWAP\n";
    std::cout << "b arr\n";
    for (int i = 8 * b.size() - 1; i >= 0; i--){
      std::cout << b[i];
    }
    std::cout << "\na arr \n";
    for (int i = 8 * a.size() - 1; i >= 0; i--){
      std::cout << a[i];
    }
    std::cout << "\n";
    std::cout << "string" << "\n";
    std::string c = a.to_string();
    std::cout << c << "\n";
    std::cout << a[3];
    // bool tr = a.any();
    // std::cout << tr << "\n";

}