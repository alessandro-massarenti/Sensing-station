#import <iostream>

using namespace std;

int main() {
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