#include <stdio.h>

float a[5];
int main()
{
    float max_();
    float min_();
    int i;
    for(i=0;i<5;i++)
        scanf("%f",&a[i]);
    max_();
    min_();
    printf("max=%.1f,min=%.1f\n",max_(),min_());
    return 0;

}
float max_()
{
    int i;
    float max;
    max=a[0];
    for(i=1;i<=5;i++)
    {
        if(max<a[i])
            max=a[i];

    }
    return max;


}

float min_()
{
    int i;
    float min;
    min=a[0];
    for(i=1;i<=5;i++)
    {
        if(min>a[i])
            min=a[i];

    }
    return min;


}
