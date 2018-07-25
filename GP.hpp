#ifndef _OPPT_GP_HPP_
#define _OPPT_GP_HPP_
#include <oppt/opptCore/core.hpp>

namespace oppt {

class GP {
public:
	GP();

	Matrixdf kernel(const Matrixdf &a, const Matrixdf &b) const;

	Vectordf mean(const Vectordf &data) const;

private:
	FloatType kernelFunction_(const Vectordf &v1, const Vectordf &v2, const FloatType &sigma) const;

};

}

#endif