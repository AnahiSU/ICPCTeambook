
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

//QUADTREE
struct QuadTree{
    char valor;
    bool esHoja;
    QuadTree *izquierdaSuperior,*derechaSuperior,*izquierdaInferior, *derechaInferior;
    QuadTree(char valor1){
        valor=valor1;
        izquierdaSuperior=derechaSuperior=izquierdaInferior=derechaInferior=nullptr;
        if(valor=='p'){
            esHoja=false;
        }
        else{
            esHoja=true;
        }
    }
    
};

//CONSTRUCTOR
QuadTree* construir(string valor,long long &indice){
    if(indice>=valor.length()){
        return nullptr;
    }
    QuadTree *nodo = new QuadTree (valor[indice]);
    char letra = valor[indice];
    if(letra!='p'){
        nodo->esHoja = true;
        indice++;
    }
    else{
        indice++;
        nodo->izquierdaSuperior=construir(valor,indice); 
        nodo->derechaSuperior =construir(valor,indice); 
        nodo->izquierdaInferior=construir(valor,indice); 
        nodo->derechaInferior=construir(valor,indice);
    }
    return nodo;
}
//METODO DE CONTAR NODOS CON CIERTA CONDICION
int contarCuadradosNegros(QuadTree *nodoReferencia,int tamano){
    if(nodoReferencia->esHoja == true){
        if(nodoReferencia->valor=='f'){
            return tamano*tamano;
        }
        else{
          return 0;
        }
    }
    long long medio = tamano/2;
    long long resultado = contarCuadradosNegros(nodoReferencia->izquierdaSuperior,medio)
    +contarCuadradosNegros(nodoReferencia->derechaSuperior,medio)+
    contarCuadradosNegros(nodoReferencia->izquierdaInferior,medio)+
    contarCuadradosNegros(nodoReferencia->derechaInferior,medio);
    return resultado;
}
//UNION DE QUADTREES
QuadTree* combinar(QuadTree *nodo1, QuadTree *nodo2){
    if(nodo1==nullptr){
        return nodo2;
    }
    if(nodo2==nullptr){
        return nodo1;
    }
    if(nodo1->esHoja==true && nodo2->esHoja==true ){
        if(nodo1->valor=='f' || nodo2->valor=='f'){
            return new QuadTree('f');
        }
        else{
            return new QuadTree('e');
        }
    }
    if(nodo1->esHoja==true){
        if(nodo1->valor=='f'){
            return new QuadTree('f');
        }
        else{
            return nodo2;
        }
    }
    if(nodo2->esHoja==true){
        if(nodo2->valor=='f'){
            return new QuadTree('f');
        }
        else{
            return nodo1;
        }
    }
    QuadTree *nuevoQuad = new QuadTree ('p');
    nuevoQuad->izquierdaSuperior=combinar(nodo1->izquierdaSuperior,nodo2->izquierdaSuperior);
    nuevoQuad->derechaSuperior=combinar(nodo1->derechaSuperior,nodo2->derechaSuperior);
    nuevoQuad->izquierdaInferior=combinar(nodo1->izquierdaInferior,nodo2->izquierdaInferior);
    nuevoQuad->derechaInferior=combinar(nodo1->derechaInferior,nodo2->derechaInferior);
    return nuevoQuad;
}
