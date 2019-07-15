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

int dimension(nodo *list) {
    if (!list)
        return 0;
    return 1 + dimension(list->next);
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
        creanodo_p(destination, copy(list, dimension(P)));
    match(list->next, P, destination);

}

int main() {

    nodo *L1 = 0;

    cout << "dammi la lista" << endl;
    L1 = leggi();
    stampa_n(L1);
    cout << "dammi il pattern" << endl;

    nodo *P = 0;
    P = leggi();
    stampa_n(P);

    nodo_p *R = 0;

    match(L1, P, R);

    cout << "ecco i match fatti" << endl;
    stampa_p(R);


    cout << dimension(L1);

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

/*

nodo *sequence_check(nodo *list, int dim_P) {

}

nodo_p *pattern_finder(nodo *list) {
    if (!list)
        return 0;
    if (!)
        return pattern_finder(list->next);
}
*/