/* Function matrix_multiply
 * matrixA, matrixB, and matrix C are matrices represented as
 * one-dimensional arrays in row-major order. This function must
 * preform matrix multiplication so that C=A*B. 
 * INPUT: matrixA, a two dimensional double array of size m by k
 *        matrixB, a two dimensional double array of size k by n
 * OUTPUT: matrixC, a two dimensional double array of size m by n
 */
void matrix_multiply(double *matrixA,double *matrixB,double *matrixC,int m,int k,int n)
{
  int x,y,z;
  for(y=0;y<m;y++)
  {
    for(x=0;x<n;x++)
    {
      for(z=0;z<k;z++)
      {
        int loc_c = y*n+x;
        int loc_a = y*k+z;
        int loc_b = z*n+x;
        matrixC[loc_c]+=matrixA[loc_a]*matrixB[loc_b];  
      }
    }
  }
}

