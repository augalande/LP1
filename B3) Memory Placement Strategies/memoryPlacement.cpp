#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class memoryPlacement
{
    public:

    vector<int> process;
    vector<int> block;

    void input()
    {
        int ps,bs;
        
        cout<<"Enter Block Size: "<<endl;
        cin>>bs;

        cout<<"Enter Process Size: "<<endl;
        cin>>ps;

        process.resize(ps);
        block.resize(bs);

        cout<<"Enter Blocks: "<<endl;
        for(int i=0;i<bs;i++)
        {
            cout<<"Block "<<i+1<<": ";
            cin>>block[i];
            cout<<endl;
        }

        cout<<"Enter Processes: "<<endl;
        for(int i=0;i<ps;i++)
        {
            cout<<"Process "<<i+1<<": ";
            cin>>process[i];
            cout<<endl;
        }
    }

    void firstFit()
    {
        input();

        vector<int> allocation(process.size(),-1);

        for(int i=0;i<process.size();i++)
        {
            for(int j=0;j<block.size();j++)
            {
                if(block[j] >= process[i])
                {
                    allocation[i]=j;
                    block[j] -= process[i];
                    break;
                }
            }
        }

        cout<<"\nProcess No.\tProcess Size\tBlock No."<<endl;
        for(int i=0;i<process.size();i++)
        {
            cout<<i+1<<"\t\t"<<process[i]<<"\t\t";
            if (allocation[i] != -1)
            {
                cout<<allocation[i]+1<<endl;
            }
            else
            {
                cout<<"Not Allocated"<<endl;
            }
        }
    }

    void nextFit()
    {
        input();

        vector<int> allocation(process.size(),-1);

        int j=0, t=block.size()-1;

        for(int i=0;i<process.size();i++)
        {
            while(j < block.size())
            {
                if(block[j] >= process[i])
                {
                    allocation[i]=j;
                    block[j] -= process[i];
                    t= (j-1) % block.size();
                    break;

                }
                if(t==j)
                {
                    t= (j-1) % block.size();
                    break;
                }
                j= (j+1) % block.size();
            }
        }

        cout<<"\nProcess No.\tProcess Size\tBlock No."<<endl;
        for(int i=0;i<process.size();i++)
        {
            cout<<i+1<<"\t\t"<<process[i]<<"\t\t";
            if (allocation[i] != -1)
            {
                cout<<allocation[i]+1<<endl;
            }
            else
            {
                cout<<"Not Allocated"<<endl;
            }
        }
    }

    void bestFit()
    {
        input();

        vector<int> allocation(process.size(),-1);

        for(int i=0;i<process.size();i++)
        {
            int bstIdx=-1;

            for(int j=0;j<block.size();j++)
            {
                if(block[j] >= process[i])
                {
                    if(bstIdx==-1)
                    {
                        bstIdx=j;
                    }
                    else if(block[bstIdx] > block[j])
                    {
                        bstIdx=j;
                    }
                }
            }

            if(bstIdx != -1)
            {
                allocation[i]=bstIdx;
                block[bstIdx] -= process[i];
            }
        }

        cout<<"\nProcess No.\tProcess Size\tBlock No."<<endl;
        for(int i=0;i<process.size();i++)
        {
            cout<<i+1<<"\t\t"<<process[i]<<"\t\t";
            if (allocation[i] != -1)
            {
                cout<<allocation[i]+1<<endl;
            }
            else
            {
                cout<<"Not Allocated"<<endl;
            }
        }
    }

    void worstFit()
    {
        input();

        vector<int> allocation(process.size(),-1);

        for(int i=0;i<process.size();i++)
        {
            int wstIdx=-1;

            for(int j=0;j<block.size();j++)
            {
                if(block[j] >= process[i])
                {
                    if(wstIdx==-1)
                    {
                        wstIdx=j;
                    }
                    else if(block[wstIdx] < block[j])
                    {
                        wstIdx=j;
                    }
                }
            }

            if(wstIdx != -1)
            {
                allocation[i]=wstIdx;
                block[wstIdx] -= process[i];
            }
        }

        cout<<"\nProcess No.\tProcess Size\tBlock No."<<endl;
        for(int i=0;i<process.size();i++)
        {
            cout<<i+1<<"\t\t"<<process[i]<<"\t\t";
            if (allocation[i] != -1)
            {
                cout<<allocation[i]+1<<endl;
            }
            else
            {
                cout<<"Not Allocated"<<endl;
            }
        }

    }
};

int main()
{
    memoryPlacement mp;
    int ch;

    while(true)
    {
        cout<<"------------------------------------------------------------------------------------"<<endl;
        cout<<"!! Memory Placement Strategies !!"<<endl;
        cout<<"1) First Fit"<<endl;
        cout<<"2) Next Fit"<<endl;
        cout<<"3) Best Fit"<<endl;
        cout<<"4) Worst Fit"<<endl;
        cout<<"5) Exit"<<endl;
        cout<<"Enter Choice: "<<endl;
        cin>>ch;
        cout<<"------------------------------------------------------------------------------------"<<endl;

        switch(ch)
        {
            case 1:
            cout<<"First Fit Memory Placement Strategy"<<endl;
            mp.firstFit();
            break;

            case 2:
            cout<<"Next Fit Memory Placement Strategy"<<endl;
            mp.nextFit();
            break;

            case 3:
            cout<<"Best Fit Memory Placement Strategy"<<endl;
            mp.bestFit();
            break;

            case 4:
            cout<<"Worst Fit Memory Placement Strategy"<<endl;
            mp.worstFit();
            break;

            case 5:
            cout<<"Exiting Program"<<endl;
            exit(0);
            break;

            default:
            cout<<"Invalid Choice !!"<<endl;
            break;
        }
    }
    return 0;
}

/*
Test Case-1:
1
5 4
100 500 200 300 600
212 417 112 426

Test Case-2:
2
5 4
100 500 200 300 600
212 417 112 426

Test Case-3:
3
5 4
100 500 200 300 600
212 417 112 426

Test Case-4:
4
5 4
100 500 200 300 600
212 417 112 426

Test Case-5:
5
 */

/*
Output:-
------------------------------------------------------------------------------------
!! Memory Placement Strategies !!
1) First Fit
2) Next Fit
3) Best Fit
4) Worst Fit
5) Exit
Enter Choice: 
1
------------------------------------------------------------------------------------
First Fit Memory Placement Strategy
Enter Block Size: 
5 4
Enter Process Size: 
Enter Blocks: 
Block 1: 100 500 200 300 600

Block 2: 
Block 3: 
Block 4: 
Block 5: 
Enter Processes: 
Process 1: 212 417 112 426

Process 2: 
Process 3: 
Process 4: 

Process No.     Process Size    Block No.
1               212             2
2               417             5
3               112             2
4               426             Not Allocated
------------------------------------------------------------------------------------
!! Memory Placement Strategies !!
1) First Fit
2) Next Fit
3) Best Fit
4) Worst Fit
5) Exit
Enter Choice: 
2
------------------------------------------------------------------------------------
Next Fit Memory Placement Strategy
Enter Block Size: 
5 4
Enter Process Size: 
Enter Blocks: 
Block 1: 100 500 200 300 600

Block 2: 
Block 3: 
Block 4: 
Block 5: 
Enter Processes: 
Process 1: 212 417 112 426

Process 2: 
Process 3: 
Process 4: 

Process No.     Process Size    Block No.
1               212             2
2               417             5
3               112             5
4               426             Not Allocated
------------------------------------------------------------------------------------
!! Memory Placement Strategies !!
1) First Fit
2) Next Fit
3) Best Fit
4) Worst Fit
5) Exit
Enter Choice: 
3
------------------------------------------------------------------------------------
Best Fit Memory Placement Strategy
Enter Block Size: 
5 4
Enter Process Size: 
Enter Blocks: 
Block 1: 100 500 200 300 600

Block 2: 
Block 3: 
Block 4: 
Block 5: 
Enter Processes: 
Process 1: 212 417 112 426

Process 2: 
Process 3: 
Process 4: 

Process No.     Process Size    Block No.
1               212             4
2               417             2
3               112             3
4               426             5
------------------------------------------------------------------------------------
!! Memory Placement Strategies !!
1) First Fit
2) Next Fit
3) Best Fit
4) Worst Fit
5) Exit
Enter Choice: 
4
------------------------------------------------------------------------------------
Worst Fit Memory Placement Strategy
Enter Block Size: 
5 4
Enter Process Size: 
Enter Blocks: 
Block 1: 100 500 200 300 600

Block 2: 
Block 3: 
Block 4: 
Block 5: 
Enter Processes: 
Process 1: 212 417 112 426

Process 2: 
Process 3: 
Process 4: 

Process No.     Process Size    Block No.
1               212             5
2               417             2
3               112             5
4               426             Not Allocated
------------------------------------------------------------------------------------
!! Memory Placement Strategies !!
1) First Fit
2) Next Fit
3) Best Fit
4) Worst Fit
5) Exit
Enter Choice: 
5
------------------------------------------------------------------------------------
Exiting Program
*/