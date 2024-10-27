#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

bool hasPath(const vector<vector<int>>& graph, int start, int end){
    if(start == end){
        return true;
    }

    queue<int> toVisit;
    toVisit.push(start);

    unordered_set<int> visited;
    visited.insert(start);

    while(!toVisit.empty()){
        int currentNode = toVisit.front();
        toVisit.pop();

        for(int neighbor : graph[currentNode]){
            if(neighbor == end){
                return true;
            }
            if(visited.find(neighbor) == visited.end()){
                toVisit.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }
    return false;
}
int main(){
    vector<vector<int>> graph = {
        {1, 2},
        {2},
        {3},
        {}
    };
    int start = 0, end = 3;
    if(hasPath(graph, start, end)){
         cout << "存在从节点 " << start << " 到节点 " << end << " 的路径。" << endl;
    } else {
        cout << "不存在从节点 " << start << " 到节点 " << end << " 的路径。" << endl;
    }

    return 0;
}
