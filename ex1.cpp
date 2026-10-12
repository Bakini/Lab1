#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

int main(){
    srand(time(NULL));

    int n;
    std::cout<<"Размер матрицы n: ";
    std::cin>>n;
    if(n<=0){
        std::cout<<"Неверный размер\n";
        return 0;
    }

    int **a=new int*[n];
    for(int i=0;i<n;i++)
        a[i]=new int[n];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            a[i][j]=rand()%60-17;

    std::cout<<"\nМатрица:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            std::cout<<std::setw(5)<<a[i][j];
        std::cout<<"\n";
    }

    int count=0,sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i][i];
        count++;
    }

    std::cout<<"\nКоличество элементов главной диагонали: "<<count<<"\n";
    std::cout<<"Сумма элементов главной диагонали: "<<sum<<"\n";

    for(int i=0;i<n;i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
