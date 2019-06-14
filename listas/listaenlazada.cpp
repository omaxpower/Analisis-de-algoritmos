#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

class Nodo
{
	public:
	int nro;
	Nodo *sgte;
};

typedef Nodo *Tlista;

class Lista
{
	private:
		int nro;
		int valor;
		int pos;
	public:
		Lista(int=0, int=0, int=0);		
		void InsertarInicio(Tlista &lista, int=0);
		void InsertarFinal(Tlista &lista, int=0);
		int InsertarAntesDespues();
		void InsertarElemento(Tlista &lista, int=0, int=0);
		void BuscarElemento(Tlista lista, int=0);
		void ReportarLista(Tlista lista);
		void EliminarElemento(Tlista &lista, int=0);
		void EliminarRepetidos(Tlista &lista, int=0);
		void OrdenarLista(Tlista lista);
		void menu();
};

Lista::Lista(int _nro, int _valor, int _pos)
{
	nro= _nro;
	valor= _valor;
	pos= _pos;
}

void Lista::OrdenarLista(Tlista lista){
	Tlista actual , siguiente;
     int t;
     
     actual = lista;
     while(actual->sgte != NULL)
     {
          siguiente = actual->sgte;
          
          while(siguiente!=NULL)
          {
               if(actual->nro > siguiente->nro)
               {
                    t = siguiente->nro;
                    siguiente->nro = actual->nro;
                    actual->nro = t;          
               }
               siguiente = siguiente->sgte;                    
          }    
          actual = actual->sgte;
          siguiente = actual->sgte;
}
}

void Lista::InsertarInicio(Tlista &lista, int valor)
{
	Tlista q;
	q= new(Nodo);
	q->nro= valor;
	q->sgte= lista;
	lista= q; 	
	system("cls");
}

void Lista::InsertarFinal(Tlista &lista, int valor){
	Tlista t, q= new(Nodo);
	q->nro= valor;
	q->sgte= NULL;
	
	if(lista==NULL)
		lista=q;
	
	else
	{
		t= lista;
		
		while(t->sgte != NULL)
			t= t->sgte;
		t->sgte= q;
	}
	system("cls");
}

int Lista::InsertarAntesDespues(){
	int op, band;
	
	cout<<"\n\t 1. Antes de la pocision \n\t 2. Despues de la posicion \n\t Opcion: ";
	cin>>op;
	
	if(op==1)
		band= -1;
	else
		band= 0;
	
	return band;
system("cls");
}


void Lista::InsertarElemento(Tlista &lista, int valor, int pos){
	Tlista q, t;
	int i;
	q= new(Nodo);
	q->nro= valor;
	
	if(pos == 1)
	{
		q->sgte= lista;
		lista= q;
	}
	
	else
	{
		int x= InsertarAntesDespues();
		t= lista;
		
		for(i=1; t!=NULL; i++)
		{
			if(i == pos+x)
			{
				q->sgte= t->sgte;
				t->sgte= q;
				return;
			}
			
			t= t->sgte;	
		}	
	}
	
	cout<<"\t Error, posicion no encontrada"<<endl;
	system("cls");
}

void Lista::BuscarElemento(Tlista lista, int valor){
	Tlista q= lista;
	int i=1, band=0;
	
	while(q != NULL)
	{
		if(q->nro == valor)
		{
			cout<<"\n Encontrada en posicion "<<i<<endl;
			band= 1;
		}
		
		q= q->sgte;
		i++;
	}
	
	if(band == 0)
		cout<<"\n Numero no encontrado "<<endl;
	getch();
	system("cls");
}

void Lista::ReportarLista(Tlista lista){
	int i= 0;
	
	while(lista != NULL)
	{
		cout<<' '<<i+1<<") "<<lista->nro<<endl;
		lista= lista->sgte;
		i++;
	}
	getch();
	system("cls");
	
}

void Lista::EliminarElemento(Tlista &lista, int valor){
	Tlista p, ant;
	p= lista;
	
	if(lista != NULL){
		while(p != NULL){
			if(p->nro == valor){
				if(p == lista){
					lista = lista->sgte;
					system("cls");
				}
					
				else{
					ant->sgte= p->sgte;
				}
				
				delete(p);
				return;
			}
			ant = p;
			p= p->sgte;	
			system("cls");	
			
		}
	}
	
	else
		cout<<"\n Lista Vacia"<<endl;
	getch();
	system("cls");
}

void Lista::EliminarRepetidos(Tlista &lista, int valor){
	Tlista q, ant;
	q= lista;
	ant= lista;
	
	while(q != NULL)
	{
		if(q->nro == valor)
		{
			if(q == lista)
			{
				lista= lista->sgte;
				delete(q);
				q= lista;
			}
			
			else
			{
				ant->sgte= q->sgte;
				delete(q);
				q= ant->sgte;
			}
		}
		
		else
		{
			ant= q;
			q= q->sgte;
		}
	}
	
	cout<<"\n Valores eliminados"<<endl;
}

void Lista::menu(){
	cout<<"\n\t Lista enlazada simple \n\n";
	cout<<" 1. Insertar  al Inicio\n";
	cout<<" 2. Insertar al Final\n";
	cout<<" 3. Insertar en una posicion\n"; 
	cout<<" 4. Reportar lista\n";
	cout<<" 5. Buscar elemento\n";
	cout<<" 6. Eliminar elemento 'v'\n";
	cout<<" 7. Eliminar elementos con valor 'v'\n";
	cout<<" 8. Ordenar elementos\n";	
	cout<<" 9. Salir\n";
	cout<<" Ingrese una opcion: ";
}

int main(){
	Tlista lista= NULL;
	Lista list;
	int op, dato ,_pos;
	
	do{
		list.menu();
		cin>>op;
		switch(op){
			case 1:
				cout<<"\n Numero a insertar: ";
				cin>>dato;
				list.InsertarInicio(lista,dato);
				break;
			case 2:
				cout<<"\n Numero a insertar: ";
				cin>>dato;
				list.InsertarFinal(lista, dato);
				break;
			case 3:
				cout<<"\n Numero a insertar: ",
				cin>>dato;
				list.InsertarElemento(lista, dato, _pos);
				break;
			case 4:
				cout<<"\n Mostrando Lista\n";
				list.ReportarLista(lista);
				break;
			case 5:
				cout<<"\n Valor a buscar: ";
				cin>>dato;
				list.BuscarElemento(lista,dato);
				break;
			case 6:
				cout<<"\n Valor a eliminar: ";
				cin>>dato;
				list.EliminarElemento(lista, dato);
				break;
			case 7:
				cout<<"\n Valor repetido a eliminar: ";
				cin>>dato;
				list.EliminarRepetidos(lista, dato);
				break;
			case 8:
				cout<<"\nLista ordenada: ";
				list.OrdenarLista(lista);
			cout<<"\n\n";
			system("pause"); 
			system("cls");
		}
		
	}while(op!=9);
	
	system("pause");
	return 0;
}

