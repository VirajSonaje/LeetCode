/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    map<int, Node*> visited;
    
    Node* cloneGraph(Node* node) {
        Node* root = new Node();
        if(node == NULL) return node;
        DFS(node, root); 
        visited.clear();
        return root;
    }
    
    void DFS(Node* node, Node* root){
        
        visited[node->val] = root;
        root->val = node->val;
        
        for(Node* x: node->neighbors){
            if(!visited[x->val]){
                Node* newNode = new Node();
                root->neighbors.push_back(newNode);
                DFS(x, newNode);
                
            }
            else{
                root->neighbors.push_back(visited[x->val]);
            }
        }
        
    }
};