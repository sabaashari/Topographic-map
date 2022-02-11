//includes
#include <iostream>
#include <fstream>
#include <stack>
#include <math.h>
#include <vector>
using namespace std;

//variables
extern int Map[10000][10000];
extern int n;

//Definitions
class Point
{
public:
    int x,y;
    Point(int a, int b)
    {
        x = a;
        y = b;
    }
    vector<Point> find_neighbours()
    {
        vector<Point> Ne;
        if(x>=1)
            Ne.push_back(Point(x-1,y));
        if(y>=1)
            Ne.push_back(Point(x,y-1));
        if(x<n-1)
            Ne.push_back(Point(x+1,y));
        if(y<n-1)
            Ne.push_back(Point(x,y+1));
        return Ne;
    }
};

//Declerations
void get_input();
void give_output(vector<Point>);
vector<Point> find_max_area_points();
