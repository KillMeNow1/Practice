#include<stdio.h>
#include<stdlib.h>



typedef struct Point
{
    double x;
    double y;
    double z;
}point;

/* You will have to implent this function!!! */
double distance(point P1, point P2)
{
	return 0.0;	
}

int main(int argc, char *argv[])
{
	point P1,P2;
	double d_distance;

	scanf("%lf %lf %lf %lf %lf %lf",&P1.x,&P1.y,&P1.z,&P2.x,&P2.y,&P2.z);
	d_distance = distance(P1,P2);
	printf("The distance between the points is: %.2lf\n",d_distance);

	return 0;
}
