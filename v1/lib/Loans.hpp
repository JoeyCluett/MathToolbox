#ifndef __JJC__LOANS__HPP__
#define __JJC__LOANS__HPP__

#include <cmath>
#include <lib/MathToolbox.hpp>

struct FixedLoan {
	RealValue principle, apr, months;
};

struct LoanPayment {
	RealValue monthly, total, total_interest;

	friend std::ostream& operator<<(std::ostream& os, const LoanPayment& lp) {
		os << "[\n    Monthly payment: $" << lp.monthly << "\n    Total owed: $" 
				<< lp.total << "\n    Interest payed: $" << lp.total_interest << "\n]";
		return os;
	}

};

RealValue MonthlyPaymentFixed(RealValue principle, RealValue apr, RealValue months) {
	RealValue r = apr / 100.0 / 12.0;
	RealValue c = r * principle;
	RealValue den = 1.0 - std::pow(1.0 + r, -months);
	c /= den;

	return c;
}

RealValue MonthlyPaymentFixed(FixedLoan& fl) {
	return MonthlyPaymentFixed(fl.principle, fl.apr, fl.months);
}

LoanPayment PaymentInfo(RealValue principle, RealValue apr, RealValue months) {
	RealValue monthly = MonthlyPaymentFixed(principle, apr, months);
	RealValue total = monthly * months;
	RealValue interest = total - principle;

	return {monthly, total, interest};
}

LoanPayment PaymentInfo(FixedLoan& fl) {
	return PaymentInfo(fl.principle, fl.apr, fl.months);
}

#endif // __JJC__LOANS__HPP__