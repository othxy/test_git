#include<stdio.h>
#include<stdlib.h>

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point p0;
    Point p1;
    Point p2;
} Triangle;

typedef struct {
    Point p00;
    Point p11;
} Rectangle; 


int point_in_triangle(Point p, Triangle t){
    double as_x = p.x - t.p0.x;
    double as_y = p.y - t.p0.y;
    
    double s_ab = (t.p1.x - t.p0.x) * as_y - (t.p1.y - t.p0.y) * as_x;
    double h1 = (t.p2.x - t.p0.x) * as_y - (t.p2.y - t.p0.y) * as_x;
    double h2 = (t.p2.x - t.p1.x) * (p.y - t.p1.y) - (t.p2.y - t.p1.y) * (p.x - t.p1.x);
    
    int s_ab_b = 0;
    int h1_b = 0;
    int h2_b = 0;
    
    if (s_ab > 0){
        s_ab_b = 1;
    }
    if (h1 > 0){
        h1_b = 1;
    }
    if (h2 > 0){
        h2_b = 1;
    } 
    if ((h1_b == s_ab_b) || (h2_b != s_ab_b)){
        return 0;
    }
    
    return 1;
}


int point_in_rectangle(Point p, Rectangle r){
    if (p.x > r.p00.x && p.x < r.p11.x && p.y > r.p00.y && p.y < r.p11.y){
        return 1;
    }
    return 0;
}


int main(int argc, char**){

    Point p0 = {0.0, 0.0};
    Point p1 = {2.0, 2.0};
    Point p2 = {4.0, 0.0};
    Triangle t = {p0, p1, p2};
    int res = 0;
    Point p = {2.0, 1.0};
    res = point_in_triangle(p, t);
    printf("%d\n", res);
    
    // rectangle 
    Point px = {0.5, 0.5};
    Rectangle r = {p0, p1};
    res = point_in_rectangle(px, r);
    printf("%d\n", res);
    
    return 0;
}
