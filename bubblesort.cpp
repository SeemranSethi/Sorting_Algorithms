// Performs bubble sort on the contents of a text file and shows the no. of comparisons and no. of swaps.

#include<bits/stdc++.h>
#include<fstream>
#include<cstdlib>
using namespace std;

int comp;
int swaps;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    comp=0,swaps=0;
    for (i = 0; i < n - 1; i++)
 
        // Last i elements are already
        // in place
        for (j = 0; j < n - i - 1; j++)
        {
            comp++;
            if (arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }
}

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
    if(!fin || !fout)
    {
        cout<<"File error!";
        exit(0);
    }
    int ar[100],n=1,num,i,j;
    string line;
    while(getline(fin,line))
    {
        j=0;
        int ar[line.length()]={0};
        for(i=0;line[i]!='\0';i++)
        {
            if(line[i]==' ')
                j++;
            else
                ar[j]=ar[j]*10+(line[i]-48);
        }
        fout<<"\nLine "<<n<<" : \n";
        fout<<"Unsorted Array : ";
        for(i=0;i<n;i++)
            fout<<ar[i]<<" ";
        fout<<endl;
        bubbleSort(ar,n);
        fout<<"Sorted Array : ";
        for(i=0;i<n;i++)
            fout<<ar[i]<<" ";
        fout<<endl;
        fout<<"Comparisons : "<<comp<<"\nSwaps : "<<swaps;
        fout<<endl;
        n++;
    }
    fin.close();
    fout.close();
    return 0;
}