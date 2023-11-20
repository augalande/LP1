#include<iostream>
#include<vector>

using namespace std; 

class ringElection
{
    public:

    int total;
    vector<bool> state;

    ringElection(int total_process)
    {
        total=total_process;
        state=vector<bool> (total,true);
    }

    void up(int pos)
    {
        state[pos-1]=true;
    }

    void down(int pos)
    {
        state[pos-1]=false;
    }

    void election(int pos)
    {
        if(pos>total)
        {
            cout<<"P"<<pos<<" cannot start an election as P"<<pos<<" > Total: "<<total<<endl;
            return;
        }

        if(!state[pos-1])
        {
            cout<<"P"<<pos<<" cannot start an election as it is down"<<endl;
            return;
        }

        cout<<"P"<<pos<<" has started an election"<<endl;

        int start=pos-1;
        int ptr= (start+1)%total;
        int last_true=start;

        while(ptr!=start)
        {
            if(state[ptr])
            {
                cout<<"Election Message sent by P"<<last_true+1<<" to P"<<ptr+1<<endl;
                last_true=ptr;
            }
            ptr= (ptr+1)%total;
        }

        cout<<"Election Message sent by P"<<last_true+1<<" to P"<<ptr+1<<endl;

        int max_process=-1;
        for(int i=total-1;i>=0;i--)
        {
            if(state[i])
            {
                max_process=i;
                break;
            }
        }

        cout<<"Election is won by P"<<max_process+1<<endl;
        cout<<"P"<<max_process+1<<" is appointed as the new coordinator"<<endl;
    }

};

int main()
{
    int n;
    cout<<"Enter Number of Nodes: "<<endl;
    cin>>n;

    ringElection r(n);

    r.down(n);
    r.election(n-1);

    return 0;
}

/*
Number or Nodes: 5
*/

/*
Output:-
Enter Number of Nodes: 
5
P4 has started an election
Election Message sent by P4 to P1
Election Message sent by P1 to P2
Election Message sent by P2 to P3
Election Message sent by P3 to P4
Election is won by P4
P4 is appointed as the new coordinator
*/