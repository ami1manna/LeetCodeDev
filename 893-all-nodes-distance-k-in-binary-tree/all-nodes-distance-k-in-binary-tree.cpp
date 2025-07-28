/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void generate(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mp) {

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            TreeNode* left = node->left;
            TreeNode* right = node->right;

            if (left) {
                q.push(left);
                mp[left] = node;
            }
            if (right) {
                q.push(right);
                mp[right] = node;
            }
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mp;
        generate(root, mp);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> st;

        q.push(target);
        st.insert(target);
        int len = 0;

        while (!q.empty()) {

            if (len == k)
                break;

            int size = q.size();

           

            for (int i = 0; i < size; i++) {
                
                TreeNode* node = q.front();
                q.pop();
                
                TreeNode* left = node->left;
                TreeNode* right = node->right;
                TreeNode* par = mp[node];

                if (left && st.find(left) == st.end()) {
                    q.push(left);
                    st.insert(left);
                }
                if (right && st.find(right) == st.end()) {
                    q.push(right);
                    st.insert(right);
                }
                if (par && st.find(par) == st.end()) {
                    q.push(par);
                    st.insert(par);
                }
            }

            len++;
        }

        vector<int> res;

        while (!q.empty()) {
            res.push_back(q.front()->val);
            q.pop();
        }

        return res;
    }
};