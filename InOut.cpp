#include "header.h"

void get_input()
{
    ifstream in;
	in.open("InOut/in.txt"); // open the read file
    in >> n ; // get size of the map
    for(int i=0;i<n;i++)
    {
		//get the height of each point in the map
        for(int j=0;j<n;j++)
        {
            int height;
            in >> height;
            Map[i][j] = height;
        }
    }
	in.close();
}

//express if each point belongs to the maximum connected surface
bool is_max_area[10000][10000];
void give_output(vector<Point> max_area_points)
{

	//make is_max_area from vector of max_area_points
	for(vector<Point>::iterator it= max_area_points.begin();it!=max_area_points.end();it++)
	{
		Point p = *it;
		is_max_area[p.x][p.y] = true;
	}
    //open the file to write to
	ofstream out;
	out.open("InOut\\out.txt");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(is_max_area[i][j])
                out << "o"; //if i,j belongs to max_area_points out 'o'
            else
                out << "."; // else out '.'
        }
        out << endl;
    }
	out.close();
}

