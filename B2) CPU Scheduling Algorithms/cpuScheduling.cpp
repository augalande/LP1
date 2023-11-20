#include<bits/stdc++.h>
using namespace std;

class Job
{
    public:

    int id;
    string name;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnAroundTime;
    int waitingTime;
    int priority;

    Job()
    {
        id=0;
        name="";
        arrivalTime=0;
        burstTime=0;
        completionTime=0;
        turnAroundTime=0;
        waitingTime=0;
        priority=0;
    }

    Job(int id,string name,int arrivalTime,int burstTime)
    {
        this->id=id;
        this->name=name;
        this->arrivalTime=arrivalTime;
        this->burstTime=burstTime;
        completionTime=0;
        turnAroundTime=0;
        waitingTime=0;
        priority=0;
    }

    void operator=(const Job &j)
    {
        this->id=j.id;
        this->name=j.name;
        this->arrivalTime=j.arrivalTime;
        this->burstTime=j.burstTime;
        completionTime=0;
        turnAroundTime=0;
        waitingTime=0;
        priority=0;
    }
};

class Scheduler
{
    public:

    int n;
    Job *processes;
    vector<Job> readyQueue;

    Scheduler(int n)
    {
        this->n=n;
        processes=new Job[n];
    }

    ~Scheduler()
    {
        delete [] processes;
    }

    void input()
    {
        int at,bt;

        for(int i=0;i<n;i++)
        {
            cout<<"Enter Arrival Time and Burst Time for P"<<i+1<<": "<<endl;
            cin>>at>>bt;
            Job j(i+1,"P"+to_string(i+1),at,bt);
            processes[i]=j;
        }
    }

    void display()
    {
        cout<<"Id\tAT\tBT\tCT\tTAT\tWT"<<endl;
        
        for(int i=0;i<n;i++)
        {
            cout<<processes[i].id<<"\t"<<processes[i].arrivalTime<<"\t"<<processes[i].burstTime<<"\t"<<processes[i].completionTime<<"\t"<<processes[i].turnAroundTime<<"\t"<<processes[i].waitingTime<<endl;
        }

        cout<<endl;

        double sumTAT=0;
        double sumWT=0;

        for(int i=0;i<n;i++)
        {
            sumTAT+=processes[i].turnAroundTime;
            sumWT+=processes[i].waitingTime;
        }

        cout<<"Average Turn Around Time: "<<(sumTAT/n)<<endl;
        cout<<"Average Waiting Time: "<<(sumWT/n)<<endl;
    }

    void displayGanttChart(vector<Job> readyQueue,int currentTime)
    {
        cout<<"Ready Queue at "<<currentTime<<"sec: "<<endl;
        for(int i=0;i<readyQueue.size();i++)
        {
            cout<<readyQueue[i].name<<"("<<readyQueue[i].burstTime<<"s)\t";
        }
        cout<<endl<<endl;;
    }

    void firstComeFirstServe()
    {
        int currentTime=0;
        int totalTime=0;
        int processCompleted=0;

        sort(processes,processes+n,[] (const Job &lhs,const Job &rhs)
        {
            return lhs.arrivalTime<rhs.arrivalTime;
        }
        );

        for(int i=0;i<n;i++)
        {
            totalTime+=processes[i].burstTime;
        }

        while(currentTime<=totalTime)
        {
            if(processCompleted<n && processes[processCompleted].arrivalTime<=currentTime)
            {
                readyQueue.push_back(processes[processCompleted]);
                processCompleted++;
            }

            this->displayGanttChart(readyQueue,currentTime);

            if(readyQueue.size()>0)
            {
                readyQueue[0].burstTime--;

                if(readyQueue[0].burstTime==0)
                {
                    for(int i=0;i<n;i++)
                    {
                        if(readyQueue[0].id==processes[i].id)
                        {
                           processes[i].completionTime=currentTime+1;
                           processes[i].turnAroundTime=processes[i].completionTime-processes[i].arrivalTime;
                           processes[i].waitingTime=processes[i].turnAroundTime-processes[i].burstTime;
                        }
                    }
                    readyQueue.erase(readyQueue.begin());
                }
            }
            currentTime++;
        }
        this->display();
    }

    void shortestJobFirst()
    {
        int currentTime=0;
        int totalTime=0;
        int processCompleted=0;

        sort(processes, processes+n,[] (const Job &lhs, const Job &rhs)
        {
            return lhs.arrivalTime< rhs.arrivalTime;
        });

        for(int i=0;i<n;i++)
        {
            totalTime+=processes[i].burstTime;
        }

        while(currentTime<=totalTime)
        {
            if(processCompleted<n && processes[processCompleted].arrivalTime<=currentTime)
            {
                readyQueue.push_back(processes[processCompleted]);
                processCompleted++;
            }

            sort(readyQueue.begin(),readyQueue.end(),[] (const Job &lhs, const Job &rhs)
            {
                return lhs.burstTime<rhs.burstTime;
            });

            this->displayGanttChart(readyQueue,currentTime);

            if(readyQueue.size()>0)
            {
                readyQueue[0].burstTime--;

                if(readyQueue[0].burstTime==0)
                {
                    for(int i=0;i<n;i++)
                    {
                        if(readyQueue[0].id==processes[i].id)
                        {
                            processes[i].completionTime=currentTime+1;
                            processes[i].turnAroundTime=processes[i].completionTime-processes[i].arrivalTime;
                            processes[i].waitingTime=processes[i].turnAroundTime-processes[i].burstTime;
                        }
                    }
                    readyQueue.erase(readyQueue.begin());
                }
            }
            currentTime++;
        }
        this->display();
    }

    void priority()
    {
        int currentTime=0;
        int totalTime=0;
        int processCompleted=0;
       
        cout<<"Enter Priorities: "<<endl;
        for(int i=0;i<n;i++)
        {
            cin>>processes[i].priority;
        }

        sort(processes, processes + n, [] (const Job &lhs, const Job & rhs) {
            return lhs.arrivalTime < rhs.arrivalTime;
        });

        for(int i=0;i<n;i++)
        {
            totalTime+=processes[i].burstTime;
        }

        while(currentTime<=totalTime)
        {
            while(processes[processCompleted].arrivalTime <= currentTime && processCompleted < n) {
                readyQueue.push_back(processes[processCompleted]);
                processCompleted++;
            }

            sort(readyQueue.begin(), readyQueue.end(), [] (const Job &lhs, const Job & rhs) {
                return lhs.priority < rhs.priority;
            });

            this->displayGanttChart(readyQueue,currentTime);

            if(readyQueue.size()>0)
            {
                readyQueue[0].burstTime--;

                if(readyQueue[0].burstTime==0)
                {
                    for(int i=0;i<n;i++)
                    {
                        if(readyQueue[0].id==processes[i].id)
                        {
                            processes[i].completionTime=currentTime+1;
                            processes[i].turnAroundTime=(processes[i].completionTime-processes[i].arrivalTime > 0) ? processes[i].completionTime-processes[i].arrivalTime : 0;
                            processes[i].waitingTime=(processes[i].turnAroundTime-processes[i].burstTime > 0) ? processes[i].turnAroundTime-processes[i].burstTime : 0; 
                        }
                    }
                    readyQueue.erase(readyQueue.begin());
                }
            }
            currentTime++;
        }
        this->display();
    }

    void roundRobin()
    {
        int currentTime=0;
        int totalTime=0;
        int processCompleted=0;
        int interval;
        int addedBurst=0;
        Job addedJob;
        addedJob.burstTime=0;

        cout<<"Enter Interval: "<<endl;
        cin>>interval;

        sort(processes,processes+n,[] (const Job &lhs,const Job &rhs)
        {
            return lhs.arrivalTime<rhs.arrivalTime;
        });

        for(int i=0;i<n;i++)
        {
            totalTime+=processes[i].burstTime;
        }

        while(currentTime<=totalTime)
        {
            while(processCompleted<n && processes[processCompleted].arrivalTime<=currentTime)
            {
                readyQueue.push_back(processes[processCompleted]);
                processCompleted++;
            }

            if(addedJob.burstTime>0)
            {
                readyQueue.push_back(addedJob);
            }

            this->displayGanttChart(readyQueue,currentTime);

            if(readyQueue.size()>0)
            {
                addedJob=readyQueue[0];
                readyQueue.erase(readyQueue.begin());

                if(addedJob.burstTime > interval)
                {
                    addedJob.burstTime -=interval;
                    addedBurst=interval;
                }
                else
                {
                    addedBurst=addedJob.burstTime;
                    addedJob.burstTime=0;
                }

                if(addedJob.burstTime==0)
                {
                    for(int i=0;i<n;i++)
                    {
                        if(addedJob.id==processes[i].id)
                        {
                            processes[i].completionTime=currentTime+addedBurst;
                            processes[i].turnAroundTime=processes[i].completionTime-processes[i].arrivalTime;
                            processes[i].waitingTime=processes[i].turnAroundTime-processes[i].burstTime;
                        }
                    }
                }
            }
            currentTime+=addedBurst;
        }
    this->display();
    }
};

int main()
{
    int n;
    cout<<"Enter number of Processes: "<<endl;
    cin>>n;

    Scheduler s(n);
    s.input();

    int ch;
    while(true)
    {
        cout<<"------------------------------------------------------------------------------------"<<endl;
        cout<<"!! CPU Scheduling Algorithms !!"<<endl;
        cout<<"1) First Come First Serve"<<endl;
        cout<<"2) Shortest Job First"<<endl;
        cout<<"3) Priority"<<endl;
        cout<<"4) Round Robin"<<endl;
        cout<<"5) Exit"<<endl;
        cout<<"Enter Choice: "<<endl;
        cin>>ch;
        cout<<"------------------------------------------------------------------------------------"<<endl;

        switch(ch)
        {
            case 1:
            s.firstComeFirstServe();
            break;

            case 2:
            s.shortestJobFirst();
            break;

            case 3:
            s.priority();
            break;

            case 4:
            s.roundRobin();
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
FCFS:-
4 0 2 1 2 5 3 6 4 1
*/

/*
SJF:-
4 0 5 1 3 2 4 4 1 2
*/

/*
Priority:-
7 0 3 2 5 1 4 4 2 6 9 5 4 7 10 3 2 6 3 5 7 4 10
*/

/*
Round Robin:-
4 0 5 1 4 2 2 4 1 4 2 
*/


