// semper fi //
// abdreams //
// 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define w(x)            int x; cin>>x; while(x--)

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void ab_d(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

int32_t main(){
ab_d();
        w(t){
        long long n;
        string s;
        cin >> s;
        long long pos;
        cin >> pos;
        pos--;
        n = s.size();
        vector<pair<char, int>> v;
        vector<bool> ck(n, false);
        for (int i = 0; i < n; i++) {
            v.push_back({s[i], -i});
        }
        sort(v.begin(), v.end());
        int x = n - 1;
        while (pos - x > 0) {
            pos -= x + 1;
            ck[-v[x].second] = true;
            x--;
        }
        for (int i = 0; i < n; i++) {
            if (ck[i])
                continue;
            if (pos == 0) {
                cout << s[i];
                break;
            } else
                pos--;
        }
        cout << endl;
        }
            return 0;

    }



// q1 sahil and vbhu
// https://practice.geeksforgeeks.org/problems/delete-without-head-pointer/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list node
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

class Solution {
public:
    // Function to delete a node without any reference to the head pointer.
    void deleteNode(Node* del) {

    }
};

int main() {
    Solution solution;

    // Example 1
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    Node* toDelete1 = head1->next;
    cout << "Before deletion - List 1: " << head1->data << " " << head1->next->data << endl;
    solution.deleteNode(toDelete1);
    cout << "After deletion - List 1: " << head1->data << " " << head1->next->data << endl;

    // Example 2
    Node* head2 = new Node(10);
    head2->next = new Node(20);
    head2->next->next = new Node(4);
    head2->next->next->next = new Node(30);
    Node* toDelete2 = head2->next;
    cout << "Before deletion - List 2: " << head2->data << " " << head2->next->data << " " << head2->next->next->data << " " << head2->next->next->next->data << endl;
    solution.deleteNode(toDelete2);
    cout << "After deletion - List 2: " << head2->data << " " << head2->next->data << " " << head2->next->next->data << " " << head2->next->next->next->data << endl;

    return 0;
}


/*--------------------------------------------------------------------------------*/

// q2 vbhu q2 sahil q2 daksh
// https://leetcode.com/problems/course-schedule-ii/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {

    }
};

int main() {
    Solution solution;

    // Example 1
    int numCourses1 = 2;
    vector<vector<int>> prerequisites1 = {{1, 0}};
    vector<int> result1 = solution.findOrder(numCourses1, prerequisites1);
    cout << "Example 1: ";
    for (int course : result1) {
        cout << course << " ";
    }
    cout << endl;

    // Example 2
    int numCourses2 = 4;
    vector<vector<int>> prerequisites2 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    vector<int> result2 = solution.findOrder(numCourses2, prerequisites2);
    cout << "Example 2: ";
    for (int course : result2) {
        cout << course << " ";
    }
    cout << endl;

    // Example 3
    int numCourses3 = 1;
    vector<vector<int>> prerequisites3 = {};
    vector<int> result3 = solution.findOrder(numCourses3, prerequisites3);
    cout << "Example 3: ";
    for (int course : result3) {
        cout << course << " ";
    }
    cout << endl;

    return 0;
}

/*--------------------------------------------------------------------------------*/

// q3 vbhu
// https://leetcode.com/problems/frequency-of-the-most-frequent-element/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<int> nums1 = {1, 2, 4};
    int k1 = 5;
    int result1 = solution.maxFrequency(nums1, k1);
    cout << "Example 1: " << result1 << endl;

    // Example 2
    vector<int> nums2 = {1, 4, 8, 13};
    int k2 = 5;
    int result2 = solution.maxFrequency(nums2, k2);
    cout << "Example 2: " << result2 << endl;

    // Example 3
    vector<int> nums3 = {3, 9, 6};
    int k3 = 2;
    int result3 = solution.maxFrequency(nums3, k3);
    cout << "Example 3: " << result3 << endl;

    return 0;
}


/*--------------------------------------------------------------------------------*/

// q3 sahil
// https://takeuforward.org/data-structure/boundary-traversal-of-a-binary-tree/

#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};


vector < int > printBoundary(node * root) {
 
}

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> left -> left = newNode(3);
  root -> left -> left -> right = newNode(4);
  root -> left -> left -> right -> left = newNode(5);
  root -> left -> left -> right -> right = newNode(6);
  root -> right = newNode(7);
  root -> right -> right = newNode(8);
  root -> right -> right -> left = newNode(9);
  root -> right -> right -> left -> left = newNode(10);
  root -> right -> right -> left -> right = newNode(11);

  vector < int > boundaryTraversal;
  boundaryTraversal = printBoundary(root);

  cout << "The Boundary Traversal is : ";
  for (int i = 0; i < boundaryTraversal.size(); i++) {
    cout << boundaryTraversal[i] << " ";
  }
  return 0;
}

/*--------------------------------------------------------------------------------*/

Technical Questions:

NFT Marketplace Project:

Can you explain the architecture of your NFT marketplace and how it interacts with the Internet Computer (ICP) Blockchain?
What challenges did you face while developing the marketplace, and how did you overcome them?
How did you ensure the security of user transactions and data in the NFT marketplace?
Newsletter Hub Project:

Can you describe the workflow of your newsletter subscription application and how you integrated MailChimp's API?
What validation methods did you implement for user-provided information to ensure data integrity?
How would you optimize the performance of the newsletter distribution process for a large number of subscribers?
Blog Website (InkBlog):

Explain the data storage mechanism for the blogs in your website. How did you design the database schema?
How did you handle user authentication and authorization on your blog website?
Can you discuss any specific challenges you encountered while developing the blog website and how you resolved them?
Programming Languages and Frameworks:

Which programming language do you feel most comfortable with, and why?
Could you explain the differences between Node.js and Express.js and when you would choose one over the other in a project?
How would you compare React.js to other front-end libraries or frameworks?
Technical Skills:

Share a project or experience where you utilized REST APIs. What were the key components of that project?
Describe the authentication systems you are familiar with and explain their significance in web development.
Can you provide an overview of how blockchain technology works, and how it can be applied in different projects?

/*--------------------------------------------------------------------------------*/

