#include<bits/stdc++.h>
using namespace std;
int xcurrent = 0, ycurrent = 0;
struct tree
{
    int x, y, h, d, c, p;
    bool cut = false;
};
tree arr[10000];
int k;
int cut_up(int index) 
{
    int min = INT_MAX;
    int profit = 0;
    int pos = -1;
    for (int i = 0; i < k; i++) 
    {
        if (!arr[i].cut  && arr[i].x == arr[index].x) 
        {
                if(arr[i].y > arr[index].y)
                {
                        if (arr[i].y < min) 
                                {
                                 min = arr[i].y;
                                 pos = i;
                                }
                }
        }
    }
    profit = arr[index].h * arr[index].d * arr[index].p;
    if (min - arr[index].y < arr[index].h ) 
    {
        if (arr[pos].h * arr[pos].d * arr[pos].c < arr[index].h * arr[index].d * arr[index].c && pos > 0) 
        {
            profit = profit + cut_up(pos);
        }
    }

    return profit;
}
void profit_cut_up( int index) 
{
    int min = INT_MAX;
    int pos = -1;
    for (int i = 0; i < k; i++) 
    {
        if (!arr[i].cut  && arr[i].x == arr[index].x && arr[i].y > arr[index].y) 
        {
            if (arr[i].y < min) 
            {
                min = arr[i].y;
                pos = i;

            }
        }
    }

    arr[index].cut = true;
    if (min - arr[index].y < arr[index].h) 
    {
        if (arr[pos].h * arr[pos].d * arr[pos].c < arr[index].h * arr[index].d * arr[index].c && pos > 0) {
            profit_cut_up( pos);
        }
    }
}
int cut_down( int index) 
{
    int max = INT_MIN;
    int profit = 0;
    int pos = -1;
    for (int i = 0; i < k; i++) 
    {
        if (arr[i].cut == 0 && arr[i].x == arr[index].x && arr[i].y < arr[index].y) 
        {
            if (arr[i].y > max) 
            {
                max = arr[i].y;
                pos = i;
            }
        }
    }
    profit = arr[index].h * arr[index].d * arr[index].p;
    if (abs(max - arr[index].y) < arr[index].h) 
    {
        if (arr[pos].h * arr[pos].d * arr[pos].c < arr[index].h * arr[index].d * arr[index].c && pos > 0) 
        {
            profit = profit + cut_down(pos);
        }
    }
    return profit;
}
void profit_cut_dowm( int index) 
{
    int max = INT_MIN;
    int pos = -1;
    for (int i = 0; i < k; i++) 
    {
        if (arr[i].cut == 0 && arr[i].x == arr[index].x && arr[i].y < arr[index].y) 
        {
            if (arr[i].y > max) {
                max = arr[i].y;
                pos = i;
            }
        }
    }
    arr[index].cut = 1;
    if (abs(max - arr[index].y) < arr[index].h) 
    {
        if (arr[pos].h * arr[pos].d * arr[pos].c < arr[index].h * arr[index].d * arr[index].c && pos > 0) {
            profit_cut_dowm(pos);
        }
    }

}
int cut_right(int index) 
{
    int min = INT_MAX;
    int profit = 0;
    int pos = -1;
    for (int i = 0; i < k; i++) {
        if (arr[i].cut == 0 && arr[i].y == arr[index].y && arr[i].x > arr[index].x) 
        {
            if (arr[i].x < min) {
                min = arr[i].x;
                pos = i;
            }
        }
    }
    profit = arr[index].h * arr[index].d * arr[index].p;
    if (abs(min - arr[index].x) < arr[index].h) {
        if (arr[pos].h * arr[pos].d * arr[pos].c < arr[index].h * arr[index].d * arr[index].c && pos > 0) {
            profit = profit + cut_right(pos);
        }
    }
    return profit;
}
void profit_cut_right( int index) {
    int min = INT_MAX;
    int pos = -1;
    for (int i = 0; i < k; i++) {
        if (arr[i].cut == 0 && arr[i].y == arr[index].y && arr[i].x > arr[index].x) {
            if (arr[i].x < min) {
                min = arr[i].x;
                pos = i;

            }
        }
    }
    arr[index].cut = 1;
    if (abs(min - arr[index].x) < arr[index].h) {
        if (arr[pos].h * arr[pos].d * arr[pos].c < arr[index].h * arr[index].d * arr[index].c && pos > 0) {
            profit_cut_right(pos);
        }
    }

}

int cut_left( int index) {
    int max = INT_MIN;
    int profit = 0;
    int pos = -1;
    for (int i = 0; i < k; i++) {
        if (arr[i].cut == 0 && arr[i].y == arr[index].y && arr[i].x < arr[index].x) {
            if (arr[i].x > max) {
                max = arr[i].x;
                pos = i;
            }
        }
    }
    profit = arr[index].h * arr[index].d * arr[index].p;
    if (abs(max - arr[index].x) < arr[index].h) {
        if (pos >= 0) {
            if (arr[pos].h * arr[pos].d * arr[pos].c < arr[index].h * arr[index].d * arr[index].c) {
                profit = profit + cut_left(pos);
            }
        }
    }
    return profit;
}
void profit_cut_left( int index) {
    int max = INT_MIN;
    int pos = -1;
    for (int i = 0; i < k; i++) {
        if (arr[i].cut == 0 && arr[i].y == arr[index].y && arr[i].x < arr[index].x ) {
            if (arr[i].x > max) {
                max = arr[i].x;
                pos = i;

            }
        }
    }
    arr[index].cut = 1;
    if (abs(max - arr[index].x) < arr[index].h) {
        if (pos >= 0) {
            if (arr[pos].h * arr[pos].d * arr[pos].c < arr[index].h * arr[index].d * arr[index].c) {
                profit_cut_left(pos);
            }

        }
    }

}

bool custom(const tree &a,const tree &b)
{
    double p, q;
    p = ((a.p) * (a.h) * (a.d)) / (a.x + a.y + a.d);
    q = ((b.p) * (b.h) * (b.d)) / (b.x + b.y + b.d);
    return p > q;
}
void path(int index) {
    int x = arr[index].x;
    int y = arr[index].y;
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
    a = cut_up(  index);
    b = cut_down(  index);
    c = cut_left( index);
    d = cut_right(   index);
    e = max(max(a, b), max(c, d));
    if (a == e) {
        cout << "cut up\n";


        profit_cut_up( index);


    }
    else if (b == e) {
        cout << "cut down\n";
        profit_cut_dowm(index);


    }
    else if (c == e) {
        cout << "cut left\n";

        profit_cut_left( index);




    }
    else if (d == e) {
        cout << "cut right\n";
        profit_cut_right(  index);


    }


}
int price(int index) {
    int a, b, c, d, e;
    a = cut_up(index);
    b = cut_down(index);
    c = cut_left(index);
    d = cut_right(index);
    e = max(max(a, b), max(c, d));
    return e;
}
void customsort( int j,int t) {
    int maxind, max = INT_MIN;
    double pr;

    for (int i = j; i < k; i++) {
        pr = price(i) / (arr[i].d + abs( arr[i].x - xcurrent) + abs(arr[i].y - ycurrent));
        if (pr > max) {
            if((arr[i].d + abs( arr[i].x - xcurrent) + abs(arr[i].y - ycurrent))>t){continue;}
            max = pr;
            maxind = i;

        }
    }
    swap(arr[j], arr[maxind]);
    xcurrent = arr[0].x; ycurrent = arr[0].y;
}

int main()
{

// #ifndef ONLINE_JUDGE
//         freopen("i.txt", "r", stdin);
// //         freopen("error.txt", "w", stderr);
//         freopen("die.txt", "w", stdout);
// #endif
    int t, n;
    cin >> t;
    cin >> n;
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        cin >> arr[i].x;
        cin >> arr[i].y;
        cin >> arr[i].h;
        cin >> arr[i].d;
        cin >> arr[i].c;
        cin >> arr[i].p;

    }
    // sort(arr, arr + k, custom);
    for (int i = 0; i < k - 1; i++) {
        customsort(i,t);
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
