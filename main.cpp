#include "header.h"

/*Global variables Related to Map*/
int Map[10000][10000];
int n;

int main()
{
    get_input();

	//find the points on the map related to the maximum connected area
    vector<Point> max_area_points = find_max_area_points();

    give_output(max_area_points);
    
	return 0;
}
