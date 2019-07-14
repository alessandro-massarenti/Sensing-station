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

void stampa_n(nodo *list) {
    if (!list) {
        cout << endl;
        return;
    }
    cout << list->info << ' ';
    stampa_n(list->next);
}

nodo* leggi(){
    int input;
    cin >> input;
    if(input == -1)
        return 0;
    return new nodo(input,leggi());
}

int dim_p(nodo *list) {
    if (!list)
        return 0;
    return 1 + dim_p(list->next);
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

    nodo* L1 = 0;
    L1 = leggi();

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