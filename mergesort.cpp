#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
int comp = 0;
int swaps = 0;

void merge(int ar[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = new int[n1];
    int* R = new int[n2];

    for (i = 0; i < n1; i++)
        L[i] = ar[l + i];
    for (j = 0; j < n2; j++)
        R[j] = ar[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            ar[k] = L[i];
            i++;
        }
        else
        {
            ar[k] = R[j];
            swaps++;
            j++;
        }
        k++;
        comp++;
    }

    while (i < n1)
    {
        ar[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        ar[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int ar[], int l, int r)
{
    if (l < r)
    {
        int m = (l+r) / 2;

        mergeSort(ar, l, m);
        mergeSort(ar, m + 1, r);

        merge(ar, l, m, r);
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
        comp=0;
        swaps=0;
        fout<<"\nLine "<<n<<" : \n";
        fout<<"Unsorted Array : ";
        for(i=0;i<n;i++)
        fout<<ar[i]<<" ";
        fout<<endl;
        mergeSort(ar, 0, n - 1);
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