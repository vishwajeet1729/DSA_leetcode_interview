// Last updated: 1/17/2026, 12:25:58 PM
class Solution {
public:
vector<vector<int>> v ;

bool check(double mid)
    {
        double below = 0, above = 0;

        for (auto &s : v)
        {
            double y = s[1];
            double l = s[2];
            double top = y + l;
            double area = l * l;

            if (mid <= y) {
                above += area;
            }
            else if (mid >= top) {
                below += area;
            }
            else {
                double cut = (mid - y) * l;
                below += cut;
                above += area - cut;
            }
        }

        return below >= above;
    }


    double separateSquares(vector<vector<int>>& squares) {
        
        v=squares;
  int n=v.size();
  double mx=0;
  for(int i=0;i<n;++i){
mx=max((double)v[i][2],mx);
  }
  double low = 0, heigh = 1e9;
   double eps = 1e-6;
  while (heigh-low>eps)
  {

    double mid = low + ((heigh - low) / 2);
    if (check(mid))
    {
 
      heigh = mid ;
    }
    else
      low = mid;
  }

return (low+heigh)/2;
//   cout << ans << endl;
    }
};