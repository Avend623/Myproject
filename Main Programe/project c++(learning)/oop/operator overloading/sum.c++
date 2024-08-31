// * method (1) . . .
// #include<iostream>
// using namespace std;
// class Sum
// {
//     private:
//         int x;
//     public:
//         void getValues()
//         {
//             cout<<"enter value of x:";
//             cin>>x;
//         }
//         void sum(Sum ob1,Sum ob2)
//         {
//             cout<<ob1.x<<" + "<<ob2.x<<" = "<<ob1.x+ob2.x<<endl;
//         }
// };
// int main()
// {
//     Sum ob1;
//     ob1.getValues();
//     Sum ob2;
//     ob2.getValues();
//     ob1.sum(ob1,ob2);
//     return 0;
// }
// * method (2) . . .
// #include<iostream>
// using namespace std;
// class Sum
// {
//     private:
//         int x;
//     public:
//         void getValues()
//         {
//             cout<<"enter value of x:";
//             cin>>x;
//         }
//         void sum(Sum ob)
//         {
//             cout<<x<<" + "<<ob.x<<" = "<<x+ob.x<<endl;
//         }
// };
// int main()
// {
//     Sum ob1;
//     ob1.getValues();
//     Sum ob2;
//     ob2.getValues();
//     ob1.sum(ob2);
//     return 0;
// }
// * method (3) . . .
#include<iostream>
using namespace std;
class Sum
{
    private:
        int x;
    public:
        void getValues()
        {
            cout<<"enter value of x:";
            cin>>x;
        }
        void operator +(Sum ob)
        {
            cout<<x<<" + "<<ob.x<<" = "<<x+ob.x<<endl;
        }
};
int main()
{
    Sum ob1;
    ob1.getValues();
    Sum ob2;
    ob2.getValues();
    ob1+ob2;
    return 0;
}