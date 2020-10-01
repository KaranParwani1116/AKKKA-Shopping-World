#include <iostream>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <map>
#include <vector>
#include <algorithm>
#define V 9
using namespace std;
//comment
int price=0;
vector<string>v1;
vector<int>v3,city;
int count1=0;
class lbar
{
public:
    void create()
    {
        for(int i=0;i<15;i++)
        {
            cout<<"  ";
        }
        cout<<"WELCOME TO THE AKKK SHOPPING WORLD "<<endl<<endl;
        char a=177;
        char b=219;
        for(int i=0;i<15;i++)
            cout<<a;
            cout<<"\r";
 cout<<"\t\t\t\t";
 for (int i=0;i<=25;i++)
 {
  cout<<b;
  for (int j=0;j<=1e8;j++);
 }
 cout<<endl;
        system("PAUSE");
        system("CLS");
    }

    void gotoy(int y)
    {
        for(int i=0;i<y;i++)
        {
            cout<<endl;
        }
    }
    void gotox(int x)
    {
        for(int i=0;i<15;i++)
            cout<<"  ";
    }
};

class bill
{
  vector<string>v2;
    bool *sptset;
    int v;
    int *dist;
 public:
     bill(int d)
     {
         v=d;
         sptset=new bool(v);
         dist=new int(v);
         for(int i=0;i<v;i++)
         {
             dist[i]=INT_MAX;
             sptset[i]=false;
         }
         v2.push_back("Banglore");
         v2.push_back("New delhi");
         v2.push_back("Jaipur");
         v2.push_back("Pune");
         v2.push_back("Mumbai");
         v2.push_back("Kolkata");
         v2.push_back("Agra");
         v2.push_back("Ajmer");
         v2.push_back("Orrisa");
     }
     void billpayment()
     {
         if(price!=0)
         {
                 int arr[9][9] = {
                        {0 , 4, 1, 1, 1, 1, 8, 1},
                        {4, 0, 8, 1, 1, 1, 1, 11, 1},
                        {1, 8, 0, 7, 1, 4, 1, 1, 2},
                        {1, 1, 7, 0, 9, 14, 1, 1, 1},
                        {1, 1, 1, 9, 0, 10, 1, 1, 1},
                        {1, 1, 4, 14, 10, 0, 2, 1, 1},
                        {1, 1, 1, 1, 1, 2, 0, 1, 6},
                        {8, 11, 1, 1, 1, 1, 1, 0, 7},
                        {1, 1, 2, 1, 1, 1, 6, 7, 0}
                     };
         dijkistra(arr,0);
         string name;
         int x;
         cout<<"Enter Your Name Sir"<<endl;
         cin>>name;
         system("CLS");
         for(int i=1;i<v;i++)
         {
             cout<<i<<":-"<<v2[i]<<endl<<endl;
         }
         cout<<"Choose your location"<<endl;
         cin>>x;
         city.push_back(x);
         system("CLS");
         cout<<"Name:-"<<name<<endl;
         cout<<"Items Purchased:-"<<endl;

         for(int i=0;i<v1.size();i++)
            cout<<v1[i]<<endl<<endl;

            //cout<<endl<<endl<<"Your Order will be delivered in "<<dist[x]<<" days";
            cout<<"Approximate time of your delivery will be given after entertaining all costumers "<<endl;

         cout<<endl<<endl<<"You have to pay RS "<<price<<" "<<name;
         cout<<endl;
         system("PAUSE");
         system("CLS");
         cout<<"Thankyou for visiting AKKK SHOPPING WORLD"<<endl;
         while(!v1.empty())
            v1.pop_back();
        while(!v3.empty())
            v3.pop_back();
         price=0;
         system("PAUSE");
         system("CLS");
         }
         else
         {
             cout<<"You didn't purchase anything what type of bill u are asking.....Bikhari......"<<endl;
             system("PAUSE");
             system("CLS");
         }
     }
    void dijkistra(int arr[9][9],int src)
    {
        dist[src]=0;
        for(int i=0;i<v;i++)
        {
            int u=min_distance();
            sptset[u]=true;


            for(int j=0;j<v;j++)
            {
                if(!sptset[j] && arr[u][j] && dist[u]!=INT_MAX && dist[u]+arr[u][j]<dist[j])
                {
                    dist[j]=dist[u]+arr[u][j];
                }
            }
        }
    }

     int min_distance()
    {
        int minimum=INT_MAX;
        int min_index;
        for(int i=0;i<v;i++)
        {
            if(sptset[i]==false && dist[i]<=minimum)
            {
                minimum=dist[i];
                min_index=i;
            }
        }
        return(min_index);
    }
};

class tshirt
{
    int *stock;
    lbar *l;
    map<int,string>m;
public:
    tshirt()
    {
        m.insert({200,"Manic Checkered t-shirt, color=White-Black,Price=200"});
        m.insert({545,"Printed men V-neck,color=Black,Price=545"});
        m.insert({999,"Peter England University Striped men,Color=Dark Blue,Price=999"});
        m.insert({1050,"Reebok Solo Men,Color=Whitish Red,Price=1050"});
        m.insert({2000,"Tripr Printed men,Color=Grey,Price=2000"});
        stock=new int[m.size()];
        int x;
        x=m.size();
        for(int i=0;i<x;i++)
            stock[i]=10;
    }
    void show()
    {
        l=new lbar;
        int i=1;
        int x;
        map<int,string>::iterator itr;
        l->gotoy(10);
        for(itr=m.begin();itr!=m.end();itr++)
        {
            l->gotox(20);
            cout<<i<<"."<<(*itr).second<<endl<<endl;
            i++;
        }
        cout<<"Select Your Choice:-";
        cin>>x;
        stock[x-1]=stock[x-1]-1;
        if(stock[x-1]<=0)
            cout<<"Item Is out of stock"<<endl;
        else
            cout<<"Item is added to Your Cart"<<endl;

        itr=m.begin();
        for(int i=0;i<x-1;i++)
            itr++;
        price=price+(*itr).first;
        v1.push_back((*itr).second);
        v3.push_back((*itr).first);

            system("Pause");
            system("CLS");
    }
};
class shirt
{
    int *stock;
    lbar *l;
    map<int,string>m;
public:
    shirt()
    {
        m.insert({639,"John Players Men's solid slim casual fit shirt,color=Mehandi,Price=639"});
        m.insert({1009,"Levi's Men's casual shirt,color=Blue,Price=1009"});
        m.insert({899,"Peter England Men's Solid Slim fit,color=white,Price=899"});
        m.insert({549,"Dennis Lingo Men's Solid Collar,color=red,Price=549"});
        m.insert({788,"USPA Men's Casual Shirt,color=Grey,Price=788"});
        stock=new int[m.size()];
        int x;
        x=m.size();
        for(int i=0;i<x;i++)
            stock[i]=10;
    }
    void show()
    {
        l=new lbar;
        int i=1;
        int x;
        map<int,string>::iterator itr;
        l->gotoy(10);
        for(itr=m.begin();itr!=m.end();itr++)
        {
            l->gotox(20);
            cout<<i<<"."<<(*itr).second<<endl<<endl;
            i++;
        }
        cout<<"Select Your Choice:-";
        cin>>x;
        stock[x-1]=stock[x-1]-1;
        if(stock[x-1]<=0)
            cout<<"Item Is out of stock"<<endl;
        else
            cout<<"Item is added to Your Cart"<<endl;

        itr=m.begin();
        for(int i=0;i<x-1;i++)
            itr++;
        price=price+(*itr).first;
        v1.push_back((*itr).second);
        v3.push_back((*itr).first);

            system("Pause");
            system("CLS");
    }
};

class jeans
{
    int *stock;
    lbar *l;
    map<int,string>m;
public:
    jeans()
    {
        m.insert({1439,"Jack & Jones Men's Clark Straight Fit Jeans,color=Blue,Price=1439"});
        m.insert({2099,"Levi's Men Slim Fit Jeans,color=white,Price=2099"});
        m.insert({1021,"John's Players Men's Relaxed Jeans,Color=Dark Blue,Price=1021"});
        m.insert({1599,"KILLER Men's Skinny Fit Jeans,Color=Black,Price=1599"});
        m.insert({2549,"Tommy Hilfiger Men's Skinny Fit,Color=Dark Blue,Price=2549"});
        stock=new int[m.size()];
        int x;
        x=m.size();
        for(int i=0;i<x;i++)
            stock[i]=10;
    }
    void show()
    {
        l=new lbar;
        int i=1;
        int x;
        map<int,string>::iterator itr;
        l->gotoy(10);
        for(itr=m.begin();itr!=m.end();itr++)
        {
            l->gotox(20);
            cout<<i<<"."<<(*itr).second<<endl<<endl;
            i++;
        }
        cout<<"Select Your Choice:-";
        cin>>x;
        stock[x-1]=stock[x-1]-1;
        if(stock[x-1]<=0)
            cout<<"Item Is out of stock"<<endl;
        else
            cout<<"Item is added to Your Cart"<<endl;

        itr=m.begin();
        for(int i=0;i<x-1;i++)
            itr++;
        price=price+(*itr).first;
        v1.push_back((*itr).second);
        v3.push_back((*itr).first);

            system("Pause");
            system("CLS");
    }
};

class shorts
{
    int *stock;
    lbar *l;
    map<int,string>m;
public:
    shorts()
    {
        m.insert({590,"Van Heusen Men's Cotton,color=Black,Price=590"});
        m.insert({499,"Jockey Men's Cotton Shorts,color=Dark Blue,Price=499"});
        m.insert({1124,"Blue saint Women Slim Fit Denim Shorts,Color=Blue,Price=1124"});
        m.insert({899,"Roadster Women Regular Fit Hot Pants,Color=Black,Price=899"});
        m.insert({359,"Leading Lady Women Slim Fit Shorts,Color=Light Pink,Price=359"});
        stock=new int[m.size()];
        int x;
        x=m.size();
        for(int i=0;i<x;i++)
            stock[i]=10;
    }
    void show()
    {
        l=new lbar;
        int i=1;
        int x;
        map<int,string>::iterator itr;
        l->gotoy(10);
        for(itr=m.begin();itr!=m.end();itr++)
        {
            l->gotox(20);
            cout<<i<<"."<<(*itr).second<<endl<<endl;
            i++;
        }
        cout<<"Select Your Choice:-";
        cin>>x;
        stock[x-1]=stock[x-1]-1;
        if(stock[x-1]<=0)
            cout<<"Item Is out of stock"<<endl;
        else
            cout<<"Item is added to Your Cart"<<endl;

        itr=m.begin();
        for(int i=0;i<x-1;i++)
            itr++;
        price=price+(*itr).first;
        v1.push_back((*itr).second);
        v3.push_back((*itr).first);

            system("Pause");
            system("CLS");
    }
};
class update
{
public:
    void show()
    {
        if(v1.size()!=0)
        {
        int x;
        for(int i=0;i<v1.size();i++)
        {
            cout<<i<<":-"<<v1[i]<<endl;
        }
        cout<<"Select the item you want to remove"<<endl;
        cin>>x;
        price=price-v3[x];
        v1.erase(v1.begin()+x);
        v3[x]=0;
        }
        else
        {
            cout<<"Ajeeb bikhari ho yaar"<<endl;
        }
        system("PAUSE");
        system("CLS");
    }
};
// implementation of traveling Salesman Problem
int travllingSalesmanProblem(int graph[][V], int s)
{
    vector<int> vertex;
    for (int i = 0; i < count1; i++)
        if (i != s)
        vertex.push_back(i);
    int min_path = INT_MAX;
    do {
            int current_pathweight = 0;
        int k = s;
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
        k = vertex[i];
        }
        current_pathweight += graph[k][s];
        min_path = min(min_path, current_pathweight);

        }while (next_permutation(vertex.begin(), vertex.end()));
        return min_path;
}
void calc_time()
{
    int arr[9][9] = {
                        {0 , 4, 1, 1, 1, 1,1, 8, 1},
                        {4, 0, 8, 1, 1, 1, 1, 11, 1},
                        {1, 8, 0, 7, 1, 4, 1, 1, 2},
                        {1, 1, 7, 0, 9, 14, 1, 1, 1},
                        {1, 1, 1, 9, 0, 10, 1, 1, 1},
                        {1, 1, 4, 14, 10, 0, 2, 1, 1},
                        {1, 1, 1, 1, 1, 2, 0, 1, 6},
                        {8, 11, 1, 1, 1, 1, 1, 0, 7},
                        {1, 1, 2, 1, 1, 1, 6, 7, 0}
                     };

                     vector<int>::iterator itr1=city.begin();
                     vector<int>::iterator itr2=city.begin();
                     int arr2[9][9];
                     for(int i=0;i<9;i++)
                     {
                         for(int j=0;j<9;j++)
                         {
                             arr2[i][j]=0;
                         }
                     }
                     count1=0;
                     while(itr1!=city.end())
                     {
                         count1++;
                         //cout<<*itr1<<" ";
                         itr1++;
                     }
                     cout<<endl;
                     itr1=city.begin();
                     int row1=0,col1=0;
                     while(itr1!=city.end())
                     {
                         col1=0;
                         itr2=city.begin();
                         while(itr2!=city.end())
                         {
                             arr2[row1][col1++]=arr[*itr1][*itr2];
                             itr2++;
                         }
                         row1++;
                         itr1++;
                     }
                     for(int i=0;i<9;i++)
                     {
                         for(int j=0;j<9;j++)
                         {
                            // cout<<arr2[i][j]<<" ";
                        }
                        cout<<endl;
                     }
                     cout<<"Max time for your delivery is :"<<travllingSalesmanProblem(arr2, 0)<<endl;
}
int main()
{
    int costumers;
    lbar l1;
    tshirt t1;
    bill b1(9);
    jeans j1;
    shirt s1;
    update u1;
    shorts s2;
    l1.gotoy(10);
    l1.create();

    cout<<"Enter the no of costumers"<<endl;
    cin>>costumers;
    for(int i=1;i<=costumers;i++){
    cout<<"Hi ..you are our "<<i<<"th costumer"<<endl;
    int x=0;
    while(x!=7)
    {
        l1.gotoy(10);
    l1.gotox(15);
    cout<<"SELECT YOUR CHOICE"<<endl<<endl<<endl;
    l1.gotox(20);
    cout<<"  1.T-shirt"<<endl<<endl;
    l1.gotox(20);
    cout<<"  2.Shirt"<<endl<<endl;
    l1.gotox(20);
    cout<<"  3.Jeans"<<endl<<endl;
    l1.gotox(20);
    cout<<"  4.Shorts"<<endl<<endl;
    l1.gotox(20);
    cout<<"  5.Bill Payment"<<endl<<endl;
    l1.gotox(20);
    cout<<"  6.Update cart"<<endl<<endl;
    l1.gotox(20);
    cout<<"  7.Exit"<<endl<<endl;
    cin>>x;

    system("CLS");

    switch(x)
    {
    case 1:
        t1.show();
        break;
    case 2:
        s1.show();
        break;
    case 3:
        j1.show();
        break;
    case 4:
        s2.show();
        break;
    case 5:
        b1.billpayment();
        break;
    case 6:
        u1.show();
        break;
    case 7:
        break;
    }
    }
    }
    city.push_back(0);
    calc_time();
}
