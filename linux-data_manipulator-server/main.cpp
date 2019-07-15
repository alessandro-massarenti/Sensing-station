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

void aggiungi_nodo_p(nodo_p *&raccolta, nodo *list) {

}

void stampa_n(nodo *list) {
    if (!list) {
        cout << endl;
        return;
    }
    cout << list->info << ' ';
    stampa_n(list->next);
}

nodo *leggi() {
    int input;
    cin >> input;
    if (input == -1)
        return 0;
    return new nodo(input, leggi());
}

int dim_p(nodo *list) {
    if (!list)
        return 0;
    return 1 + dim_p(list->next);
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

nodo *match(nodo *list, nodo *P) {
    if (!list)
        return 0;
    if (check(list, P)) {
        return copy(list, dim_p(P));
    } else {
        return match(list->next, P);
    }

}

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

int main() {

    nodo *L1 = 0;

    cout << "dammi la lista" << endl;
    L1 = leggi();
    stampa_n(L1);
    cout << "dammi il pattern" << endl;

    nodo *P = 0;
    P = leggi();
    stampa_n(P);

    nodo *R = match(L1, P);
    stampa_n(R);


    cout << dim_p(L1);

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