/*#ifndef COMPLEX_NUMBER_HPP
#define COMPLEX_NUMBER_HPP*/    
// metodo classico


#pragma once   // Metodo nuovo 

#include <iostream>
#include <concepts>

template<typename T>
    requires std::floating_point<T>
class complex_number {
private:
    T m_real;
    T m_imag;

public:
    // Costruttore di default
    complex_number()
        : m_real(0), m_imag(0) {}

    // Costruttore con real e imag ----(user-defined)
    complex_number(T real, T imag)
        : m_real(real), m_imag(imag) {}

    // Metodi getter
    T real() const { return m_real; }
    T imag() const { return m_imag; }

    // Metodo coniugato
    complex_number conjugate() const {
        return complex_number(m_real, -m_imag);
    }



//SOMME
    // Operatore += 
	complex_number& operator+=(const complex_number& other) {
    m_real += other.m_real;
    m_imag += other.m_imag;
    return *this;
}



    //Operatore +  ( che non è distruttivo) 
	complex_number operator+(const complex_number& other) const 
	
	{
    complex_number result = *this;
    result += other;
    return result;
	
}


	// Operatore += con T 
	complex_number& operator+=(T value) {
        m_real += value;
        return *this;
    }
  
  
	//Operatore + con T
	complex_number operator+(T value) const {
        complex_number result = *this;
        result += value;
        return result;
    }
	
	
	
//MOLTIPLICAZIONI	
  
  
	//Operatore *=
	complex_number& operator*=(const complex_number& other) {
    T a = m_real;
    T b = m_imag;
    T c = other.m_real;
    T d = other.m_imag;

    m_real = a * c - b * d;
    m_imag = a * d + b * c;

    return *this;
}
 
 
	// Operatore * (prodotto non distruttivo)
	complex_number operator*(const complex_number& other) const {
    complex_number result = *this;
    result *= other;
    return result;
}


	// Operatore *= con T
	complex_number& operator*=(T value) {
        m_real *= value;
        m_imag *= value;
        return *this;
    }
	
	
	
	//Operatore * con T 
	complex_number operator*(T value) const {
        complex_number result = *this;
        result *= value;
        return result;
    }



};

	

// Parte 2


// Overload dell'operatore <<
template<typename T>
std::ostream& operator<<(std::ostream& os, const complex_number<T>& c) {
    os << c.real(); // parte reale

    // parte immaginaria con segno corretto
    if (c.imag() >= 0)
        os << "+" << c.imag();
    else
        os << c.imag();  // già contiene il segno meno

    os << "i";
    return os;
}


//Commutatività per il +

template<typename T>
    requires std::floating_point<T>
complex_number<T> operator+(const T& value, const complex_number<T>& c) {
    return c + value;
}


//Commutatività per il *
template<typename T>
    requires std::floating_point<T>
complex_number<T> operator*(const T& value, const complex_number<T>& c) {
    return c * value;
}









 /// #endif // COMPLEX_NUMBER_HPP  ( metodo vecchio; ho usato #pragma once)
 
