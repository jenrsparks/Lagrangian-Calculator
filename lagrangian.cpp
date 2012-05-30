#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int main(void) {

int n; // number of points; *never bigger than 6*
int i, j; // counters
int *x, *y; // points (input data)
int u, p1, p2, sum = 0; // holders

system("cls");

/* Get count of points
Restrict user to 6 points or less */
do {
cout << "\tHow many sets of points would you like to enter? ";
cin >> n;
if(n > 6) cout << "\tError: Please limit your sets to groups of 6 or less." << endl;
} while (n > 6);

x = new int[n];
y = new int[n];

/* Get Input */
cout << "\tEnter the points:" << endl;
cout << endl;
for(i = 0; i < n; i++) {
cout << "\tx" << i << ": ";
cin >> *(x + i);
cout << "\ty" << i << ": ";
cin >> *(y + i);
cout << endl;
}

/* Show Input */
cout << "\n\tEntered Data:" << endl;
cout << endl;
for(i = 0; i < n; i++) {
cout << "\t\t(" << *(x+i) << ", " << *(y+i) << ")" << endl;
} // i

cout << "\n\n\tWhat is the value of u? >> ";
cin >> u;

/* Process Points */
for(i = 0; i < n; i++) {
p1 = 1;
p2 = 1;
for(j = 0; j < n; j++) {
if(j != i) {
p1 = p1 * (u - *(x+j) );
p2 = p2 * ( *(x+i) - *(x+j) );
} // if
} // for j
p2 = p1 / p2 * *(y+i);
sum = sum + p2;
} // for i

cout << "\n\n\tThe value of y is " << sum << ".\n\n";

cout << "\tPress any key to exit.";
getchar();

delete [] x, y;
exit(0);
}