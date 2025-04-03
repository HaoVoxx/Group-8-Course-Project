#pragma once
#include <iostream>
#include <queue>
#include <string>
struct trie
{
    struct Node
    {
        int count = 0;
        bool check = 0;
        int end = 0;
        Node *node[26];
        Node *link;
        Node()
        {
            for(int i = 0; i < 26; i++)
                node[i] = NULL;
        }
    };
    Node *root = new Node;
    void erase(Node *&p)
    {
        if(p == NULL) return;
        for(int i = 0; i < 26; i++)
            erase(p->node[i]);
        delete p;
    }
    void release()
    {
        erase(root);
    }
    void add(std::string s)
    {
        Node *temp = root;
        for(int i = 0; i < s.size(); i++)
        {
            int idx = s[i] - 'A';
            if(temp->node[idx] == NULL)
                temp->node[idx] = new Node;
            temp = temp->node[idx];
            temp->count++;
            temp->link = root;
        }
        temp->end++;
    }

    void link(Node *&p)
    {
        for(int i = 0; i < 26; i++)
        {
            if(p->node[i] == NULL) continue;
            Node* temp = p->link;
            while(temp != root && temp->node[i] == NULL)
                temp = temp->link;
            if(temp->node[i] != NULL) (p->node[i])->link = temp->node[i];
            link(p->node[i]);
        }
    }

    void preprocessing()
    {
        for(int i = 0; i < 26; i++)
            if(root->node[i]) link(root->node[i]);
    }
    
    int checkPrefix(Node *r)
    {
        if(r == root) return 0;
        int count = 0;
        if(r->end && !r->check) 
        {
            r->check = 1;
            count++;
        }
        return count + checkPrefix(r->link);
    }

    int travel(std::string s, int idx, Node *r)
    {
        if(idx == s.size()) return 0;
        int count = 0;
        if(r->end) 
        {
            r->check = 1;
            count++;
        }
        count += checkPrefix(r->link);
        int indx = s[idx] - 'A';
        if(r->node[indx]) count += travel(s, idx + 1, r->node[indx]);
        else if(r != root) count += travel(s, idx, r->link);
        return count;
    }

    void resetLink(Node *r)
    {
        if(r == root) return;
        if(r->end) r->check = 0;
        return resetLink(r->link);
    }

    void reset(std::string s, int idx, Node *r)
    {
        if(idx == s.size()) return;
        resetLink(r);
        int indx = s[idx] - 'A';
        if(r->node[indx]) reset(s, idx + 1, r->node[indx]);
        else if(r != root) reset(s, idx, r->link);
    }

    int countPattern(std::string s)
    {
        int indx = s[0] - 'A';
        if(!root->node[indx]) return 0;
        int count =  travel(s, 1, root->node[indx]);
        reset(s, 1, root->node[indx]);
        return count;
    }
};
