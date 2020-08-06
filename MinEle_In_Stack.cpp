/*----------------------------------------------------Problem------------------------------------------------------------

You are given N elements and your task is to Implement a Stack in which you can get minimum element in O(1) time.

-------------------------------------------------------------------------------------------------------------------------*/

class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int q;
    cin>>q;
    _stack *a=new _stack();
    while(q--)
    {
      int qt;
      cin>>qt;
      if(qt==1)
      {
        int att;
        cin>>att;
        cout<<a->push(att)<<" ";
      }
      else if(qt==2)
      {
        //pop
        cout<<a->pop()<<" ";
      }
      else if(qt==3)
      {
        //getMin
        cout<<a->getMin()<<" ";
      }
    }
  }
}

/*returns min element from stack*/
int _stack :: getMin()
{
   if(s.empty())
   {
       return -1;
   }
   return s.top();
}

/*returns poped element from stack*/
int _stack ::pop()
{
    int ele;
    if(s.empty())
    {
        return -1;
    }
    else
    {
        s.pop();
        ele=s.top();
        s.pop();
    }
    if(!s.empty())
        minEle=s.top();
    return ele;
}

/*push element x into the stack*/
void _stack::push(int x)
{
   if(s.empty())
   {
       s.push(x);
       minEle=x;
       s.push(minEle);
   }
   else
   {
       s.push(x);
       if(x<minEle)
       {
           minEle=x;
       }
       s.push(minEle);
   }
}

/*----------------------Approach--------------

---It is developed using single stack.
---Push
    --- We push the element and we also push minele put to ,into top the stack
    ---Top of stack will give u Minimum Element of the stack
---Pop
    ---We double pop the elements 
        1)Minimum Element of stack 
        2)Actual Value of the stack
        3)Assign top of the element to minEle
---getMin
    ---return top most element of stack

---------------------------------------------*/
