#include "GP.hpp"

using namespace oppt;

int main(int argc, char *argv[])
{
	oppt::GP gp;

	Matrixdf a(2, 2);
	a << 1.0, 0.0,
	     0.0, 1.0;
	Matrixdf b(2, 2);
	b << 1.0, 0.0, 
	     0.0, 1.0;
	gp.kernel(a, b);

}