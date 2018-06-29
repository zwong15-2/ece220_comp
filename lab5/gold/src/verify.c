#include "verify.h"

int verify_matrix(double *matrixA,double *matrixB,double *matrixC,
                 int m,int k,int n)
{
  int x,y,z;
  double temp;
  for(y=0;y<m;y++)
  {
    for(x=0;x<n;x++)
    {
      temp=0.0;
      int loc_c = y*n+x; 
      for(z=0;z<k;z++)
      {
        int loc_a = y*k+z;
        int loc_b = z*n+x;
        temp+=matrixA[loc_a]*matrixB[loc_b];
      }
      if(matrixC[loc_c]!=temp)
      {
        return 0;
      }
    }
  }

  return 1;
}
