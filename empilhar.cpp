#include <iostream>
using namespace std;
#include <locale.h>
#define MAX 30

struct Pilha
{
int qtd;
float nivel[MAX];
};

Pilha* init() {
Pilha *p = new Pilha;
p->qtd = 0;

return p;
}

int push(Pilha *p, float v){
int empilhar = (p->qtd <MAX);
if (empilhar){
p->nivel[p->qtd++] = v;
}
return empilhar;
}

void print(Pilha *p){
cout << "Quantidade de elementos na pilha: " << p->qtd<<endl;
for (int i=p->qtd-1; i>=0; --i)
{
cout<<p->nivel[i]<<endl;
}
}
void printPar (Pilha *par){
int x,y;
cout << "Os numeros pares são: "<<endl;
for (int i=par->qtd-1; i>=0; --i){
x=par->nivel[i];
if (x % 2 ==0){
cout<<x<<endl;
}
else {
y;
}
}
}
void printImpar (Pilha *impar){
int x,y;
cout << "Os numeros impares são: "<<endl;
for (int i=impar->qtd-1; i>=0; --i){
x=impar->nivel[i];
if (x % 2 ==0){
y;
}
else {
cout<<x<<endl;
}
}
}
int isEmpty(Pilha *p){
return (p->qtd == 0);
}
int count(Pilha *p){
return (p->qtd);
}
float pop(Pilha *p){
int podeDesempilhar = (p->qtd >0);
float v;
if (podeDesempilhar){
v=p->nivel[p->qtd-1];
p->qtd--;
}
else {
v = -1;
}
return v;

}
int main(int argc, char** argv)
{
setlocale(LC_ALL, "Portuguese");
Pilha *pilhaFloat;
pilhaFloat = new Pilha;
pilhaFloat = init();
int n;
float num=0;
for(int i=1; i<=30; i++){
cout<<"Digite o "<<i<<"º número: ";
cin>>n;
if (n>num){
push(pilhaFloat, n);
}
else
{
cout <<"Digite um número maior que " << num << ": ";
cin>>n;
push(pilhaFloat, n);
}
num =n;
        system("CLS");
}
     cout<<endl;
printPar(pilhaFloat);
cout<<endl;
printImpar(pilhaFloat);
     cout<<endl;
for(int i=0; i<30; i++){
cout << "Valor desempilhado: " << pop(pilhaFloat) << endl;
}
return 0;
}