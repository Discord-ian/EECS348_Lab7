#include <iostream>

using namespace std;

const int SIZE = 4; // Global variable for matrix size

class Matrix {
private:
    int data[SIZE][SIZE]; // 2D array for matrix data (using int for simplicity)

public:
    // 1. Read values from stdin into a matrix
    void readFromStdin() {
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                cin >> data[row][col];
            }
        }
    }

    // 2. Display a matrix
    void display() const {
        for (int row = 0; row < SIZE; row++) {
            cout << "[";
            for (int col = 0; col < SIZE; col++) {
                cout << " " << data[row][col];
            }
            cout << " ]" << endl;
        }
    }

    // 3. Add two matrices (operator overloading for +)
    Matrix operator+(const Matrix &other) const {
        Matrix results;
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                results.data[row][col] = data[row][col] + other.data[row][col];
            }
        }
        return results;
    }

    // 4. Multiply two matrices (operator overloading for *)
    Matrix operator*(const Matrix &other) const {
        // Code copied from my lab 5 matrix.c file
        // Modified to work correctly in this context.
        Matrix result;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                // Multiply a11 * b11, then add a12 * b21 to that
                // initialize that cell
                // now we need to go through all rows in m2 with our current indices
                // (Because we go down the rows in matrix multiplication, not across columns)
                for (int k = 0; k < SIZE; k++) {
                    /* Example:
                     * [ 1 2 3 ] * [2 3]    result at (0,0) = [ (1*2) + (2*2) + (3*3) ]
                     * [ 2 1 4 ]   [2 7] =
                     *			   [3 5]
                     */
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // 5. Compute the sum of matrix diagonal elements
    int sumOfDiagonals() const {
        // Since SIZE = 4, there is no overlap.
        // If size was an odd number, there would be overlap to have to deal with.
        int sum = 0;
        // top left to bottom right
        for (int combo = 0; combo < SIZE; combo++) {
            sum += data[combo][combo];
        }
        for (int combo = (SIZE - 1); combo >= 0; combo--) {
            sum += data[combo][combo];
        }
        return sum;
    }

    // 6. Swap matrix rows
    void swapRows(int row1, int row2) {
        for ( int col = 0; col < SIZE; col++) {
            int temp = data[row1][col];
            data[row1][col] = data[row2][col];
            data[row2][col] = temp;
        }
    }
};

int main() {
    // Example usage:
    Matrix mat1;
    cout << "Enter values for Matrix 1:" << endl;
    mat1.readFromStdin();
    cout << "Matrix 1:" << endl;
    mat1.display();

    Matrix mat2;
    cout << "Enter values for Matrix 2:" << endl;
    mat2.readFromStdin();
    cout << "Matrix 2:" << endl;
    mat2.display();

    Matrix sum = mat1 + mat2;
    cout << "Sum of matrices:" << endl;
    sum.display();

    Matrix product = mat1 * mat2;
    cout << "Product of matrices:" << endl;
    product.display();

    cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;
    int row1 = 0, row2 = 2;
    mat1.swapRows(row1, row2);
    cout << "Matrix 1 after swapping rows " << row1 << " and " << row2 << ":" << endl;
    mat1.display();

    return 0;
}
