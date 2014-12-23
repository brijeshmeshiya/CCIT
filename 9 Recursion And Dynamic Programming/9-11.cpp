#include <iostream>
#include <stack>

using namespace std;

bool calculator(bool x,bool y,char operatr)
{
switch (operatr)
{
	case '&' :
		return x&y;
	case '|' :
		return x|y;
	case '^' :
		return x^y;
}
}

bool expression_evaluation(string e)
{
	stack <bool> operand;
	stack <char> operatr;
	bool var1,var2;
	int i=0,j=e.length();
	e==e+'$';
	while(i<j)
	{
		if(e.at(i)=='1' || e.at(i)=='0')
			operand.push(e.at(i));
		else if(e.at(i)=='(')
			operatr.push('(');
		else if(e.at(i)==')')
		{
			while(!operatr.empty() && operatr.top()!='(')
			{
				var1=operand.top();
				operand.pop();
				var2=operand.top();
				operand.pop();
				operand.push(calculator(var1,var2,operatr.top()));
				operatr.pop();
			}
			operatr.pop();
		} 
		else if(e.at(i)=='^')
		{
			while(!operatr.empty() && operatr.top()=='&')
			{
				var1=operand.top();
				operand.pop();
				var2=operand.top();
				operand.pop();
				operand.push(calculator(var1,var2,operatr.top()));
				operatr.pop();
			}
			operatr.push('^');
		}
		else if(e.at(i)=='|')
		{
			while(!operatr.empty() && (operatr.top()=='^' || operatr.top()=='&'))
			{
				var1=operand.top();
				operand.pop();
				var2=operand.top();
				operand.pop();
				operand.push(calculator(var1,var2,operatr.top()));
				operatr.pop();
			}
			operatr.push('|');
		}
		else if(e.at(i)=='&')
			operatr.push('&');
		else // if $
		{
			// Emptying Stack
			while(!operatr.empty())
			{
				var1=operand.top();
				operand.pop();
				var2=operand.top();
				operand.pop();
				operand.push(calculator(var1,var2,operatr.top()));
				operatr.pop();
			}
		}

		i++;
	}
	while(!operatr.empty())
	{
		var1=operand.top();
		operand.pop();
		var2=operand.top();
		operand.pop();
		operand.push(calculator(var1,var2,operatr.top()));
		operatr.pop();
	}
	return operand.top();
}

// Not optimized
void expression_maker(string s,bool result,int paran)
{
	int i,j=s.length(),count;
	//cout<<s<<endl;
	if(paran<0)
		return ;
	else if(expression_evaluation(s)==result)
	{
		cout<<"Answer : "<<s<<endl;
		return;
	}
	i=0;
	while(i<j)
	{
		count=0;
		if(s.at(i)=='|' || s.at(i)=='&' || s.at(i)=='^')
		{
			count++;
			while(i+count<j && (s.at(i+count)!='|' || s.at(i+count)!='&' || s.at(i+count)!='^')){
				count++;
			}
			if(count>3)
				expression_maker(s.substr(0,i+1)+"("+s.substr(i+1,count)+")"+s.substr(i+count),result,paran-1);
			}
		i++;
		}
}

int main()
{
	expression_maker("1^0|0|1",0,3);
	return 0;
}