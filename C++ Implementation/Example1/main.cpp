#include<iostream>
using namespace std;

class point{
public:
int x,y;
void pointoff(int x,int y){
    this->x=this->x +x;
    this->y=this->y +y;
}
void pr(point p){
cout<<"("<<p.x<<","<<p.y<<")";
}
};
class vector{
public:
point start;
point end;

void vectoroffset(int x,int y)
{

start.pointoff(x,y);
end.pointoff(x,y);
}
void printvector(vector v)
{
start.pr(start);
cout<< "->";
end.pr(end);
}
};
int main()
{
vector ve;
cin>>ve.start.x>>ve.start.y>>ve.end.x>>ve.end.y;
ve.vectoroffset(1,1);
ve.printvector(ve);
return 0;
}
