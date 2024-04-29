#ifndef Q2_H_
#define Q2_H_
int ** readMatrix(int size);
int ** makeSymmetricMatrix(int **matrix, int size, bool fromLower);
void printMatrix(int **matrix, int size);
bool isSymmetric(int **matrix, int size);
#endif /* Q2_H_ */