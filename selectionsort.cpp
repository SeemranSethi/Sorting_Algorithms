// Performs selection sort on the contents of a text file and shows the no. of comparisons and no. of swaps.

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

void selection(int ar[],int n)
{
    int i, j, min_idx;
    comp=0,swaps=0;
    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < n-1; i++)
    {
       
        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
        comp++;
        if (ar[j] < ar[min_idx])
            min_idx = j;
 
        // Swap the found minimum element
        // with the first element
        if(min_idx!=i)
        {
            swap(&ar[min_idx], &ar[i]);
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
        selection(ar,n);
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