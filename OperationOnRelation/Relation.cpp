#include "Relation.hpp"
Relation::Relation(BooleanMatrix const & _matrix): matrix(_matrix) {

}

BooleanMatrix Relation::getBooleanMatrix() const {
	return matrix;
}

// Operations on Relations
Relation Relation::complementary() const {
	Relation temp(matrix);
	for(int i = 1; i <= matrix.getRow(); i++)
		for (int j = 1; j <= matrix.getColums(); j++) {
			if (matrix.getElement(i, j) == 1)
				temp.matrix.replace(0, i, j);
			else
				temp.matrix.replace(1, i, j);
		}
	return temp;
}
Relation Relation::inverse() const {
	BooleanMatrix _matrix(matrix.getColums(), matrix.getRow());
	for (int i = 1; i <= matrix.getRow(); i++)
		for (int j = 1; j <= matrix.getColums(); j++) {
			if (matrix.getElement(i, j) == 1)
				_matrix.replace(1, j, i);
		}
	Relation temp(_matrix);
	return temp;
}
Relation Relation::operator&(const Relation & dest) {
	Relation temp(matrix);
	temp.matrix = matrix & dest.matrix;
	return temp;
}
Relation Relation::operator|(const Relation & dest) {
	Relation temp(matrix);
	temp.matrix = matrix | dest.matrix;
	return temp;
}