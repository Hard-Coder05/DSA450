class Solution
{
public:
    void nextPermutation(vector<int> &a)
    {
        int n = a.size(), l, k;
        //check for reverse order
        for (k = n - 2; k >= 0; --k)
            if (a[k] < a[k + 1]) //if the prev is smaller then break cauz
                break;           //thats the point where the number will change from
        //if the array is in reverse order then k=-1
        if (k < 0)
            reverse(a.begin(), a.end());
        else
        {
            //check for the index where the a[l] is greater than a[k]
            //cauz now that will become the lead
            for (l = n - 1; l > k; --l)
                if (a[l] > a[k])
                    break;
            swap(a[k], a[l]);
            reverse(a.begin() + k + 1, a.end());
        }
    }
};