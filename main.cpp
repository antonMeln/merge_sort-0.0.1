#include <iostream>
#include <sstream>

using namespace std;

bool read (int & n, int * mas)
{ 
  
  
  string str;
   getline(cin,str);
    istringstream stream(str);
     bool F = true;
    
       for (int i=0;i<n;i++)
        {
          if (!(stream >> mas[i])) { F = false; break;}
        }
   return F;
}
void merge_s (int *mas , int l,int m, int r)
{
  int *left = new int[m - l + 1];
  int *right = new int[m-r];
  int i,j;
  int k;
  for (i = 0; i < (m - l +1); i++)
      left[i] = mas[l+i];
  for (j = 0; j < (r-m) ; j++)
      right[j] = mas[m+1+j];  
      
    i = 0;
    j = 0;
    k = l;
    
    while ((i < m-l+1) && (j < r - m)) {
       if (left[i] <= right[j])
         {
           mas[k] = left[i];
           i++;
         }
        else
        {
           mas[k] = right[j];
           j++;
        }  
    k++;
    }
   
    while (i < m -l+1)
    {
      mas[k] = left[i];
      i++;
    }
       
    while (j < r-m) 
    {
      mas[k] = right[j];
      j++;
    }
  }

void merge_sort(int * mas, int left, int right)
{
  if (left < right) {
        int m = left + (right - left) / 2;
        merge_sort(mas, left, m);
        merge_sort(mas, m + 1, right);
        merge_s(mas, left, m, right);
    }

}

int main ()
 { 
  
   int *mas = new int; 
   int i,n;
   string str;
   getline(cin,str);
   istringstream  stream (str);
    
       if (stream >> n ) {   
         if ( read (n , mas) ){
           for (i = 0; i < n; i++) {
              merge_sort(mas, 0, n-1);
         } }
   
   for (i = 0 ; i < n; i++)
      cout << mas[i] << " ";
       }
       
                else {cout << "An error has occured while reading input data." ; } 
   return 0;
 }
