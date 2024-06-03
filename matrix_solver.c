/*This repository is for matrix operations.*/

#include <stdio.h>
void matrix_addition();
void matrix_subtraction();
void matrix_multiplication();
void matrix_sumAllElements();
void matrix_sumAllDiagonalselem();
void matrix_sumAllfDiagonalselem();
void matrix_productelem();

int main()
{
    printf("\n******MATRIX SOLVER******\n");
    printf("Choose :\n(1) for \'Matrix Addition.\'\n(2) for \'Matrix Subtarction.\'\n(3) for \'Matrix Multiplication.\'\n(4) for \'Sum of all elements of the Matrix.\'\n(5) for \'Sum of All Diagonals Elements.\'\n(6) for \'Sum of flipped diagonal's elements.\'\n(7) for \'Multiplication of Constant Term with Matrix .\'\n");
    int n;
    printf("=> ");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        matrix_addition();
        break;
    case 2:
        matrix_subtraction();
        break;
    case 3:
        matrix_multiplication();
        break;
    case 4:
        matrix_sumAllElements();
        break;
    case 5:
        matrix_sumAllDiagonalselem();
        break;
    case 6:
        matrix_sumAllfDiagonalselem();
        break;
    case 7:
        matrix_productelem();
        break;

    default:
        printf("invalid\n");
    }

    return 0;
}
// for matrix input

void matrix_entry(int rows, int columns, int matrix[rows][columns])
{

    for (int i = 0; i < rows; i++)
    {
        printf("Enter elements of %d row: ", i + 1);
        for (int j = 0; j < columns; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void matrix_addition()
{
    int arows;
    int acolumns;
    int brows;
    int bcolumns;
    int sum = 0;

    printf("Enter the rows and columns of matrix A: ");
    scanf("%d %d", &arows, &acolumns);

    int matrixA[arows][acolumns];

    matrix_entry(arows, acolumns, matrixA);

    printf("Enter the rows and columns of matrix B: ");
    scanf("%d %d", &brows, &bcolumns);

    int matrixB[brows][bcolumns];
    if (arows == brows && acolumns == bcolumns)
    {
        matrix_entry(brows, bcolumns, matrixB);
        int matrix_added[arows][acolumns];

        for (int x = 0; x < arows; x++)
        {
            for (int y = 0; y < acolumns; y++)
            {
                sum += matrixA[x][y] + matrixB[x][y];
                matrix_added[x][y] = sum;
                sum = 0;
            }
        }
        printf("\n************** RESULTANT MATRIX ************\n");
        for (int m = 0; m < arows; m++)
        {
            for (int n = 0; n < bcolumns; n++)
            {
                printf("%d ", matrix_added[m][n]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("\n***INVALID***\n");
        printf("\nWe cannot add these Matrixes.\n");
    }
}

// matrix subtraction

void matrix_subtraction()
{
    int arows;
    int acolumns;
    int brows;
    int bcolumns;
    int sum = 0;

    printf("Enter the rows and columns of matrix A: ");
    scanf("%d %d", &arows, &acolumns);

    int matrixA[arows][acolumns];

    matrix_entry(arows, acolumns, matrixA);

    printf("Enter the rows and columns of matrix B: ");
    scanf("%d %d", &brows, &bcolumns);

    int matrixB[brows][bcolumns];
    if (arows == brows && acolumns == bcolumns)
    {
        matrix_entry(brows, bcolumns, matrixB);
        int matrix_sub[arows][acolumns];

        for (int x = 0; x < arows; x++)
        {
            for (int y = 0; y < acolumns; y++)
            {
                sum += matrixA[x][y] - matrixB[x][y];
                matrix_sub[x][y] = sum;
                sum = 0;
            }
        }
        printf("\n************** RESULTANT MATRIX ************\n");
        for (int m = 0; m < arows; m++)
        {
            for (int n = 0; n < bcolumns; n++)
            {
                printf("%d ", matrix_sub[m][n]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("\n***INVALID***\n");
        printf("\nWe cannot subtract these Matrixes.\n");
    }
}

// matrix multiplication

void matrix_multiplication()
{
    int arows;
    int acolumns;
    int brows;
    int bcolumns;
    int sum = 0;

    printf("Enter the rows and columns of matrix A: ");
    scanf("%d %d", &arows, &acolumns);

    int matrixA[arows][acolumns];
    matrix_entry(arows, acolumns, matrixA);
    printf("Enter the rows and columns of matrix B: ");
    scanf("%d %d", &brows, &bcolumns);

    int matrixB[brows][bcolumns];

    if (acolumns == brows)
    {
        matrix_entry(brows, bcolumns, matrixB);
        int matrixNew[arows][bcolumns];

        for (int x = 0; x < arows; x++)
        {
            for (int y = 0; y < bcolumns; y++)
            {
                for (int z = 0; z < brows; z++)
                {
                    sum += matrixA[x][z] * matrixB[z][y];
                }
                matrixNew[x][y] = sum;
                sum = 0;
            }
        }
        printf("\n************** RESULTANT MATRIX ************\n");
        for (int m = 0; m < arows; m++)
        {
            for (int n = 0; n < bcolumns; n++)
            {
                printf("%d ", matrixNew[m][n]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("\n***INVALID***\n");
        printf("\nWe cannot multiply these Matrixes.\n");
    }
}

/*sum of all elements of the matrix*/

void matrix_sumAllElements()
{
    int rows;
    int columns;
    int matrix[rows][columns];
    matrix_entry(rows, columns, matrix);
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            sum += matrix[i][j];
        }
    }

    printf("Sum of all elements of the given Matrix is: \n");
    printf("Sum: ,%d", sum);
}

/*sum of all diagonals elements of the matrix*/

void matrix_sumAllDiagonalselem()
{
    int rows;
    int columns;
    printf("Enter the rows and columns of matrix : ");
    scanf("%d %d", &rows, &columns);
    int matrix[rows][columns];
    matrix_entry(rows, columns, matrix);
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (i == j)
            {
                sum += matrix[i][j];
            }
        }
    }

    printf("Sum of all the Diagonals elements of the given Matrix is: \n");
    printf("Sum: ,%d", sum);
}

/*sum of all the flipped diagonals elements of the matrix*/

void matrix_sumAllfDiagonalselem()
{
    int rows;
    int columns;
    printf("Enter the rows and columns of matrix: ");
    scanf("%d %d", &rows, &columns);
    int matrix[rows][columns];
    matrix_entry(rows, columns, matrix);
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (i + j == rows - 1)
            {
                sum += matrix[i][j];
            }
        }
    }

    printf("Sum of all the flipped Diagonal's elements of the given Matrix is: \n");
    printf("Sum: ,%d", sum);
}

/*Constant Term with Matrix multiplication.*/

void matrix_productelem()
{
    int rows;
    int columns;
    printf("Enter the rows and columns of matrix: ");
    scanf("%d %d", &rows, &columns);
    int matrix[rows][columns];
    matrix_entry(rows, columns, matrix);
    int term;
    printf("Enter the Constant Term: ");
    scanf("%d", &term);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            matrix[i][j] = matrix[i][j] * term;
        }
    }

    printf("\n************** RESULTANT MATRIX ************\n");
    for (int m = 0; m < rows; m++)
    {
        for (int n = 0; n < columns; n++)
        {
            printf("%d ", matrix[m][n]);
        }
        printf("\n");
    }
}
