#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createnode(int data) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// Function to insert a node into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        root = createnode(data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to find the minimum node
int findmin(struct Node* root) {
    struct Node* temp = root;
    while (temp->left != NULL) {
        temp = temp->left;
    }
    return temp->data;
}

// Function to find the maximum node
int findmax(struct Node* root) {
    struct Node* temp = root;
    while (temp->right != NULL) {
        temp = temp->right;
    }
    return temp->data;
}


// Function to search for a value in the BST
int search(struct Node* root, int data) {
    if (root == NULL) {
        return 0;
    } else if (root->data == data) {
        return 1;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Function to calculate the depth of the tree
int depth(struct Node* root) {
    if (root == NULL) {
        return -1;
    } else {
        int lefth = depth(root->left);
        int righth = depth(root->right);
        return (lefth > righth ? lefth : righth) + 1;
    }
}

// Function for Breadth-First Search (BFS) without a queue
//void bfs(struct Node* root, int level) {
//    if (root == NULL) return;
//    if (level == 0) {
//        printf("%d ", root->data);
//    } else {
//        bfs(root->left, level - 1);
//        bfs(root->right, level - 1);
//    }
//}
//
//// Wrapper function to perform BFS level-by-level
//void bfsTraversal(struct Node* root) {
//    int h = depth(root);
//    for (int i = 0; i <= h; i++) {
//        bfs(root, i);
//    }
//    printf("\n");
//}
//
//// Function for Pre-Order Depth-First Search (DFS)
//void dfs_pre(struct Node* root) {
//    if (root == NULL) {
//        return;
//    }
//    printf("%d ", root->data);
//    dfs_pre(root->left);
//    dfs_pre(root->right);
//}
//
//// Function for In-Order Depth-First Search (DFS)
//void dfs_in(struct Node* root) {
//    if (root == NULL) {
//        return;
//    }
//    dfs_in(root->left);
//    printf("%d ", root->data);
//    dfs_in(root->right);
//}
//
//// Function for Post-Order Depth-First Search (DFS)
//void dfs_post(struct Node* root) {
//    if (root == NULL) {
//        return;
//    }
//    dfs_post(root->left);
//    dfs_post(root->right);
//    printf("%d ", root->data);
//}
//
//// Function to delete a node from the BST
//struct Node* Delete(struct Node* root, int data) {
//    if (root == NULL) {
//        return NULL;
//    }
//
//    if (data < root->data) {
//        root->left = Delete(root->left, data);
//    } else if (data > root->data) {
//        root->right = Delete(root->right, data);
//    } else {
//        if (root->left == NULL && root->right == NULL) {
//            free(root);
//            root = NULL;
//        } else if (root->left == NULL) {
//            struct Node* temp = root;
//            root = root->right;
//            free(temp);
//        } else if (root->right == NULL) {
//            struct Node* temp = root;
//            root = root->left;
//            free(temp);
//        } else {
//            struct Node* temp = findmin(root->right);
//            root->data = temp->data;
//            root->right = Delete(root->right, temp->data);
//        }
//    }
//    return root;
//}

// Main function to test the tree operations
int main() {
    struct Node* root = NULL;
    int n;

    root = insert(root, 15);
    root = insert(root, 19);
    root = insert(root, 17);
    root = insert(root, 11);
    root = insert(root, 14);
    root = insert(root, 2);
    root = insert(root, 100);
    root = insert(root, 0);
    root = insert(root, 1000);
    root = insert(root, 101);
    root = insert(root, 10);
    root = insert(root, 13);
    root = insert(root, 300);

    printf("Enter a number to search: ");
    scanf("%d", &n);
    if (search(root, n)) {
        printf("Data Found!\n\n");
    } else {
        printf("Data not Found!\n\n");
    }

    printf("Depth of tree is %d\n", depth(root));


    printf("Minimum element in the tree is %d\n", findmin(root));
    printf("Maximum element in the tree is %d\n", findmax(root));

//    printf("Breadth-First Traversal: ");
//    bfsTraversal(root);
//
//    printf("Depth-First Traversal (Pre-order):       ");
//    dfs_pre(root);
//    printf("\n");
//
//    printf("Depth-First Traversal (In-order)/Sorted: ");
//    dfs_in(root);
//    printf("\n");
//
//    printf("Depth-First Traversal (Post-order):      ");
//    dfs_post(root);
//    printf("\n");
//
//    root = Delete(root, 2);
//    printf("After deletion of 2, In-order Traversal: ");
//    dfs_in(root);
//    printf("\n");

    return 0;
}
