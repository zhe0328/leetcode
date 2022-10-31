class Solution {
public:
int stringTointeger(string str)   //To convert the given string into integer (since we don't have to use any built-in function)
{
    int sum = 0;
    for(int i = 0 ; i < str.length() ; i++)
    {
        sum = sum*10 + (str[i]-'0');
    }
    return sum;
}

int calculate(string s) {
    int num = 0, ans = 0 , i = 0, sign = 1;
    stack<int> st;
    
    while(i < s.length())
    {
        if(s[i] >= 48 && s[i] <= 57)   //if we encounter with any digit (0---9)
        {
            string number;
            while(s[i]>= 48 && s[i] <= 57)  // store the whole digit in a new string 
            {
                number += s[i];
                i++;
            }
            i--;   // i will be one index forward after coming out from while loop, so we'll decrement it to its right place
            num = stringTointeger(number);  // converting digit string to num 
            num *= sign;                   // multiplying with sign and storing to ans
            ans += num;
        }
        
        else if(s[i] == '+')
            sign = 1;
        else if(s[i] == '-')
            sign = -1;
        else if(s[i] == '(')    // if we encounter this, we'll push our current answer with its sign 
        {                       // then we'll consider new ans to be 0 and number to be positive and repeat the same steps
            st.push(ans);
            st.push(sign);
            ans = 0;
            sign = 1;
        }
        else if(s[i] == ')')  // when the whole bracket is done , we'll multiplty it with previous num sign stored in stack 
        {                     // and then adding the previous ans to our current ans 
            ans *= st.top();
            st.pop();
            ans += st.top();
            st.pop();
        }
        i++;
    }
  return ans;
}
};