#include "header.h"
//boolean array to check which pooints have been seen
bool is_seen[10000][10000];

//find the connected area starting from 'start' point using stack instead of dfs
vector<Point> find_area(Point start)
{
    vector<Point> current_area_points; //vector containing the area points connected
    
	stack<Point> surface_points; //the stack containg connected points
    surface_points.push(start); //add start to the stack
    
	is_seen[start.x][start.y] = true;
	int height = Map[start.x][start.y]; //the height of current area
    
	while (!surface_points.empty()) //while stack contains point
    {
        Point current_point = surface_points.top(); // pop the top point of the stack
		surface_points.pop();

		current_area_points.push_back(current_point); //add current point to the connected area points
        
		//find the neighbours of current point in according to vertical and horizontal movement
        vector<Point> Ne = current_point.find_neighbours(); 
        for(vector<Point>::iterator it = Ne.begin();it!=Ne.end();it++) //check the neighbours
        {
            Point next_point = *it;
            int x = next_point.x, y = next_point.y;
            if(Map[x][y]==height && !is_seen[x][y]) // add the neighbour point if it hasnot been seen and has same height as the current point
            {
                is_seen[x][y] = true;
                surface_points.push(next_point);
            }
        }
		Ne.clear();
    }
    return current_area_points;
}

//find the maximum connected area, return the points which belong to that area
vector<Point> find_max_area_points()
{
	vector<Point> max_area_points; // points belonging to maximum area surface
    int max_area = 0;

	//start from each point on the map if it hasnot been seen
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!is_seen[i][j])
            {
                Point current_point = Point(i,j);
				//find the connected area starting from current point
                vector<Point> current_area_points = find_area(current_point);
				int current_area = current_area_points.size();

				//if the area is larger than the maximum area found, update maximum area and points
				if(current_area >= max_area)
                {
                    max_area =current_area ;
                    max_area_points = current_area_points;
                }
            }
        }
    }
    return max_area_points;
}
