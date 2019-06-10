#include <iostream>
#include <stdlib.h>

using namespace std;

class Nodo
{
	private:
		int nro;
		int valor;
		int pos;
		Nodo *sgte;
		typedef Nodo*Tlista;
	public:
		Nodo(int=0, int=0, int=0);
		void InsertarInicio(Tlista &lista, int=0);
		void InsertarFinal(Tlista &lista, int=0);
		int InsertarAntesDespues();
		void InsertarElemento(Tlista &lista, int=0, int=0);
		void BuscarElemento(Tlista lista, int=0);
		void ReportarLista(Tlista lista);
		void EliminarElemento(Tlista &lista, int=0);
		void EliminarRepetidos(Tlista &lista, int=0);
		void menu();
};

Nodo::Nodo(int _nro, int _valor, int _pos)
{
	nro= _nro;
	valor= _valor;
	pos= _pos;
}

void Nodo::InsertarInicio(Tlista &lista, int valor)
{
	Tlista q;
	q= new(Nodo);
	q->nro= valor;
	q->sgte= lista;
	lista= q; 	
}

void Nodo::InsertarFinal(Tlista &lista, int valor)
{
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
}

int Nodo::InsertarAntesDespues()
{
	int op, band;
	
	cout<<"\n\t 1. Antes de la pocision \n\t 2. Despues de la posicion \n\t Opcion: ";
	cin>>op;
	
	if(op==1)
		band= -1;
	else
		band= 0;
	
	return band;
}

void Nodo::InsertarElemento(Tlista &lista, int valor, int pos)
{
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
}

void Nodo::BuscarElemento(Tlista lista, int valor)
{
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
}

void Nodo::ReportarLista(Tlista lista)
{
	int i= 0;
	
	while(lista != NULL)
	{
		cout<<' '<<i+1<<") "<<lista->nro<<endl;
		lista= lista->sgte;
		i++;
	}
}

void Nodo::EliminarElemento(Tlista &lista, int valor)
{
	Tlista p, ant;
	p= lista;
	
	if(lista != NULL)
	{
		while(p != NULL)
		{
			if(p->nro == valor)
			{
				if(p == lista)
					lista = lista->sgte;
					
				else
					ant->sgte= p->sgte;
					
				delete(p);
				return;
			}
			
			ant = p;
			p= p->sgte;	
		}
	}
	
	else
		cout<<"\n Lista Vacia"<<endl;
}

void Nodo::EliminarRepetidos(Tlista &lista, int valor)
{
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

void Nodo::menu()
{
	cout<<"\n\t Lista enlazada simple \n\n";
	cout<<" 1. Insertar  al Inicio\n 2. Insertar al Final\n";
	cout<<" 3. Insertar en una posicion\n 4. Reportar lista\n";
	cout<<" 5. Buscar elemento\n 6. Eliminar elemento 'v'\n";
	cout<<" 7. Eliminar elementos con valor 'v'\n 8. Salir\n";
	cout<<" Ingrese una opcion: ";
}

int main()
{
	Tlista lista=NULL;
	int op, dato, pos;
	
	do
	{
		menu();
		switch(op)
		{
			case 1: cout<<"\n NUMERO A INSERTAR: ";cin>>_dato;
			InsertarInicio(lista,_dato);
			break;
			case 2: cout<<"\n NUMERO A INSERTAR: ";cin>>_dato;
			InsertarFinal(lista,_dato);
			break;
			case 3: cout<<"\n NUMERO A INSERTAR: ";cin>>_dato;
			InsertarElemento(lista,_dato,pos);
			break; 
			case 4: cout<<"\n MOSTRANDO LISTA: \n\n";
			ReportarLista(lista);
			break;
			case 5: cout<<"\n VALOR A BUSCAR";cin>>_dato;
			BuscarElemento(lista,_dato);
			break;
			case 6: cout<<"\n ELIMINAR ELEMENTO: ";cin>>_dato;
			EliminarElemento(lista,_dato);
			break;
			case 7: cout<<"\n VALOR REPETIDO A ELIMINAR: ";cin>>_dato;
			EliminarRepetidos(lista,_dato);			
			break;
			cout<<"\n\n";
			system("pause");
			system("cls");
		}while (opcion!=8);
		system("pause");
		return 0;
	}
}
