#include "ComplexNumber.h"

int main() {
	ComplexNumber a, b, sum, diff;

	a.realpart = 20;
	a.imagpart = 35;
	Print(a);
	
	b.realpart = 16;
	b.imagpart = 54;
	Print(b);

	Add(a, b, sum);
	Print(sum);

	diff = Subtract(a, b);
	Print(diff);

	return 0;
}
