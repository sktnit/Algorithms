#include <iostream>
#include <vector>
#include <cstdlib>
#include <climits>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int size_of_vector;
    signed long num_of_rotations;
    int input;
    cin>>size_of_vector;
    vector<int>v1;
    for(int i=0;i<size_of_vector;++i){
        cin>>input;
        v1.push_back(input);
    }
    /*pushes back the first element in vector and
    deletes the first element(which was added to back)         which creates a shift
    */
    cin>>num_of_rotations;
    if(num_of_rotations<0)
    {
        int x;
        x=abs(num_of_rotations%=size_of_vector);

    for(int i=0;i<x;++i){
        int temp=v1.at(0);
        v1.push_back(temp);
        v1.erase(v1.begin());
    }
    }
    for(int i=0;i<size_of_vector;++i){
        std::cout<<v1.at(i)<<" ";
    }
     return 0;
}
