// Performs insertion sort on the contents of a text file and shows the no. of comparisons and no. of swaps.

#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

int comp;
int swaps;
void insertion(int ar[],int n)
{
    int i,j,no;
    comp=0;
    swaps=0;
    for(i=1;i<n;i++)
    {
    	no = ar[i];
    	j = i-1;
    	comp++;
    	while(ar[j]>no && j>=0)
    	{
    		ar[j+1] = ar[j];
    		j--;
    		swaps++;
    	}
    	ar[j+1] = no;
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
        insertion(ar,n);
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