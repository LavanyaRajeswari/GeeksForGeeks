//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    unordered_map<long long,vector<long long>>mp;
    unordered_map<long long,long long>v;
    int t = 0,mx = 0,n = 0,vd = 1;
    void tree(Node* root,unordered_map<long long,vector<long long>>&mp) {
        if(root == NULL){
            return;
        }
        v[root->data]++;
        n++;
        if(root->left == NULL &&root->right == NULL) return;
        if(root->left != NULL){
            // vector<int>ans;
            // ans = mp[root->data];
            // ans.push_back(root->left->data);
            // mp[root->data] = ans;
            // ans = mp[root->left->data];
            // ans.push_back(root->data);
            // mp[root->left->data] = ans;
            
            mp[root->data].push_back(root->left->data);
            mp[root->left->data].push_back(root->data);
            
            tree(root->left,mp);
        }
        if(root->right != NULL){
            // vector<int>ans;
            // ans = mp[root->data];
            // ans.push_back(root->right->data);
            // mp[root->data] = ans;
            // ans = mp[root->right->data];
            // ans.push_back(root->data);
            // mp[root->right->data] = ans;
            
            mp[root->data].push_back(root->right->data);
            mp[root->right->data].push_back(root->data);
            
            tree(root->right,mp);
        }
    }
    void dfs(int t,long long target,unordered_map<long long,long long>&v){
        mx = max(mx,t);
        if(vd == n) return;
            if(v[target]) v[target] = 0;
            for(auto i : mp[target]){
                if(v[i]){
                    vd++;
                    v[i] = 0;
                    dfs(t+1,i,v);
                }
            }
    }
        
    int minTime(Node* root, int target) 
    {
        if(root == NULL) return 0;
        tree(root,mp);
        // cout<<n<<endl;
        dfs(t,target,v);
        return mx;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends