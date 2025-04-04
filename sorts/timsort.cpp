#include "sortari.h"

int calculate_minrun(int size) {
    int r = 0;
    while (size >= 64) {
        r |= size & 1;
        size >>= 1;
    }
    return size + r;
}

void merge(std::vector<int> &v,int l,int mid,int r)
{
    std::vector<int>aux;
    int i=l,j=mid+1;

    while( i<=mid and j<=r )
    {
        if( v[i] < v[j] )
        {
            aux.push_back( v[i] );
            i++;
        }
        else
        {
            aux.push_back( v[j] );
            j++;
        }
    }
    while( i<=mid )
    {
        aux.push_back( v[i] );
        i++;
    }
    while( j<=r )
    {
        aux.push_back( v[j] );
        j++;   
    }

    for(int i=l;i<=r;i++)
    {
        v[i]=aux[i-l];
    }

}

void insertion_sort(std::vector<int> &v,int l,int r)
{
    for(int i=l+1;i<=r;i++)
    {
        int aux = v[i];
        int j =i-1;
        while( j>=l and v[j]>aux )
        {
            v[j+1]=v[j];
            j--;
        }
        v[j+1] = aux;
    }
}

void timsort(std::vector<int>& v)
{
    int size = v.size();
    int minrun = calculate_minrun(size);

    for(int i=0; i<size; i+=minrun)
        insertion_sort(v,i,std::min(size-1,i+minrun-1) );

    for(int bucket =minrun; bucket<size; bucket *=2 )
    {
        for(int i=0;i<size;i+=2*bucket)
        {
            int mid = i+bucket-1;
            int r = std::min(size-1,i+2*bucket-1);

            if ( mid < r )
                merge(v,i,mid,r);
        }
    }
}