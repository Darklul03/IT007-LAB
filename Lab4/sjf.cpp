#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
using namespace std;

// struct for priority queue
struct Process {
    int pid;
    int arrival;
    int burst;
    int remaining;
    int waiting;
    int turnaround;
    int response;

    bool operator ==(Process const& p1) {
        return pid == p1.pid && arrival && p1.arrival && burst != p1.burst;
    }
};

Process NIL{-1, -1, -1, -1, -1, -1, -1};

struct CompareProcess {
    bool operator()(Process const& p1, Process const& p2)
    {
        if (p1.arrival == p2.arrival)
            return p1.pid < p2.pid;
        return p1.arrival < p2.arrival;
    }
};

int main() {
    priority_queue<Process, vector<Process>, CompareProcess> pq;
    int n;
    cout << "Enter the number of process: ";
    cin >> n;
    vector<Process> p(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter the process id, arrival time & burst time: ";
        cin >> p[i].pid >> p[i].arrival >> p[i].burst;
        p[i].remaining = p[i].burst;
        p[i].response = -1;
    }

    // sort based on arrival
    sort(p.begin(), p.end(), [](const Process& p1, const Process& p2) -> bool
    {
        return p1.arrival > p2.arrival;
    });

    Process running = NIL;
    vector<int> waiting(n);
    vector<int> turnaround(n);
    vector<int> response(n, 999999);

    int t = 0;
    vector<Process> finish;
    while (!p.empty() || !pq.empty() || running.remaining > 0) {
        // if exists -> remaining--
        if (running.pid != -1) {
            running.remaining--;
        }

        // insert process to priority queue
        while (!p.empty() && p.back().arrival <= t) {
            pq.push(p.back());
            p.pop_back();
        }

        // end process
        if (running.remaining == 0) {
            running.turnaround = t - running.arrival;
            running.waiting = running.turnaround - running.burst;
            finish.push_back(running);
            running = NIL;
        }

        // if running is empty and queue has process
        if (running.pid == -1 && !pq.empty()) {
            running = pq.top();
            if (running.response == -1)
                running.response = t - running.arrival;
            pq.pop();
        }

        // reserved for srtf
        // if (pq.top().remaining < running.remaining) {
        //     pq.push(running);
        //     running = pq.top();
        //     if (running.response == -1)
        //         running.response = t - running.arrival;
        //     pq.pop();
        // }

        t++;
    }

    sort(finish.begin(), finish.end(), [](const Process& p1, const Process& p2) -> bool
    {
        return p1.pid < p2.pid;
    });

    float tw = 0, tt = 0;
    printf("\n%-6s%-8s%-8s%-6s%-6s%-6s\n", "PName", "Arrtime", "Burtime", "Res", "Wait", "Turnaround");
    for (int i = 0; i < n; i++) {
        printf("%-6d%-8d%-8d%-6d%-6d%-6d\n", finish[i].pid, finish[i].arrival, finish[i].burst, finish[i].response, finish[i].waiting, finish[i].turnaround);
        tw += finish[i].waiting;
        tt += finish[i].turnaround;
    }

    printf("Avg waiting: %.2f\nAvg turnaround: %.2f", tw/n, tt/n);

    return 0;
}