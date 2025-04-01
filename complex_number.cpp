#include <iostream>
#include "complex_number.hpp"

int main() {
    complex_number<double> z1(1.0, 2.0);
    complex_number<double> z2(3.0, -1.0);
    complex_number<double> z3(0.0, -5.0);

    std::cout << "z1 = " << z1 << "\n";
    std::cout << "z2 = " << z2 << "\n";
    std::cout << "z3 = " << z3 << "\n";
	
	
	complex_number<double> sum = z1 + z2; 
/* faccio prima la somma non distruttiva affinchè i riultati siano coerenti. 
Se usassi prima l'operazione += e poi + allora il secondo + mi restituirebbe 
ad esempio: z1 += z2 ----> restituisce z1 aggiornato
			se poi faccio z1 +z2 ora è come se facessi z1 +z2 + z2 ,
			e non è ciò che voglio*/


	

    std::cout << "z1 + z2 = " << sum << "\n"; 

	z1 += z2;

    std::cout << "z1 dopo l'operazione += z2: " << z1 << "\n";
	
	
	
	complex_number<double> z4(2.0, 3.0);
	complex_number<double> z5(4.0, -1.0);

	complex_number<double> prod = z4 * z5;              // IDEM con * e *=
	std::cout << "z4 * z5 = " << prod << "\n";
	

	z4 *= z5;
	std::cout << "z4 dopo z4 *= z5: " << z4 << "\n";
	
	
	
// Test per la commutratività e per complex + T e viceversa
std::cout << "Test per la commutratività e per complex + T e viceversa" << "\n";

complex_number<double> z(1.0, 2.0);

std::cout << "z + 3.0 = " << z + 3.0 << "\n"; 
std::cout << "3.0 + z = " << 3.0 + z << "\n"; 

std::cout << "z * 2.0 = " << z * 2.0 << "\n"; 
std::cout << "2.0 * z = " << 2.0 * z << "\n"; 

z += 5.0;
std::cout << "z dopo z += 5.0: " << z << "\n";

z *= 2.0;
std::cout << "z dopo z *= 2.0: " << z << "\n"; // ----> sto usando z aggiornato (ne sono consapevole)


	
	
	

	

    return 0;
}
