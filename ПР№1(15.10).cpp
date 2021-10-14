#include <iostream>
#include <math.h>
using namespace std;

int minimum (int arr[], int min,int n)
{
	for (int i=0;i<n;i++){
	min=arr[i]; break;
	}
	return min;
}

int maximum (int arr[], int max,int n)
{
	for (int i=n-1;i>1;i--) {
	max=arr[i]; break;
	}
	return max;
}

int srznach(int arr[],int sum, int n)
{
	for (int i=0;i<n;i++){
		sum=sum+arr[i];
	}
	return sum/n;
}

int moda(int arr[], int n)
{
	int h=1,l=0, s=0;
	for (int i=0;i<n-1;i++)
	{
		for (int j=i+1;j<n;j++)
		{
			if (arr[i]==arr[j])
			{
				h++;
				if (s<h)
				{
					s=h;
					l=arr[i];
				}
			}
			else h=1;
		}
	}
	return l;
}

float disp ( int arr[],int n)
{
	float mo=0,dis=0;
	for (int i=0;i<n;i++)	mo=mo+arr[i];		//mo -мат ожидание
	mo=mo/n;
	for (int i=0;i<n;i++) dis=pow((arr[i]-mo),2)+dis;
	dis=dis/(n-1);
	return dis;

}

int main()
{	setlocale (LC_ALL,"Russian");
	int n, t=0;
	cout<<"Введите количество элементов в массиве";
	cin>>n;
	int arr[n];
	cout<<"Введите каждый элемент через пробел ";
	for (int i=0;i<n;i++) cin>>arr[i];
	for (int i=0;i<n-1;i++) {
		for (int j=i+1;j<n;j++) {
			if (arr[i] > arr[j]) {			
				arr[j]=arr[j]+arr[i];
				arr[i]=arr[j]-arr[i];
				arr[j]=arr[j]-arr[i];		
			}
		}
	}
	int min=0,max=0,sum=0,k=0;     //	for (int i=0;i<n;i++) cout<<arr[i]<<endl;
	cout<<"max="<<maximum(arr,max,n)<<endl<<"min="<<minimum(arr,min,n)<<endl<<"Размах="<<maximum(arr,max,n)-minimum(arr,min,n)<<endl<<"Среднее значение="<<srznach(arr,sum,n)<<endl;
	if (n%2==0) cout<<"Медиана="<<float (arr[n/2]+arr[n/2-1])/2<<endl;
	else cout<<"Медиана="<<arr[n/2]<<endl;
	cout<<"Мода= ";
	if (moda(arr,n)==0) cout<<"Моды нет"<<endl;
	else cout<<moda(arr,n)<<endl;
	cout<<"Дисперсия= "<<disp(arr,n);
	return 1;
}
