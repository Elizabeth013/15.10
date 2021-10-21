#include <iostream>
#include <iomanip>
using namespace std;

void input(int &n, double *a) {
     do {
        cout<<"n="; cin>>n;
        if(n<=0) cout<<"error!";
    }while(n<=0);
	
    for(int i=0;i<n;i++) {
    	for(int j=0;j<n;j++) {
        cout<<"a["<<i+1<<","<<j+1<<"]="; cin>>*(a+i*n+j);
    	}
	}      
}

void output(int n, double *a)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) {
        	cout<<setw(7)<<setprecision(3)<<*(a+i*n+j)<<" ";
        	cout<<endl;
		}   
    }
}
//replacing a string
void swap(int n, double *a, int n1,int n2) {
    double t;
    for(int j=0;j<n;j++) {
        t=*(a+n1*n+j);
        *(a+n1*n+j)=*(a+n2*n+j);
        *(a+n2*n+j)=t;
    }

}
//str_n2=str_n1+str_n2
void sum(int n, double *a, int n1,int n2) {
	for(int j=0;j<n;j++){
	*(a+n2*n+j)=*(a+n2*n+j)+*(a+n1*n+j);
    }
}
//str_n1=str_n1*p
void mult(int n, double *a, int n1,double p){
	for(int j=0;j<n;j++){
	*(a+n1*n+j)=(*(a+n1*n+j))*p;
    }
}
//Gauss step
void G(int n, double *a, int n1) {
    for(int i=n1+1;i<n;i++){
    	for(int j=n1;j<n;j++)   {
        // a[i,j]=a[i,j]+a[n1,j]*(-a[i,n1])
        *(a+i*n+j)=*(a+i*n+j)+*(a+n1*n+j)*(-1*(*(a+i*n+n1)));
   		 }
	}
}

int main()
{
    int n;
    double *a=new double [n*n];
    input(n,a);
    cout<<"Matrix:"<<endl;
    output(n,a);
    cout<<"Do you want to swap any raws? y/n: "<<endl;
    char c;
    do {
       cin>>c;
    }while(c!='y'&& c!='n');

    if(c=='y') {
        int n1,n2;
        cin>>n1>>n2;
        swap(n,a,n1,n2);
    }

    for(int i=0;i<n;i++) {
        cout<<"Step "<<i+1<<endl;
        mult(n,a,i,1/(*(a+i*n+i)));
        G(n,a,i);
        output(n,a);
    }
    delete [] a;
return 1;
}
