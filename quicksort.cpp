#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
int comp = 0;
int swaps = 0;

int partition(int array[], int low, int high)
{
    int pivot = array[high]; 
    int i = (low-1);
    for (int j = low; j < high; j++)
    {
        comp++;
        if (array[j] < pivot)
        {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            swaps++;
        }
    }

    int temp = array[i+1];
    array[i+1] = array[high];
    array[high] = temp;
    swaps++;

    return i+1;
}
void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int pivotPoint = partition(array, low, high);
        quickSort(array, low, pivotPoint-1);
        quickSort(array, pivotPoint+1, high);
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
        quickSort(ar, 0, n - 1);
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