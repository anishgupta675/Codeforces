/*
A. Deterministic Scheduling for Extended Reality over 5G and Beyond
time limit per test
2 seconds
memory limit per test
1024 megabytes
input
standard input
output
standard output

Background
Extended reality (XR) service is a promising application for future communications. In wireless communications, XR data are transmitted over radio between base stations and mobile terminals. A region is usually divided into multiple cells, each of which is equipped with a base station to serve users. One base station usually serves multiple users, and multiple base stations may serve one user at the same time.
Task
The task of this competition is to design a scheduling algorithm for XR service. By properly allocating radio resources, we want to maximize the number of XR data frames that are successfully transmitted. A diagram is provided below for illustration: The transmission of a data frame is failed when it cannot be completely transmitted during the permitted transmission time window.
Therefore, the objective of this task can be modeled as: P:max∑jfj(1)-
fj={1,gj≥TBSj0,gj<TBSj(2)-
Here, fj represents the transmission result of the j--th frame: when the actual transmitted bits gj (computed via (5)) is not less than the size of the frame, i.e., TBSj (transport block size), the frame would be successfully transmitted so that fj=1. Otherwise, fj=0.
To achieve better user experience, scheduling algorithm should be proposed to efficiently assign the limited radio resources:
Time domain resource, which is divided into several transmission time intervals (TTIs), each TTI corresponds to a transmission time of 0.5-ms.
Frequency domain resource, which is divided into several resource block groups (Resource Block Group, RBG), each RBG corresponds to a transmission bandwidth of 5760 kHz.
Power domain resource: each cell has a fixed maximum transmission power to serve users.

Summarily, two optimization variables are introduced to represent the scheduling result: b(k)rnt∈{0,1}(3)-
p(k)rnt≥0,∑r∑np(k)rnt≤R,∑np(k)rnt≤4(4)-
Here, b(k)rnt is a Boolean variable denoting whether the r--th RBG of cell k is allocated to user n at TTI t, and p(k)rnt is a nonnegative continuous variable denoting the power allocated to user n in the r--th RBG of cell k at TTI t. For each TTI of each cell, the power range of each RBG is between 0 and 4, and the total power of all RBGs can not be larger than R.
When the radio resources are allocated to the users, the XR data transmission can be provided for them. Assume that the j--th frame belongs to the n--th user, the actual transmitted bits for the frame, i.e., gj can be given by:
+gj=W×∑t=t0,jt1,j∑k∑rb(k)rnt×log2(1+s(k)nt).(5)-
Note that W×log2(1+s(k)nt) is the well-known Shannon formula, which represents the transmitted data volume, where s(k)nt represents the transmission SINR (Signal-to-Interference-plus-Noise-Ratio) of user n in cell k at TTI t, and W=192 is the constant number of available frequency resounce elements of one RBG. t0,j and t1,j denote the start TTI and the end TTI of frame j, respectively. The physical meaning of Formula (5) is that the number of bits transmitted within the valid time period, t0,j∼t1,j, will be counted as valid transmission bits for the j--th frame.
Finally, we give the expression of SINR, which may be complicated but corresponds to the actual physical transmission:
+s(k)nt=⎛⎝⎜∏r,b(k)rnt=1s(k)rnt⎞⎠⎟1∑rb(k)rnt(6)-
s(k)rnt=s(k)0,rnt×p(k)rnt×∏m≠ned(k)mrn×b(k)rmt1+∑k′≠k,n′≠ns(k′)0,rnt×p(k′)rn′t×e−d(k′)n′rn(7)-

Formula (6) shows the computation of user-level effective SINR: the transmission SINR of user n, i.e., s(k)nt, is the geometric mean of the SINRs of scheduled RBGs. Then, formula (7) shows the computation of RBG-level effective SINR. s(k)0,rnt is a given constant denoting the initial SINR on RBG r of cell k at TTI t, which indicates the quality of the channel. Another given constant value d(k)mrn represents the interference factor between user m and user n on RBG r, when user m is scheduled on cell k. Note that d(k)mrn=d(k)nrm≤0, which reveals that scheduling multiple users on the same RBG-TTI resource will cause a decrease in the SINR of each user.
To sum up, participants are required to find an efficient radio resource allocation, so that more XR data frames can be successfully transmitted.


Input
The input of a single test has (4+R⋅K⋅T+N⋅R⋅K+1+J) lines, which contains user number N, cell number K, TTI number T, RBG number R, initial SINRs s(k)0,rnt, interference factors dmrn, frame number J and information about J frames.
The details are as follows:
Line 1-: User number N, integer, 1≤N≤100. Users are numbered from 0 to N−1.
Line 2-: Cell number K, integer, 1≤K≤10. Cells are numbered from 0 to K−1.
Line 3-: TTI number T, integer, 1≤T≤1000. TTIs are numbered from 0 to T−1.
Line 4-: RBG number R, integer, 1≤R≤10. RBGs are numbered from 0 to R−1.
Line 5 to (4+R⋅K⋅T)-: Initial SINRs s(k)0,rnt, float, 0<s(k)0,rnt<10000. Each line has N elements, corresponding to N users. s(k)0,rnt is the (n+1)--th element of line (5+r+k⋅R+t⋅K⋅R).
Line (5+R⋅K⋅T) to (4+R⋅K⋅T+N⋅R⋅K)-: Interference factors d(k)mrn, float, −2≤d(k)mrn≤0. Each line has N elements, corresponding to N users. d(k)mrn is the (n+1)--th element of line (5+R⋅K⋅T+m+r⋅N+k⋅R⋅N).
Line (5+R⋅K⋅T+N⋅R⋅K)-: Frame number J, integer, 1≤J≤5000.
Last J lines: Frame information. Each line contains 5 integers corresponding to a frame, which are, in order: frame ID j∈{0,…,J−1} in increasing order, size TBSj (0<TBSj≤100000), user ID it belongs to, first TTI t0,j∈{0,…,T−1}, and number of TTIs td,j∈[1,100]. Last TTI for frame j can be found as t1,j=t0,j+td,j−1; it is guaranteed that t1,j≤T−1.

It is guaranteed that each user has at most one frame at each TTI.
Output
Output for a certain input is the optimization result of p(k)rnt (float), which has R⋅K⋅T lines. Each line has N elements, corresponding to N users. p(k)rnt is the (n+1)--th element of line (1+r+k⋅R+t⋅K⋅R).
Note that the optimization result of b(k)rnt does not need to be output, because p(k)rnt>0 and p(k)rnt=0 means b(k)rnt=1 and b(k)rnt=0, respectively.
Please note that if the outputs do not meet the constraint (4), it will be judged as an incorrect answer and get score 0. Besides, transmit on some TTIs out of time window is valid, but usually results in a lower score due to resources waste.

Scoring
The goal is to maximize the number of successfully scheduled frames. When these numbers are tied, we will compare who used less power. To achieve that, Score=X−10−6×p, where X and p represent the number of successfully scheduled frames and the total power used for transmission, respectively.
The total score for a submission is the sum of scores on each test.

Example
Input
2
2
2
1
1.3865 11.3865
1.3865 11.3865
2.3865 2.3865
2.3865 2.3865
0 -2
-2 0
0 -2
-2 0
2
0 250 0 0 2
1 25 1 0 2

Output
0.000000 0.004950
0.000000 0.004950
0.245039 0.000000
0.245039 0.000000

Note
A simple case with N=2, K=2, T=2, R=1, J=2 is giveTwo sets of tests are prepared in this problem. For the duration of the competition, each submission ais an example. All two frames can be transmitted successfully with the outputtested on the preliminary set of tests. When the competition is finished, for each contestant:
The jury takes the latest submission with non-zero score on preliminary tests;
This submission is tested on the final set of tests for the final rank;
The two sets of tests are generated from the same pool of data, based on the real word data.
*/

#include<bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

vector<vector<int>> optimizeResult(int n, int k, int t, int r, int j, vector<vector<int>> &sinr, vector<vector<int>> &interference_factors, vector<vector<int>> &frame_information) {
    vector<vector<int>> res;
    return res;
}

void printResult(vector<vector<int>> result) {
    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[i].size(); j++) cout << result[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void solve() {
    int n, k, t, r, j;
    vector<vector<int>> sinr(r * k * t, vector<int>(n));
    vector<vector<int>> interference_factors(n * r * k, vector<int>(n));
    cin >> n >> k >> t >> r;
    for(int i = 0; i < sinr.size(); i++) for(int j = 0; j < n; j++) cin >> sinr[i][j];
    for(int i = 0; i < interference_factors.size(); i++) for(int j = 0; j < n; j++) cin >> interference_factors[i][j];
    cin >> j;
    vector<vector<int>> frame_information(j, vector<int>(5));
    for(int i = 0; i < frame_information.size(); i++) for(int j = 0; j < 5; j++) cin >> frame_information[i][j];
    printResult(optimizeResult(n, k, t, r, j, sinr, interference_factors, frame_information));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}