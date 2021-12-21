#include <iostream>
#include<bits/stdc++.h>
 
//graph: INDEX:PAIR(InDEX, DIST) !!
 
typedef unsigned long long int llu;
typedef unsigned int iu;
 
void generate_graph(int E, std::vector<std::pair<iu, iu>> graph []){
    iu index1, index2 ,dist;
    for(int i = 0; i < E; i++){
        std::cin >> index1; std::cin >> index2; std::cin >> dist;
        graph[index1].push_back({index2, dist});
        graph[index2].push_back({index1, dist});
    }
 
}
 
void dijkstra(int V, std::vector<std::pair<iu, iu>> graph [], std::vector<int>& start_nodes, llu arr_ans[]){
 
    std::priority_queue<std::pair<llu, iu>, std::vector<std::pair<llu, iu>>, std::greater<std::pair<llu, iu>> > available;
        
    bool visited[V];
    llu arr_dist[V]; 
    
    for(int i = 0; i < V; i++){
        visited[i] = 0;
        arr_dist[i] = LLONG_MAX;
    }
    
    
    for(auto start_node : start_nodes){
        available.push(std::make_pair(0, start_node));
        arr_dist[start_node] = 0;
    }
    
    iu current;
 
    while(available.size() != 0){
        auto current_node = available.top();
        current = current_node.second;
        available.pop();
        
        if(visited[current] == 1)
            continue;
        
        visited[current] = 1;
 
        for(auto node : graph[current]){
            if(arr_dist[node.first] > arr_dist[current] + node.second){
                arr_dist[node.first] = arr_dist[current] + node.second;
                available.push(std::make_pair(arr_dist[node.first], node.first));
            }
        }
    }
    
    for(int i = 0; i < V; i++){
        arr_ans[i] = arr_dist[i];
    }
    
}
 
int main(){
    
    int E, V, K;
    std::cin >> V; std::cin >> E;
    
    std::vector<std::pair<iu, iu>> graph[V + 1];
    generate_graph(E, graph);
    
    int in;
    std::cin >> K;
    std::vector<int> arr_T (K);
    for(int i = 0; i < K; i++){
        std::cin >> in; arr_T[i] = in;
    }
    
    llu arr_ans[V + 1] = {0};
    
    dijkstra(V, graph, arr_T, arr_ans);
    
    int Q; std::cin >> Q;
    for(int i = 0; i < Q; i++){
        std::cin >> in;
        printf("%llu\n", arr_ans[in]);
    }
    
    return 0;
}