#include "BinaryRelation.hpp"
int BinaryRelation::getSetElePos(int temp) {
	for (int i = 0; i < set.getSize(); i++) {
		if (set.getMembers()[i] == temp)
			return i;
	}
}
BinaryRelation::BinaryRelation(BooleanMatrix const &m, Set const &s): Relation(m) {
	set = s;
}
int BinaryRelation::inDegree(int temp) {
	int pos = getSetElePos(temp) + 1, re = 0;
	for (int i = 1; i <= getBooleanMatrix().getRow(); i++) {
		if (getBooleanMatrix().getElement(i, pos) == 1)
			re++;
	}
	return re;
}
int BinaryRelation::outDegree(int temp) {
	int pos = getSetElePos(temp) + 1, re = 0;
	for (int i = 1; i <= getBooleanMatrix().getColums(); i++) {
		if (getBooleanMatrix().getElement(pos, i) == 1)
			re++;
	}
	return re;
}

BinaryRelation BinaryRelation::pathOfLength(int path) {
	BinaryRelation temp(getBooleanMatrix(), set);
	if (path == 0)
		return temp;
	BooleanMatrix temp_mat = temp.getBooleanMatrix();
	while (--path) {
		temp.matrix = temp.matrix.BooleanProduct(temp_mat);
	}
	return temp;
}

// Properties of Relations.    
bool BinaryRelation::isReflexive() const {
	for (int i = 1; i <= getBooleanMatrix().getRow(); i++) {
		for (int j = 1; j <= getBooleanMatrix().getColums(); j++) {
			if (i == j && getBooleanMatrix().getElement(i, j) != 1)
				return 0;
		}
	}
	return 1;
}
bool BinaryRelation::isIrreflexive() const {
	for (int i = 1; i <= getBooleanMatrix().getRow(); i++) {
		for (int j = 1; j <= getBooleanMatrix().getColums(); j++) {
			if (i == j && getBooleanMatrix().getElement(i, j) == 1)
				return 0;
		}
	}
	return 1;
}
bool BinaryRelation::isSymmetric() const {
	for (int i = 1; i <= getBooleanMatrix().getRow(); i++) {
		for (int j = 1; j <= getBooleanMatrix().getColums(); j++) {
			if (getBooleanMatrix().getElement(i, j) == 1 &&
				getBooleanMatrix().getElement(j, i) != 1)
				return 0;
		}
	}
	return 1;
}
bool BinaryRelation::isAsymmetric() const {
	for (int i = 1; i <= getBooleanMatrix().getRow(); i++) {
		for (int j = 1; j <= getBooleanMatrix().getColums(); j++) {
			if (getBooleanMatrix().getElement(i, j) == 1 &&
				getBooleanMatrix().getElement(j, i) == 1)
				return 0;
		}
	}
	return 1;
}
bool BinaryRelation::isAntisymmetric() const {
	for (int i = 1; i <= getBooleanMatrix().getRow(); i++) {
		for (int j = 1; j <= getBooleanMatrix().getColums(); j++) {
			if (i != j && getBooleanMatrix().getElement(i, j) == 1 &&
				getBooleanMatrix().getElement(j, i) == 1)
				return 0;
		}
	}
	return 1;
}
bool BinaryRelation::isTransitive() const {
	for (int i = 1; i <= getBooleanMatrix().getRow(); i++) {
		for (int j = 1; j <= getBooleanMatrix().getColums(); j++) {
			for (int s = 1; s <= getBooleanMatrix().getRow(); s++)
				if (getBooleanMatrix().getElement(i, j) == 1 &&
					getBooleanMatrix().getElement(j, s) == 1 &&
					getBooleanMatrix().getElement(i, s) != 1)
					return 0;
		}
	}
	return 1;
}

bool BinaryRelation::isEquivalence() const {
	if (isReflexive() && isSymmetric() && isTransitive())
		return 1;
	return 0;
}

BinaryRelation BinaryRelation::composition(const BinaryRelation & m) {
	BinaryRelation temp(matrix, set);
	temp.matrix = m.matrix.BooleanProduct(matrix);
	return temp;
}

BinaryRelation BinaryRelation::reflexiveClosure() const {
	BinaryRelation temp(matrix, set);
	for (int i = 1; i <= getBooleanMatrix().getRow(); i++) {
		for (int j = 1; j <= getBooleanMatrix().getColums(); j++) {
			if (i == j && getBooleanMatrix().getElement(i, j) != 1)
				temp.matrix.replace(1, i, j);
		}
	}
	return temp;
}
BinaryRelation BinaryRelation::symmetricClosure() const {
	BinaryRelation temp(matrix, set);
	for (int i = 1; i <= getBooleanMatrix().getRow(); i++) {
		for (int j = 1; j <= getBooleanMatrix().getColums(); j++) {
			if (getBooleanMatrix().getElement(i, j) == 1 &&
				getBooleanMatrix().getElement(j, i) != 1)
				temp.matrix.replace(1, j, i);
		}
	}
	return temp;
}
BinaryRelation BinaryRelation::transitiveClosure() const {
	BinaryRelation temp(matrix, set);
	for (int k = 1; k <= temp.getBooleanMatrix().getRow(); ++k) {
		for (int i = 1; i <= temp.getBooleanMatrix().getColums(); ++i) {
			for (int j = 1; j <= temp.getBooleanMatrix().getColums(); ++j) {
				if (temp.getBooleanMatrix().getElement(i, k) == 1 &&
					temp.getBooleanMatrix().getElement(k, j) == 1)
					temp.matrix.replace(1, i, j);
			}
		}
	}
	return temp;
}