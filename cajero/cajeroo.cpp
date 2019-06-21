#include<conio.h>
#include<iostream>

using namespace std;
int main(){
int bill[]={10,20,50,100,200};
int nbill[]={10,10,10,10,10};
int ent[]={0,0,0,0,0};
int ntipos =5;
int saldo;
saldo=70;
ntipos=5;
int isaldo;
do{
	isaldo = saldo;
	for(int i=ntipos-1;i>=0;i--){
		if  (saldo >=bill[i])
		if (nbill[i]>0){
			saldo=saldo-bill[i];
			nbill[i]--;
			ent[i]++;
			break;
		}
	}
}while(saldo>0 && isaldo != saldo);

if (isaldo ==saldo){
	cout<<"no se puede emitir ese monto";
}
else if (saldo==0){
	
	for (int i=0;i<ntipos;i++){
		cout<<"array"<<ent[i]<<endl;
	}
}

	
	
}


