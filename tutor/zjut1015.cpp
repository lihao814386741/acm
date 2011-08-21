#include <time.h>
#include <iostream>

using namespace std;

# define      MAXN      100
int a[MAXN];
int counts=0;


void      comb(int m,int k)
{     int i,j;
      for (i=m;i>=k;i--)
      {     a[k]=i;
          if (k>1)
              comb(i-1,k-1);
          else
          {   
              counts++;
              /*
              for (j=a[0];j>0;j--)
                  printf("%4d",a[j]);
              printf("/n");
              */
          }
      }
}

int main()
{   

      int m,r;
	  while (cin >> m >> r)
	  {
      counts=0;
      a[0]=r;
      comb(m,r);
      cout<<counts<<endl;
	  }
      return 0;
}
