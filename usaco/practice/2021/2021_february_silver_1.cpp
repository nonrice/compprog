#include <iostream>
#include <set>
#include <vector>

using namespace std;
typedef pair<int, int> cow_loc;

bool cow_exists(cow_loc cow, set<cow_loc>& occupied, set<cow_loc>& needed){
    if ((occupied.find(cow) != occupied.end()) || (needed.find(cow) != needed.end())){
        return true;
    }

    return false;
}

pair<vector<cow_loc>, vector<cow_loc>> find_neighbors(cow_loc cow, set<cow_loc>& occupied, set<cow_loc>& needed){
    vector<cow_loc> adj;
    adj.push_back(make_pair(cow.first, cow.second+1));
    adj.push_back(make_pair(cow.first, cow.second-1));
    adj.push_back(make_pair(cow.first+1, cow.second));
    adj.push_back(make_pair(cow.first-1, cow.second));
    
    vector<cow_loc> neighbors;
    vector<cow_loc> empty;

    for(cow_loc adj_cow : adj){
        if(cow_exists(adj_cow, occupied, needed)){
            neighbors.push_back(adj_cow);
        } else {
            empty.push_back(adj_cow);
        }
    }

    return make_pair(neighbors, empty);
}

void update_needed(cow_loc cow, set<cow_loc>& occupied, set<cow_loc>& needed){
    vector<cow_loc> to_visit;
    vector<cow_loc> to_visit_new;

    to_visit.push_back(cow);

    while (to_visit.size() > 0){
        to_visit_new.clear(); 
        for(cow_loc n_cow : to_visit){
            pair<vector<cow_loc>, vector<cow_loc>> adj_cows = find_neighbors(n_cow, occupied, needed);
            vector<cow_loc> neighbors = adj_cows.first;
            vector<cow_loc> empty = adj_cows.second;

            if (empty.size() == 1){
                needed.insert(empty[0]);
                to_visit_new.push_back(empty[0]);
            }

            for (cow_loc neighbor: neighbors){
                vector<cow_loc> empty = find_neighbors(neighbor, occupied, needed).second;
                if (empty.size() == 1){
                    needed.insert(empty[0]);
                    to_visit_new.push_back(empty[0]);
                }
            }
        }
        to_visit = to_visit_new;
    }
}

int main(){
    set<cow_loc> occupied;
    set<cow_loc> needed;

    int n, x, y;
    cow_loc cur_cow;
    cin >> n;

    for (int i = 0; i < n; ++i){
        cin >> x >> y;
        cur_cow = make_pair(x, y);
        occupied.insert(cur_cow);

        if (needed.find(cur_cow) != needed.end()){
            needed.erase(cur_cow);
        } else {
            update_needed(cur_cow, occupied, needed);
        }

        cout << needed.size() << "\n";
    }
}

