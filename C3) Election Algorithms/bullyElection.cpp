#include<iostream>
#include<vector>

using namespace std;

class bullyElection
{
    public:

    int total;
    vector<bool> state;

    bullyElection(int total_process)
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

        for(int i=pos;i<total;i++)
        {
            cout<<"Election Message sent by P"<<pos<<" to P"<<i+1<<endl;
        }

        for(int i=pos;i<total;i++)
        {
            if(state[i])
            {
                cout<<"P"<<i+1<<" responds OK to P"<<pos<<endl;
            }
        }

        for(int i=pos;i<total;i++)
        {
            if(state[i])
            {
                election(i+1);
                return;
            }
        }

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

    bullyElection b(n);

    b.down(2);
    b.down(5);

    b.election(1);

    return 0;
}

/*
Number or Nodes: 5
*/

/*
Output:-
Enter Number of Nodes: 
5
P1 has started an election
Election Message sent by P1 to P2
Election Message sent by P1 to P3
Election Message sent by P1 to P4
Election Message sent by P1 to P5
P3 responds OK to P1
P4 responds OK to P1
P3 has started an election
Election Message sent by P3 to P4
Election Message sent by P3 to P5
P4 responds OK to P3
P4 has started an election
Election Message sent by P4 to P5
Election is won by P4
P4 is appointed as the new coordinator
*/