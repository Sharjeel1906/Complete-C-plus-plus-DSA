#include<iostream>
using namespace std;

class CommitNode{
public:
    string filename;
    string content;
    int commitID;
    string timestamp;

    CommitNode* next;

    CommitNode(string fname, string cont, int id, string time);
};

class CommitQueue{
private:
    CommitNode* front;
    CommitNode* rear;

public:
    CommitQueue(){
        front = NULL;
        rear = NULL;
    }

    void enqueueCommit(string filename, string content, int commitID, string timestamp);

    CommitNode* dequeueCommit();

    bool processCommit();

    bool isQueueEmpty();

    void displayQueue();

    void VersionManager(string filename, string content, int commitID, string timestamp);
};

int main(){

}

void CommitQueue::enqueueCommit(string filename, string content, int commitID, string timestamp)
{
    CommitNode *new_node = new CommitNode(filename,content,commitID,timestamp);
    new_node->next=NULL;
    if(front==NULL){
        front=rear=new_node;
    }else{
        rear->next=new_node;
        rear = new_node;
    }
}

CommitNode *CommitQueue::dequeueCommit()
{
    if(isQueueEmpty()){
        return nullptr;
    }
    CommitNode* temp = front;
    front = front->next;
    if(front==NULL){
        rear=NULL;
    }
    return temp;
}

bool CommitQueue::processCommit()
{
    if(isQueueEmpty()){
        return false;
    }
    CommitNode* first = front;
    VersionManager(first->filename,first->content,first->commitID,first->timestamp);
    dequeueCommit();
    return true;
}

bool CommitQueue::isQueueEmpty()
{
    if(front==NULL){
        return true;
    }
    return false;
}

void CommitQueue::displayQueue()
{
    if(isQueueEmpty()){
        return;
    }else{
        CommitNode* temp = front;
        cout<<"Pending Commits:"<<endl;

        while(temp!=NULL){
            cout<<"File: "<<temp->filename<<endl;
            cout<<"CommitId"<<temp->commitID<<endl;
            cout<<"Time"<<temp->timestamp<<endl;
            temp = temp->next;

        }
    }
}
