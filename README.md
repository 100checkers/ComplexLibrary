This project uses a complex class that has re and im as private variables to represent the two parts of a complex number.
Default constructors as well as constructors that take in different parameters (two values (imag and real) or one value (real) or none)

Member functions for +=, -=, /=, and *= help perform the operations based off whether an object is being operated on another object,
or whether an object is being operated on a non-object/regular number

The *this pointer is returned after performing the operations because each operator will call one of the member helper function

This project works to mimic actions that are performed by the <complex> library
The various helper functions demonstrate many of the operations that can be performed on the complex numbers

Test cases were also implemented following the example test cases to help ensure things work as expected
Assertx was used as well as a throw and catch block to help output any errors
