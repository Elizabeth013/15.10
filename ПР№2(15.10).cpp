#include <iostream>
using namespace std;

int bin(int arr[],int a)
{
	int left=-1, right=a-1, middle=0;
	while ( right - left > 1 ) {
		middle = ( right + left ) / 2;
		if (arr[middle]>=a) {
			right=middle;
		}
		else {
			left=middle;
		}
	}
	if (arr[right]==a) cout<<right;
	else cout<<-1;	
}
int main() 
{
	setlocale (LC_ALL, "Russian");
	int n;
	cout<<"������� ���������� �������� � �������";
	cin>>n;
	int arr [n];
	cout<<"������� �������� �������������� ������� ";
	for (int i=0;i<n;i++)  cin>>arr[i];
	int a;
	cout<<"������� �����, ������� ����� ����� ";
	cin>>a;
	bin(arr,a);
	return 1;		
}
