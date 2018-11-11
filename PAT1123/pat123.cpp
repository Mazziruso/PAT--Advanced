#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

struct node {
    int key;
    struct node *p;
    struct node *l;
    struct node *r;
    int height;

    node() : key(0), p(nullptr), l(nullptr), r(nullptr), height(0) {};
    node(int k) : key(k), p(nullptr), l(nullptr), r(nullptr), height(0) {};
};

class AVLTree {
    public: 
        struct node *root;
        bool complete;
        int N;
        int levelSeq[21];

        //Construct
        AVLTree() {
            this->root = new struct node();
            this->complete = true;
            this->N = 0;
            fill_n(levelSeq, 21, 0);
        }

        //Methods
        //Height
        static void setHeight(struct node *root) {
            root->height = max(root->l->height, root->r->height) + 1;
        }
        //Rotations
        //LL, right rotation
        static struct node* LLRotate(struct node *root) {
            struct node *lchild = root->l;
            struct node *parent = root->p;

            root->l = lchild->r;
            root->p = lchild;
            AVLTree::setHeight(root);

            lchild->r = root;
            lchild->p = parent;
            AVLTree::setHeight(lchild);

            /*
            if(parent!=nullptr) {
                if(parent->l==root) {
                    parent->l = lchild;
                } else {
                    parent->r = lchild;
                }
            }
            */

            return lchild;
        }
        //RR, left rotation
        static struct node* RRRotate(struct node *root) {
            struct node *rchild = root->r;
            struct node *parent = root->p;

            root->r = rchild->l;
            root->p = rchild;
            AVLTree::setHeight(root);

            rchild->l = root;
            rchild->p = parent;
            AVLTree::setHeight(rchild);

            /*
            if(parent!=nullptr) {
                if(parent->l==root) {
                    parent->l = rchild;
                } else {
                    parent->r = rchild;
                }
            }
            */

            return rchild;
        }
        static struct node* LRRotate(struct node *root) {
            root->l = AVLTree::RRRotate(root->l);
            return AVLTree::LLRotate(root);
        }
        static struct node* RLRotate(struct node *root) {
            root->r = AVLTree::LLRotate(root->r);
            return AVLTree::RRRotate(root);
        }
        //Balance method
        static struct node* balance(struct node *root) {
            AVLTree::setHeight(root);
            struct node *lchild = root->l;
            struct node *rchild = root->r;
            if(lchild->height > rchild->height + 1) {
                if(lchild->l->height > lchild->r->height) {
                    root = AVLTree::LLRotate(root);
                } else {
                    root = AVLTree::LRRotate(root);
                }
            } else if(rchild->height > lchild->height + 1) {
                if(rchild->l->height > rchild->r->height) {
                    root = AVLTree::RLRotate(root);
                } else {
                    root = AVLTree::RRRotate(root);
                }
            }
            return root;
        }
        //Insertion
        /*
        void insert(int key) {
            struct node *v = nullptr;
            struct node *nod = this->root;
            while(nod->height > 0) {
                v = nod;
                if(nod->key > key) {
                    nod = nod->l;
                } else {
                    nod = nod->r;
                }
            }
            nod->key = key;
            nod->l = new struct node();
            nod->r = new struct node();
            nod->p = v;
            nod->height = 1;

            nod = nod->p;
            while(nod != nullptr) {
                nod = AVLTree::balance(nod);
                this->root = nod;
                nod = nod->p;
            }
        }
        */
       static struct node* insert(struct node *nod, int key) {
           if(nod->height == 0) {
               nod->key = key;
               nod->l = new struct node();
               nod->r = new struct node();
               nod->height = 1;
               return nod;
           }

           if(key < nod->key) {
               nod->l = AVLTree::insert(nod->l, key);
               if((nod->l->height - nod->r->height) >= 2) {
                   if(key < nod->l->key) {
                       nod = AVLTree::LLRotate(nod);
                   } else {
                       nod = AVLTree::LRRotate(nod);
                   }
               }
           } else {
               nod->r = AVLTree::insert(nod->r, key);
               if((nod->r->height - nod->l->height) >= 2) {
                   if(key >= nod->r->key) {
                       nod = AVLTree::RRRotate(nod);
                   } else {
                       nod = AVLTree::RLRotate(nod);
                   }
               }
           }
           AVLTree::setHeight(nod);
           return nod;
       }
        //BFS, Level-order travel
        void BFS() {
            //initialization
            this->complete = true;
            bool flag = false; //which represents leaf's vertex
            queue<struct node*> q;

            struct node* v;
            struct node* lchild;
            struct node* rchild;
            v = this->root;
            int index = 0;

            q.push(v);
            while(!q.empty()) {
                v = q.front();
                q.pop();
                this->levelSeq[index++] = v->key;

                //push left child into queue
                lchild = v->l;
                if(lchild->height > 0) {
                    q.push(lchild);
                }
                //push right child into queue
                rchild = v->r;
                if(rchild->height > 0) {
                    q.push(rchild);
                }

                //check whether the tree is complete binary tree
                //判断叶结点之后还有无带子结点的结点
                if(lchild->height==0 && rchild->height==1) {
                    this->complete = false;
                }
                if(flag && v->height>1) {
                    this->complete = false;
                }
                //到达半叶结点或全叶结点
                if(rchild->height==0) {
                    flag = true;
                }
            }
        }
};

int main() {

    int N;
    int vertex;

    scanf("%d", &N);

    AVLTree tree;
    tree.N = N;
    for(int i=0; i<N; i++) {
        scanf("%d", &vertex);
        tree.root = AVLTree::insert(tree.root, vertex);
    }

    tree.BFS();

    printf("%d", tree.levelSeq[0]);
    for(int i=1; i<N; i++) {
        printf(" %d", tree.levelSeq[i]);
    }
    printf("\n%s\n", tree.complete ? "YES" : "NO");

    return 0;
}