#include <iostream>
using namespace std;

struct No {
int dado;
struct No *prox;
};

struct Pilha {
No *topo;
};

Pilha* init() {
Pilha *p = new Pilha;
p->topo = NULL;
return p;
}

void push(Pilha *p, int v) {
No *no = new No;
no->dado = v;
no->prox = p->topo;
p->topo = no;
}

int pop(Pilha *p) {
int ret;
int podeDesempilhar = (p->topo != NULL);
if (podeDesempilhar) {
  No *no = p->topo;
  ret = no->dado;
  p->topo = p->topo->prox;
  free(no);
}
else
{
ret = -1;
}
return ret;
}

void print(Pilha* p) {
No* n;
n = p->topo;
while (n != NULL) {
cout << n->dado << endl;
n = n->prox;
}
cout << "----------------------" << endl;
}
void printPar (Pilha* par){
    No* n;
n = par->topo;
while(n != NULL)
{
if (n->dado % 2 == 0){
    cout<<n->dado<< endl;
}
n = n->prox;
}
cout << "----------------------" << endl;
}
void printImpar (Pilha* par){
    No* n;
n = par->topo;
while(n != NULL)
{
if (n->dado % 2 != 0){
    cout<<n->dado<< endl;
}
n = n->prox;
}
cout << "----------------------" << endl;
}

int count(Pilha* p) {
int i = 0;
No* n;
n = p->topo;
while (n != NULL) {
i++;
n = n->prox;
}
return i;
}

int isEmpty(Pilha *p) {
return (p->topo == NULL);
}

void freePilha(Pilha *p) {
No *n = p->topo;
while(n != NULL) {
No *t = n->prox;
free(n);
n = t;
}
free(p);
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Portuguese");
Pilha *pilhaFloat;
pilhaFloat = init();
int n;
int num=0;
for(int i=1; i<=5; i++){
cout<<"Digite o "<<i<<"º valor: ";
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
print(pilhaFloat);
printPar(pilhaFloat);
printImpar(pilhaFloat);
for(int i=1; i<=5; i++){
cout << "Valor desempilhado: " << pop(pilhaFloat) << endl;
}

return 0;
}