#include <iostream>

using namespace std;

struct nodo {
    int info;
    nodo *next;

    nodo(int a = 0, nodo *b = 0) {
        info = a;
        next = b;
    }
};

struct nodo_p {
    nodo *P;
    nodo_p *next;

    nodo_p(nodo *a = 0, nodo_p *b = 0) {
        P = a;
        next = b;
    }
};

void creanodo(nodo *&list, int input) {
    if (!list)
        list = new nodo(input);
    else
        creanodo(list->next, input);
}

void creanodo_p(nodo_p *&raccolta, nodo *list) {
    if (!raccolta)
        raccolta = new nodo_p(list);
    else
        creanodo_p(raccolta->next, list);
}

void del_lista(nodo *&list) {
    if (!list)
        return;
    nodo *temp = list->next;
    delete list;
    list = temp;
    del_lista(list);
}

void stampa_n(nodo *list) {
    if (!list) {
        cout << endl;
        return;
    }
    cout << list->info << ' ';
    stampa_n(list->next);
}

void stampa_p(nodo_p *list) {
    if (!list) {
        cout << endl;
        return;
    }
    stampa_n(list->P);
    stampa_p(list->next);
}

nodo *leggi() {
    int input;
    cin >> input;
    if (input == -1)
        return 0;
    return new nodo(input, leggi());
}

int get_lenght(nodo *list) {
    if (!list)
        return 0;
    return 1 + get_lenght(list->next);
}

bool check(nodo *list, nodo *P) {
    if (!P)
        return true;
    if (!list)
        return false;
    if (list->info == P->info)
        return check(list->next, P->next);
    return false;
}

nodo *copy(nodo *list, int quantity) {
    if (!list)
        return 0;
    if (!quantity)
        return 0;
    return new nodo(list->info, copy(list->next, quantity - 1));
}

void match(nodo *list, nodo *P, nodo_p *&destination) {
    if (!list)
        return;
    if (check(list, P))
        creanodo_p(destination, copy(list, get_lenght(P)));
    match(list->next, P, destination);
}


void match_try(nodo *list, nodo_p *&destination, int dimensione) {
    if (!list)
        return;
    nodo *pattern = copy(list, dimensione);
    if (get_lenght(pattern) < dimensione)
        return;
    match(list, pattern, destination);
    del_lista(pattern);
    match_try(list->next, destination, dimensione);
}

void autoscan(nodo *list, nodo_p *&destination) {
    int size = get_lenght(list);
    for (int i = 0; i < size; i ++){
        match_try(list,destination,i);
    }
}

int main() {

    nodo *L1 = 0;

    cout << "dammi la lista" << endl;
    L1 = leggi();
    stampa_n(L1);

    nodo_p *result = 0;
    autoscan(L1,result);

    cout << "ecco i match fatti" << endl;
    stampa_p(result);

    cout << "inserisci qualcosa e premi invio per chiudere il programma";
    int x ;
    cin >> x;

    return 0;
}


/*
 int data[] = {10, 5, 13};  //Random data we want to send
    FILE *file;
    file = fopen("/dev/ttyUSB0", "w");  //Opening device file
    int i = 0;
    for (i = 0; i < 3; i++) {
        fprintf(file, "%d", data[i]); //Writing to the file
        fprintf(file, "%c", ','); //To separate digits
        sleep(1);
    }
    fclose(file);
 */
