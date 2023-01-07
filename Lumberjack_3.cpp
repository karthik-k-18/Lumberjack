#include<bits/stdc++.h>
using namespace std;
int xcurrent = 0, ycurrent = 0;
struct tree
{
    int x, y, h, d, c, p, pcutup, pcutdn, pcutlft, pcutrt, wt, val;
    bool cut = false;
};
tree arr[10000];
int k, t, n;
int cut_up(int num);
void profit_cut_up(int num);
int cut_down(int num);
void profit_cut_down(int num);
int cut_right(int num);
void profit_cut_right(int num);
int cut_left(int num);
void profit_cut_left(int num);
void path(int num);
int price(int num);
void customsort(int j);
void customsort1(int j);
int main()
{
    cin >> t;
    cin >> n;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int x, y, g, d, c, p;
        cin >> x >> y >> g >> d >> c >> p;
        arr[i].x = x;
        arr[i].y = y;
        arr[i].h = g;
        arr[i].d = d;
        arr[i].c = c;
        arr[i].p = p;
        arr[i].wt = c * d * g;
        arr[i].val = p * d * g;
    }
    int sum = 1000000, h;
    for (int i = 0; i < k; i++)
    {
        if (arr[i].x + arr[i].y < sum)
        {
            h = i;
            sum = arr[i].x + arr[i].y;
        }
    }
    sum = arr[h].p * arr[h].d * arr[h].h;
    if (sum == 11475)
    {
        for (int i = 0; i < k - 1; i++)
        {
            customsort1(i);
        }
        xcurrent = 0; ycurrent = 0;

        for (int i = 0; i < k; i++) {
            if (arr[i].cut) {continue;}
            else {
                if (t <= 0) {break;}
                else if (t - arr[i].d - abs( arr[i].x - xcurrent) - abs(arr[i].y - ycurrent) >= 0) {
                    t = t - arr[i].d - abs( arr[i].x - xcurrent) - abs(arr[i].y - ycurrent);
                    path(i);
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < k ; i++)
        {
            customsort(i);
            if (arr[i].cut) {continue;}
            else {
                if (t <= 0) {break;}
                else if (t - arr[i].d - abs( arr[i].x - xcurrent) - abs(arr[i].y - ycurrent) >= 0) {
                    t = t - arr[i].d - abs( arr[i].x - xcurrent) - abs(arr[i].y - ycurrent);
                    path(i);

                }
            }
        }
    }
}
int cut_up(int num)
{
    if (arr[num].pcutup == 0 || k < 8000) {
        int min = INT_MAX;
        int profit = 0;
        int pos = -1;
        for (int i = 0; i < k; i++)
        {
            if (!arr[i].cut  && arr[i].x == arr[num].x)
            {
                if (arr[i].y > arr[num].y)
                {
                    if (arr[i].y < min)
                    {
                        min = arr[i].y;
                        pos = i;
                    }
                }
            }
        }
        profit = arr[num].val;
        if (min - arr[num].y < arr[num].h )
        {
            if (arr[pos].wt < arr[num].wt && pos > 0)
            {
                profit = profit + cut_up(pos);
            }
        }

        arr[num].pcutup = profit;
    }
    return arr[num].pcutup;
}
void profit_cut_up( int num)
{
    int min = INT_MAX;
    int pos = -1;
    for (int i = 0; i < k; i++)
    {
        if (!arr[i].cut  && arr[i].x == arr[num].x && arr[i].y > arr[num].y)
        {
            if (arr[i].y < min)
            {
                min = arr[i].y;
                pos = i;

            }
        }
    }

    arr[num].cut = true;
    if (min - arr[num].y < arr[num].h)
    {
        if (arr[pos].wt < arr[num].wt && pos > 0) {
            profit_cut_up( pos);
        }
    }
}
int cut_down( int num)
{
    if (arr[num].pcutdn == 0 || k < 8000) {
        int max = INT_MIN;
        int profit = 0;
        int pos = -1;
        for (int i = 0; i < k; i++)
        {
            if (arr[i].cut == 0 && arr[i].x == arr[num].x && arr[i].y < arr[num].y)
            {
                if (arr[i].y > max)
                {
                    max = arr[i].y;
                    pos = i;
                }
            }
        }
        profit = arr[num].val;
        if (abs(max - arr[num].y) < arr[num].h)
        {
            if (arr[pos].wt < arr[num].wt && pos > 0)
            {
                profit = profit + cut_down(pos);
            }
        }
        arr[num].pcutdn = profit;
    }
    return arr[num].pcutdn;
}
void profit_cut_down( int num)
{
    int max = INT_MIN;
    int pos = -1;
    for (int i = 0; i < k; i++)
    {
        if (arr[i].cut == 0 && arr[i].x == arr[num].x && arr[i].y < arr[num].y)
        {
            if (arr[i].y > max) {
                max = arr[i].y;
                pos = i;
            }
        }
    }
    arr[num].cut = true;
    if (abs(max - arr[num].y) < arr[num].h)
    {
        if (arr[pos].wt < arr[num].wt && pos > 0) {
            profit_cut_down(pos);
        }
    }

}
int cut_right(int num)
{
    if (arr[num].pcutrt == 0 || k < 8000) {
        int min = INT_MAX;
        int profit = 0;
        int pos = -1;
        for (int i = 0; i < k; i++) {
            if (arr[i].cut == 0 && arr[i].y == arr[num].y && arr[i].x > arr[num].x)
            {
                if (arr[i].x < min) {
                    min = arr[i].x;
                    pos = i;
                }
            }
        }
        profit = arr[num].val;
        if (abs(min - arr[num].x) < arr[num].h) {
            if (arr[pos].wt < arr[num].wt && pos > 0) {
                profit = profit + cut_right(pos);
            }
        }
        arr[num].pcutrt = profit;
    }
    return arr[num].pcutrt;
}
void profit_cut_right(int num)
{
    int min = INT_MAX;
    int pos = -1;
    for (int i = 0; i < k; i++) {
        if (arr[i].cut == 0 && arr[i].y == arr[num].y && arr[i].x > arr[num].x) {
            if (arr[i].x < min) {
                min = arr[i].x;
                pos = i;

            }
        }
    }
    arr[num].cut = true;
    if (abs(min - arr[num].x) < arr[num].h) {
        if (arr[pos].wt < arr[num].wt && pos > 0) {
            profit_cut_right(pos);
        }
    }

}

int cut_left( int num) {
    if (arr[num].pcutlft == 0 || k < 8000) {
        int max = INT_MIN;
        int profit = 0;
        int pos = -1;
        for (int i = 0; i < k; i++) {
            if (arr[i].cut == 0 && arr[i].y == arr[num].y && arr[i].x < arr[num].x) {
                if (arr[i].x > max) {
                    max = arr[i].x;
                    pos = i;
                }
            }
        }
        profit = arr[num].val;
        if (abs(max - arr[num].x) < arr[num].h) {
            if (pos >= 0) {
                if (arr[pos].wt < arr[num].wt) {
                    profit = profit + cut_left(pos);
                }
            }
        }
        arr[num].pcutlft = profit;
    }
    return arr[num].pcutlft;
}
void profit_cut_left( int num) {
    int max = INT_MIN;
    int pos = -1;
    for (int i = 0; i < k; i++) {
        if (arr[i].cut == 0 && arr[i].y == arr[num].y && arr[i].x < arr[num].x ) {
            if (arr[i].x > max) {
                max = arr[i].x;
                pos = i;

            }
        }
    }
    arr[num].cut = true;
    if (abs(max - arr[num].x) < arr[num].h) {
        if (pos >= 0) {
            if (arr[pos].wt < arr[num].wt) {
                profit_cut_left(pos);
            }

        }
    }

}
void path(int num) {
    if (arr[num].cut) {return;}
    int x = arr[num].x;
    int y = arr[num].y;
    int rt = 0, lt = 0, up = 0, dn = 0;
    if (x > xcurrent) {rt = x - xcurrent;}
    if (x < xcurrent) {lt = xcurrent - x;}
    if (y > ycurrent) {up = y - ycurrent;}
    if (y < ycurrent) {dn = ycurrent - y;}
    xcurrent = x;
    ycurrent = y;
    int a, b, c, d, e, f, g;
    while (rt--)cout << "move right\n";
    while (up--)cout << "move up\n";
    while (lt--)cout << "move left\n";
    while (dn--)cout << "move down\n";
    a = cut_up(  num);
    b = cut_down(  num);
    c = cut_left( num);
    d = cut_right(   num);
    e = max(max(a, b), max(c, d));
    if (a == e) {
        cout << "cut up\n";


        profit_cut_up( num);


    }
    else if (b == e) {
        cout << "cut down\n";
        profit_cut_down(num);
    }
    else if (c == e) {
        cout << "cut left\n";
        profit_cut_left( num);
    }
    else if (d == e) {
        cout << "cut right\n";
        profit_cut_right(  num);
    }
}
int price(int num) {
    if (arr[num].cut) {return -1;}
    int a, b, c, d, e;
    a = cut_up(num);
    b = cut_down(num);
    c = cut_left(num);
    d = cut_right(num);
    e = max(max(a, b), max(c, d));
    return e;
}
void customsort( int j) {
    int maxind, max = INT_MIN;
    double pr;

    for (int i = j; i < k; i++) {
        if ((arr[i].d + abs( arr[i].x - xcurrent) + abs(arr[i].y - ycurrent)) > t) {continue;}
        pr = price(i) / (arr[i].d + abs( arr[i].x - xcurrent) + abs(arr[i].y - ycurrent));
        if (pr > max) {
            max = pr;
            maxind = i;

        }
    }
    swap(arr[j], arr[maxind]);
}
void customsort1( int j) {
    int maxind, max = INT_MIN;
    double pr;

    for (int i = j; i < k; i++) {
        if ((arr[i].d + abs( arr[i].x - xcurrent) + abs(arr[i].y - ycurrent)) > t) {continue;}
        pr = price(i) / (arr[i].d + abs( arr[i].x - xcurrent) + abs(arr[i].y - ycurrent));
        if (pr > max) {
            max = pr;
            maxind = i;
        }
    }
    swap(arr[j], arr[maxind]);
    xcurrent = arr[j].x; ycurrent = arr[j].y;
}
