// You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.

// All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.

// For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
// You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.

// Input: tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
// Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
// Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"] but it is larger in lexical order.

#include<iostream>
#include<vector>
using namespace std;
#include<unordered_map>
#include<algorithm>

class Solution {
    private:
    vector<string>result;
    unordered_map<string,vector<string>>AdjList;
    void dfs(string fromAirpot){
        //hierholzer's algorithm
        //so what we will do is , start from our desired given airport and then until all flight tickets are used , we will fly using this ticket(dfs) and reach to the station and from that station , repeat the process
        //repeat it until from an airpot we no longer can fly out anymore , in that  case simply add that airport as our end point in our path and go to previous airpot and repeat everything

        while(!AdjList[fromAirpot].empty()){
            string toAirpot = AdjList[fromAirpot].back();
            AdjList[fromAirpot].pop_back();
            dfs(toAirpot);
        }

        result.push_back(fromAirpot);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        //as its given , use tickets exactly once and its a directed way , we can think of it as finding an eulerian circuit which states that :- An Euler circuit is a path that traverses every edge of a graph exactly once, and the path ends on the starting vertex.

        //And for directed graphs , we have an algorithm called HierHolzer's algorithm to find path
        //Conditions for Eulerian circuit in a Directed Grpah : (1) All vertices belong to a single strongly connected component. (2) All vertices have same in-degree and out-degree. Note that for an undirected graph, the condition is different (all vertices have even degree)


        for(auto ticket : tickets){
            AdjList[ticket[0]].push_back(ticket[1]);
        }

        for(auto& [k,v] : AdjList){
            sort(v.begin(),v.end());
            reverse(v.begin(),v.end());
        }
        //sort all neighbors in lexicographical shortest order , to prevent from indexing issues and costly erase and insertion we will reverse each order
        dfs("JFK");
        reverse(begin(result),end(result));
        return result;
    }
};

int main(){
    Solution sol1;
    vector<vector<string>>tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    vector<string>ans = sol1.findItinerary(tickets);
    for(auto it : ans)cout<<it<<" -> ";
    cout<<"end";
    return 0;
}