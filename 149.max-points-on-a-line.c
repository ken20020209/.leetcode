/*
 * @lc app=leetcode id=149 lang=c
 *
 * [149] Max Points on a Line
 */
#include "header\leetcode.h"

// @lc code=start
// ax+by+c=0
// m1=m2
// y-y1=y1-y2
// x-x1=x1-x2
// y-y1=(x-x1)*(y1-y2)/(x1-x2)
// y-y1=x*(y1-y2)/(x1-x2)-x1*(y1-y2)/(x1-x2)
// y*(x1-x2)-y1*(x1-x2)=x*(y1-y2)-x1*(y1-y2)
//(x1-x2)*y-(y1-y2)*x+(x1*(y1-y2)-y1*(x1-x2))=0

// a=y1-y2
// b=x1-x2
// c=x1*(y1-y2)-y1*(x1-x2)
#define MAPSIZE 5000
#define abs(a) (((a) < 0) ? -(a) : (a))
int findAddress(int map[MAPSIZE][4], int a, int b, int c)
{
    int address = a * 31 * 31 + b * 31 + c;
    address %= MAPSIZE;
    address = abs(address);
    while (map[address][3] != 0 && !(map[address][0] == a && map[address][1] == b && map[address][2] == c))
        address = address + 1 % MAPSIZE;
    return address;
}
int GCD(int a, int b)
{
    if (b)
        while ((a %= b) && (b %= a))
            ;
    return a + b;
}
int maxPoints(int **points, int pointsSize, int *pointsColSize)
{
    // 0=a 1=b 2=c 3=cnt
    int res = 0;
    int map[MAPSIZE][4] = {0};
    for (int i = 0; i < pointsSize; i++)
    {
        for (int j = 0; j < pointsSize; j++)
        {
            if (i == j)
                continue;
            int x1 = points[i][0], y1 = points[i][1], x2 = points[j][0], y2 = points[j][1];
            int a = y1 - y2;
            int b = x1 - x2;
            int c = x1 * (y1 - y2) - y1 * (x1 - x2);
            if (a < 0)
            {
                a = -a;
                b = -b;
                c = -c;
            }
            int gcd = GCD(abs(a), abs(b));
            gcd = GCD(gcd, abs(c));
            // printf("    x1:%d y1:%d x2:%d y2:%d\n", x1, y1, x2, y2);
            // printf("    gcd:%d\n", gcd);
            a /= gcd;
            b /= gcd;
            c /= gcd;
            int address = findAddress(map, a, b, c);
            // printf("    a:%d b:%d c:%d\n", a, b, c);
            map[address][0] = a;
            map[address][1] = b;
            map[address][2] = c;
            map[address][3]++;
            res = fmax(res, map[address][3]);
        }
        memset(map, 0, sizeof(map));
    }
    return res + 1;
}
// @lc code=end
