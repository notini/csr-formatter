#include "../csr_formatter.h"

int main(int argc, char* argv[]){
	
	/* File informed as a param. */
	cout << "File informed: " << argv[1] << '\n';
	CSR asym = assemble_csr_matrix(argv[1]);

	cout << "Tests for asymetric matrix \n";
	
	cout << "Matrix bandwidth is " << getBandwidth(asym) << '\n';
	
	cout << "Degree of 2: " << getDegree(asym.row_ptr, 2) << '\n';
	
	cout << "Adjs to 2: ";
	printArray(getAdjVertices(asym.col_ind, asym.row_ptr, 2));
	
	/* Uncomment these lines case you want to work with simetric matrices. */
	
	/*cout << " \n \n \n Tests for symmetric matrix \n";
	CSR sim = assemble_simetric_csr_matrix(argv[1]);
	
	cout << "Matrix bandwidth is " << getBandwidth(sym) << '\n';
	
	cout << "Degree of 2: " << getDegree(sym.row_ptr, 409) << '\n';
	
	cout << "Adjs to 2: ";
	printArray(getAdjVertices(sym.col_ind, sym.row_ptr, 409));	
	*/
		
	
}