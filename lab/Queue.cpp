void interleaveQueue(queue<int>& q){
    // Step 1: Push first half elements into stack
    stack<int> s;
    int halfSize = q.size() / 2;
    for (int i = 0; i < halfSize; ++i) {
        s.push(q.front());
        q.pop();
    }

    // Step 2: Enqueue back the stack elements
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Step 3: Dequeue the first half elements of the queue and enqueue them back
    for (int i = 0; i < halfSize; ++i) {
        q.push(q.front());
        q.pop();
    }

    // Step 4: Again push the first half elements onto the stack
    for (int i = 0; i < halfSize; ++i) {
        s.push(q.front());
        q.pop();
    }

    // Step 5: Interleave the elements of stack and queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}
bool isBipartite(vector<vector<int>> graph) {
     int n = graph.size();
    vector<int> colors(n, 0); // 0: not colored, 1: red, -1: blue
    
    for (int start = 0; start < n; ++start) {
        if (colors[start] != 0) continue; // Skip already colored nodes
        
        // Start BFS from the node 'start'
        queue<int> q;
        q.push(start);
        colors[start] = 1; // Color the start node red
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbor : graph[node]) {
                if (colors[neighbor] == 0) {
                    // Color with opposite color
                    colors[neighbor] = -colors[node];
                    q.push(neighbor);
                } else if (colors[neighbor] == colors[node]) {
                    // Found the same color neighbor
                    return false;
                }
            }
        }
    }
    
    return true;
}

void push(T item) {
    // TODO: Push new element into the end of the queue
    list.add(item);
}

T pop() {
    // TODO if (empty()) throw std::out_of_range("Queue is empty");
    if (empty()) throw std::out_of_range("Queue is empty");
        return list.removeAt(0);
        
}

T top() {
    // TODO: Get value of the element in the head of the queue
     if (empty()) throw std::out_of_range("Queue is empty");
        return list.get(0);    
}

bool empty() {
        return list.empty();
    }

    // Returns the number of items in the queue
    int size() {
        return list.size();
    }

    // Removes all items from the queue
    void clear() {
        list.clear();
    }
void bfs(vector<vector<int>> graph, int start) {
	vector<bool> visited(graph.size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int node = q.front();
        cout << node << " ";
        q.pop();
        for (int i : graph[node]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    cout << "\n";
}

void push(T item) {
    // TODO: Push new element into the end of the queue
    list.add(item);
}

T pop() {
    // TODO if (empty()) throw std::out_of_range("Queue is empty");
    if (empty()) throw std::out_of_range("Queue is empty");
        return list.removeAt(0);
        
}

T top() {
    // TODO: Get value of the element in the head of the queue
     if (empty()) throw std::out_of_range("Queue is empty");
        return list.get(0);    
}

bool empty() {
        return list.empty();
    }

    // Returns the number of items in the queue
    int size() {
        return list.size();
    }

    // Removes all items from the queue
    void clear() {
        list.clear();
    }

// iostream, vector and queue are included
// You can write helper methods

long long nthNiceNumber(int n) {
    queue<long long> q;
    q.push(2);
    q.push(5);
    long long number;
    
    for (int i = 0; i < n; ++i) {
        number = q.front();
        q.pop();
        q.push(number * 10 + 2);
        q.push(number * 10 + 5);
    }
    
    return number;
}

// iostream, vector and queue are included
// Hint: use breadth-first-search

int secondsToBeRotten(vector<vector<int>>& grid) {
     int rows = grid.size();
    int cols = grid[0].size();
    queue<pair<int, int>> q;
    int freshCount = 0;
    int time = 0;

    // Initial pass to find all rotten apples and count fresh apples
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 2) {
                q.push({i, j});
            } else if (grid[i][j] == 1) {
                ++freshCount;
            }
        }
    }

    // Directions array for the adjacent cells
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // BFS to rot the fresh apples
    while (!q.empty() && freshCount > 0) {
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i) {
            pair<int, int> cell = q.front();
            q.pop();
            for (auto dir : directions) {
                int x = cell.first + dir[0];
                int y = cell.second + dir[1];
                if (x >= 0 && y >= 0 && x < rows && y < cols && grid[x][y] == 1) {
                    grid[x][y] = 2;
                    q.push({x, y});
                    --freshCount;
                }
            }
        }
        ++time; // Increase time after each level of BFS
    }

    // If there are still fresh apples, return -1
    return freshCount == 0 ? time : -1;
}

int sumOfMaxSubarray(vector<int>& nums, int k) {
    // STUDENT ANSWER
    int sum = 0;
    deque<int> dq; // Will store indices of elements in `nums`

    for (int i = 0; i < nums.size(); ++i) {
        // Remove indices that are out of the current window
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
        
        // Remove indices whose corresponding values are less than `nums[i]`
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }
        
        // Add `i` to the deque since it is in the current window
        dq.push_back(i);
        
        // If we have hit at least `k` elements added to `nums`, add to sum
        if (i >= k - 1) {
            sum += nums[dq.front()];
        }
    }

    return sum;
}
