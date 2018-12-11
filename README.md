# csr-formatter
C++ package to store Matrix Market (.mtx) file format sparse matrices in Compressed Sparse Row (CSR) format.

## About

Compressed Sparse Row is a matrix storaging technique that only cares about non-zero values in the matrix and, for that reason, it is more memory efficient than regular matrix storaging costs. Instead of storaging <a href="https://www.codecogs.com/eqnedit.php?latex=n^{2}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?n^{2}" title="n^{2}" /></a> elements, CSR format storages <a href="https://www.codecogs.com/eqnedit.php?latex=2nnz&space;&plus;&space;n&space;&plus;&space;1" target="_blank"><img src="https://latex.codecogs.com/gif.latex?2nnz&space;&plus;&space;n&space;&plus;&space;1" title="2nnz + n + 1" /></a> elements, where <a href="https://www.codecogs.com/eqnedit.php?latex=nnz" target="_blank"><img src="https://latex.codecogs.com/gif.latex?nnz" title="nnz" /></a> equals the number of non-zero elements in the matrix.

A simple explanation on the CSR format can be found in [netlib.org](http://netlib.org/linalg/html_templates/node91.html).

A nice collection of .mtx format matrices can be seen in [SuiteSparse Matrix Collection](https://sparse.tamu.edu/).

## Usage

Save [csr_formatter.h](csr_formatter.h) to your code directory and inform it as a header in your file.

```C++
#include "csr_formatter.h"
```

When dealing with a simetric matrix:
```C++
#include "csr_formatter.h"

int main(int argc, char* argv[]){
  CSR sym = assemble_simetric_csr_matrix("simetricMatrix.mtx");
}
```
Otherwise (asymmetric):
```C++
#include "csr_formatter.h"

int main(int argc, char* argv[]){
  CSR asym = assemble_csr_matrix("asymmetricMatrix.mtx");
}
```

Both functions will return a CSR object with the three characteristic csr format lists: col_ind, data and row_ptr.

Aditional functions that might be useful for the user were also implemented.

To obtain the matrix bandwidth, use:
```C++
#include "csr_formatter.h"

int main(int argc, char* argv[]){
  CSR asym = assemble_csr_matrix("asymmetricMatrix.mtx");
  cout << "Matrix bandwidth is " << getBandwidth(asym) << '\n';
}
```
To obtain the degree of a given vertex:
```C++
#include "csr_formatter.h"

int main(int argc, char* argv[]){
  CSR asym = assemble_csr_matrix("asymmetricMatrix.mtx");
  cout << "Degree of 2: " << getDegree(asym.row_ptr, 2) << '\n';
}
```

To obtain the adjacency list of a vertex:
```C++
#include "csr_formatter.h"

int main(int argc, char* argv[]){
  CSR asym = assemble_csr_matrix("asymmetricMatrix.mtx");
  cout << "Adjcents to 2: " << printArray(getAdjVertices(asym.col_ind, asym.row_ptr, 2)) << '\n';
}
```

Any doubts/suggestions, feel free to contact me.
