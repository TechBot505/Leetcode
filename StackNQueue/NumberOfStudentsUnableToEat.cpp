// Brute
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int len = sandwiches.size();
        queue<int> q;
        for(auto it : students) {
            q.push(it);
        }
        stack<int> st;
        for(int i=len-1; i>=0; i--) {
            st.push(sandwiches[i]);
        }
        int served = 0;
        while(!q.empty() && served < q.size()) {
            if(st.top() == q.front()) {
                st.pop();
                q.pop();
                served = 0;
            }
            else {
                q.push(q.front());
                q.pop();
                served++;
            }
        }
        return q.size();
    }
};

// Optimal
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count0 = 0;
        int count1 = 0;
        for(int it : students) {
            if(it) count1++;
            else count0++;
        }
        for(int x : sandwiches) {
            if(x) {
                if(count1>0) {
                    count1--;
                }
                else return count0;
            }
            else {
                if(count0) {
                    count0--;
                }
                else return count1;
            }
        }
        return 0;
    }
};