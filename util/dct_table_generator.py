#!/usr/bin/env python3

from numpy import pi, cos, sqrt, zeros

coefficients = zeros((8, 8))

# Genereate the coefficient matrix
coefficients[0] = sqrt(0.125)
for j in range(1, 8):
	for i in range(8):
		coefficients[j][i] = 0.5*cos(i*(2*j + 1)*pi/16.0)

# Print out the matrix
print("{")
for j in range(8):
	print("   {", end = " ")
	for i in range(8):
		print("%ff" % coefficients[j][i], end = (", " if i != 7 else ""))
	print("}", end = ", \n" if j != 7 else "\n")
print("}")
