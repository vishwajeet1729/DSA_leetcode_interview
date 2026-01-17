// Last updated: 1/17/2026, 12:27:29 PM
class SegmentTree
{

private:

    vector<int> seg;

public:

    SegmentTree(int n)
    {
        seg.resize(4*n+1);
    }

    void build(int ind,int lo,int hi,vector<int> &a)
    {
        if(lo==hi)
        {
            seg[ind]=a[lo];
            return;
        }
        int mid=lo+(hi-lo)/2;
        build(2*ind+1,lo,mid,a);
        build(2*ind+2,mid+1,hi,a);
        seg[ind]=(seg[2*ind+1]|seg[2*ind+2]);
    }

    int query(int ind,int lo,int hi,int l,int r)
    {
        if(l>hi||lo>r)
        {
            return 0;
        }
        if(l<=lo&&hi<=r)
        {
            return seg[ind];
        }
        int mid=lo+(hi-lo)/2;
        int left=query(2*ind+1,lo,mid,l,r),right=query(2*ind+2,mid+1,hi,l,r);
        return (left|right);
    }

};


class Solution {
public:
int minimumSubarrayLength(vector<int> &a, int k) 
{
    int n=a.size(),ans=1e9;
    SegmentTree st(n);
    st.build(0,0,n-1,a);
    for(int i=0;i<n;++i)
    {
        int lo=i,hi=n-1,idx=-1;
        while(hi>=lo)
        {
            int mid=lo+(hi-lo)/2;
            if(st.query(0,0,n-1,i,mid)>=k)
            {
                idx=mid;
                hi=mid-1;
            }
            else
            {
                lo=mid+1;
            }
        }
        if(idx!=-1)
        {
            ans=min(ans,idx-i+1);
        }
    }
    if(ans==1e9)
    {
        ans=-1;
    }
    return ans;
}
};