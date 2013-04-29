#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string longestPalindrome(string s)
{
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    string str;
    str +="$";
    int len=s.length();
    for(int i=0; i<len; i++)
    {
        str = str+"#"+s[i];
    }
    str +="#";
    int max=0,id=0;
    int len2= str.length();
    vector<int> p(len2,0);
    for(int i=1; i<len2; i++)
    {
        p[i] = max>i?min(p[2*id-i],max-i):1;
        while(str[i+p[i]]==str[i-p[i]]) p[i]++;
        if(i+p[i]>max)
        {
            max = i+p[i];
            id = i;
        }
    }
    int maxp=0,maxid=0;
    for(int i=1; i<len2; i++)
    {

        if(p[i]>maxp)
        {
            maxp = p[i];
            maxid=i;
        }
    }
    string res = str.substr(maxid-maxp+1,2*maxp-1);
    auto i =res.begin();
    while(i!=res.end())
    {
        if(*i=='#')
        {
            res.erase(i);
            continue;
        }

        i++;
    }
    return res;
}

int main()
{
    string s;
    cin>>s;
    cout<<longestPalindrome(s)<<endl;
    return 0;
}
