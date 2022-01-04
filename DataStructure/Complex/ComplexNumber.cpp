#include "ComplexNumber.h"

double GetRealPart(ComplexNumber cn) {
	return cn.realpart;
}

double GetImagPart(ComplexNumber cn) {
	return cn.imagpart;
}

void Add(ComplexNumber cn1, ComplexNumber cn2, ComplexNumber &sum) {
	sum.realpart = cn1.realpart + cn2.realpart;
	sum.imagpart = cn1.imagpart + cn2.imagpart;
	return;
}

void Print(ComplexNumber cn) {
	printf("%lf + %lfi\n", cn.realpart, cn.imagpart);
	return;
}

ComplexNumber Subtract(ComplexNumber cn1, ComplexNumber cn2) {
	ComplexNumber diff;
	diff.realpart = cn1.realpart - cn2.realpart;
	diff.imagpart = cn1.imagpart - cn2.imagpart;
	return diff;
}
