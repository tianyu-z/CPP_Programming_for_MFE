// (C) Datasim Education BV 2005
//

#ifndef ParabolicIBVP_HPP
#define ParabolicIBVP_HPP

namespace ParabolicIBVP
{

	// Coefficients of PDE equation
	double (*sigma)(double x, double t); // Diffusion term
	double (*mu)(double x, double t);	 // Convection term
	double (*b)(double x, double t);	 // Free term
	double (*f)(double x, double t);	 // The forcing term term


	// (Dirichlet) boundary conditions
	double (*BCL)(double t);	 // The left-hand boundary condition
	double (*BCR)(double t);	 // The right-hand boundary condition

	// Initial condition
	double (*IC)(double x);		// The condition at time t = 0

}

#endif