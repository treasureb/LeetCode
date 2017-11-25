#include<iostream>
using namespace std;

class HammingDistance
{
public:
     HammingDistance(int x,int y)
       :_x(x)
       ,_y(y)
      {}
        
    int DiffBits1()
    {
       int diffcounts = 0;
       int exc = _x^_y;
   
       while(exc)
       {
          ++diffcounts;
          exc &= (exc -1);
       }

          return diffcounts;
     }

    int DiffBits2()
    {
        int diffcounts = 0;
        for(int i =0;i<32;++i)
        {
            if((_x&(1<<i))^(_y&(1<<i)))
                diffcounts++;
        }

        return diffcounts;
    }

    int DiffBits3()
    {
        int diffcounts = 0;
        int exc = _x ^ _y;
        for(int i = 0;i < 32;++i)
        {
            diffcounts += (exc >> i) & 1;
        }
        
        return diffcounts;
    };

private:
    int _x;
    int _y;
};

int DiffBits4(int x,int y)
{
    if((x ^ y) == 0)
        return 0;
    return (x ^ y) % 2 + DiffBits4(x>>1,y>>1);
}

int main()
{
    HammingDistance hd(1,4);
    cout<<hd.DiffBits1()<<endl;
    cout<<hd.DiffBits2()<<endl;
    cout<<hd.DiffBits3()<<endl;
    cout<<DiffBits4(1,4)<<endl;
    return 0;
}
