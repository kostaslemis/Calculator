#include "Matrix.h"


int main (void) {

    Matrix a(2, 2);
    a(1, 1) = 1; a(1, 2) = 0;
    a(2, 1) = 0; a(2, 2) = 1;

    Matrix b(2, 2);
    b(1, 1) = 1; b(1, 2) = 0;
    b(2, 1) = 0; b(2, 2) = 1; 

    std::cout << a << std::endl;

    std::cout << b << std::endl;

    Matrix sum = a + b;
    std::cout << sum << std::endl;


    std::cout << det(sum) << std::endl;
    
    std::cout << std::boolalpha << (a == b) << std::endl;

    Matrix I_2_2 = identity_matrix(3);
    std::cout << I_2_2 << std::endl;

    std::cout << std::boolalpha << equalRowsCols(a, b) << std::endl;

    return EXIT_SUCCESS;
}
