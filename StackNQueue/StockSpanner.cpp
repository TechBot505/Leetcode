class StockSpanner {
public:
    stack<pair<int, int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(st.empty()) {
            st.push({price, 1});
            return 1;
        }
        int count = 1;
        while(!st.empty() && st.top().first <= price) {
            count += st.top().second;
            st.pop();
        }
        st.push({price, count});
        return count;
    }
};