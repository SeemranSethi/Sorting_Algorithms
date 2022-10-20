//Gets random input from 1-100 into a text file.

#include<iostream>
#include<fstream>
#include<random>
#include<time.h>
using namespace std;

int main()
{
    int i,j,num;
    ofstream fout;
    fout.open("input.txt");
    srand(time(NULL));
    for(i=1;i<=100;i++)
    {
        for(j=1;j<=i;j++)
        {
            num=rand()%970+30;
            fout<<num<<" ";
        }
        fout<<"\n";
    }
    fout.close();
    return 0;
}