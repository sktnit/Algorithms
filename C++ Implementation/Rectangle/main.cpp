#include<iostream>

using namespace std;

class point {
        public:
        int x_coord;
        int y_coord;
};
class Rectangle {
        public:
        point lower_left;  // Lower Left point.
        point upper_right; // Upper Right point.
        int area;
        void readRectangle() {
                cin >> lower_left.x_coord;
                cin >> lower_left.y_coord;
                cin >> upper_right.x_coord;
                cin >> upper_right.y_coord;
        }
        void printRectangle() {
                cout << "(" << lower_left.x_coord << ", " << lower_left.y_coord << ")";
                cout << "("<<  upper_right.x_coord << ", " << upper_right.y_coord << ")  ";
        }
};
 int main() {
        int N, M, i;
        cin >> N; // number of rectangles.
        for (i=0; i< N; i++) {
                // add code to read N input rectangles.
        }
        cin >> M; // number of queries.
        char type;
        for (i=0; i< M; i++) {
                cin >> type;
                if (type == 'I') {
                        int index1, index2;
                        cin >> index1;
                        cin >> index2;
                        // add code to process Intersection query.
                        continue;
                }
                if (type == 'A') {
                        int index;
                        cin >> index;
                        // add code to process Area query.
                        continue;
                }
                if (type == 'C') {
                        int index1, index2;
                        cin >> index1;
                        cin >> index2;
                        // add code to process co-ordinates query.
                        continue;
                }
                if (type == 'S') {
                        // add code to process sort-query.
                        continue;
                }
                if (type == 'P') {
                        int index1, index2, numHops;
                        cin >> index1;
                        cin >> index2;
                        cin >> numHops;
                        // add code to process path query.
                }
        }
        return 0;
}

