#include <stdio.h>

typedef struct {
	double realpart;
	double imagpart;
} ComplexNumber;

double GetRealPart(ComplexNumber cn);
double GetImagPart(ComplexNumber cn);
void Add(ComplexNumber cn1, ComplexNumber cn2, ComplexNumber &sum);
ComplexNumber Subtract(ComplexNumber cn1, ComplexNumber cn2);
void Print(ComplexNumber cn); 

