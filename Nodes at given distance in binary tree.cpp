class Solution
{
private:
    void markParent(Node* root, unordered_map<Node*, Node*>& parent) {
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            Node* current = q.front();
            q.pop();
            if(current->left) {
                parent[current->left] = current;
                q.push(current->left);
            }
            if(current->right) {
                parent[current->right] = current;
                q.push(current->right);
            }
        }
    }
    
    Node* findTarget(int target, Node* root) {
        if(!root) return NULL;
        if(target == root->data) {
            return root;
        }
        
        Node* leftSearch = findTarget(target, root->left);
        if(leftSearch) return leftSearch;
    
        return findTarget(target, root->right);
    }

    
    
public:

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        unordered_map<Node*, Node*> parent;
        markParent(root, parent);
        unordered_map<Node*, bool> vis;
        
        Node* t = findTarget(target, root);
        queue<Node*> q;
        q.push(t);
        vis[t] = 1;
        int level = 0;
        
        while(!q.empty()) {
            int size = q.size();
            if(level++ == k) break;
            
            for(int i=0; i<size; i++) {
                Node* current = q.front();
                q.pop();
                if(current->left && !vis[current->left]) {
                    vis[current->left] = 1;
                    q.push(current->left);
                }
                if(current->right && !vis[current->right]) {
                    vis[current->right] = 1;
                    q.push(current->right);
                }
                if(parent[current] && !vis[parent[current]]) {
                    vis[parent[current]] = 1;
                    q.push(parent[current]);
                }
            }
        }
        
        vector<int> ans;
        while(!q.empty()) {
            Node* curr = q.front();
            q.pop();
            ans.push_back(curr->data);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
