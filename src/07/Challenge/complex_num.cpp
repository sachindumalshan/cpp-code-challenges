#include "complex_num.h"

complex_num::complex_num(double r, double i){
    real = r;
    imaginary = i;
}

complex_num complex_num::operator +(complex_num w){
    complex_num z;
    z.real = real + w.real;
    z.imaginary = imaginary + w.imaginary;
    return z;
}

complex_num complex_num::operator -(complex_num w){
    complex_num z;
    z.real = real - w.real;
    z.imaginary = imaginary - w.imaginary;
    return z;
}

complex_num complex_num::operator *(complex_num w){
    complex_num z;
    z.real = (real * w.real) - (imaginary * w.imaginary); //ac - bd            z.real = (real * w.real) - (imaginary * w.imaginary);
    z.imaginary = (real * w.imaginary) + (imaginary * w.real); //ad+bc         z.imaginary = (real * w.imaginary) + (imaginary * w.real);
    return z;
}

complex_num complex_num::operator /(complex_num w){
    double com = w.real*w.real + w.imaginary*w.imaginary;
    complex_num z;
    // ((ac+bd)/(c^2+d^2)) + i((bc-ad)/(c^2+d^2))
    z.real = (real * w.real + imaginary * w.imaginary) / com;
    z.imaginary = (imaginary * w.real - real * w.imaginary) / com ;

    return z;
}

void complex_num::print(std::ostream &os){
    if(imaginary >= 0.0)
        os << real << " + " << imaginary << "i";
    else
        os << real << " - " << imaginary * -1 << "i";
    os << std::flush;
}