#include "GP.hpp"

namespace oppt {
GP::GP() {

}

Matrixdf GP::kernel(const Matrixdf &a, const Matrixdf &b) const {
	FloatType sigma = 0.1;
	Matrixdf k(a.rows(), b.rows());
	for (size_t i = 0; i != a.rows(); ++i) {
		for (size_t j = 0; j != b.rows(); ++j) {
			k(i, j) = kernelFunction_(a.row(i), b.row(j), sigma);
		}
	}

	return k;
}

Vectordf GP::mean(const Vectordf &data) const {
	return data.mean();
}

FloatType GP::kernelFunction_(const Vectordf &v1, const Vectordf &v2, const FloatType &sigma) const {
	return exp(-(v1 - v2).squaredNorm() / (2.0 * sigma *sigma));

}

}