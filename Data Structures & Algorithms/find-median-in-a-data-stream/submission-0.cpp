class MedianFinder {
public:
    priority_queue<double> max_h;
    priority_queue<double,vector<double>,greater<double>> min_h;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(min_h.empty() || min_h.top()>=num){
            max_h.push(num);
        }
        else{
            auto it=min_h.top();
            min_h.pop();
            min_h.push(num);
            max_h.push(it);
        }
        if(min_h.size()<max_h.size()){
            auto it=max_h.top();
            max_h.pop();
            min_h.push(it);
        }
    }
    
    double findMedian() {
        if(max_h.size()==min_h.size()){
            return (max_h.top()+min_h.top())/2;
        }
        return min_h.top();
    }
};
