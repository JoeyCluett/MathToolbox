#define __USE__STD__LIBS__
#include <lib/MathToolbox.hpp> // now a single include for the entire library
NAMESPACE_RESOLUTION;

int main(int argc, char* argv[]) {

	FixedLoan fl {200000, 6.5, 360};

	cout << PaymentInfo(fl) << endl; // $200,000 principle, 6.5% interest, 30 years (360 months)
	return 0;
}
